#!/usr/bin/env bash

# Shell script for creating the OF book!
# Usage: ./create_ofBook.sh html
#        ./create_ofBook.sh pdf
#        ./create_ofBook.sh tex
# List detected files:
#        ./create_ofBook.sh debug

# Generated files end up in the imgdump folder which gets recreated on each
# run. Sadly, Pandoc is fragile w.r.t multiple input files and relative
# paths in subdirectories

# Pandoc options here: http://johnmacfarlane.net/pandoc/README.html#synopsis

# general options:
GENERAL_OPTS="-N --smart --toc --toc-depth=4 -s -p"

# Latex-related options
# Note: PDF output requires Latex, too
# Note: requires xetex currently due to UTF8 problems with regular latex
LATEX_OPTS="--latex-engine=xelatex -V papersize=a4 -V documentclass=scrbook -V links-as-notes"

# html-related options
HTML_OPTS=""

# Find chapter files
FILES=$(find $(pwd) -type f -name "chapter.md" | sort | tr "\n" " ")

# work around an issue with pandoc not finding images specified with relative
# paths - just dump them in a directory

rm -rf imgdump
mkdir -p imgdump
IMAGES=$(find . -type f -name "*.png" -o -name "*.gif" -o -name "*.jpg" -o -name "*.svg")

for image in $IMAGES; do
    target="imgdump/${image#./*/}"
    mkdir -p $(dirname $target)
    cp "$image" "$target"
done

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


cd imgdump
pandoc $FILES $OPTS -o ofBook.$1
cd ..

exit 0



