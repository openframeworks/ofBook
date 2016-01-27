DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
sudo apt-get install python3 python3-pip python3-dev git pandoc ruby-sass texlive texlive-latex-extra texlive-xetex texlive-pictures
sudo pip install virtualenv
cd ${DIR}/..
virtualenv pythonenv -p $(which python3)
source pythonenv/bin/activate
pip install beautifulsoup4
pip install libsass
deactivate
