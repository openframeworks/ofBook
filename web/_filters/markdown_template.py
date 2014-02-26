import markdown
import logging
import sys
import os
sys.path.append(os.getcwd()+"/_filters")
import mdx_mathjax

config = {
    'name': "Markdown",
    'description': "Renders markdown formatted text to HTML",
    'aliases': ['markdown']
    }


#Markdown logging is noisy, pot it down:
logging.getLogger("MARKDOWN").setLevel(logging.ERROR)


def run(content):
    return markdown.markdown(content, ['fenced_code','footnotes','headerid','mathjax'], output_format="html5")
