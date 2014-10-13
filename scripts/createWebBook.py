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


import os
import subprocess
import shutil
from bs4 import BeautifulSoup as Soup
from bs4 import Tag, NavigableString

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

def wrap(to_wrap, wrap_in):
    contents = to_wrap.replace_with(wrap_in)
    wrap_in.append(contents)

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



# Create the output directories for the webBook
webBookPath = os.path.join("..", "output", "webBook")
webBookChaptersPath = os.path.join(webBookPath, "chapters")
if not os.path.exists(webBookPath): os.makedirs(webBookPath)
if not os.path.exists(webBookChaptersPath): os.makedirs(webBookChaptersPath)

# Copy static directories
staticStylePath = os.path.join("..", "static", "style")
webBookStylePath = os.path.join(webBookPath, "style")
staticJSPath = os.path.join("..", "static", "javascript")
webBookJSPath = os.path.join(webBookPath, "javascript")
staticFAPath = os.path.join("..", "static", "octicons")
webBookFAPath = os.path.join(webBookPath, "octicons")
copytree(staticStylePath, webBookStylePath)
copytree(staticJSPath, webBookJSPath)
copytree(staticFAPath, webBookFAPath)


chapterTags = [];

for chapter in chapters:
	sourceDirectoryPath = os.path.join("..", "chapters", chapter)
	sourceChapterPath = os.path.join(sourceDirectoryPath, "chapter.md")
	sourceImagesPath = os.path.join(sourceDirectoryPath, "images")

	destDirectoryPath = os.path.join(webBookPath, "images", chapter)
	destChapterPath = os.path.join(webBookPath, "chapters", chapter+".html")
	destImagesPath = os.path.join(destDirectoryPath, "images")

	internalImagesPath = os.path.join("..", "images", chapter)

	# I've remove the TOC from pandoc, will do it below...

	print "Converting", sourceChapterPath, "to", destChapterPath, "..."
	subprocess.call(["pandoc", "-o", destChapterPath, sourceChapterPath,
					"-s", "-p", "--mathjax",	
					"--include-in-header=createWebBookTemplate/IncludeInHeader.html",
					"--include-before-body=createWebBookTemplate/IncludeBeforeBody.html",
					"--include-after-body=createWebBookTemplate/IncludeAfterBody.html"])

	print destImagesPath

	if os.path.exists(sourceImagesPath):
		copytree(sourceImagesPath, destImagesPath)
	

	chapterDict = {}
	chapterDict['path'] = chapter


	#now, let's parse the index.html and change some things: 
	if os.path.exists(destChapterPath):
		soup = Soup(open(destChapterPath).read())

		
		h1s = soup.find_all("h1")
		if (len(h1s) > 0):
			chapterDict['title'] = h1s[0].getText()
		else: 
			chapterDict['title'] = "needs h1"
		h2s = soup.find_all("h2")

		chapterDict['chapterListName'] = chapter
		chapterDict['innerTags'] = [];
		chapterDict['destChapterPath'] = destChapterPath
		for h2 in h2s: 
			#print h1
			a = Tag(Soup, None, "a");
			sectionName = h2.getText();
			a['name'] = sectionName
			#wrap(h2, a)
			chapterDict['innerTags'].append(h2.getText())

		chapterTags.append(chapterDict);

		# Find all the figures so that we can make a series of tweaks
		divFigures = soup.find_all("div", class_="figure")
		if len(divFigures) != 0:
			
			for fig in divFigures:
				
				figCaption = fig.p
				# Turn the caption into span for CSS formatting

				#note the games chapter needs some caption work
				if figCaption is not None: 
					figCaption.name = "span"

				# [zach] -- this is to make images that are not full width, have captions below the image
				
				div = Tag(soup, None, "div")
				div['style'] = "clear:both"
				div.append(clone(fig.img));
				
				fig.img.replace_with(div)
				# Images have been stored in ./CHAPTER_NAME/images/ relative 
				# to the chapter html, but image references in the html are 
				# to ./images/.  Modify the image tags:
				div.img["src"] = internalImagesPath + "/" + div.img["src"]

				# Turn the figure image into a hyperlink that points to the
				# full resolution version of the image
				imgHyperlink = soup.new_tag("a", href=fig.img["src"])
				fig.img.wrap(imgHyperlink)

		
		# Make all hyperlinks in the chapter target a new window/tab
		hyperlinkTags = soup.find_all("a")
		for hyperlinkTag in hyperlinkTags:
			hyperlinkTag["target"]= "_blank"

		html = str(soup)
		with open(destChapterPath, "wb") as file:
			file.write(html)

	#h1s will be super helpful for sidebar and building up a map of content :)
	

soup = Soup()
html = Tag(soup, None, "html")
a = Tag(soup, None, "a")
soup.append(html)
# html.append(table)
# table.append(tr)
# for attr in mem_attr:
#     th = Tag(soup, None, "th")
#     tr.append(th)
#     th.append(attr)
# print soup.prettify()


# now, we have a full list of chapters, let's add this to HTML of each page: 


# for cg in chapterGroups:
# 	print cg['name']
# 	for c in cg['chapters']:
# 		print c


def returnChapterByCommonName( commonName ):
	for c in chapterTags: 
		if c['chapterListName'] == commonName: 
			return c
	return None



for chapter in chapterTags: 
	soup = Soup()

	a = Tag(soup, None, "a")
	soup.append(html)
	ul = Tag(soup, None, "ul")

	for cg in chapterGroups:

		li = Tag(soup, None, "li")
		li['class']="group"
		li.append( cg['groupName'])
		ul.append(li)

		for chap in cg['chapters']:

			

			c = returnChapterByCommonName(chap)
			if (c != None):
				li = Tag(soup, None, "li")
				if (c == chapter):
					 li['class'] = "selected"
				a = Tag(soup, None, "a");
				a['href'] =  c['path'] + ".html"
				a.string = c['title']
				li.append(a)
				ul.append(li)
			else:
				print chap
		
	
	soupFromFile = Soup(open(chapter['destChapterPath']).read())
	chaptersTag = soupFromFile.find_all("div", {"id":"chapters"})
	chaptersTag[0].append(ul);
	
	htmlFromFile = str(soupFromFile)
	
	with open(chapter['destChapterPath'], "wb") as file:
		file.write(htmlFromFile)

	#print html



soup = Soup()
html = Tag(soup, None, "html")
a = Tag(soup, None, "a")
soup.append(html)

for c in chapterTags: 
	ul = Tag(soup, None, "ul")
	li = Tag(soup, None, "li")
	a = Tag(soup, None, "a");
	a['href'] = "chapters/" + c['path'] + ".html"
	a.string = c['title']
	li.append(a)
	ul.append(li)

	#print c['title']
	#print c['path']
	if (len(['innerTags'])):
		ulInner = Tag(soup, None, "ul")
		li.append(ulInner);
		for tag in c['innerTags']: 
			liInner = Tag(soup, None, "li")
			ulInner.append(liInner)
			a = Tag(soup, None, "a")
			tagNoSpaces = tag.replace(" ", "")
			a['href'] = "chapters/" + c['path'] + ".html#" + tagNoSpaces
			a['target'] = "_top"
			a.string = tag
			liInner.append(a);
		#print "\t" + tag

	html.append(ul);

htmlOut = soup.prettify("utf-8")
tocPath = os.path.join(webBookPath, "toc.html")
with open(tocPath, "wb") as file:
    file.write(htmlOut)




# <ul>
#   <li>Coffee</li>
#   <li>Tea
#     <ul>
#     <li>Black tea</li>
#     <li>Green tea</li>
#     </ul>
#   </li>
#   <li>Milk</li>
# </ul>



