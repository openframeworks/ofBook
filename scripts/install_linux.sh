DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
sudo apt-get install python-pip python2.7-dev git pandoc ruby-sass texlive texlive-latex-extra texlive-xetex texlive-pictures
sudo pip install virtualenv
cd ${DIR}/..
virtualenv pythonenv -p /usr/bin/python2.7
source pythonenv/bin/activate
pip install beautifulsoup4
pip install libsass
deactivate
