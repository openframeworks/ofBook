ofBook
======

이 저장소는 협업으로 작성되는 오픈프레임웍스 책입니다.

다른 언어는 아래에서 보실 수 있습니다.
- English(영어) : [README.md](README.md)

**이 저장소는 현재 작업 진행중임을 명심하십시오**
**현재는 ofBook은 영어로만 보여지고 있습니다. [이곳](http://openframeworks.cc/ofBook/)에서 확인할 수 있습니다. 한국어 및 일본어 번역이 진행중에 있습니다.**

# 책 빌드하기

의존성 패키지

- [LaTeX](http://www.latex-project.org/)
- [pandoc](http://johnmacfarlane.net/pandoc/)
- [python 2.7+](https://www.python.org/)
- [beauitful soup 4](http://www.crummy.com/software/BeautifulSoup/)
- [sass](http://sass-lang.com/)
- [libsass](https://github.com/dahlia/libsass-python)

책의 web과 pdf 버전을 빌드하기위한 스크립트는 `scripts/` 디렉토리에 있습니다: `createWebBook.py`와 `ceatePDFBook.py`입니다. 반드시 `scripts/`디렉토리에서 실행되어야 하며, 더블클릭하거나 커맨드라인에서 실행하면 됩니다.

- web버전의 책을 빌드하면, 결과물인 웹사이트는 `output/webBook`디렉토리에 저장됩니다. `output/webBook/index.html`을 열면 목차가 열립니다.
- pdf버전의 책을 빌드하면, pdf파일은 `output/ofBook.pdf`로 생성됩니다. 디버깅을 위한 `output/ofBook.tex`파일 역시 생성됩니다.

## OS X
1. 터미널에서 pip를 설치합니다 : ```sudo easy_install pip```
2. [beauitful soup 4](http://www.crummy.com/software/BeautifulSoup/) (bs4) 설치합니다: `pip install beautifulsoup4`
3. [pandoc](https://github.com/jgm/pandoc/releases) 설치합니다.
4. [basictex & MacTeX-Additions](http://www.tug.org/mactex/morepackages.html) 설치합니다.
5. [libsass](https://github.com/dahlia/libsass-python) 설치합니다 : `sudo pip install libsass`

## 윈도우 운영체제에서 의존성 패키지 설치
1. [Python 2.7+](https://www.python.org/)를 다운받아 설치
2. 파이썬 패키지 매니저인 ([pip](https://pip.pypa.io/en/latest/installing.html))를 사용하여 필요한 파이선 라이브러리를 설치합니다.
  - Python 2.7.9 이상 (python2 시리즈에서), 그리고 Python 3.4 이상에는 pip가 기본으로 포함되어 있으므로, 아마도 이미 pip가 설치되어 있을겁니다. 일반적으로 `C:/PythonXX/Scripts`에 위치합니다. 커맨드라인에서 접근하려면, `Scripts`폴더의 위치를 PATH 환경변수에 추가해주어야 합니다.(이 [가이드](http://windowsitpro.com/systems-management/how-can-i-add-new-folder-my-system-path)를 읽어보시길 바랍니다.).
  - [beauitful soup 4](http://www.crummy.com/software/BeautifulSoup/) (bs4)를 다운받아 설치합니다. 커맨드라인에서  `pip install beautifulsoup4`를 실행하여 BeautifulSoup을 설치합니다.
  - [libsass](https://github.com/dahlia/libsass-python)를 다운받아 설치합니다 : `pip install libsass`
3. [이곳](https://github.com/jgm/pandoc/releases)에서 최신의 인스톨러를 다운받아 pandoc을 설치합니다.
4. [이곳](http://miktex.org/download)에서 인스톨러를 다운받아 MiKTex를 설치합니다.
  - 설치할 때, "Install Packages on the Fly." 선택박스를 체크해줍니다. pandoc -> PDF 파이프라인은 latex 패키지를 사용하지만, 이는 MiKTeX의 기본설치과정에서 설치되지 않기 때문입니다. 이 옵션을 사용하면 책을 처음 한번 빌드할 때에 빠진 패키지들을 설치해줍니다.

## 데비안 (리눅스)
1. 패키지를 설치해줍니다 : ```sudo apt-get install python-pip python2.7-dev git pandoc ruby-sass texlive```
2. [beauitful soup 4](http://www.crummy.com/software/BeautifulSoup/)와 [libsass](https://github.com/dahlia/libsass-python)를 설치합니다 : ```pip install beauitfulsoup4 libsass```

## Gulp
In addition to the python routines to build the book, there is also an optional gulp file for use in style development.  It requires gulp, browser-sync and gulp sass and can be used primarily to see changes to CSS reflect live on the static pages.  You have to run the python createWebBook script first.


# 제작 참여하는 방법
[git](http://git-scm.com/)이야 말로 이 프로젝트 관리의 핵심이므로, [git best practices](https://sethrobertson.github.io/GitBestPractices/)를 읽어주시기 바랍니다. 저 가이드 전부에 대해 동의할 수 없다면, 적어도 "미리 그리고 자주 커밋하세요" 패러다임을 따라주시기 바랍니다. 이렇게 하면 다른 공헌자들이 훨씬 쉽게 리뷰할 수 있습니다. Github 자체에서도 일반적인 이슈에 대해서 [방대한 도움말](https://help.github.com/)을 제공합니다. 따라서 가입하신 뒤, 저희의 방법에 따라 [저장소를 fork](https://help.github.com/articles/fork-a-repo/)하신 뒤, [pull requests를 작성](https://help.github.com/articles/creating-a-pull-request/)해주시기 바랍니다.

# 메일링 리스트

[오픈프레임웍스 책에 관한 토론](http://dev.openframeworks.cc/listinfo.cgi/ofbook-openframeworks.cc).

이전에 있었던 책에 관한 토론은 [ofBook Archives](http://dev.openframeworks.cc/private.cgi/ofbook-openframeworks.cc/)에서 확인할 수 있습니다.