
import os
import re
import logging

from blogofile.cache import bf
import shutil
import sys

import argparse
import glob

import logging
import StringIO
import collections


logger = logging.getLogger("blogofile.post")   

def stripFileLine(line):
    return  line.lstrip(' ').rstrip('\n').rstrip(' ')
    
        
class MarkdownArticle:
    def __init__(self,markdown):
        mdfile = open(markdown,'r')
        state = 'begin'
        self.file = 'index.html'
        self.date = ''
        self.title = ''
        self.summary = ''
        self.author = ''
        self.author_site = ''
        self.body = ''
        self.type = 'markdown'
        for line in mdfile:
            line = line.decode('utf-8','replace')
            self.body = self.body + line       
            

def run():
    classes = []
    directory = ".."
    categories = []
    
    dirs = os.listdir(directory)
    dirs.sort()
    for catfolder in dirs:
        if not os.path.isdir(os.path.join(directory,catfolder)):
            continue
        if catfolder == 'web':
            continue
        if catfolder == '.git':
            continue
        articles = []
        category = catfolder[catfolder.find("_")+1:]
        articlesfiles = os.listdir(os.path.join(directory,catfolder));
        articlesfiles.sort()
        for article in articlesfiles:
            if article == "chapter.md":
                articleobj = MarkdownArticle(os.path.join(directory,catfolder,article))
                bf.template.materialize_template("tutorial.mako", (category,articleobj.file), {'article':articleobj} )
                articles.append(articleobj)
            if os.path.isdir(os.path.join(directory,catfolder,article)):
                shutil.copytree(os.path.join(directory,catfolder,article),os.path.join('_site',category,article))
            else:
                fileName, fileExtension = os.path.splitext(article)
                if fileExtension == '.png' or fileExtension == '.gif' or fileExtension == '.svg':
                    try:
                        os.mkdir(os.path.join('_site',category))
                    except Exception:
                        pass
                    shutil.copyfile(os.path.join(directory,catfolder,article),os.path.join('_site',category,article))
        categories.append({'category': category, 'articles': articles});
    bf.template.materialize_template("tutorials.mako", ('',"index.html"), {'categories':categories} )
