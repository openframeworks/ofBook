#!/usr/bin/env bash

# Shell script for creating the OF book!
# Usage: ./create_ofBook.sh html
#        ./create_ofBook.sh pdf
#        ./create_ofBook.sh tex
# List detected files:
#        ./create_ofBook.sh debug

# Pandoc options here: http://johnmacfarlane.net/pandoc/README.html#synopsis

# general options:
GENERAL_OPTS="-N --smart --toc --toc-depth=4 -s -p"

# Latex-related options
# Note: PDF output requires Latex, too
# Note: requires xetex currently due to UTF8 problems with regular latex
LATEX_OPTS="--latex-engine=xelatex -V papersize=a4 -V documentclass=scrbook -V links-as-notes"

# html-related options
HTML_OPTS="--self-contained"

# Find chapter files
FILES=$(find . -type f -name "chapter.md" | sort | tr "\n" " ")




# option string construction
if [ $1 = "html" ] ; then
    OPTS="$GENERAL_OPTS $HTML_OPTS"
elif [ $1 = "tex" ] ; then
    OPTS="$GENERAL_OPTS $LATEX_OPTS"
elif [ $1 = "pdf" ] ; then
    OPTS="$GENERAL_OPTS $LATEX_OPTS"
elif [ $1 = "debug" ] ; then
    echo "List of discovered files:"
    echo $FILES
    exit 0
else
    echo "Invalid argument $1!"
    exit 1
fi

# echo $OPTS



pandoc $FILES $OPTS -o ofBook.$1




