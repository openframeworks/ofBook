ofBook
======

This is a collaboratively written openFrameworks book.  

Read the latest version [here](http://openframeworks.cc/ofBook/chapters/foreword.html)!

For other language, please read below.
- Korean(한국어) : [README.ko.md](README.ko.md)

**please note that this is still work-in-progress**

---

# Building the Book

Dependencies

- [LaTeX](http://www.latex-project.org/)
- [pandoc](http://johnmacfarlane.net/pandoc/)
- [python 2.7+](https://www.python.org/)
- [beautiful soup 4](https://www.crummy.com/software/BeautifulSoup/)
- [sass](http://sass-lang.com/)
- [libsass](https://github.com/dahlia/libsass-python)

Scripts for building the web and pdf versions of the book are in `scripts/` directory: `createWebBook.py` and `createPDFBook.py`.  You must run them from the `scripts/` directory, so either double-click the script or run it from command line.
- When building the web book, the website is stored in the `output/webBook` directory.  Opening up `output/webBook/index.html` will open up the table of contents.
- When building the pdf book, the pdf is created at `output/ofBook.pdf`. `output/ofBook.tex` is also created, for debugging purposes.

---

## OS X
1. install pip at the terminal ```sudo easy_install pip```
2. install python dependencies with `pip install -r requirements.txt`
3. install [pandoc](https://github.com/jgm/pandoc/releases)
4. install [basictex & MacTeX-Additions](http://www.tug.org/mactex/morepackages.html)
5. install [libsass](https://github.com/dahlia/libsass-python) `sudo pip install libsass`

---

## Windows Installation of Dependencies
1. Download and install [Python 2.7+](https://www.python.org/)
2. Get the necessary python libraries using the python package manager ([pip](https://pip.pypa.io/en/latest/installing.html)).
  - Python 2.7.9 and later (on the python2 series), and Python 3.4 and later include pip by default, so you may have pip already.  It is typically stored in `C:/PythonXX/Scripts`.  To access it from command line, you will need to add the location of your `Scripts` folder to your path variable (see this [guide](http://windowsitpro.com/systems-management/how-can-i-add-new-folder-my-system-path)).
  - Run `pip install -r requirements.txt` from the command line (inside of the ofBook/ directory) to install the dependencies.
3. Download and install pandoc using the latest windows installer (.msi) from [here](https://github.com/jgm/pandoc/releases)
4. Download and install MiKTeX using the windows installer from [here](http://miktex.org/download)
  - When installing, check the box for "Install Packages on the Fly."  The pandoc -> PDF pipeline uses latex packages that don't all come standard with MiKTeX, so this will allow you to grab any missing packages when building the book for the first time.

---

## Debian (Linux)
1. install packages: ```sudo apt-get install python-pip python2.7-dev git pandoc ruby-sass texlive```
2. install python dependencies with `pip install -r requirements.txt`

## Gulp
In addition to the python routines to build the book, there is also an optional gulp file for use in style development.  It requires [gulp](http://gulpjs.com/), [browser-sync](https://browsersync.io/) and [gulp sass](https://github.com/dlmanning/gulp-sass) and can be used primarily to see changes to CSS reflect live on the static pages.  You have to run the python createWebBook script first.

---

# Contribution Workflow
Since [git](http://git-scm.com/) is at the heart of the management of this endeavour, please check the [git best practices](https://sethrobertson.github.io/GitBestPractices/). If you do not agree with all of them, please at least stick to the "Do commit early and often" paradigm. This will make doing reviews, picking the good stuff from your contributions and polishing the rest a lot easier. Github itself also offers [a lot of help](https://help.github.com/) on common issues. So sign up, [fork the repo](https://help.github.com/articles/fork-a-repo/) and [send your pull requests](https://help.github.com/articles/creating-a-pull-request/) along our way.

---

# Mailing List

[openFrameworks Book discussion](http://dev.openframeworks.cc/listinfo.cgi/ofbook-openframeworks.cc).

Older Book discussions can be checked at [ofBook Archives](http://dev.openframeworks.cc/private.cgi/ofbook-openframeworks.cc/)

---

# gulp

In addition to the python routines to build the book, there is also an optional gulp file for use in style development.  It requires [gulp](http://gulpjs.com/), [browser-sync](https://browsersync.io/) and [gulp sass](https://github.com/dlmanning/gulp-sass) and can be used primarily to see changes to CSS reflect live on the static pages.  You have to run the python createWebBook script first.
