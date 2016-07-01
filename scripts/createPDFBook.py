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
				- order.txt (order list of chapters in ofBook)

	After running, the pdf and tex of ofBook will be added to output/ like this:
		- ofBook
			- ...
			- output
				- ofBook.pdf
				- ofBook.tex

	Dependencies:
		Pandoc
"""
from __future__ import print_function
from io import open

import os
import re
import subprocess

# Output path
outputPath = os.path.join("..", "output")
if not os.path.exists(outputPath): os.makedirs(outputPath)
pdfBookPath = os.path.join(outputPath, "ofBook.pdf")
texBookPath = os.path.join(outputPath, "ofBook.tex")

# Load each chapter from order.txt, do any pre-processing necessary and save the
# final version as /../chapters/CHAPTER_NAME/chapterModified.md
chapterPaths = []
chapterOrderPath = os.path.join("..", "chapters", "order.txt")
with open(chapterOrderPath) as fh:
	fh.readline()

	# For each chapter
	for line in fh:

		# [zach] -- this is checking for tabs to organzing groups for chapters
		# http://stackoverflow.com/questions/13241399/python-check-string-indentation

		leading_spaces = len(line) - len(line.lstrip())

		if (leading_spaces):

			chapters = []

			chapterName = line.lstrip().rstrip()
			chapterPath = os.path.join("..", "chapters", chapterName, "chapter.md")

			# If a chapter.md exists
			if os.path.exists(chapterPath):

				# Process the chapter:
				# 	1. Make all images relative to the current directory, i.e. preappend
				# 		../chapters/CHAPTER_NAME/ to each chapter.  This uses python's
				#		sub function of the regular expression module.  It looks for the
				# 		markdown formatted "![image title](" and adds the path at the end.
				with open(chapterPath, "r", encoding='utf-8') as originalChapter:
					fileString = originalChapter.read()
					imgPattern = r'(\!\[(.*)\]\()'
					subPattern = r'\1../chapters/{0}/'.format(chapterName)
					modifiedChapterString = re.sub(imgPattern, subPattern, fileString)
					modifiedChapterPath = os.path.join("..", "chapters", chapterName, "chapter_modified_for_print.md")
					with open(modifiedChapterPath, "w", encoding='utf-8') as modifiedChapter:
						modifiedChapter.write(modifiedChapterString)
				chapterPaths.append(modifiedChapterPath)


# Set up the appropriate options for the pandoc command
inputOptions = chapterPaths
generalOptions = ["-N", "--smart", "--no-tex-ligatures", "--toc", "--toc-depth=4", "--standalone", "--preserve-tabs"]
latexOptions = ["--template=ofBookTemplate.tex", "--latex-engine=xelatex", "--variable=papersize:a4",
				"--variable=documentclass:scrbook",	"--listings", "--variable=links-as-notes", "--default-image-extension=PDF"]
outputOptions = ["--output={0}".format(pdfBookPath)]
pandocCommand = ["pandoc"] + outputOptions + inputOptions + generalOptions + latexOptions

# Print out of the chapters being built and the flags being used
print("Generating {0} from:".format(pdfBookPath))
for chapter in inputOptions:
	print("\t{0}".format(chapter))
print("Using the following flags:")
for flag in generalOptions+latexOptions:
	print("\t{0}".format(flag))

# For debugging purposes, it's a good idea to generate the .tex.  Errors
# printed out through pandoc aren't as useful as those printed
# directly from trying to build a PDF in TeXworks.
texOutputOptions = ["--output={0}".format(texBookPath)]
texPandocCommand = ["pandoc"] + texOutputOptions + inputOptions + generalOptions + latexOptions
returnCode = subprocess.call(texPandocCommand)
if returnCode == 0:
	print("Successful building of {0}".format(texBookPath))
else:
	print("Error in building of {0}".format(texBookPath))

# Call pandoc
returnCode = subprocess.call(pandocCommand)
if returnCode == 0:
	print("Successful building of {0}".format(pdfBookPath))
else:
	print("Error in building of {0}".format(pdfBookPath))

# Cleanup - remove the modified chapters
for modifiedChapterPath in chapterPaths:
	os.remove(modifiedChapterPath)
