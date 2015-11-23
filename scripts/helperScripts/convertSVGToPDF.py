import os
import sys
import subprocess

# Get the order of the chapters
chapterOrderPath = os.path.join("..", "..", "chapters", "order.txt")

# Get a straight list of chapters
chapters = []
lines = open(chapterOrderPath).read().splitlines()
for line in lines:
	leading_spaces = len(line) - len(line.lstrip())
	if (leading_spaces):
		chapters.append(line.lstrip().rstrip())

for chapter in chapters:
	chapterImagesPath = os.path.join("..", "..", "chapters", chapter, "images")

	for filename in os.listdir(chapterImagesPath):
		name, ext = filename.split(".")
		infilepath = os.path.join(chapterImagesPath, filename)
		outfilepath = os.path.join(chapterImagesPath, name+".pdf")
		if ext == "svg":
			subprocess.call(["inkscape", "-z", infilepath, 
							"--export-background=rgb(255, 255, 255)",
							"--export-pdf="+outfilepath])
			print "Converting {0} to {1}".format(infilepath, outfilepath)

