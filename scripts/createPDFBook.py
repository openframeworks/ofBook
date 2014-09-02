"""
	Takes the markdown chapters, and using pandoc, converts and combines them into 
	a PDF.  Pandoc uses LaTex for the conversion.  The file scripts/ofBookTemplate.tex
	provides LaTeX styling.

	Assumes that the file structure looks like this:

		- ofBook
			- scripts
				- createPDFBook.py
				- ofBookTemplate.tex
			- chapters
				- CHAPTER_NAME
					- chapter.md
					- images/
				- order.txt 

	where order.txt is an ordered list of the chapters of ofBook

	The final PDF is saved to ofBook/ofBook.pdf 

	Dependencies: 
		Pandoc
"""

import os
import re
import subprocess

# Output path
pdfBookPath = os.path.join("..", "ofBook.pdf") 

# Load each chapter from order.txt, do any pre-processing necessary and save the
# final version as /../chapters/CHAPTER_NAME/chapterModified.md
chapterPaths = []
chapterOrderPath = os.path.join("..", "chapters", "order.txt")
with open(chapterOrderPath) as fh:
	fh.readline()	

	# For each chapter
	for line in fh:
		chapterName = line.rstrip()
		chapterPath = os.path.join("..", "chapters", chapterName, "chapter.md")

		# If a chapter.md exists
		if os.path.exists(chapterPath): 

			# Process the chapter:
			# 	1. Make all images relative to the current directory, i.e. preappend
			# 		../chapters/CHAPTER_NAME/ to each chapter.  This uses python's 
			#		sub function of the regular expression module.  It looks for the
			# 		markdown formatted "![image title](" and adds the path at the end.		
			with open(chapterPath, "r") as originalChapter:
				fileString = originalChapter.read()
				imgPattern = r'(\!\[(.*)\]\()'
				subPattern = r'\1../chapters/{0}/'.format(chapterName)
				modifiedChapterString = re.sub(imgPattern, subPattern, fileString)
				modifiedChapterPath = os.path.join("..", "chapters", chapterName, "chapter_modified_for_print.md")
				with open(modifiedChapterPath, "w") as modifiedChapter:
					modifiedChapter.write(modifiedChapterString)			
			chapterPaths.append(modifiedChapterPath)


# Set up the appropriate options for the pandoc command
inputOptions = chapterPaths
generalOptions = ["-N", "--smart", "--no-tex-ligatures", "--toc", "--toc-depth=4", "--standalone", "--preserve-tabs"]
latexOptions = ["--template=ofBookTemplate.tex", "--latex-engine=xelatex", "--variable=papersize:a4", 
				"--variable=documentclass:scrbook",	"--listings", "--variable=links-as-notes"]
outputOptions = ["--output={0}".format(pdfBookPath)]
pandocCommand = ["pandoc"] + outputOptions + inputOptions + generalOptions + latexOptions

# Print out of the chapters being built and the flags being used
print "Generating {0} from:".format(pdfBookPath)
for chapter in inputOptions:
	print "\t{0}".format(chapter)
print "Using the following flags:"
for flag in generalOptions+latexOptions:
	print "\t{0}".format(flag)

# For debugging purposes, it's a good idea to generate the .tex.  Errors
# printed out through pandoc aren't as useful as those printed
# directly from trying to build a PDF in TeXworks.
texBookPath = "ofBook.tex"
texOutputOptions = ["--output={0}".format(texBookPath)]
texPandocCommand = ["pandoc"] + texOutputOptions + inputOptions + generalOptions + latexOptions
returnCode = subprocess.call(texPandocCommand)
if returnCode == 0: 
	print "Successful building of {0}".format(texBookPath)
else:
	print "Error in building of {0}".format(texBookPath)

# Call pandoc
returnCode = subprocess.call(pandocCommand)
if returnCode == 0: 
	print "Successful building of {0}".format(pdfBookPath)
else:
	print "Error in building of {0}".format(pdfBookPath)