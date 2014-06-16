import os
import subprocess
import shutil

#todo: all the path stuff here is linux / osx friendly.  deal with windows....

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


def prepender(filename, content):
    with open(filename,'r+') as f:
        prevContent = f.read()
        f.seek(0,0)
        for line in content: 
        	f.write(line)
        for line in prevContent:
        	f.write(line)
        f.close();

def appender(filename, content):
	with open('log.txt','a') as f:
		for line in content:
			f.write(line)
		f.close();


chapters = open("../chapters/order.txt").read().splitlines()

for chapter in chapters:
	path = "../output/chapters/" + chapter;
	print path
	if not os.path.exists(path):
		os.makedirs(path)
	source = "../chapters/" + chapter + "/chapter.md";
	dest = path + "/index.html"
	subprocess.call(["pandoc", "-o", dest, source])

	if os.path.exists(dest):
		with open ("createWebBookTemplate/header.html", "r") as myfile:
			data=myfile.readlines()
			prepender(dest, data)
    	with open ("createWebBookTemplate/footer.html", "r") as myfile:
			data=myfile.readlines()
			appender(dest, data)

	imagesSource = source = "../chapters/" + chapter + "/images";
	imagesDest = path + "/images"
	if os.path.exists(imagesSource):
		copytree(imagesSource, imagesDest)
	
	#sanity check
	#command = "pandoc -o " + dest + " " + source
	#print command



