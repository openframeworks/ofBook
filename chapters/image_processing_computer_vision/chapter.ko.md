****# 이미지 처리와 컴퓨터 비전

[Golan Levin](http://www.flong.com/) 작성<br />
[Brannon Dorsey](http://brannondorsey.com) 편집

This chapter introduces some basic techniques for manipulating and analyzing images in openFrameworks. As it would be impossible to treat this field comprehensively, we limit ourselves to a discussion of how images relate to computer memory, and work through an example of background subtraction, a popular operation for detecting people in video. This chapter is not a comprehensive guide to computer vision; for that, we refer you to excellent resources such as Richard Szeliski's [*Computer Vision: Algorithms and Applications*](http://szeliski.org/Book/) or Gary Bradski's [*Learning OpenCV*](http://cs.haifa.ac.il/~dkeren/ip/OReilly-LearningOpenCV.pdf).

이 챕터에서는 오픈프레임웍스에서의 이미지 조작과 분석을 위한 몇가지 기본적인 테크닉을 소개합니다. 이 분야를 포괄적으로 다루는것은 불가능하므로, 여기서 다루는 주제들은 비디오에서 사람을 인식하기 위한 대표적인 방법인 배경제거의 예제를 통해 이미지가 어떻게 컴퓨터 메모리와 연관이 있는지로 한정합니다. 이 챕터는 컴퓨터 비전을 다루는 가이드는 아닙니다만, 혹시 더 상세한 정보를 원하신다면 Richard Szeliski의 [*Computer Vision: Algorithms and Applications*](http://szeliski.org/Book/)와 Gary Bradski의 [*Learning OpenCV*](http://cs.haifa.ac.il/~dkeren/ip/OReilly-LearningOpenCV.pdf)를 읽어보시길 추천해 드립니다.

우리는 "완전히 비닥부터 새롭게" 이 주제를 다룰것이라 배울것이 아주 많습니다, 따라서 시작하기전에 여러분이 하고싶은 무언가와 정확히 동일한 도구인지 아닌지 체크할 필요도 있습니다. 첫 챕터에서는, 영상처리 작업흐름을 잘 캡슐화해두어 인터랙티브 아트와 디자인분야에서 무료로 사용가능한 몇몇 도구들을 살펴보는걸로 시작해보고자 합니다.


## 어쩌면 이미 마법의 총알이 있을지도 모릅니다.

컴퓨터 비전은 여러분으로 하여금 이미지, 비디오, 카메라 피드에서 어떤일이 일어나는지에 관해서 단언할수 있게 합니다. 여러분만의 영상처리 소프트웨어를 만들기에 재밌습니다(그리고 상당히 교육적이기도 합니다)만, 그렇다고 해서 항상 *반드시* 이러한 테크닉들을 직접 구현할 필요는 없습니다. 대부분의 많은 컴퓨터 비전 작업흐름들은 어플리케이션에 잘 캡슐화되어있어서, 여러분이 원하는 작업들을 알아서 해주고, OSC를 통해 오픈프레임웍스 앱으로 그 결과를 전송받을수도 있거든요! 이 챕터에 들어가기 전, 아래에 언급하는 영상처리 도구들을 사용하여 프로토타입 프로그램을 만들수 있을지를 고려해보세요.

![TSPS (left) and Community Core Vision (right)](images/tsps_ccv.png)

*TSPS(좌측) 과 Community Core Vision(우측)은 고급기능을 제공하는, 인터랙티브 인스톨레이션 분야에서 흔하게 쓰이는 컴퓨터 비전 도구입니다. 이 프로그램들은 그 분석결과를 OSC(미디어 아트분야에서 널리 사용되는 신호전송 프로토콜)로 전송합니다.

- [Toolkit for Sensing People in Spaces (TSPS)](http://opentsps.com/): A powerful toolkit for tracking bodies in video.
- [Community Core Vision](http://ccv.nuigroup.com/): Another full-featured toolkit for a wide range of tracking tasks.
- [FaceOSC](https://github.com/kylemcdonald/ofxFaceTracker/releases/): An app which tracks faces (and face parts, like eyes and noses) in video, and transmits this data over OSC.
- [Reactivision TUIO](http://reactivision.sourceforge.net/): A system which uses fiducial markers to track the positions and orientations of objects, and transmits this data over OSC.
- [EyeOSC](https://github.com/downloads/kylemcdonald/AppropriatingNewTechnologies/EyeOSC.zip) (.zip): An experimental, webcam-based eyetracker that transmits the viewer's fixation point over OSC.
- [Synapse for Kinect](http://synapsekinect.tumblr.com/post/6610177302/synapse): A Kinect-based skeleton tracker with OSC.
- [DesignIO kinectArmTracker](https://github.com/ofTheo/kinectArmTracker): A lightweight OSC app for tracking arm movements with the Kinect.
- [OCR-OSC](http://www.davidlubl.in/projects/#/ocr-osc/) A lightweight kit for performing optical character recognition (OCR) on video streams. 


This book's [chapter on Game Design](https://github.com/openframeworks/ofBook/blob/master/chapters/game_design/chapter.md) 서적에서는 이러한 도구들에 의해 만들어지는 OSC 메시지를 사용해 오픈프레임웍스 어플리케이션을 만드는 방법을 제공합니다. 당연하게도, 이러한 도구들이 여러분이 원하는 도구가 아니라면, 아래의 내용에 대해서 살펴봐야 할 것입니다...


## 이미지처리를 얘기하기 전에 알아두어야 할것들 

### 디지털 이미지 포착, 및 데이터 구조

This chapter introduces techniques for manipulating (and extracting certain kinds of information from) *raster images*. Such images are sometimes also known as *bitmap images* or *pixmap images*, though we'll just use the generic term **image** to refer to any array (or *buffer*) of numbers that represent the color values of a rectangular grid of *pixels* ("picture elements"). In openFrameworks, such buffers come in a variety of flavors, and are used within (and managed by) a wide variety of convenient container objects, as we shall see.

이 챕터에서는 *래스터 이미지*를 다루는(그리고 래스터 이미지에서 특정 정보를 추출하는) 기법을 소개합니다. 비록 일반적인 용어로 **이미지**를 사용하지만, 이것은 종종 *비트맵 이미지* 혹은 *픽스맵 이미지*라고도 알려져 있는데, 각 사각 *픽셀* 그리드의 컬러값을 표현하는 숫자들의 배열(혹은 *버퍼*)입니다. 오픈프레임웍스에서, 버퍼는 앞으로 보게 되겠지만, 널리 사용되는 편리한 컨테이너 오브젝트입니다.

#### 이미지를 불러와 보여주기

이미지 처리의 시작은 당연히 *이미지*입니다. 편리하게도 오픈프레임웍스에서 이미지를 보여주는것은 아주 직관적입니다. 자 아주 조그만한, 낮은 해상도(12x16픽셀)인 링컨의 흑백 초상화로 시작해보죠:

![A small image of Lincoln](images/lincoln.png) 

아래의 이미지를 불러와 표시하는 아주 간단한 어플리케이션은, 예제의 *imageLoaderExample*와 아주 흡사합니다. 프로그램의 헤더파일인, *ofApp.h*에서, `ofImage`오브젝트의 인스턴스인 *myImage*를 선언합니다. 


```cpp
// Example 1: Load and display an image.
// This is ofApp.h

#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void draw();
		
		// Here in the header (.h) file, we declare an ofImage:
		ofImage myImage;
};

```
Below is our complete *ofApp.cpp* file. The Lincoln image is *loaded* from our hard drive (once) in the `setup()` function; then we *display* it (many times per second) in our `draw()` function. As you can see from the filepath provided to the `loadImage()` function, the program assumes that the image *lincoln.png* can be found in a directory called "data" alongside your executable: 

아래는 최종 *ofApp.cpp* 파일내용입니다. 링컨 이미지는 `setup()`함수에 의해 하드드라이브에서 (한번) *불러와집니다*. 그리고 나서 이것을 `draw()`함수에서 (1초에 여러번) *그려냅니다*. `loadImage()`함수의 파일경로에서 볼 수 있읏이, 이 프로그램은 실행파일과 같은 경로에 있는 "data" 디렉토리에서 *lincoln.png*를 취합니다:

```cpp
// Example 1: Load and display an image.
// This is ofApp.cpp

#include "ofApp.h"

void ofApp::setup(){
	// We load an image from our "data" folder into the ofImage:
	myImage.loadImage("lincoln.png");
	myImage.setImageType(OF_IMAGE_GRAYSCALE);
}

void ofApp::draw(){
	ofBackground(255);
	ofSetColor(255);

	// We fetch the ofImage's dimensions and display it 10x larger.  
	int imgWidth = myImage.width;
	int imgHeight = myImage.height;
	myImage.draw(10, 10, imgWidth * 10, imgHeight * 10);
}
```

위의 프로그램을 컴파일하고 실행하면 캔버스에 이 (쪼만한) 이미지를 10배 키워서, 좌측상단의 위치를 (10, 10)로 하여 그려냅니다.  이미지의 위치지정과 크기조절은 `myImage.draw()` 명령에 의해 수행됩니다. 이미지는 "흐리게" 보여지는데, 오픈프레임웍스는 확대된 이미지를 그려낼 때에 기본적으로 [linear interpolation](http://en.wikipedia.org/wiki/Linear_interpolation)를 사용하기 떄문입니다.

![The small Lincoln image, scaled up large in an openFrameworks app](images/lincoln-displayed.jpg)

If you're new to working with images in oF, it's worth pointing out that you should try to avoid loading images in the `draw()` or `update()` functions, if possible. Why? Well, reading data from disk is one of the slowest things you can ask a computer to do. In many circumstances, you can simply load all the images you'll need just once, when your program is first initialized, in `setup()`. By contrast, if you're repeatedly loading an image in your `draw()` loop — the same image, again and again, 60 times per second — you're hurting the performance of your app, and potentially even risking damage to your hard disk.  

만약 오픈프레임웍스에서 이미지를 처음 다루는 분들이라면, 가능한 한 `draw()`나 `update()`함수에서 이미지를 불러오면 안된다라는 사실을 알고 계셔야 합니다. 왜냐구요? 디스크에서 데이터를 불러오는것은 가장 느린 작업이기 떄문입니다. 대부분 필요한 모든 이미지는 프로그램이 초기화되는 `setup()`함수에서 단 한번만에 불러오면 됩니다. 이와 반대로, 만약 `draw()` 루프에서 같은 이미지를 1초에 60번 반복하여 불러오면, 어플리케이션의 성능이 떨어질 뿐만 아니라, 심지어 하드디스크의 손상을 가져올 수도 있습니다.

#### 이미지들은 어디서 오는거죠 ?

오픈프레임웍스에서, 래스터 이미지들은 다양한 소스에서 올 수 있습니다. 아래의 포맷들이 있죠 (하지만 이에 한정된다는 것은 아닙니다) :

- 하드디스크에서 `ofImage`로 불러져 압축해제되는 이미지 파일 (.JPEG, .PNG, .TIFF, 또는 .GIF 와 같이 일반적으로 사용되는 저장 포맷)
- 웹캠 또는 다른 비디오 카메라들에서 볼려진 실시간 이미지 스트림 (`ofVideoGrabber` 사용) 
- 디지털 비디오 파일에서 불려진 프레임의 시퀀스 (`ofVideoPlayer` 사용)
- `ofImage::grabScreen()을 사용하여 캡쳐된, 이미 화면에 출력된 것들을 취한 픽셀들의 버퍼
- `ofFBO`에서 얻은, 혹은 `ofPixels`나 `ofTexture`오브젝트에 저장된, 생성된 컴퓨터 그래픽 렌더링.
- a real-time video from a more specialized variety of camera, such as a 1394b Firewire camera (via `ofxLibdc`), a networked Ethernet camera (via `ofxIpCamera`), a Canon DSLR (using `ofxCanonEOS`), or with the help of a variety of other community-contributed addons like `ofxQTKitVideoGrabber`, `ofxRPiCameraVideoGrabber`, etc.
- perhaps more exotically, a *depth image*, in which pixel values represent *distances* instead of colors. Depth images can be captured from real-world scenes with special cameras (such as a Microsoft Kinect via the `ofxKinect` addon), or extracted from CGI scenes using (for example) `ofFBO::getDepthTexture()`.

![A Kinect depth image (left) and corresponding RGB image (right)](images/kinect_depth_image.png) 

*뎁스 이미지(좌측)과 이에 대응되는 RGB 컬러 이미지(우측) 마이크로소프트의 키넥트로 지속적으로 캡쳐된 이미지의 예제. 뎁스 이미지는 카메라에서부터의 거리가 픽셀의 밝기로 표현된다. (이 두 이미지들은, raw 상태로 표현되며, 아직 상호 "calibrate"되지 않았음 - 컬러와 뎁스의 각 이미지 픽셀들이 픽셀-대-픽셀에 대응되지 않는다는 의미)*

참고로, 오픈프레임웍스는 **인터넷에서 이미지를 바로** 쉽게 불러불러올수 있으며, 아래와 같이 파일명 인수에 URL을 넣어주면 됩니다.

```
myImage.loadImage("http://en.wikipedia.org/wiki/File:Example.jpg");
```

다만, 원격에-저장된 이미지를 물러올때는 *동기방식*으로 동작한다는 점을 명심하셔야 합니다, 다시말해 프로그램은 웹에서 모든 이미지를 다운받을 동안 "블락"(또는 멈춤) 상태가 된다는 것입니다. 유저 경험의 향상을 위해,`ofloadURLAsync()` 메소드를 사용하여 *비동기* 방식으로 이미지를 블러올 수도 있습니다. 이 내용은 오픈프레임웍스의 graphics 예제중 *imageLoaderWebExample*에서 보실수 있습니다. (또한 *threadedImageLoaderExample* 에서도 확인할 수 있습니다.) 예제에서는 API를 사용해 (예를들어 [Temboo](https://temboo.com/library/), [Instagram](http://instagram.com/developer/) or [Flickr](https://www.flickr.com/services/api/)또는 실시간 교통 트래픽 카메라들과 같은 온라인 자료들에서)*자동화된 방식으로* 이미지들을 불러올 수 있습니다/ 

#### 웹캠 이미지를 얻어와 화면에 그리기

실시간 웹캠 혹은 디지털 비디오파일에서 **비디오 스트림을 얻어오는** 절차는 `ofImage`를 불러오는것만큼이나 어렵지 않습니다. 가장 큰 차이점이라면 `ofVideoGrabber` 또는 `ofVideoPlayer`오브젝트에 포함된 이미지 데이터가 졔속해서 바뀐다는 점인데, 일반적으로 초당 30번(혹은 세팅 혹은 파일의 프레임률을 따름) 바뀝니다. 아래와 같이 `myVideoGrabber.draw()` 화면에 데이터를 그려내기 위해 매번 이 오브젝트에 요청을 하면, 새로 업데이트된 픽셀들이 포함된 데이터들을 얻을 수 있습니다.

아래의 프로그램(*videoGrabberExample*예제에서 찾을 수 있습니다)은 기본적인 절차를 보여줍니다. 아래의 예제에서는, 약간 재밌는 것들이 추가가 됐는데, 추가로 `ofVideoGrabber`의 픽셀이 담긴 데이터의 버퍼를 얻어온 뒤, 이것을 수학적으로 "반전" 시켜 ("네거티브 효과"를 만들기 위해), 그것을 `ofTexture`를 사용하여 화면에 그려냅니다.

The header file for our app declares an `ofVideoGrabber`, which we will use to acquire video data from our computer's default webcam. We also declare a buffer of unsigned chars to store the inverted video frame, and the `ofTexture` which we'll use to display it:

헤더파일에서 컴퓨터에 기본적으로 내장된 웹캠에서 비디오 데이터를 얻어오기 위해 `ofVideoGrabber`를 선언했습니다. 또한 반전된 비디오 프레임을 저장하기 위한 `unsigned chars`의 버퍼와, 화면에 이 프레임을 그리기 위해 사용할 `ofTexture`를 선언했습니다:

```cpp
// Example 2. An application to capture, display,
// and invert live video from a webcam.
// This is ofApp.h

#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
	
		void setup();
		void update();
		void draw();

		ofVideoGrabber myVideoGrabber;
		ofTexture myTexture;

		unsigned char* invertedVideoData;
		int camWidth;
		int camHeight;
};

```

`unsigned char*`의 선언이 낯설죠? 이부분을 알아차리고 이해하는것이 매우 중요합니다, 사실상 이미지 데이터를 저장하거나 교환하는 가장 범용적인 방법이기 때문입니다. `unsigned` 키워드는 이미지의 컬러값을 특별하게 부호없는 숫자(즉 양수)로 표현하겠다는 의미입니다. `char`는 픽셀의 각 컬러 요소들을 하나의 8비트 숫자(바이트. 즉 0 - 255)로 표현하겠다는 것인데, 이는 수년간 문자(캐릭터,*char*acters)를 저장하는데에 사용되었던 데이터형 이기도 합니다. 그리고 별표(`*`)는 이 변수로 이름지어진 데이터가 하나의 unsigned char를 담는것이 아니라, unsigned char의 *배열*을 담는다는 것입니다(더 정확히 설명하자면, unsigned char 배열로 이루어진 버퍼를 가리키는 *포인터* 입니다). 이러한 데이터형에 관한 보다 자세한 정보는  *C++의 메모리* 챕터를 읽어보시길 바랍니다.

아래의 두번째 예제는 완성된 웹캠에서 이미지를 얻어오는 코드의 .cpp 파일입니다. 예상한대로. `ofVideoGrabber`오브젝트는 이 예제에서 다루지 않은 더 많은 세팅과 메소드를 제공합니다. 가령 이미지 캡쳐장치의 리스트를 제공하고, 선택을 할수 있게 한다거나; 캡쳐받을 해상도와 프레임률을 세팅하거나; (하드웨어와 드라이버에 따라 다르겠지만) 카메라의 밝기와 명암등을 조절하는 등의 기능을 제공합니다.

예제에서 무거운 계산처리는 `update()`메소드로, 그래픽을 그려내는 부분은 `draw()`로 분리되었음을 눈여겨 보시기 바랍니다. 이는 추천되는 코드의 구조입니다.


```cpp
// Example 2. An application to capture, invert,
// and display live video from a webcam.
// This is ofApp.cpp

#include "ofApp.h"

void ofApp::setup(){

	// Set capture dimensions of 320x240, a common video size.
	camWidth = 320;
	camHeight = 240;

	// Open an ofVideoGrabber for the default camera
	myVideoGrabber.initGrabber (camWidth,camHeight);

	// Create resources to store and display another copy of the data
	invertedVideoData = new unsigned char [camWidth * camHeight * 3];
	myTexture.allocate (camWidth,camHeight, GL_RGB);
}

void ofApp::update(){

	// Ask the grabber to refresh its data.
	myVideoGrabber.update();

	// If the grabber indeed has fresh data,
	if(myVideoGrabber.isFrameNew()){

		// Obtain a pointer to the grabber's image data.
		unsigned char* pixelData = myVideoGrabber.getPixels();
		
		// Reckon the total number of bytes to examine. 
		// This is the image's width times its height,
		// times 3 -- because each pixel requires 3 bytes
		// to store its R, G, and B color components.  
		int nTotalBytes = camWidth * camHeight * 3;
		
		// For every byte of the RGB image data,
		for(int i=0; i<nTotalBytes; i++){

			// pixelData[i] is the i'th byte of the image;
			// subtract it from 255, to make a "photo negative"
			invertedVideoData[i] = 255 - pixelData[i];
		}

		// Now stash the inverted data in an ofTexture
		myTexture.loadData (invertedVideoData, camWidth,camHeight, GL_RGB);
	}
}

void ofApp::draw(){
	ofBackground(100,100,100);
	ofSetColor(255,255,255);

	// Draw the grabber, and next to it, the "negative" ofTexture.
	myVideoGrabber.draw(10,10);
	myTexture.draw(340, 10);
}
```

이 어플리케이션은 연속해서 카메라의 피드를 화면에 그려내면서, 동시에 실시간으로 "필터링된"(반전효과) 버전도 함께 그려냅니다. 아래의 이미지가 제 노트북의 웹캠을 사용한 결과입니다.

![웹캠에서 얻어온 비디오(좌측)와 반전된 버전(우측)](images/videograbber.png)

디스크에 저장된 퀵타임 무비 혹은 다른 디지털 비디오파일에서 프레임을 얻어오는 방법은 거의 동일합니다. 오픈프레임웍스에 내장된 *videoPlayerExample*예제의 구현이나 `ofVideoGrabber` 클래스의 [도큐멘트](http://openframeworks.cc/documentation/video/ofVideoGrabber.html)에서 자세한 사항을 살펴보시기 바랍니다.

인터랙티브 컴퓨터 비전 개발자들 사이에서 찾아볼수 있는 공통된 패턴은, 미리 저장된 "샘플" 비디오와 실시간 카메라에서 얻어온 비디오 사이에서 전환이 쉽다는 점입니다. 그리하여, 호텔방에서 처리 알고리즘을 테스트하고 다듬은 뒤, 설치 현장에서 "실제" 카메라 입력으로 전환할 수 있는 것이지요. 이러한 패턴의 "효과"를 보여주는 예제가 오픈프레임웍스의 애드온 예제 디렉토리에 있는 *opencvExample*인데, 이러한 "스위치" 기능이 `#define`[전처리기 지시자](http://www.cplusplus.com/doc/tutorial/preprocessor/)를 사용하여 내장되어 있습니다:

```cpp
    //...
	#ifdef _USE_LIVE_VIDEO
        myVideoGrabber.initGrabber(320,240);
	#else
        myVideoPlayer.loadMovie("pedestrians.mov");
        myVideoPlayer.play();
	#endif
	//...
```
Uncommenting the `//#define _USE_LIVE_VIDEO` line in the .h file of the *opencvExample* forces the compiler to attempt to use a webcam instead of the pre-stored sample video. 

*opencvExample* 예제의 .h파일 에서, `//#define _USE_LIVE_VIDEO` 부분을 주석해제하면, 컴파일러로 하여금 미리 저장된 샘플비디오 대신 웹캠을 사용하도록 해줍니다.

#### 메모리 내의 픽셀

이미지 처리와 컴퓨터 비전에 관해 공부하기 위해, 우리는 이미지를 불러오고 그려내는 것 이상의 것들이 더 필요합니다; *이것의 픽셀들이 숫자로 표현된 데이터에 접근, 조작, 분석* 하는 것입니다. 따라서 픽셀들이 어떻게 컴퓨터의 메모리에 저장되는지 살펴볼 필요가 있습니다. 아래는 에이브라함 링컨의 초상화가 저장된, 흑백이미지 버퍼를 간략하게 도식화한 것입니다. 각 픽셀의 밝기는-0(검정)에서 255(흰색)의 범위를 가지는 하나의 8-비트 숫자로 표현됩니다:

![Pixel data diagram. At left, our image of Lincoln; at center, the pixels labeled with numbers from 0-255, representing their brightness; and at right, these numbers by themselves.](images/lincoln_pixel_values.png)

In point of fact, pixel values are almost universally stored, at the hardware level, in a *one-dimensional array*. For example, the data from the image above is stored in a manner similar to this long list of unsigned chars:

실제로, 픽셀의 값은 하드웨어 레벨의 관점에서, *1차원 배열*로 거의 동일한 방법으로 저장됩니다. 예를들어, 위의 이미지에서 얻어지는 데이터는, 아래의 긴 unsigned char의 리스트와 비슷한 방법으로 저장됩니다:

```cpp
{157, 153, 174, 168, 150, 152, 129, 151, 172, 161, 155, 156,
 155, 182, 163,  74,  75,  62,  33,  17, 110, 210, 180, 154,
 180, 180,  50,  14,  34,   6,  10,  33,  48, 106, 159, 181,
 206, 109,   5, 124, 131, 111, 120, 204, 166,  15,  56, 180,
 194,  68, 137, 251, 237, 239, 239, 228, 227,  87,  71, 201,
 172, 105, 207, 233, 233, 214, 220, 239, 228,  98,  74, 206,
 188,  88, 179, 209, 185, 215, 211, 158, 139,  75,  20, 169,
 189,  97, 165,  84,  10, 168, 134,  11,  31,  62,  22, 148,
 199, 168, 191, 193, 158, 227, 178, 143, 182, 106,  36, 190,
 205, 174, 155, 252, 236, 231, 149, 178, 228,  43,  95, 234,
 190, 216, 116, 149, 236, 187,  86, 150,  79,  38, 218, 241,
 190, 224, 147, 108, 227, 210, 127, 102,  36, 101, 255, 224,
 190, 214, 173,  66, 103, 143,  96,  50,   2, 109, 249, 215,
 187, 196, 235,  75,   1,  81,  47,   0,   6, 217, 255, 211,
 183, 202, 237, 145,   0,   0,  12, 108, 200, 138, 243, 236,
 195, 206, 123, 207, 177, 121, 123, 200, 175,  13,  96, 218};
```

이러한 이미지 데이터를 저장법을 볼때 대충 예상하실 수 있으실지도 모르겠습니다. 데이터가 사실상 2차원 배열처럼 *보이기* 때문이지요. 아직 컴퓨터 메모리는 단순한 한방향으로만 증가하는 주소 공간의 리스트일 뿐이지만요.

자 여기서 이 데이터는 아직 이미지의 가로와 세로크기에 관한 디테일이 없다는 점에 주목하시기 바랍니다. 이 값들의 리스트가 흑백 이미지이면서 가로세로 크기가 12x16로 해석되어야 할까요? 8x24? 아니면 3x64? 아니면 컬러 이미지로 해석될수도 있지 않을까요? 흠 일종의 '메타-데이터'가 어딘가에 있을텐데요 - 일반적으로 `ofImage`와 같은 컨테이너 오브젝트가 바로 그렇습니다.

#### 그레이스케일 픽셀들과 배열 인덱스

컴퓨터 메모리에 픽셀데이터가 어떻게 저장되는지 이해하는것은 매우 중요합니다. 각 픽셀은 정수(0부터 시작합니다)로 이루어진 *주소*를 갖습니다.

![How pixels are stored in memory.](images/pixels_in_memory.png)

Observe how a one-dimensional list of values in memory can be arranged into successive rows of a two-dimensional grid of pixels, and vice versa.

자 어떻게 메모리 내의 1차원의 값 리스트가 픽셀의 2차원 그리드로, 혹은 그 반대로 변환되는지 살펴봅시다.

It frequently happens that you'll need to determine the array-index of a given pixel *(x,y)* in an image that is stored in an `unsigned char*` buffer. This little task comes up often enough that it's worth committing the following pattern to memory:

사실 `unsigned char*` 버퍼에 저장되어있는 이미지에서 *(x,y)* 좌표로 배열의 인덱스를 계산해야 하는 일은 자주 발생합니다. 메모리에서 아래의 패턴을 적용하면 됩니다:


```cpp
// Given:
// unsigned char *buffer, an array storing a one-channel image
// int x, the horizontal coordinate (column) of your query pixel
// int y, the vertical coordinate (row) of your query pixel
// int imgWidth, the width of your image

int arrayIndex = y*imgWidth + x;

// Now you can GET values at location (x,y), e.g.:
unsigned char pixelValueAtXY = buffer[arrayIndex];

// And you can also SET values at that location, e.g.:
buffer[arrayIndex] = pixelValueAtXY;
```
Likewise, you can also fetch the x and y locations of a pixel corresponding to a given array index:

```cpp
// Given:
// A one-channel (e.g. grayscale) image
// int arrayIndex, an index in that image's array of pixels
// int imgWidth, the width of the image

int y = arrayIndex / imgWidth; // NOTE, this is integer division!
int x = arrayIndex % imgWidth; // The friendly modulus operator.
```

<!-- #### Low-Level vs. High-Level Pixel Access Methods -->
#### 로우레벨 vs. 하이레벨 필셀 접근 메소드들

대부분, 여러분은 `ofImage`와 같은 고급-레벨 컨테이너 오브젝트내에 저장되어있는 이미지를 가지고 작업하게 될 것입니다. 하지만 "로우-레벨" 메소드를 사용할때는, `.getPixles()`를 사용하여 ungiend char 픽셀데이터가, 담긴 배열을 가리키는 포인터를 요청하여 얻어올 수 있습니다. 이 부분에서 위에 언급했던 패턴을 사용해 배열-인덱스를 계산하게 됩니다.(참고로, `ofVideoGrabber`와 같은 대부분의 다른 오픈프레임웍스 이미지 컨테이너 역시 `.getPixels()`와 같은 메소드를 제공합니다.)

```cpp
int arrayIndex = (y * imgWidth) + x;
unsigned char* myImagePixelBuffer = myImage.getPixels();
unsigned char pixelValueAtXY = myImagePixelBuffer[arrayIndex];
```

고급-레벨의 두번째 메소드는 주어진 픽셀 위치에 저장된 *color*값을 리턴해줍니다:

```cpp
ofColor colorAtXY = myImage.getColor(x, y);
float brightnessOfColorAtXY = colorAtXY.getBrightness();
```

#### 이미지에서 가장 밝은 픽셀 찾기

우리가 살펴본 방법들을 알면, 이미지에서 가장 밝은 픽셀의 위치를 찾아내는 간단한 프로그램을 작성할 수 있습니다. 이 간단한 컨셉은 콜렉티브 아티스트인, 그래피티 리서치랩(Graffiti Research Lab(GRL))이 오픈프레임웍스를 사용하여 2007년에 작업한 [*L.A.S.E.R Tag*](http://www.graffitiresearchlab.com/blog/projects/laser-tag/) 프로젝트에서 사용되었습니다. *L.A.S.E.R Tag*의 컨셉은 레이저포인터를 사용하여, 사람들로 하여금 거대한 빌딩의 벽면에 그래피티를 그릴수 있게 하는 것입니다. 아래의 코드와 비슷한 방식으로 레이저포인터가 가리키는 밝은 위치를 트래킹하는데, 이러한 방식이 창의적인 인터랙티브 프로젝션 그래픽에 사용되었습니다.

![L.A.S.E.R. Tag by the Graffiti Research Lab (GRL), 2007](images/laser_tag.jpg)

The .h file for our app loads an ofImage (`laserTagImage`) of someone pointing a laser at the building. (In the real application, a live camera was used.)

.h 파일에서는 빌딩에서 누군가가 레이저를 가리키고 있는 `laserTagImage` ofImage를 어플리케이션에 불러옵니다. (실제 어플리케이션에서는, 실시간 카메라가 사용됩니다.)

```cpp
// Example 3. Finding the Brightest Pixel in an Image
// This is ofApp.h

#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void draw();
		
		// Replace this ofImage with live video, eventually
		ofImage laserTagImage;
};
```

아래가 .cpp의 내용입니다:

```cpp
// Example 3. Finding the Brightest Pixel in an Image
// This is ofApp.cpp

#include "ofApp.h"

//---------------------
void ofApp::setup(){
	laserTagImage.loadImage("images/laser_tag.jpg");
}

//---------------------
void ofApp::draw(){
	ofBackground(255);

	int w = laserTagImage.getWidth();
	int h = laserTagImage.getHeight();

	float maxBrightness = 0; // these are used in the search
	int maxBrightnessX = 0; // for the brightest location
	int maxBrightnessY = 0;

	// Search through every pixel. If it is brighter than any
	// we've seen before, store its brightness and coordinates.
	// After testing every pixel, we'll know which is brightest!
	for(int y=0; y<h; y++) {
		for(int x=0; x<w; x++) {
			ofColor colorAtXY = laserTagImage.getColor(x, y);
			float brightnessOfColorAtXY = colorAtXY.getBrightness();
			if(brightnessOfColorAtXY > maxBrightness){
				maxBrightness = brightnessOfColorAtXY;
				maxBrightnessX = x;
				maxBrightnessY = y;
			}
		}
	}

	// Draw the image.
	ofSetColor (255);
	laserTagImage.draw(0,0);

	// Draw a circle at the brightest location.
	ofNoFill();
	ofDrawEllipse (maxBrightnessX, maxBrightnessY, 40,40);
}
```

우리의 이 작은 어플리케이션은 레이저가 가리키는 밝은 부분을 찾아내고 (다행히도 현장에서 가장 밝은 부분이었습니다), 그 주위에 원들을 그렸습니다. *L.A.S.E.R Tag*를 재현하기 위해, 이 위치들을 별도로 기록해두고, 그것을 프로젝션에 적합한, 컬러 잔상으로 그려내었습니다. 당연히, 이제부터는 어디가 가장 밝은(혹은 가장 어두운) 지점인지를 알수 있으므로, 태양 추적, 거북이 추적 등과 같은 다른 다양한 어플리케이션들을 개발할 수 있을것입니다...

![L.A.S.E.R. Tag by GRL, with the laser point highlighted](images/laser_tag_result.jpg)

이미지에서 가장 밝은 부분들을 찾아내는 방법은 다른 방식으로도 사용할 수 있을것입니다. 가령 예를 들어 (키넥트 센서에 의해 만들어진) *depth image*를 사용한다면, 가장 밝은 픽셀은 *foremost point*, 즉 센서에서 가장 가까운 부분을 의미하게 됩니다. 이는 사용자의 손을 트래킹하는 인터랙티브 설치작업을 만드는데 아주 유용합니다.

![The foremost point, or 'fore-point', in a Kinect depth image](images/kinect-forepoint.jpg)

*depth image에서 가장 밝은 부분은 센서에서 가장 가까운 부분입니다. 여기에서 보여지는 설정에서는, "가장 가까운 부분"은 사용자의 손입니다.*

Unsurprisingly, tracking *more than one* bright point requires more sophisticated forms of processing. If you're able to design and control the tracking environment, one simple yet effective way to track up to three objects is to search for the reddest, greenest and bluest pixels in the scene. Zachary Lieberman used a technique similar to this in his [*IQ Font*](https://vimeo.com/5233789) collaboration with typographers Pierre & Damien et al., in which letterforms were created by tracking the movements of a specially-marked sports car.

당연히 *하나 이상의* 밝은 부분을 트래킹하려면, 좀 더 복잡한 처리가 필요할 것입니다. 만약 여러분이 이러한 트래킹 환경을 디자인하고 제어하기 위해선, 씬에서 가장 빨간, 가장 녹색인, 가장 파란색인 세 오브젝트를 추적하는 효과적이면서도 간편한 방법이 있을것입니다. Zachary Lieberman은 이와 비슷한 방법을 사용하여, 타이포그래퍼인 Pierre & Damienet al과 함께 [*IQ Font*](https://vimeo.com/5233789)프로젝트를 진행했습니다. 이 프로젝트에서는, 특별한 마크가 달린 스포츠카의 우밎ㄱ임을 추적하여 글자를 만들어냅니다.

![The IQ Font overhead camera view](images/iq_font.jpg)

보다 더 일반적으로, 하나의 *구체적인* 컬러가 위치한 지점을 추적하는 시스템을 만들수도 있습니다. 이를 구현하는 가장 쉬운 방법은 ("RGB 공간" 에서) 타깃 컬러와 가장 짧은 유클리드 거리(Euclidean distance)를 갖는 컬러 픽셀을  찾는것입니다. 아래에서 보여지는 코드의 내용이 바로 그것입니다:

```cpp
// Code fragment for tracking a spot with a certain target color. 
// Our target color is CSS LightPink: #FFB6C1 or (255, 182, 193)
float rTarget = 255; 
float gTarget = 182;
float bTarget = 193; 

// these are used in the search for the location of the pixel 
// whose color is the closest to our target color.
float leastDistanceSoFar = 255; 
int xOfPixelWithClosestColor = 0; 
int yOfPixelWithClosestColor = 0;

for (int y=0; y<h; y++) {
	for (int x=0; x<w; x++) {
	
		// Extract the color components of the pixel at (x,y)
		// from myVideoGrabber (or some other image source)
		ofColor colorAtXY = myVideoGrabber.getColor(x, y);
		float rAtXY = colorAtXY.r; 
		float gAtXY = colorAtXY.g; 
		float bAtXY = colorAtXY.b;
		
		// Compute the difference between those (r,g,b) values 
		// and the (r,g,b) values of our target color
		float rDif = rAtXY - rTarget; // difference in reds 
		float gDif = gAtXY - gTarget; // difference in greens 
		float bDif = bAtXY - bTarget; // difference in blues 
		
		// The Pythagorean theorem gives us the Euclidean distance.
		float colorDistance = 
			sqrt (rDif*rDif + gDif*gDif + bDif*bDif); 
			
		if(colorDistance < leastDistanceSoFar){
			leastDistanceSoFar = colorDistance;
			xOfPixelWithClosestColor = x;
			yOfPixelWithClosestColor = y;
		}
	}
}

// At this point, we now know the location of the pixel 
// whose color is closest to our target color: 
// (xOfPixelWithClosestColor, yOfPixelWithClosestColor)

```

이러한 방식은 종종 사용자가 대상 컬러를 클릭하는 방식인 "컬러피커(스포이드)" 인터랙션에 사용되기도 합니다. 
*Delta-E* [calculation](http://colormine.org/delta-e-calculator/)는 빛의 여러 베리에이션 중 인간의 색상 인지에 적합하게 설계된  CIE76 컬러공산 상에서 "[color distance](http://en.wikipedia.org/wiki/Color_difference)"를 계산하는 것과 같이 보다 복잡한 방법을 사용하는 여러 사례들도 있습니다. 

#### 세가지-채널 (RGB) 이미지

우리의 링컨 초상화 이미지는 8-비트, 즉 1채널인 "[grayscale](http://en.wikipedia.org/wiki/Grayscale)" 이미지 입니다. 각 픽셀은 하나의 휘도를 표현하는, 하나의 숫자(기술적으로는, unsigned char)를 사용합니다. 하지만 다른 데이터 포맷 역시 가능합니다.

예를 들어, 일반적으로 컬러 이미지를 표현하기 위해 8-비트, *3-채널*을 사용합니다. 이 경우, 각 픽셀은 3 바이트로 묶이게 되는데. 각 1 바이트는 빨강, 녹색, 파란색의 정도를 표현하게 됩니다. 보시다시피, RGB 컬러 이미지는 3배의 정보를 포함하게 됩니다.

![Interleaved RGB pixels](images/interleaved_1.png)

여러분의 LCD 모니터를 한번 가까이 들여다보시면, 이렇게 저장된 데이터들이 어떻게 디스플레이 장치의 형광체 레이아웃에 직접적으로 적용되는지를 볼 수 있을것입니다:

![Magnified photograph of an LCD screen's pixels](images/rgb-screen.jpg)

컬러 데이터는 교차로 배치(interleaved)되므로, RGB데이터가 담긴 버퍼의 픽셀값에 접근하는것은 살짝 복잡합니다. 아래의 코드는 주어진 *(x,y)*좌표의 RGB 픽셀에서 red, green, blue 각 요소 값들을 얻어오는 방법을 보여줍니다:

```cpp
// Code fragment for accessing the colors located at a given (x,y) 
// location in an RGB color image. 

// Given:
// unsigned char *buffer, an array storing an RGB image
// (assuming interleaved data in RGB order!)
// int x, the horizontal coordinate (column) of your query pixel
// int y, the vertical coordinate (row) of your query pixel
// int imgWidth, the width of the image

int rArrayIndex = (y*imgWidth*3) + (x*3);
int gArrayIndex = (y*imgWidth*3) + (x*3) + 1;
int bArrayIndex = (y*imgWidth*3) + (x*3) + 2;

// Now you can get and set values at location (x,y), e.g.:
unsigned char redValueAtXY   = buffer[rArrayIndex];
unsigned char greenValueAtXY = buffer[gArrayIndex];
unsigned char blueValueAtXY  = buffer[bArrayIndex];
```

이내용은 사실, 앞의 흑백 이미지에서 픽셀값을 얻어오는 방법인 `index = y*width = x` 패턴의 3-채널 "RGB 버전" 입니다.

하지만 BGR과 같이 RGB 바이트가 다른 순서로 배치되는 외부 라이브러리나 이미지 하드웨어를 사용하는 상황이 발생할수도 있다는 점도 알아두시기 바랍니다.

#### 다양한 이미지 포맷들

8-비트 1-채널 (그레이스케일) 그리고 8-비트 3-채널 (RGB) 이미지는 가장 흔히 사용되는 포맷입니다. 하지만 이미지 처리 알고리즘의 넓은 세계에서는 아래 언급되는 포맷들처럼 다른 다양한 이미지 타입들이 있습니다:
- 8-비트 *palettized* 이미지 포맷은 각 픽셀에 최대 256 종류의 컬러들이 저장되어있는 배열의 인덱스를 담고 있습니다;
- 16-비트 (unsigned short)이미지는, 각 컬러 채널들이 *2* 바이트를 사용하며, 0-66535의 범위를 갖습니다;
- 32-비트 (float)이미지는, 각 컬러채널의 데이터가 부동소수점으로 표현됩니다.

좀더 실용적인 예시를 위해, 0-1000의 범위값으로 뎁스정보를 알려주는 XBox 360용 마이크로소프트의 키넥트 센서를 한번 더 생각해봅시다. 0-1000범위는 보통 이미지에서 사용되는 8-비트(0-255)의 범위를 벗어납니다만; 사실, 이 범위는 대략 11비트의 해상도를 갖게 됩니다. 이를 수용하기 위해 `ofxKinect`애드온은 이 정보를 16-비트 이미지 포맷을 사용하여 정보손실 없이 저장합니다. 이와 마찬가지로, 32-비트 부동소수점 포맷은 거의 대부분의 고-화질의 비디오포맷 처리에서 필수적으로 사용됩니다.

이밖에도 다양한 방식이 있습니다:

* 2-채널 이미지 : 휘도 + 투명 에서 일반적으로 사용됨
* 3-채널 이미지 : 일반적으로 RGB 데이터에서 사용되지만, 종종 HSB, YUV와 같은 다른 컬러공간을 사용하는 이미지 저장을 위해 사용됨
* 4-채널 이미지 : RGBA 이미지에서 사용되지만, CMYK에서도 종종 사용됨
* [*Bayer images*](https://en.wikipedia.org/wiki/Bayer_filter) : RGB 컬러이지만 교차로 저장되는 R-G-B-R-G-B-R-G-B... 이 아닌, 독특한 체커보드 패턴의 형태로 저장됨.


이보다 더 희한한 방식도 있습니다. 예를들어 ["Hyperspectral" imagery from the Landsat 8 satellite](https://www.mapbox.com/blog/putting-landsat-8-bands-to-work/)는 11채널을 사용하는데, 자외선 주파수대역, 근적외선 영역, 열화상 적외선 영역을 포함합니다!

#### 다양한 이미지 컨테이너 (데이터 구조)

이미지 *포맷*이 이미지 데이터를 어떻게 표현할것인가(가령 8-비트 그레이스케일 이미지 vs. RGB 이미지) 라면, 이미지 *컨테이너 클래스*는 좀 더 이미지 데이터를 다양한 방법과 컨텍스트를 사용하여 어떻게 사용(캡쳐, 디스플레이, 계산, 분석 또는 저장) 될수 있을까에 초점을 맞춘 라이브러리-스펙, 또는 데이터 구조를 말합니다.

- **unsigned char*** : unsigned char의 배열이며, 이는 픽셀데이터의 버퍼를 저장하기 위해 사용된 가장 전통적인, C-스타일의 포맷입니다. 비록 이 방식이 아주 "스마트" 하진 않지만(딱히 특별한 기능이나 *이미지*를 관리하기위한 메타데이터를 제공하지 않습니다), 서로 다른 라이브러리 사이에 정보교환을 할때에 종종 사용됩니다. 많은 이미지 처리 교과서에서는 이러한 방식을 사용합니다.

- **ofPixels** : 이는 오픈프레임웍스에서 픽셀데이터를 답는 컨테이너이며, `ofImage` 뿐만아니라 `ofVideoGrabber`와 같은 다른 클래스들에도 포함되어있습니다. 이미지의 가로, 세로크기와 같은 부가적인 정보를 담고있는 버퍼들을 포함한 래퍼입니다.

- **ofImage** : `ofImage`는 오픈프레임웍스에서 정적인 이미지를 불러오거나, 저장, 화면에 그려낼때 사용되는 아주 일반적인 오브젝트입니다. ofImage에 파일을 불러오면, 내부의 `ofPixels`오브젝트에 이미지 데이터를 저장합니다. `ofImage` 오브젝트는 단순한 컨테이너라기 보다는, 내부에 메소드들과 픽셀데이터를 화면에 그려내기 위한 `ofTexture`와 같은 오브젝트도 갖고 있습니다.

- **ofxCvImage** This is a container for image data used by the ofxOpenCV addon for openFrameworks, which supports a range of functionality from the popular OpenCV library for filtering, thresholding, and other image manipulations.

- **ofxCvImage** : ofxOpenCV 애드온에서 사용되는 이미지 컨테이너입니다. 인기있는 라이브러리인 OpenCV의 필터링, 쓰레숄딩, 및 다양한 이미지 처리 기능을 제공합니다.

- **ofTexture** : 이 컨테이너는 컴퓨터의 그래픽카드(GPU)의 텍스쳐 메모리에 이미지 데이터를 저장합니다. `ofImage`, `ofxCvImage`, `ofVideoPlayer`, `ofVideoGrabber`, `ofFbo`, `ofKinect`와 같은 클래스에 데이터를 화면에 그려내는 목적으로, 내부적으로 `ofTextre`가 포함되어있습니다.

- **ofFBO** : GPU의 "프레임 버퍼 오브젝트(frame buffer object)"는 텍스쳐와 추가적인 깊이버퍼(depth buffer, 역자주 : z버퍼라고도 불리움)를 위한 컨테이너입니다. 계산된 픽셀들이 이미지처럼 다뤄지는 여타 렌더러(3D 혹은 2D에 그려낼때 사용되는 캔버스)같은 것이라고 설명할 수 있습니다. 궁극적으로 `ofFBO`는 그려진 드로잉 패쓰를 표현하는, 그래픽카드에 저장되는 오브젝트라고 할 수 있습니다.


- **cv::Mat** : OpenCV에서 이미지 정보를 저장하는데 사용되는 자료구조입니다. 오픈프레임웍스에서 사용되지는 않지만, 만약 여러분이 자주 OpenCV로 작업한다면, 이 포맷으로 데이터를 다루고 추출하게 될 것입니다.

- **IplImage** This is an older data container (from the [Intel Image Processing Library](https://www.safaribooksonline.com/library/view/learning-opencv/9780596516130/ch03s03.html)) that plays well with OpenCV. Note that you generally won't have to worry about IplImages unless (or until) you do much more sophisticated things with OpenCV; the ofxCvImage should give you everything you need to get its data in and out.

- **IplImage** : OpenCV에서 잘 동작하는 구형 자료구조입니다([Intel Image Processing Library](https://www.safaribooksonline.com/library/view/learning-opencv/9780596516130/ch03s03.html 에서 유래되었음). (적어도) 여러분이 OpenCV로 복잡한 일들을 하지 않는다면 일반적으로 IplImage에 대해서 걱정할 필요는 없습니다; ofxCvImage가 여러분이 필요로 하는 데이터 입출력을 맡아줄 것이기 때문이죠.

최대한의 확장성 위해, 오픈프레임웍스(그리고 ofxOpenCV, Kyle McDonald의 [ofxCv](https://github.com/kylemcdonald/ofxCv)와 같은 이미지 처리를 위한 애드온)의 디자이너들은 이러한 컨테이너들 간에 데이터교환을 쉽게 할 수 있도록 연산자들을 제공합니다.

![Simplified diagrams of ofImage (left) and ofxCvImage (right)](images/two-image-types.png)

The diagram above shows a simplified representation of the two most common oF image formats you're likely to see. At left, we see an `ofImage`, which at its core contains an array of unsigned chars. An `ofPixels` object wraps up this array, along with some helpful metadata which describes it, such as its width, height, and format (RGB, RGBA, etc.). The `ofImage` then wraps this `ofPixels` object up together with an `ofTexture`, which provides functionality for rendering the image to the screen. The `ofxCvImage` at right is very similar, but stores the image data in IplImages. All of these classes provide a variety of methods for moving image data into and out of them.

위의 다이어그램은 오픈프레임웍스에서 가장 많이 사용되는 두 종류의 이미지포맷을 간략하게 도식화한 것입니다. 좌측은, unsigned char의 배열을 갖고 있는 `ofImage` 핵심 컨테이너입니다. `ofPixels`오브젝트는 이 배열을 감싸고 있고, 이와 함께 이미지의 가로크기, 세로크기, 포맷(RGB, RGBA, 등등)과 같은 그것을 설명하는 메타데이터가 위치하고 있습니다. `ofImage`는 이 `ofPixels`오브젝트와 함께 이미지를 화면에 그려내는 기능을 제공하는 `ofTexture`를 함께 감싸고 있습니다. 우측의 `ofxCvImage`는 이와 아주 흡사하지만, 이미지 데이터를 IplImage에 저장합니다.이러한 모든 클래스들은 이미지 데이터를 불러오거나 내보내기 위한 다양한 메소드들을 제공합니다.

It's important to point out that image data may be stored in very different parts of your computer's memory. Good old-fashioned unsigned chars, and image data in container classes like `ofPixels` and `ofxCvImage`, are maintained in your computer's main RAM; that's handy for image processing operations by the CPU. By contrast, the `ofTexture` class, as indicated above, stores its data in GPU memory, which is ideal for rendering it quickly to the screen. It may also be helpful to know that there's generally a performance penalty for moving image data back-and-forth between the CPU and GPU, such as the `ofImage::grabScreen()` method, which captures a portion of the screen from the GPU and stores it in an `ofImage`, or the `ofTexture::readToPixels()` and `ofFBO::readToPixels()` methods, which copy image data to an `ofPixels`.

이미지데이터가 여러분의 컴퓨터 메모리 내에 아주 다른 부분들에 저장 될 수 있다는 점이 매우 중요합니다. 전통적인 unsigned chars와, `ofPixels`, `ofxCvImage` 컨테이너 내의 이미지 데이터들은 컴퓨터의 RAM에 저장되는데, 이는 CPU에 의해 이미지 연산을 하기에 편리합니다. 이와 반대로, `ofTexture`클래스는 앞에서 살펴봤듯이, CPU 메모리상에 데이터를 저장하는데, 이는 화면에 빠르게 렌더링하는데에 적합합니다. 또한 일반적으로 CPU와 GPU간에 이미지 데이터를 교환할 때 성능손실이 발생한다는 점도 알아두면 좋습니다, 가령 GPU에서 화면의 일부분을 캡쳐하는 `ofImage::grabScreen`메소드라든가, `ofPixels`에 이미지 데이터를 복사하는 `ofTexture::readToPixels()`와 `ofFBO::readToPixels`메소드가 바로 그렇습니다.

#### RGB 에서 Grayscale로의 변환, 그리고 컴퓨터비젼에서의 이러한 변환의 역할
Many computer vision algorithms (though not all) are commonly performed on one-channel (i.e. grayscale or monochrome) images. Whether or not your project uses color imagery at some point, you'll almost certainly still use grayscale pixel data to represent and store many of the intermediate results in your image processing chain. The simple fact is that working with one-channel image buffers (whenever possible) can significantly improve the speed of image processing routines, because it reduces both the number of calculations as well as the amount of memory required to process the data. 

많은 컴퓨터 비전 알고리즘(비록 전부는 아니겠지만)들은 일반적으로 싱글채널(그레이스케일 혹은 흑백) 이미지 상에서 이루어집니다. 설령 여러분의 프로젝트가 컬러 이미지를 사용한다고 해도, 결국은  이미지 처리 체인의 여러 중간 결과물은 그레이스케일 픽셀데이터로 처리됩니다. 이유는 단순합니다. 싱글채널 이미지 버퍼를 사용해야 이미치 처리 루틴의 속도가 향상되기 때문입니다. 이는 데이터 처리를 위한 메모리 크기와 동시에 연산량도 줄어들기 때문이지요.

For example, if you're calculating a "blob" to represent the location of a user's body, it's common to store that blob in a one-channel image; typically, pixels containing 255 (white) designate the foreground blob, while pixels containing 0 (black) are the background. Likewise, if you're using a special image to represent the amount of motion in different parts of the video frame, it's enough to store this information in a grayscale image (where 0 represents stillness and 255 represents lots of motion). We'll discuss these operations more in later sections; for now, it's sufficient to state this rule of thumb: if you're using a buffer of pixels to store and represent a one-dimensional quantity, do so in a one-channel image buffer. Thus, except where stated otherwise, *all of the examples in this chapter expect that you're working with monochrome images*. 


예를들어, 만약 사용자의 바디 위치를 나타내기 위해 "blob"을 계산한다면, 이 blob을 싱글채널 이미지로 저장하는것이 일반적입니다; 보편적으로 이 이미지에서 255(흰색)이 담긴 픽셀은 전면 blob을 의미하고, 0(검정)이 담긴 픽셀은 배경을 의미합니다. 마찬가지로 비디오프레임의 차이를 이용해 움직임의 양을 표한하는 특별한 이미지를 사용한다면, 당연히 이 정보 또한 그레이스케일 이미지(0은 변화가 전혀없는, 255은 변화가 가장 큰)를 사용합니다. 이러한 연산에 대해서는 나중에 다른 섹션에서 다룰것입니다; 일단 이정도의 규칙만 알고 있다면 충분합니다: if you're using a buffer of pixels to store and represent a one-dimensional quantity, do so in a one-channel image buffer. Thus, except where stated otherwise, *all of the examples in this chapter expect that you're working with monochrome images*. 

Let's suppose that your raw source data is color video (as is common with webcams). For many image processing and computer vision applications, your first step will involve *converting this to monochrome*. Depending on your application, you'll either clobber your color data to grayscale directly, or create a grayscale copy for subsequent processing. 

여러분에게 가공되지 않은 컬러비디오(일반적으로 웹캠을 사용하죠)가 있다고 해봅시다. 많은 이미지 처리 및 컴퓨터 비전 응용사례에서, 여러분이 가장 먼저 해야할 일은 *이것을 흑백으로 변환* 하는 것입니다. 여러분의 어플리케이션에 따라, 그 컬러를 직접 그레이스케일로 변환해버리거나, 혹은 별도의 처리를 통해 그레이스케일의 사본을 만들어내야 합니다.

컬러 이미지를 그레이스케일로 변환하는 아주 단순한 처리는, 오픈프레임웍스에서 해당 데이터를 `OF_IMAGE_GRAYSCALE` 이미지 타입으로 변경하는 것입니다. 이는 이미지를 재할당하고, ofTexture를 업데이트해줘야 하기 때문에, 자주 수행한다면 자칫 무거운 연산이 될 수도 있다는점을 명심하셔야 합니다. 또한, 원본의 컬러정보가 변환 과정에서 정보의 손실이 발생하므로 "손실 연산"이기도 합니다.

```cpp
ofImage myImage; 
myImage.loadImage ("colorful.jpg"); // Load a colorful image.
myImage.setImageType (OF_IMAGE_GRAYSCALE); // Poof! Now it's grayscale. 
```

ofxOpenCV 애드온 라이브러리는 컬러 이미지를 그레이스케일로 변환하는 몇가지 메소드를 제공합니다. 예를들어 `convertToGrayscalePlanarImage()`와 `setFromColorImage()` 함수는 `ofxColorImage`에 저장된 컬러 이미지 데이터를 변환하여 `ofxCvGrayscaleImage`를 생성 혹은 세팅해줍니다:

```
// Given a color ofxOpenCv image, already filled with RGB data:
// ofxCvColorImage kittenCvImgColor; 

// And given a declared ofxCvGrayscaleImage:
ofxCvGrayscaleImage kittenCvImgGray;
	
// The color-to-gray conversion is then performed by this assignment.
// NOTE: This uses "operator overloading" to customize the meaning of
// the '=' operator for ofxOpenCV images. 
kittenCvImgGray = kittenCvImgColor;
```

Although oF provides the above utilities to convert color images to grayscale, it's worth taking a moment to understand the subtleties of the conversion process. There are three common techniques for performing the conversion: 

비록 오픈프레임웍스가 위와같은 컬러이미지를 그레이스케일로 변환하는 기능들을 제공해주긴 하지만, 실제로 변환하는 과정의 디테일들을 이해하는것도 나쁘지 않을겁니다. 이러한 변환을 수행하는 방법은 대체로 세가지 방법이 있습니다:

* **Extracting just one of the R,G, or B color channels,** as a proxy for the luminance of the image. For example, one might fetch only the green values as an approximation to an image's luminance, discarding its red and blue data. For a typical color image whose bytes are interleaved R-G-B, this can be done by fetching every 3rd byte. This method is computationally fast, but it's also perceptually inaccurate, and it tends to produce noisier results for images of natural scenes. 
* **R, G, B 컬러 채널중 하나만 추출** : 이미지의 휘도를 대략적으로 추출하기 위한 방법입니다. 예를들자면 이미지의 휘도를 얻기위해, 빨강, 파랑 데이터는 무시하고 녹색 값들만 뽑아낼 수 있을것입니다. 일반적인 컬러이미지 byte 데이터는 R-G-B의 순서로 배치되어있으므로, 세번째 바이트만 뽑아내면 됩니다. 이 방법은 빠른 컴퓨터 연산이 가능하지만, 인간이 느끼기에 부정확하기도 하고, 자연 이미지들의 경우 노이즈가 많이 생기는 단점이 있습니다.

* **Taking the average of the R,G, and B color channels.** A slower but more perceptually accurate method approximates luminance (often written *Y*) as a straight average of the red, green and blue values for every pixel: `Y = (R+G+B)/3;`. This not only produces a better representation of the image's luminance across the visible color spectrum, but it also diminishes the influence of noise in any one color channel.

* **R, G, B 컬러 채널의 평균값 사용** : 느리지만 인지적으로 대체로 정확한 휘도(일반적으로 *Y*라고 표기하기도 합니다)을 얻기 위해 모픈 픽셀에 담긴 빨강, 녹색, 파란색 값의 평균을 구하는 것입니다: Y = (R+G+B)/3;`. 가시영역의 컬러 스펙트럼에서 보다 나은 휘도값을 얻을수 있으면서 동시에 모든 채널에서의 노이즈도 줄일 수 있는 방법이기도 합니다.

* **Computing the luminance with colorimetric coefficients**. The most perceptually accurate methods for computing grayscale from color images employ a specially-weighted "colorimetric" average of the RGB color data. These methods are marginally more expensive to compute, as each color channel must be multiplied by its own perceptual weighting factor. The CCIR 601 imaging specification, which is used in the OpenCV [cvtColor](http://docs.opencv.org/modules/imgproc/doc/miscellaneous_transformations.html#cvtcolor) function, itself used in the ofxOpenCV addon, employs the formula `Y = 0.299*R + 0.587*G + 0.114*B` (with the further assumption that the RGB values have been gamma-corrected). According to [Wikipedia](http://en.wikipedia.org/wiki/Luma_(video)), "these coefficients represent the measured intensity perception of typical trichromat humans; in particular, human vision is most sensitive to green and least sensitive to blue."

* **컬러 상수(colorimetric coefficient)를 이용하여 휘도값을 계산** : 인지적으로 가장 정확한 방법으로, RGB컬러데이터에서 그레이스케일값을 얻기위해 특별히 정의된 RGB컬러데이터의 평균 "표색(colormetric" 수치를 사용하여 계산하는 방법입니다. 이 방법은 대체로 비싼 연산이라고 할 수 있는데, 각 컬러채널별로 고유의 인지적 요소값을 곱하게 됩니다. ofxOpenCV애드온에서 사용되고 있는 OpenCV의 [cvtColor](http://docs.opencv.org/modules/imgproc/doc/miscellaneous_transformations.html#cvtcolor)함수에서 채택하고 있는 CCIR 601 이미징 스펙에 따르면, `Y = 0.299*R + 0.587*G + 0.114*B` 공식을 적용하고 있습니다.(추가적인 감마-수정을 적용한 RGB 값입니다). [위키피디아](http://en.wikipedia.org/wiki/Luma_(video))에 따르면, "이러한 상수는 인간의 삼중 인지강도를 바탕으로 하고 있는데, 일반적으로 인간의 시각은 파란색에 둔감하고 녹색에 더 민감하기 떄문이다" 라고 서술되어 있습니다.


Here's a code fragment for converting from color to grayscale, written "from scratch" in C/C++, using the averaging method described above. This code also shows, more generally, how the pixelwise computation of a 1-channel image can be based on a 3-channel image. 

아래는 위에 서술된 내용을 바탕으로 C/C++로 작성된 컬러값을 그레이스케일로 변환하는 코드입니다. 3-채널 이미지를 단일 채널이미지로 변환함에 있어 픽셀단위로 처리하는 보다 일반적인 방법을 보여주고 있습니다.

```cpp
// Code fragment to convert color to grayscale (from "scratch")

// Load a color image, fetch its dimensions, 
// and get a pointer to its pixel data. 
ofImage myImage; 
myImage.loadImage ("colorful.jpg");
int imageWidth = myImage.getWidth();
int imageHeight = myImage.getHeight();
unsigned char* rgbPixelData = myImage.getPixels(); 

// Allocate memory for storing a grayscale version.
// Since there's only 1 channel of data, it's just w*h. 
int nBytesGrayscale = imageWidth * imageHeight; 
unsigned char* grayPixelData = new unsigned char [nBytesGrayscale];

// For every pixel in the grayscale destination image, 
for(int indexGray=0; indexGray<nBytesGrayscale; indexGray++){

	// Compute the index of the corresponding pixel in the color image,
	// remembering that it has 3 times as much data as the gray one. 
	int indexColor = (indexGray * 3); 

	// Fetch the red, green and blue bytes for that color pixel. 
	unsigned char R = rgbPixelData[indexColor  ]; 
	unsigned char G = rgbPixelData[indexColor+1]; 
	unsigned char B = rgbPixelData[indexColor+2]; 
	
	// Compute and assign the luminance (here, as an average of R,G,B).
	// Alternatively, you could use colorimetric coefficients.  
	unsigned char Y = (R+G+B)/3; 
	grayPixelData[indexGray] = Y;
}
```


## 이미지에서의 포인트 프로세싱 연산 (Point Processing Operation)

In this section, we consider image processing operations that are precursors to a wide range of further analysis and decision-making. In particular, we will look at *point processing* operations, namely image arithmetic and thresholding.  

이 섹션에서는, 부가적인 분석 및 의사결정을 위한 precursor을 하는 이미지 처리 연산을 살펴보겠습니다. 특히, 우리가 살펴볼 것은 *포인트 프로세싱(point processing")* 연산, 즉 이미지 산술 및 쓰레숄딩 입니다. 

We begin with *image arithmetic*, a core part of the workflow of computer vision. These are the basic mathematical operations we all know—addition, subtraction, multiplication, and division—but as they are applied to images. Developers use such operations constantly, and for a wide range of reasons. 

일단 *이미지 산술(arithmetic)*로 시작할텐데요, 이는 컴퓨터 비전 워크플로의 핵심입니다. 이것들은 우리가 일반적으로 알고 있는 기초적인 수학 연산자인 덧셈, 뺄셈, 곱셈, 나눗셈이지만, 이미지에 적용되는 것 뿐입니다. 개발자들은 여러가지 이유로, 지속적으로 이러한 연산들을 사용합니다.

### 상수를 사용한 이미지 산술

이미지 내 값에 적용하는 산술 변환의 가장 단순한 연산은 상수를 사용하는 것입니다. 아래의 예제에서는, 8-비트 흑백이미지 에 상수 **10**를 더하고 있습니다. 어떻게 *픽셀 단위*로 값이 더해지는지 살펴보시기 바랍니다: 결과가 되는 이미지의 각 픽셀은 원본이 되는 이미지보다 10씩 더 큰 값(그레이 레벨단위로 10씩 밝아짐)이 적용됩니다. 각 픽셀들은 인접한 픽셀과 별개로 독립적으로 처리되므로, 이러한 이미지 연산을 *포인트 프로세싱*이라고도 부릅니다.

![Pixelwise image arithmetic: adding 10 to an image, i.e., adding 10 to every pixel value. But what value should go in the red square?](images/image_arithmetic_1b.png)

값을 더하면 이미지는 전체적으로 밝아지고, 반대로 값을 빼면 이미지는 전체적으로 어두워집니다.

아래의 코드에서는, 픽셀버퍼를 직접 조작하여 포인트 프로세싱을 구현합니다. 실제 컴퓨터비전 프로젝트에서는 이러한 과정을 OpenCV와 같은 고급-레벨의 라이브러리를 사용하겠지만, 실제 내부에서의 동작 원리를 살펴볼 수 있을것입니다.

```cpp
// Example 4: Add a constant value to an image.
// This is done from "scratch", without OpenCV.
// This is ofApp.h

#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
	void setup();
	void draw();
	
	ofImage lincolnOfImageSrc; // The source image
	ofImage lincolnOfImageDst; // The destination image
};
```

```cpp
// Example 4. Add a constant value to an image.
// This is ofApp.cpp
#include "ofApp.h"

void ofApp::setup(){
	
	// Load the image and ensure we're working in monochrome.
	// This is our source ("src") image. 
	lincolnOfImageSrc.loadImage("images/lincoln_120x160.png");
	lincolnOfImageSrc.setImageType(OF_IMAGE_GRAYSCALE);
	
	// Construct and allocate a new image with the same dimensions. 
	// This will store our destination ("dst") image. 
	int imgW = lincolnOfImageSrc.width;
	int imgH = lincolnOfImageSrc.height;
	lincolnOfImageDst.allocate(imgW, imgH, OF_IMAGE_GRAYSCALE);
	
	// Acquire pointers to the pixel buffers of both images. 
	// These images use 8-bit unsigned chars to store gray values. 
	// Note the convention 'src' and 'dst' -- this is very common.
	unsigned char* srcArray = lincolnOfImageSrc.getPixels();
	unsigned char* dstArray = lincolnOfImageDst.getPixels();
	
	// Loop over all of the destination image's pixels. 
	// Each destination pixel will be 10 gray-levels brighter
	// than its corresponding source pixel.
	int nPixels = imgW * imgH; 
	for(int i=0; i<nPixels; i++) {
		unsigned char srcValue = srcArray[i];
		dstArray[i] = srcValue + 10; 
	}
	
	// Don't forget this!
	// We tell the ofImage to refresh its texture (stored on the GPU)
	// from its pixel buffer (stored on the CPU), which we have modified.
	lincolnOfImageDst.update();
}

//---------------------
void ofApp::draw(){
	ofBackground(255);
	ofSetColor(255);

	lincolnOfImageSrc.draw ( 20,20, 120,160);
	lincolnOfImageDst.draw (160,20, 120,160);
}
```

### 정수 오버플로우에 관한 주의사항


이미지 산술은 단순합니다만, 픽셀에 저장된 값에 산술연산을 할때에 숨어있는 위험이 있습니다!: *[정수 오버플로우](http://en.wikipedia.org/wiki/Integer_overflow)*가 바로 그것입니다.

Consider what happens when we add 10 to the specially-marked pixel in the bottom row of the illustration above. Its initial value is 251—but the largest number we can store in an unsigned char is 255! What should the resulting value be? More generally, what happens if we attempt to assign a pixel value that's too large to be represented by our pixel's data type?

위의 그림에서 하단에 마킹된 픽셀에 10을 더하면 어떻게 될까요? 원래의 값은 251인데, 이 값은 unsigned char로 저장되므로 가능한 최대의 값은 255입니다! 그렇다면 결과는 어떻게 될까요? 좀 더 일반적으로 질문해본다면, 픽셀의 데이터타입에에 비해 너무 큰 픽셀값이 할당되면 어떤 일이 발생할까요?

The answer is: *it depends which libraries or programming techniques you're using*, and it can have very significant consequences! Some image-processing libraries, like OpenCV, will clamp or constrain all arithmetic to the data's desired range; thus, adding 10 to 251 will result in a maxed-out value of 255 (a solution sometimes known as "saturation"). In other situations, such as with our direct editing of unsigned chars in the code above, we risk "rolling over" the data, wrapping around zero like a car's odometer. Without the ability to carry, only the least significant bits are retained. In the land of unsigned chars, adding 10 to 251 gives... 6!

정답은 바로 : *어떤 라이브러리를 사용하는지에 따라, 혹은 여러분이 사용하는 프로그래밍 스킬에 따라 다름* 입니다. 그리고 이건 아주아주 중요한 결과가 될수 있죠! OpenCV와 같은 어떤 이미지 처리 라이브러리의 경우라면, 모든 산술연산에 데이터형에 따라 값을 잘라내거나 제한해줄 것입니다.  그러금로 만약 251에 10을 더하면, 결과는 255이상을 넘지 않습니다(이러한 방법은 "saturation"이라고도 알려져있습니다). 이와 다르게 우리가 위에서 작성했던 코드와 같이 직접 unsigned char를 처리한다고 하면, 데이터의 "롤오버" 현상을 감수해야 합니다, 자동차의 주행적산메터가 표현할수 있는 값을 넘어가면 0이 되는것처럼요. 자리올림의 기능없이, 오직 sifnificant bit만이 남게 되는것이죠. 따라서 unsigned char 데이터 단위에서는, 251에 10을 더하면... 6이 됩니다!


The perils of integer overflow are readily apparent in the illustration below. I have used the code above to lighten a source image of Abraham Lincoln, by adding a constant to all of its pixel values. Without any preventative measures in place, many of the light-colored pixels have "wrapped around" and become dark. 

정수 오버플로우의 위험성은 아래의 그림에서 살펴볼 수 있습니다. 

![Numeric overflow in an image of Lincoln](images/numeric_overflow.png)

In the example above, integer overflow can be avoided by promoting the added numbers to integers, and including a saturating constraint, before assigning the new pixel value:

```cpp
// The 'min' prevents values from exceeding 255, avoiding overflow.
dstArray[index] = min(255, (int)srcValue + 10);
```

Integer overflow can also present problems with other arithmetic operations, such as multiplication and subtraction (when values go negative). 

### Image Arithmetic with the ofxOpenCv Addon

The OpenCV computer vision library offers fast, easy-to-use and high-level implementations of image arithmetic. Here's the same example as above, re-written using the ofxOpenCV addon library, which comes with the openFrameworks core download. Note the following: 

* ofxOpenCv provides convenient methods for copying data between images.
* ofxOpenCv provides convenient operators for performing image arithmetic.
* ofxOpenCv's arithmetic operations saturate, so integer overflow is not a concern.
* ofxOpenCv does not currently provide methods for loading images, so we employ an `ofImage` as an intermediary for doing so. 
* As with all addons, it's important to import the ofxOpenCV addon properly into your project. (Simply adding `#include "ofxOpenCv.h"` in your app's header file isn't sufficient!) The openFrameworks [ProjectGenerator](https://www.youtube.com/watch?v=4k2ZcvC0YEA) is designed to help you with this, and makes it easy to add an addon into a new (or pre-existing) project. 

```cpp
// Example 5: Add a constant value to an image, with ofxOpenCv.
// Make sure to use the ProjectGenerator to include the ofxOpenCv addon.
// This is ofApp.h
#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void draw();
		ofxCvGrayscaleImage lincolnCvImageSrc;
		ofxCvGrayscaleImage lincolnCvImageDst;
};
```

```cpp
// Example 5: Add a constant value to an image, with ofxOpenCv.
// This is ofApp.cpp
#include "ofApp.h"

void ofApp::setup(){
	
	// ofxOpenCV doesn't have image loading.
	// So first, load the .png file into a temporary ofImage.
	ofImage lincolnOfImage;
	lincolnOfImage.loadImage("lincoln_120x160.png");
	lincolnOfImage.setImageType(OF_IMAGE_GRAYSCALE);
	
	// Set the lincolnCvImage from the pixels of this ofImage.
	int imgW = lincolnOfImage.getWidth();
	int imgH = lincolnOfImage.getHeight();
	unsigned char *lincolnPixels = lincolnOfImage.getPixels();
	lincolnCvImageSrc.setFromPixels( lincolnPixels, imgW, imgH);
	
	// Make a copy of the source image into the destination.
	lincolnCvImageDst = lincolnCvImageSrc;
	
	// ofxOpenCV has handy operators for in-place image arithmetic.
	lincolnCvImageDst += 60;
}

//---------------------
void ofApp::draw(){
	ofBackground(255);
	ofSetColor(255);
	
	lincolnCvImageSrc.draw ( 20,20, 120,160);
	lincolnCvImageDst.draw (160,20, 120,160);
}
```
Here's the result. Note how the high values (light areas) have saturated instead of overflowed. 

![Image arithmetic with saturation](images/image_lightening.png)

### Arithmetic with Two Images: Absolute Differencing

Image arithmetic is especially useful when applied to two images. As you would expect, it is possible to add two images, multiply two images, subtract one image from another, and divide one image by another. When performing an arithmetic operation (such as addition) on two images, the operation is done "pixelwise": the first pixel of image *A* is added to the first pixel of image *B*, the second pixel of *A* is added to the second pixel of *B*, and so forth. For the purposes of this discussion, we'll assume that *A* and *B* are both monochromatic, and have the same dimensions. 

Many computer vision applications depend on being able to compare two images. At the basis of doing so is the arithmetic operation of *absolute differencing*, illustrated below. This operation is equivalent to taking the absolute value of the results when one image is subtracted from the other: *|A-B|*. As we shall see, absolute differencing is a key step in common workflows like *frame differencing* and *background subtraction*.  

![Diagram of absolute differencing. The image at right contains values which are the absolute difference of the corresponding pixels in the left and center images](images/absolute-difference.png)

In the illustration above, we have used absolute differencing to compare two 5x5 pixel images. From this, it's clear that the greatest difference occurs in their lower-right pixels. 

Absolute differencing is accomplished in just a line of code, using the ofxOpenCv addon:

```cpp
// Given: 
// ofxCvGrayscaleImage myCvImageA;    // the minuend image
// ofxCvGrayscaleImage myCvImageB;    // the subtrahend image
// ofxCvGrayscaleImage myCvImageDiff; // their absolute difference

// The absolute difference of A and B is placed into myCvImageDiff:
myCvImageDiff.absDiff (myCvImageA, myCvImageB);
```

### Thresholding

In computer vision programs, we frequently have the task of determining which pixels represent something of interest, and which do not. Key to building such discriminators is the operation of *thresholding*. 

Thresholding poses a *pixelwise conditional test*—that is, it asks "`if`" the value stored in each pixel *(x,y)* of a source image meets a certain criterion. In return, thresholding produces a destination image, which represents where and how the criterion is (or is not) met in the original's corresponding pixels. As we stated earlier, pixels which satisfy the criterion are conventionally assigned 255 (white), while those which don't are assigned 0 (black). And as we shall see, the white blobs which result from such thresholding are ideally suited for further analysis by *contour tracers*.

Here's an example, a photomicrograph (left) of light-colored cells. We'd like to know which pixels represent a cell, and which do not. For our criterion, we test for pixels whose grayscale brightness is greater than some constant, the *threshold value*. In this illustration, we test against a threshold value of 127, the middle of the 0-255 range: 

![Thresholding, also called binarization](images/thresholded_cells.png)

And below is the complete openFrameworks program for thresholding the image—although here, instead of using a constant (127), we instead use the `mouseX` as the threshold value. This has the effect of placing the thresholding operation under interactive user control. 

```cpp
// Example 6: Thresholding 
// This is ofApp.h
#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void draw();
		ofxCvGrayscaleImage myCvImageSrc;
		ofxCvGrayscaleImage myCvImageDst;
};
```

```cpp
// Example 6: Thresholding 
// This is ofApp.cpp
#include "ofApp.h"

//---------------------
void ofApp::setup(){
	
	// Load the cells image
	ofImage cellsOfImage;
	cellsOfImage.loadImage("cells.jpg");
	cellsOfImage.setImageType(OF_IMAGE_GRAYSCALE);
	
	// Set the myCvImageSrc from the pixels of this ofImage.
	int imgW = cellsOfImage.getWidth();
	int imgH = cellsOfImage.getHeight();
	unsigned char *cellsPixels = cellsOfImage.getPixels();
	myCvImageSrc.setFromPixels (cellsPixels, imgW, imgH);
}

//---------------------
void ofApp::draw(){
	ofBackground(255);
	ofSetColor(255);
	
	// Copy the source image into the destination:
	myCvImageDst = myCvImageSrc;
	
	// Threshold the destination image. 
	// Our threshold value is the mouseX, 
	// but it could be a constant, like 127.
	myCvImageDst.threshold (mouseX); 
	
	myCvImageSrc.draw ( 20,20,  320,240);
	myCvImageDst.draw (360,20,  320,240);
}
```
## A Complete Workflow: Background Subtraction

We now have all the pieces we need to understand and implement a popular and widely-used workflow in computer vision: *contour extraction and blob tracking from background subtraction*. This workflow produces a set of (x,y) points that represent the boundary of (for example) a person's body that has entered the camera's view. 

![Screenshot of the opencvExample](images/opencvExample.png)

In this section, we'll base our discussion around the standard openFrameworks *opencvExample*, which can be found in the `examples/addons/opencvExample` directory of your openFrameworks installation. When you compile and run this example, you'll see a video of a hand casting a shadow—and, at the bottom right of our window, the contour of this hand, rendered as a cyan polyline. This polyline is *our prize:* using it, we can obtain all sorts of information about our visitor. So how did we get here?

The code below is a slightly simplified version of the standard *opencvExample*; for example, we have here omitted some UI features, and we have omitted the `#define _USE_LIVE_VIDEO` (mentioned earlier) which allows for switching between a live video source and a stored video file.  

In the discussion that follows, we separate the inner mechanics into five steps, and discuss how they are performed and displayed: 

1. Video Acquisition
2. Color to Grayscale Conversion 
3. Storing a "Background Image"
4. Thresholded Absolute Differencing
5. Contour Tracing

```cpp
// Example 7: Background Subtraction 
// This is ofApp.h

#pragma once
#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
	
		ofVideoPlayer			vidPlayer;
	
		ofxCvColorImage			colorImg;
		ofxCvGrayscaleImage 	grayImage;
		ofxCvGrayscaleImage 	grayBg;
		ofxCvGrayscaleImage 	grayDiff;
		ofxCvContourFinder		contourFinder;

		int						thresholdValue;
		bool					bLearnBackground;
};
```

```cpp
// Example 7: Background Subtraction 
// This is ofApp.cpp
#include "ofApp.h"

//---------------------
void ofApp::setup(){
	vidPlayer.load("fingers.mov");
	vidPlayer.play();

	colorImg.allocate(320,240);
	grayImage.allocate(320,240);
	grayBg.allocate(320,240);
	grayDiff.allocate(320,240);

	bLearnBackground = true;
	thresholdValue = 80;
}

//---------------------
void ofApp::update(){
	
	// Ask the video player to update itself.
	vidPlayer.update();
	
	if (vidPlayer.isFrameNew()){ // If there is fresh data...
		
		// Copy the data from the video player into an ofxCvColorImage
		colorImg.setFromPixels(vidPlayer.getPixels());
		
		// Make a grayscale version of colorImg in grayImage
		grayImage = colorImg;
		
		// If it's time to learn the background;
		// copy the data from grayImage into grayBg
		if (bLearnBackground == true){
			grayBg = grayImage; // Note: this is 'operator overloading'
			bLearnBackground = false; // Latch: only learn it once.
		}

		// Take the absolute value of the difference 
		// between the background and incoming images.
		grayDiff.absDiff(grayBg, grayImage);
		
		// Perform an in-place thresholding of the difference image.
		grayDiff.threshold(thresholdValue);

		// Find contours whose areas are betweeen 20 and 25000 pixels.
		// "Find holes" is true, so we'll also get interior contours.
		contourFinder.findContours(grayDiff, 20, 25000, 10, true);
	}
}

//---------------------
void ofApp::draw(){
	ofBackground(100,100,100);

	ofSetHexColor(0xffffff);
	colorImg.draw(20,20);    // The incoming color image
	grayImage.draw(360,20);  // A gray version of the incoming video
	grayBg.draw(20,280);     // The stored background image
	grayDiff.draw(360,280);  // The thresholded difference image

	ofNoFill();
	ofDrawRectangle(360,540,320,240);

	// Draw each blob individually from the blobs vector
	int numBlobs = contourFinder.nBlobs;
	for (int i=0; i<numBlobs; i++){
		contourFinder.blobs[i].draw(360,540);
	}
}

//---------------------
void ofApp::keyPressed(int key){
	bLearnBackground = true;
}
```

**Step 1. Video Acquisition.** <br /> 
In the upper-left of our screen display is the raw, unmodified video of a hand creating a shadow. Although it's not very obvious, this is actually a color video; it just happens to be showing a mostly black-and-white scene. 

In `setup()`, we initialize some global-scoped variables (declared in ofApp.h), and allocate the memory we'll need for a variety of globally-scoped `ofxCvImage` image buffers.  We also load the hand video from from its source file into `vidPlayer`, a globally-scoped instance of an `ofVideoPlayer`.

It's quite common in computer vision workflows to maintain a large number of image buffers, each of which stores an intermediate state in the image-processing chain. For optimal performance, it's best to `allocate()` these only once, in `setup()`; otherwise, the operation of reserving memory for these images can hurt your frame rate. 

Here, the `colorImg` buffer (an `ofxCvColorImage`) stores the unmodified color data from `vidPlayer`; whenever there is a fresh frame of data from the player, in `update()`, `colorImg` receives a copy. Note the commands by which the data is extracted from `vidPlayer` and then assigned to `colorImg`: 

```cpp
colorImg.setFromPixels(vidPlayer.getPixels());
```

In the full code of opencvExample (not shown here) a `#define` near the top of ofApp.h allows you to swap out the `ofVideoPlayer` for an `ofVideoGrabber`—a live webcam. 

**Step 2. Color to Grayscale Conversion.** <br />
In the upper-right of the window is the same video, converted to grayscale. Here it is stored in the `grayImage` object, which is an instance of an `ofxCvGrayscaleImage`. 

It's easy to miss the grayscale conversion; it's done implicitly in the assignment `grayImage = colorImg;` using operator overloading of the `=` sign. All of the subsequent image processing in *opencvExample* is done with grayscale (rather than color) images. 

**Step 3. Storing a "Background Image".** <br />
In the middle-left of the screen is a view of the *background image*. This is a grayscale image of the scene that was captured, once, when the video first started playing—before the hand entered the frame. 

The background image, `grayBg`, stores the first valid frame of video; this is performed in the line `grayBg = grayImage;`. A boolean latch (`bLearnBackground`) prevents this from happening repeatedly on subsequent frames. However, this latch is reset if the user presses a key. 

It is absolutely essential that your system "learn the background" when your subject (such as the hand) is *out of the frame*. Otherwise, your subject will be impossible to detect properly!

**Step 4. Thresholded Absolute Differencing.** <br />
4. In the middle-right of the screen is an image that shows the *thresholded absolute difference* between the current frame and the background frame. The white pixels represent regions that are significantly different from the background: the hand! 

The absolute differencing and thresholding take place in two separate operations, whose code is shown below. The `absDiff()` operation computes the absolute difference between `grayBg` and `grayImage` (which holds the current frame), and places the result into `grayDiff`. 

The subsequent thresholding operation ensures that this image is *binarized*, meaning that its pixel values are either black (0) or white (255). The thresholding is done as an *in-place operation* on `grayDiff`, meaning that the `grayDiff` image is clobbered with a thresholded version of itself. 

The variable `thresholdValue` is set to 80, meaning that a pixel must be at least 80 gray-levels different than the background in order to be considered foreground. In the official example, a keypress permits the user to adjust this number. 

```cpp
// Take the absolute value of the difference 
// between the background and incoming images.
grayDiff.absDiff(grayBg, grayImage);

// Perform an in-place thresholding of the difference image.
grayDiff.threshold(thresholdValue);
```

This example uses thresholding to distinguish dark objects from a light background. But it's worth pointing out that thresholding can be applied to any image whose brightness quantifies a variable of interest. 

If you're using a webcam instead of the provided "fingers.mov" demo video, note that automatic gain control can sometimes interfere with background subtraction. You may need to increase the value of your threshold, or use a more sophisticated background subtraction technique. 

**Step 5. Contour Tracing.** <br />
5. The final steps are displayed in the bottom right of the screen. Here, an `ofxCvContourFinder` has been tasked to `findContours()` in the binarized image. It does this by identifying contiguous blobs of white pixels, and then tracing the contours of those blobs into an `ofxCvBlob` outline comprised of (x,y) points. 

Internally, the `ofxCvContourFinder` first performs a pixel-based operation called [*connected component labeling*](https://en.wikipedia.org/wiki/Connected-component_labeling), in which contiguous areas are identified as uniquely-labeled blobs. It then extracts the boundary of each blob, which it stores in an `ofPolyline`, using a process known as a [*chain code algorithm*](http://www.mind.ilstu.edu/curriculum/chain_codes_intro/chain_codes_intro.php). 

Some of the parameters to the `findContours()` method allow you to select only those blobs which meet certain minimum and maximum area requirements. This is useful if you wish to discard very tiny blobs (which can result from noise in the video) or extremely large blobs (which can result from sudden changes in lighting). 

```cpp
// Find contours whose areas are betweeen 20 and 25000 pixels.
// "Find holes" is set to true, so we'll also get interior contours.
contourFinder.findContours(grayDiff, 20, 25000, 10, true);
```

In `draw()`, the app then displays the contour of each blob in cyan, and also shows the bounding rectangle of those points in magenta.

```cpp
// Draw each blob individually from the blobs vector
int numBlobs = contourFinder.nBlobs;
for (int i=0; i<numBlobs; i++){
   contourFinder.blobs[i].draw(360,540);
}
```

### Frame Differencing

Closely related to background subtraction is *frame differencing*. If background subtraction is useful for detecting *presence* (by comparing a scene before and after someone entered it), frame differencing is useful for detecting *motion*. 

The difference between background subtraction and frame differencing can be described as follows: 

* Background subtraction compares the current frame with a previously-stored background image
* Frame differencing compares the current frame with the immediately previous frame of video. 

As with background subtraction, it's customary to threshold the difference image, in order to discriminate signals from noise. Using frame differencing, it's possible to quantify *how much motion* is happening in a scene. This can be done by counting up the white pixels in the thresholded difference image. 

In practice, background subtraction and frame differencing are often used together. For example, background subtraction can tell us that someone is in the room, while frame differencing can tell us how much they are moving around. In a common solution that combines the best of both approaches, motion detection (from frame differencing) and presence detection (from background subtraction) can be combined to create a generalized detector. A simple trick for doing so is to take a weighted average of their results, and use that as the basis for further thresholding. 

### Contour Games

Blob contours are a *vector-based* representation, comprised of a series of (x,y) points. Once obtained, a contour can be used for all sorts of exciting geometric play. 

A good illustration of this is the following project by Cyril Diagne, in which the body's contour is triangulated by [ofxTriangle](https://github.com/obviousjim/ofxTriangle), and then used as the basis for simulated physics interactions using [ofxBox2D](https://github.com/vanderlin/ofxBox2d). The user of Diagne's project can "catch" the bouncy circular "balls" with their silhouette. 

![Screenshots of ofx-kikko by Cyril Diagne](images/ofx-kikko.jpg)

One of the flags to the `ofxCvContourFinder::findContours()` function allows you to search specifically for *interior* contours, also known as [*negative space*](https://en.wikipedia.org/wiki/Negative_space). An interactive artwork which uses this to good effect is *Shadow Monsters* by Philip Worthington, which interprets interior contours as the boundaries of lively, animated eyeballs. 

![Screenshots of Philip Worthington's Shadow Monsters. Photo by Jef Rouner](images/shadowmonsters_jefrouner.jpg)

The original masterwork of contour play was Myron Krueger’s landmark interactive artwork, [*Videoplace*](https://www.youtube.com/watch?v=dmmxVA5xhuo), which was developed continuously between 1970 and 1989, and which premiered publicly in 1974. The *Videoplace* project comprised at least two dozen profoundly inventive scenes which comprehensively explored the design space of full-body camera-based interactions with virtual graphics — including telepresence applications and (as pictured here, in the “Critter” scene) interactions with animated artificial creatures. 

![Photographs of Myron Krueger's VideoPlace](images/krueger.jpg)

Here's a quick list of some fun and powerful things you can do with contours extracted from blobs: 

* A blob's contour is represented as a `ofPolyline`, and can be smoothed and simplified with `ofPolyline::getSmoothed()`. Try experimenting with extreme smoothing, to create ultra-filtered versions of captured geometry. 
* If you have too many (or too few) points in your contour, consider using `ofPolyline::getResampledBySpacing()` or `getResampledByCount()` to reduce (or increase) its number of points. 
* `ofPolyline` provides methods for computing the area, perimeter, centroid, and bounding box of a contour; consider mapping these to audiovisual or other interactive properties. For example, you could map the area of a shape to its mass (in a physics simulation), or to its color. 
* You can identify "special" points on a shape (such as the corners of a square, or an extended fingertip on a hand) by searching through a contour for points with high local curvature. The function `ofPolyline::getAngleAtIndex()` can be helpful for this. 
* The mathematics of [*shape metrics*](http://what-when-how.com/biomedical-image-analysis/spatial-domain-shape-metrics-biomedical-image-analysis/) can provide powerful tools for contour analysis and even recognition. One simple shape metric is [*aspect ratio*](https://en.wikipedia.org/wiki/Aspect_ratio), which is the ratio of a shape's width to its height. Another elegant shape metric is *compactness* (also called the [*isoperimetric ratio*](https://en.wikipedia.org/wiki/Isoperimetric_ratio)), which the ratio of a shape's perimeter-squared to its area. You can use these metrics to distinguish between (for example) cardboard cutouts of animals or numbers.
* The ID numbers (array indices) assigned to blobs by the `ofxCvContourFinder` are based on the blobs' sizes and locations. If you need to *track* multiple blobs whose positions and areas change over time, see the [*example-contours-tracking*](https://github.com/kylemcdonald/ofxCv/tree/master/example-contours-tracking) example in Kyle McDonald's addon, [ofxCv](https://github.com/kylemcdonald/ofxCv/).


## Refinements

In this section we briefly discuss several important refinements that can be made to improve the quality and performance of computer vision programs. 

* Cleaning Up Thresholded Images: Erosion and Dilation
* Automatic Thresholding and Dynamic Thresholding
* Adaptive Background Subtraction
* ROI Processing

#### Cleaning Up Thresholded Images: Erosion and Dilation

Sometimes thresholding leaves noise, which can manifest as fragmented blobs or unwanted speckles. If altering your threshold value doesn't solve this problem, you'll definitely want to know about [*erosion*](http://homepages.inf.ed.ac.uk/rbf/HIPR2/erode.htm) and [*dilation*](http://homepages.inf.ed.ac.uk/rbf/HIPR2/dilate.htm), which are types of *morphological operators* for binarized images. Simply put, 

* Erosion *removes* a layer of pixels from every blob in the scene. 
* Dilation *adds* a layer of pixels to every blob in the scene. 

In the example below, one pass of erosion is applied to the image at left. This eliminates all of the isolated specks of noise: 

![Original image (left), after one pass of erosion (right)](images/erosion_in_use.png)

By contrast, observe how dilation is used in the person-detecting pipeline below: 

![A complete image-processing pipeline, including ](images/full_pipeline.png)

1. Live video is captured and converted to grayscale. A background image is acquired at a time when nobody is in the scene. (Sometimes, a running average of the camera feed is used as the background, especially for outdoor scenes subject to changing lighting conditions.)
2. A person walks into the frame.  
3. The live video image is compared with the background image. The absolute difference of Images (1) and (2) is computed. 
4. Image (3), the absolute difference, is thresholded. Unfortunately, the person's body is fragmented into pieces, because some pixels were insufficiently different from the background. 
5. Two passes of dilation are applied to Image (4) the thresholded image. This fills in the cracks between the pieces, creating a single, contiguous blob. 
6. The contour tracer identifies just one blob instead of several.  

OpenCV makes erosion and dilation easy. See `ofxCvImage::erode()` and `ofxCvImage::dilate()` for methods that provide access to this functionality. 

Other operations which may be helpful in removing noise is `ofxCvImage::blur()` and `ofxCvImage:: blurGaussian()`. These should be applied *before* the thresholding operation, rather than after. 

#### Adaptive Background Subtraction

In situations with fluctuating lighting conditions, such as outdoor scenes, it can be difficult to perform background subtraction. One common solution is to slowly adapt the background image over the course of the day, accumulating a running average of the background. 

The overloaded operators for `ofxCvImage` make such running averages straightforward. In the code fragment below, the background image is continually but slowly reassigned to be a combination of 99% of what it was a moment ago, with 1% of new information. This is also known as an *adaptive background*. 

```cpp
grayBg = 0.99*grayBg + 0.01*grayImage;
```
 
#### Automatic Thresholding and Dynamic Thresholding

Sometimes it's difficult to know in advance exactly what the threshold value should be. Camera conditions change, lighting conditions change, scene conditions change; all affect the value which we hope to use to distinguish light from dark. 

To resolve this, you could make this a manually adjusted setting, as we did in Example 6 (above) when we used the `mouseX` as the threshold value. But there are also *automatic thresholding* techniques that can compute an "ideal" threshold based on an image's luminance histogram. There are dozens of great techniques for this, including [Otsu's Method](https://en.wikipedia.org/wiki/Otsu%27s_method), Gaussian Mixture Modeling, IsoData Thresholding, and Maximum Entropy thresholding. For an amazing overview of such techniques, check out [ImageJ](http://imagej.nih.gov/ij/), an open-source (Java) computer vision toolkit produced by the US National Institute of Health. 

![An image histogram, and four possible thresholds. The histogram shows a hump of dark pixels (with a large peak at 28/255), and a shallower hump of bright pixels (with a peak at 190). The vertical gray lines represent possible threshold values, automatically determined by four different methods. ](images/thresholds.png)

Below is code for the *Isodata* method, one of the simpler (and shorter) methods for automatically computing an ideal threshold. Note that the function takes as input the image's *histogram*: an array of 256 integers that contain the count, for each gray-level, of how many pixels are colored with that gray-level. 

```cpp
/*
From: http://www.ph.tn.tudelft.nl/Courses/FIP/frames/fip-Segmenta.html
This iterative technique for choosing a threshold was developed by 
Ridler and Calvard. The histogram is initially segmented into two parts
using a starting threshold value such as th0 = 127, half the maximum
dynamic range for an 8-bit image. The sample mean (mf,0) of the gray 
values associated with the foreground pixels and the sample mean (mb,0) 
of the gray values associated with the background pixels are computed. 
A new threshold value th1 is now computed as the average of these two 
sample means. The process is repeated, based upon the new threshold, 
until the threshold value does not change any more. 

Input: imageHistogram, an array of 256 integers, each of which represents 
the count of pixels that have that particular gray-level. For example,
imageHistogram[56] contains the number of pixels whose gray-level is 56.
Output: an integer (between 0-255) indicating an ideal threshold.
*/

int ofApp::getThresholdIsodata (int *imageHistogram){
	int theThreshold = 127; // our output
	
	if (input != NULL){ // sanity check
		int thresh = theThreshold;
		int tnew = thresh;
		int thr  = 0;
		int sum  = 0;
		int mean1, mean2;
		int ntries = 0;
		
		do {
			thr = tnew;
			sum = mean1 = mean2 = 0;

			for (int i=0; i<thr; i++){
				mean1 += (imageHistogram[i] * i);
				sum   += (imageHistogram[i]);
			}     
			if (sum != 0){ mean1 = mean1 / sum;}

			sum = 0;
			for (int i=thr; i<255; i++){
				mean2 += (imageHistogram[i] * i);
				sum   += (imageHistogram[i]);
			}

			if (sum != 0){ mean2 = mean2 / sum;}
			tnew = (mean1 + mean2) / 2;
			ntries++;

		} while ((tnew != thr) && (ntries < 64));
		theThreshold = tnew;
	}
	return theThreshold;
}
```

In some situations, such as images with strong gradients, a single threshold may be unsuitable for the entire image field. Instead, it may be preferable to implement some form of *per-pixel thresholding*, in which a different threshold is computed for every pixel (i.e. a "threshold image"). 

As you can see below, a single threshold fails for this particular source image, a page of text. Instead of using a single number, the threshold is established for each pixel by taking an average of the brightness values in its neighborhood (minus a constant!). 

![Adaptive Thresholding. From the Hypertext Image Processing Reference.](images/hipr-adaptive.jpg)

The name for this technique is *adaptive thresholding*, and an excellent discussion can be found in the online [Hypertext Image Processing Reference](http://homepages.inf.ed.ac.uk/rbf/HIPR2/adpthrsh.htm). 

#### ROI Processing 

Many image processing and computer vision operations can be sped up by performing calculations only within a sub-region of the main image, known as a *region of interest* or ROI. 

The relevant function is `ofxCvImage::setROI()`, which sets the ROI in the image. Region of Interest is a rectangular area in an image, to segment object for further processing. Once the ROI is defined, OpenCV functions will operate on the ROI, reducing the number of pixels that the operation will examine and modify.

## Suggestions for Further Experimentation

There's tons more to explore! We strongly recommend you try out all of the openCV examples that come with openFrameworks. (An audience favorite is the *opencvHaarFinderExample*, which implements the classic Viola-Jones face detector!) When you're done with those, check out the examples that come with Kyle McDonald's [ofxCv](https://github.com/kylemcdonald/ofxCv) addon. 

I sometimes assign my students the project of copying a well-known work of interactive new-media art. Reimplementing projects such as the ones below can be highly instructive, and test the limits of your attention to detail. Such copying provides insights which cannot be learned from any other source. *I recommend you build...*

#### A Slit-Scanner.
*Slit-scanning* — a type of spatiotemporal or "time-space imaging" — has been a common trope in interactive video art for more than twenty years. Interactive slit-scanners have been developed by some of the most revered pioneers of new media art (Toshio Iwai, Paul de Marinis, Steina Vasulka) as well as by [literally dozens](http://www.flong.com/texts/lists/slit_scan/) of other highly regarded practitioners. The premise remains an open-ended format for seemingly limitless experimentation, whose possibilities have yet to be exhausted. It is also a good exercise in managing image data, particularly in extracting and copying image subregions. 

In digital slit-scanning, thin slices are extracted from a sequence of video frames, and concatenated into a new image. The result is an image which succinctly reveals the history of movements in a video or camera stream. In [*Time Scan Mirror*](http://www.smoothware.com/danny/timescan.html) (2004) by Danny Rozin, for example, a image is composed from thin vertical slices of pixels that have been extracted from the center of each frame of incoming video, and placed side-by-side. Such a slit-scanner can be built in fewer than 20 lines of code—try it!

![Daniel Rozin, Time Scan Mirror (2004)](images/rozin_timescan.jpg)

#### A cover of *Text Rain* by Utterback & Achituv (1999).

*[Text Rain](http://camilleutterback.com/projects/text-rain/)* by Camille Utterback and Romy Achituv is a now-classic work of interactive art in which virtual letters appear to "fall" on the visitor's "silhouette". Utterback writes: "In the *Text Rain* installation, participants stand or move in front of a large projection screen. On the screen they see a mirrored video projection of themselves in black and white, combined with a color animation of falling letters. Like rain or snow, the letters appears to land on participants’ heads and arms. The letters respond to the participants’ motions and can be caught, lifted, and then let fall again. The falling text will 'land' on anything darker than a certain threshold, and 'fall' whenever that obstacle is removed."

![Camille Utterback and Romy Achituv, Text Rain (1999)](images/text-rain.jpg)

*Text Rain* can be implemented in about 30 lines of code, and involves many of the topics we've discussed in this chapter, such as fetching the brightness of a pixel at a given location. It can also be an ideal project for ensuring that you understand how to make objects (to store the positions and letters of the falling particles) and arrays of objects.

========================================================  
## Bibliography

This chapter has introduced a few introductory image processing and computer vision techniques. But computer vision is a huge and constantly evolving field. For more information, we highly recommend the following books and online resources.

- Bradski, Gary. [Learning OpenCV](http://cs.haifa.ac.il/~dkeren/ip/OReilly-LearningOpenCV.pdf) (PDF)
- Cardoso, Jorge. [Computer vision techniques for interactive art](http://www.slideshare.net/jorgecardoso/computer-vision-techniques-for-interactive-art)
- Fisher, Robert, et. al. [HIPR2, The Hypertext Image Processing Reference](http://homepages.inf.ed.ac.uk/rbf/HIPR2/index.htm)
- [Introduction to Video and Image Processing](http://what-when-how.com/category/introduction-to-video-and-image-processing/)
- Levin, Golan. [Computer Vision for Artists and Designers](http://www.flong.com/texts/essays/essay_cvad/)
- Szeliski & Zisserman. [20 techniques that every computer vision researcher should know](http://www.frontiersincomputervision.com/slides/FCV_Core_Szeliski_Zisserman.pdf) (PDF)
- Szeliski, Richard. [Computer Vision: Algorithms and Applications](http://szeliski.org/Book/)
- [The OpenCV Reference Manual](http://docs.opencv.org/opencv2refman.pdf) (PDF)





