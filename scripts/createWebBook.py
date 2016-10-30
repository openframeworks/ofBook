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
			- static
				- javascript
				- style
					- fonts

	After running, the website will be added to output/webBook like this:
		- ofBook
			- ...
			- output
				- webBook
					- chapters
						- CHAPTER_NAME.html
					- images
						- CHAPTER_NAME
							- images go here
					- javascript
					- style
						- fonts
					- toc.html (Table of Contents)

	The reason for this structure is that, for firefox, the fonts directory must be located
	on the same domain as CHAPTER_X.html (i.e. it must be in /chapters or a subdirectory of /chapters)

	Dependencies:
		BeautifulSoup4, install using "sudo pip install BeautifulSoup4"
"""
from __future__ import print_function

import os
import subprocess
import shutil
import sass
import string
from bs4 import BeautifulSoup as Soup
from bs4 import Tag, NavigableString
from sys import platform as _platform

#-------------------------------------------------------------- copy a folder recursively
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

#-------------------------------------------------------------- wrap function for soup
def wrap(to_wrap, wrap_in):
    contents = to_wrap.replace_with(wrap_in)
    wrap_in.append(contents)

#-------------------------------------------------------------- clone function for soup
#http://stackoverflow.com/questions/23057631/clone-element-with-beautifulsoup
def clone(el):
    if isinstance(el, NavigableString):
        return type(el)(el)

    copy = Tag(None, el.builder, el.name, el.namespace, el.nsprefix)
    # work around bug where there is no builder set
    # https://bugs.launchpad.net/beautifulsoup/+bug/1307471
    copy.attrs = dict(el.attrs)
    for attr in ('can_be_empty_element', 'hidden'):
        setattr(copy, attr, getattr(el, attr))
    for child in el.contents:
        copy.append(clone(child))
    return copy

#-------------------------------------------------------------- parse out the chapter list and path
# Get the order of the chapters
chapterOrderPath = os.path.join("..", "chapters", "order.txt")


# (1) get a straight list of chapters

chapters = []
lines = open(chapterOrderPath).read().splitlines()
for line in lines:
	leading_spaces = len(line) - len(line.lstrip())
	if (leading_spaces):
		chapters.append(line.lstrip().rstrip())

# (2) make an organizational heirarchy

chapterGroups = []
chapterGroup = {}

for line in lines:
	leading_spaces = len(line) - len(line.lstrip())
	if (leading_spaces == 0):
		if ('groupName' in chapterGroup):
			chapterGroups.append(chapterGroup)
		chapterGroup = {}
		chapterGroup['groupName'] = line.rstrip()
		chapterGroup['chapters'] = []
	if (leading_spaces):
		chapterGroup['chapters'].append(line.lstrip().rstrip())
#snag the last group if we got to the end
if ('groupName' in chapterGroup):
	chapterGroups.append(chapterGroup)


#-------------------------------------------------------------- folders for the book
# Create the output directories for the webBook
webBookPath = os.path.join("..", "output", "webBook")
webBookChaptersPath = os.path.join(webBookPath, "chapters")
if not os.path.exists(webBookPath): os.makedirs(webBookPath)
if not os.path.exists(webBookChaptersPath): os.makedirs(webBookChaptersPath)


#--------------------------------------------------------------  static stuff
# Copy static directories
staticStylePath = os.path.join("..", "static", "style")
webBookStylePath = os.path.join(webBookPath, "style")
staticJSPath = os.path.join("..", "static", "javascript")
webBookJSPath = os.path.join(webBookPath, "javascript")
staticFAPath = os.path.join("..", "static", "octicons")
copytree(staticStylePath, webBookStylePath)
copytree(staticJSPath, webBookJSPath)

staticScssFile = os.path.join("..", "static", "style", 'style.scss')
outputCssFile = os.path.join(webBookPath, "style", "style.css")

print("compiling " + staticScssFile)
compiledCss = sass.compile(filename=staticScssFile)
cssFile = open(outputCssFile, 'w')
cssFile.write(compiledCss)
cssFile.close()
print("output " + outputCssFile)






chapterDicts = [];

#-------------------------------------------------------------- make the book
for chapter in chapters:

	#src:
	sourceDirectoryPath = os.path.join("..", "chapters", chapter)
	sourceChapterPath = os.path.join(sourceDirectoryPath, "chapter.md")
	sourceImagesPath = os.path.join(sourceDirectoryPath, "images")

	#dst:
	destDirectoryPath = os.path.join(webBookPath, "images", chapter)
	destChapterPath = os.path.join(webBookPath, "chapters", chapter+".html")
	destImagesPath = os.path.join(destDirectoryPath, "images")

	internalImagesPath = os.path.join("..", "images", chapter)

	# ----------- run pandoc

	print("Converting", sourceChapterPath, "to", destChapterPath, "...")


	subprocess.call(["pandoc", "-o", destChapterPath, sourceChapterPath,
                                        "-s", "-p", "--mathjax",
                                        "--include-in-header=createWebBookTemplate/IncludeInHeader.html",
                                        "--include-before-body=createWebBookTemplate/IncludeBeforeBody.html",
                                        "--include-after-body=createWebBookTemplate/IncludeAfterBody.html",
                                        "--template=createWebBookTemplate/default.html",
                                        "--default-image-extension=svg"])



	# ----------- copy images over:

	print(destImagesPath)
	if os.path.exists(sourceImagesPath):
		copytree(sourceImagesPath, destImagesPath)


	chapterDict = {}
	chapterDict['path'] = chapter
	chapterDict['href'] = chapter + ".html"

	# ----------- now let's alter the HTML that's produced:

	if os.path.exists(destChapterPath):
		soup = Soup(open(destChapterPath, "rb").read(), "html.parser")

		# --- grab the title from h1

		h1s = soup.find_all("h1")
		if (len(h1s) > 0):
			chapterDict['title'] = h1s[0].getText()
		else:
			chapterDict['title'] = "needs h1"

		chapterDict['chapterListName'] = chapter
		chapterDict['sections'] = [];
		chapterDict['destChapterPath'] = destChapterPath

		# --- Grab all the h2 (we call them sections)
		h2s = soup.find_all("h2")
		for h2 in h2s:
			# Remove punctuations from the id of the sections (punctiations like . wont work with anchors)
			for c in string.punctuation:
				h2['id'] = h2['id'].replace(c,"")

			# Store the section [0] = title  and [1] = ID
			chapterDict['sections'].append([h2.getText(), h2['id']])

		chapterDicts.append(chapterDict);

		# --- Update the title
		soup.title.string = "ofBook - " + chapterDict['title']

		# --- change images (path and tag)

		# Find all the figures so that we can make a series of tweaks
		divFigures = soup.findAll("div",{"class":"figure"})

		if len(divFigures) != 0:

			for fig in divFigures:

				figCaption = fig.p
				# Turn the caption into span for CSS formatting

				#note the games chapter needs some caption work
				if figCaption is not None:
					figCaption.name = "div"

				# [zach] -- this is to make images that are not full width, have captions below the image

				div = Tag(soup, None, "div")

				div['style'] = "image" #"clear:both"

				div.append(clone(fig.img))

				fig.img.replace_with(div)
				# Images have been stored in ./CHAPTER_NAME/images/ relative
				# to the chapter html, but image references in the html are
				# to ./images/.  Modify the image tags:
				div.img["src"] = internalImagesPath + "/" + div.img["src"]
				# Turn the figure image into a hyperlink that points to the
				# full resolution version of the image
				imgHyperlink = soup.new_tag("a", href=fig.img["src"])
				fig.img.wrap(imgHyperlink)


				fig['class'] = "inner"
				divWhole = Tag(soup, None, "div")
				divWhole['class'] = "figure"
				divWhole.append(clone(fig));
				fig.replace_with(divWhole)

		# --- make html links work better
		# Make all hyperlinks in the chapter target a new window/tab

		hyperlinkTags = soup.find_all("a")
		for hyperlinkTag in hyperlinkTags:
			hyperlinkTag["target"]= "_blank"

		html = soup.encode();
		destChapterPathTemp = destChapterPath + ".temp"

		with open(destChapterPathTemp, "wb") as file:
			file.write(html)
		shutil.move(destChapterPathTemp, destChapterPath)



def returnChapterByCommonName( commonName ):
	for c in chapterDicts:
		if c['chapterListName'] == commonName:
			return c
	return None


#-----------------------------------------------------
# make sidebar for chapters
#-----------------------------------------------------

for idx, chapter in enumerate(chapterDicts):
	soup = Soup()

	soupFromFile = Soup(open(chapter['destChapterPath'], "rb").read(), "html.parser")

	# Create previous/next links in the footer
	nextChapterDiv = soupFromFile.find(id='next_chapter')
	prevChapterDiv = soupFromFile.find(id='prev_chapter')

	if (idx != 0):
		prevLink = Tag(soup, None, "a")
		prevLink['href'] = chapterDicts[idx-1]['href']
		prevLink.string = "< " + chapterDicts[idx-1]['title']
		prevChapterDiv.append(prevLink)


	if(idx != len(chapterDicts)-1):
		nextLink = Tag(soup, None, "a")
		nextLink['href'] = chapterDicts[idx+1]['href']
		nextLink.string = chapterDicts[idx+1]['title'] + " >"
		nextChapterDiv.append(nextLink)


	# Find the navbar UL
	navbar = soupFromFile.find_all("ul", {"id":"nav-parts"})[0]


	# Run through the chapter groups
	for group in chapterGroups:
		# Create a chapter group LI
		groupLi = Tag(soup, None, "li")
		groupLi['class']="group"
		groupTitle = Tag(soup, None, 'div')
		groupTitle['class'] = 'groupTitle'
		groupTitle.string = group['groupName']
		groupLi.append(groupTitle)
		navbar.append(groupLi)

		# Run through the chapters of the group
		for chap in group['chapters']:
			c = returnChapterByCommonName(chap)
			if (c != None):
				chapUl = Tag(soup, None, "ul")
				groupLi.append(chapUl)

				chapLi = Tag(soup, None, "li")
				chapLi['class'] = "chapter"

				if (c == chapter):
					chapLi['class'] = "chapter selected"
					groupLi['class']="group selected"

				a = Tag(soup, None, "a");
				a['href'] =  c['href']
				a.string = c['title']

				div = Tag(soup, None, "div");
				div['class'] = "chapterTitle";
				if (c == chapter):
					div['class'] = "chapterTitle selected";
				div.append(a);

				chapLi.append(div)
				chapUl.append(chapLi)

				if (len(c['sections'])):

					ulInner = Tag(soup, None, "ul")
					divTag = Tag(soup, None, "div")
					divTag['class'] = "chapterContents"
					if (c == chapter):
						divTag['class'] = "chapterContents selected"
					divTag.append(ulInner);
					chapLi.append(divTag);



					first = True
					for tag in c['sections']:
						liInner = Tag(soup, None, "li")
						liInner['class'] = 'section'
						if(first):
							liInner['class'] = 'section selected'

						ulInner.append(liInner)
						a = Tag(soup, None, "a")



						a['href'] = "#" + tag[1]
						a['target'] = "_top"
						a.string = tag[0]
						liInner.append(a);
						first = False;
			else:
				print(chap)




	#navULTag = soupFromFile.find_all("ul", {"id":"nav-parts"})
	#navULTag[0].append(ul);

	htmlFromFile = soupFromFile.encode()

	with open(chapter['destChapterPath'], "wb") as file:
		file.write(htmlFromFile)

	#print html


#----------------------------------------------------- make TOC content

soup = Soup()

wrapperDiv = Tag(soup, None, "div");
wrapperDiv['class'] = "toc-wrapper"


# Build the output like...
# div[toc-wrapper]
#   h3 Group name
#   ul
#     li Chapter name
#     li Chapter name

# Run through the chapter groups
for group in chapterGroups:


	tocSection = Tag(soup, None, "div");
	tocSection['class'] = "tocSection"


	h3 = Tag(soup, None, "h3")
	h3.append(group['groupName'])
	tocSection.append(h3)

	ul = Tag(soup, None, "ul");

	# Run through the chapters of the group
	for chap in group['chapters']:
		c = returnChapterByCommonName(chap)
		if (c != None):

			a = Tag(soup, None, "a");
			a['href'] =  c['href']
			a.string = c['title']

			li = Tag(soup, None, "li");
			li.append(a)
			ul.append(li)

		else:
			print(chap)

	tocSection.append(ul)
	wrapperDiv.append(tocSection);

soup.append(wrapperDiv)

#print(soup.prettify("utf-8"));

htmlOut = soup.prettify("utf-8")

tocPathTemp = os.path.join(webBookPath, "tocTemp.html")
tocPath = os.path.join(os.path.join(webBookPath, "chapters"), "toc.html")
print("toc path")
print(tocPath)
with open(tocPathTemp, "wb") as file:
    file.write(htmlOut)





filenames = ['createWebBookTemplate/IncludeBeforeBodyTOC.html', tocPathTemp, 'createWebBookTemplate/IncludeAfterBodyTOC.html']
with open(tocPath, 'w') as outfile:
    for fname in filenames:
        with open(fname) as infile:
            outfile.write(infile.read())

os.remove(tocPathTemp);
#----------------------------------------------------- run pandoc for TOC

# destTocPath = os.path.join(webBookPath, "chapters", "toc.html")
# sourceTocPath = os.path.join(webBookPath, "toc.html")

# print("Converting", sourceTocPath, "to", destTocPath, "...")

# # subprocess.call(["pandoc", "-o", destTocPath, sourceTocPath,
# #                                     "-s", "-p",
# #                                     "--include-in-header=createWebBookTemplate/IncludeInHeader.html",
# #                                     "--include-before-body=createWebBookTemplate/IncludeBeforeBodyTOC.html",
# #                                     "--include-after-body=createWebBookTemplate/IncludeAfterBodyTOC.html",
# #                                     "--template=createWebBookTemplate/default.html"])

# print("Removing", sourceTocPath, "...")
# os.remove(sourceTocPath)

#----------------------------------------------------- copy index redirect to TOC

destPath = os.path.join(webBookPath, "index.html")
sourcePath = os.path.join("createWebBookTemplate", "index.html")

# print("Copying", sourcePath, "to", destPath, "...")
# shutil.copyfile(sourcePath, destPath)

bookBaseUrl = "http://openframeworks.cc/ofBook/chapters/";

for group in chapterGroups:
    print("- " + group['groupName']);
    for chap in group['chapters']:
        c = returnChapterByCommonName(chap)
        print("\t- [" +c['title'] +"](" + bookBaseUrl + c['href'] + ")");
        
        #print(c['href'])
#print()

