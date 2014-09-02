ofBook
======

this is a collaboratively written openFrameworks book.  

**please note that this is still work-in-progress**


# Building the Book

Dependencies

- [pandoc](http://johnmacfarlane.net/pandoc/)
- [python 2.7+](https://www.python.org/)
- [beauitful soup 4](http://www.crummy.com/software/BeautifulSoup/) 
- LaTeX 
  - Windows: [MiKTeX](http://miktex.org/) is recommended 

Scripts for building the web and pdf versions of the book are in `scripts/` directory, `createWebBook.py` and `createPDFBook.pdf` respectively.  Neither script take command line arguments, so you can run them either by double-clicking on the script or by running it from command line.
- When building the web book, the website is stored in the `output/` directory.  Opening up `/output/toc.html` will open up the table of contents.
- When building the pdf book, the pdf is created is at the root directory: `/ofBook.pdf`.

## Windows Installation of Dependencies
1. Download and install [Python 2.7+](https://www.python.org/)
2. Download and install [beauitful soup 4](http://www.crummy.com/software/BeautifulSoup/) (bs4)
  - Method 1: 
    1. Get the python package manager, [pip](https://pip.pypa.io/en/latest/installing.html).  This involves downloading `get-pip.py` and running it from command line.
    2. Run `pip install beautifulsoup4` from the command line to install BeautifulSoup
  - Alternate [installation methods](http://www.crummy.com/software/BeautifulSoup/bs4/doc/#installing-beautiful-soup) for bs4
3. Download and install pandoc using the latest windows installer (.msi) from [here](https://github.com/jgm/pandoc/releases)
4. Download and install MiKTeX installer from [here](http://miktex.org/download)



#Mailing List

[openFrameworks Book discussion](http://dev.openframeworks.cc/listinfo.cgi/ofbook-openframeworks.cc).

Older Book discussions can be checked at [Ofbook Archives](http://dev.openframeworks.cc/private.cgi/ofbook-openframeworks.cc/)
