"""
	This program takes a chapter.md that uses spaced/tabbed code blocks
	and converts them to spaced, cpp fenced code blocks.

	If the chapter.md already has fenced code blocks, this will no function
	properly!

	This script takes a single command line argument:
		e.g. ../chapters/animation/chapter.md
	The output file is stored at:
		e.g. ../chapters/animation/chapter_fenced_code.md

	Note, regular expressions are a pain, so any file should be checked
	just to make sure nothing was missed.
"""


import re 
import os
import sys

NUM_SPACES_PER_TAB = 4
TAB_TO_SPACES = " " * NUM_SPACES_PER_TAB


def convertToFencedCode(originalChapterPath):
	head, tail = os.path.split(originalChapterPath)
	outputChapterPath = os.path.join(head, "chapter_fenced_code.md")

	print "Converting {0} to {1}".format(originalChapterPath, outputChapterPath)

	with open(originalChapterPath, "r") as chapter:

		# Original chapter string
		fileString = chapter.read()

		# Find all tab- or space-indended code blocks!
		#
		# An indented code block looks something like this: 
		#	Line 1: "WORDS_BEFORE_CODE\n"
		#	Line 2: "\n" <- This break is essential
		#	Line 3: "\tCODE_CODE_CODE\n"
		#	Line 4: "\tCODE_CODE_CODE\n"
		#	Line 5: "\n" <- This break is essential
		#	Line 6: "WORDS_AFTER_CODE\n"
		# Break down of turning that into a regex:
		#	?: 				Causes groups to not be stored, omitted from 
		#					descriptions below
		# 	re.MULTILINE	Allows "^" to match the start of any line
		#					instead of just matching the start of the string
		#	^\s+ 			Start with an empty line
		#	((^( {4}|\t)+.*)
		#					Next line starts with tabs or sets of 4 spaces followed
		#					by zero or more wildcards.  AKA "indented line".
		#	((\s+(^( {4}|\t)+.*))*)) 
		#					Followed by zero or more of the following:
		#						Whitespace followed by an "indented line"
		# Running the regex on the example above would return:
		#	Line 3: "\tCODE_CODE_CODE\n"
		#	Line 4: "\tCODE_CODE_CODE\n"	
		pattern = r'^\s+((?:(?:^(?: {4}|\t)+.*)(?:\s+(?:^(?: {4}|\t)+.*))*))'
		matches = re.findall(pattern, fileString, flags=re.MULTILINE)

		for match in matches:
			# Find the starting and ending positions of the match inside of
			# the chapter file string
			start = fileString.find(match)
			end = start + len(match)

			# Convert tabs inside of the match into spaces
			match = match.replace("\t", TAB_TO_SPACES)

			# Remove the first indent from all lines
			# 	The second line below is a little hacky.  The match
			#	doesn't start with a blank line, but we know that
			# 	it must be indented.  So, we can manually remove it. 
			match = match.replace("\n"+TAB_TO_SPACES, "\n")
			match = match[NUM_SPACES_PER_TAB:]

			# Added fenced code blocks with the cpp identifier
			match = "```cpp\n" + match + "\n```" 

			# Splice the match back into the chapter file string
			fileString = fileString[:start] + match + fileString[end:]

	with open(outputChapterPath, "w") as outputChapter:
		outputChapter.write(fileString)

	print "Done!"


if __name__ == "__main__":
	pathToChapter = sys.argv[1]
	convertToFencedCode(pathToChapter)
