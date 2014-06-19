"""
	Takes the markdown chapters, and using pandoc, converts them to HTML.  CSS styling by Andy
	and Ishac is applied.  A few hacks are applied to make everything run smoothly.

	Assumes that the file structure looks like this:

		- ofBook
			- scripts
				- createWebBook.py
				- createWebBookTemplate
					- IncludeAfterBody.html
					- IncludeBeforeBody.html
					- IncludeInHeader.html
			- chapters
				- CHAPTER_X
					- chapter.md
					- images
				- order.txt 
			- output
				- chapters
				- style
					- fonts
					- style.css

	After running, the chapters will be added to output/chapters like this:
		- chapters
			- CHAPTER_X
				- images
			- CHAPTER_X.html

	The reason for this structure is that, for firefox, the fonts directory must be located
	on the same domain as CHAPTER_X.html (i.e. it must be in /chapters or a subdirectory of /chapters)

	Dependencies: 
		BeautifulSoup4, install using "sudo pip install BeautifulSoup4"
"""


import os
import subprocess
import shutil
from bs4 import BeautifulSoup as Soup

def copytree(src, dst, symlinks=False, ignore=None):
    if not os.path.exists(dst):
        os.makedirs(dst)
    for item in os.listdir(src):
        s = os.path.join(src, item)
        d = os.path.join(dst, item)
        if os.path.isdir(s):
            copytree(s, d, symlinks, ignore)
        else:
            if not os.path.exists(d) or os.stat(src).st_mtime - os.stat(dst).st_mtime > 1:
                shutil.copy2(s, d)

chapters = open("../chapters/order.txt").read().splitlines()

for chapter in chapters:
	sourceDirectoryPath = os.path.join("..", "chapters", chapter)
	sourceChapterPath = os.path.join(sourceDirectoryPath, "chapter.md")
	sourceImagesPath = os.path.join(sourceDirectoryPath, "images")

	destDirectoryPath = os.path.join("..", "output", "chapters", chapter)
	destChapterPath = os.path.join("..", "output", "chapters", chapter+".html")
	destImagesPath = os.path.join(destDirectoryPath, "images")

	print "Converting", sourceChapterPath, "to", destChapterPath, "..."
	subprocess.call(["pandoc", "-o", destChapterPath, sourceChapterPath,
					"-s", "--toc", "--toc-depth=4", "-p", "--mathjax",	
					"--include-in-header=createWebBookTemplate/IncludeInHeader.html",
					"--include-before-body=createWebBookTemplate/IncludeBeforeBody.html",
					"--include-after-body=createWebBookTemplate/IncludeAfterBody.html"])

	if os.path.exists(sourceImagesPath):
		copytree(sourceImagesPath, destImagesPath)
	
	#now, let's parse the index.html and change some things: 
	if os.path.exists(destChapterPath):
		soup = Soup(open(destChapterPath).read())
		h1s = soup.find_all("h2")

		# Turn captions into spans for CSS formatting
		pCaption = soup.find_all("p", class_="caption")
		for tag in pCaption:
			tag.name = "span"

		# Images have been stored in ./CHAPTER_NAME/images/ relative to the chapter html,
		# but image references in the html are to ./images/.  Modify the image tags:
		imgTags = soup.find_all("img")
		for imgTag in imgTags:
			imgTag["src"] = chapter + "/" + imgTag["src"]

		html = soup.encode("utf-8")
		with open(destChapterPath, "wb") as file:
			file.write(html)

	#h1s will be super helpful for sidebar and building up a map of content :)
	

