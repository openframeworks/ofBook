DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd ${DIR}/..
source pythonenv/bin/activate
cd scripts
python createWebBook.py
# don't create the PDF by now it fails when compiling gifs
#python createPDFBook.py
deactivate

