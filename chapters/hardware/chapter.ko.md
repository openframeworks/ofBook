---
.. title: 하드웨어
.. type: ofBook
.. translator: Jongun won
.. translator_site: http://scripter.co.kr
---

# Hardware
# 하드웨어
*by [Caitlin Morris](http://www.caitlinmorris.net/) and [Pierre Proske](http://www.digitalstar.net/)*


## introduction
## 소개

This chapter will give you an introduction to working with openFrameworks outside of your computer screen and into the physical world. Why exactly would you want to do this? Well, given that we are physical creatures ourselves, having software control, sense and actuate real-world things can be pretty exciting and create truly visceral experiences. Screen based work can be captivating, but physical installations have the potential to deliver greater impact due to their more tangible nature.
이 챕터는 당신에게 당신의 컴퓨터 스크린이외에서 작업과 실제 물리적인 오픈프레임웍스 작업을 소개 할 것이다. 당신은 정확히 왜 이것을 하기 원하는가? 글쎄, 우리는 스스로 물리적인 창조물 이며, 소프트웨어를 컨트롤 하며, 감각적이며, 실제 세계에서 어떤것을 조작 하는것이 상당히 흥미롭게 하며 진실로 본능적인 경험을 창조 한다. 스크린을 베이스로한 작업은 매혹적이나, 물리적인 설치물은 그들에게 실제로 보이는 것들이기 때문에 가능성과 강력한 임펙트를 전달한다.

There are a number of ways of taking your openFrameworks app out of the frame of your own personal computer and getting it to interact with the outside world. Largely this involves some kind of communication from openFrameworks to whatever hardware you've decided to hook up to. The different types of computer based communications (or protocols) vary, but the most common is what's known as 'serial' communication, so called because each bit of data sent is transferred one after the other (as opposed to multiple bits being sent in parallel).
오픈프레임웍스 앱을 이용하여 당신의 개인 컴퓨터를 벗어나고 인터랙티브한 바깥 세상으로 나가기 위한 3가지 방법이 있다. 크게는 어떤 당신이 관심을 가지기로 한 하드웨어의 오픈프레임웍스 커뮤니티같은 곳에 참여 하는 것이다. 다른 종류의 컴퓨터기반의 통신(혹은 프로토콜)은 서로 다르나, 대부분은 '시리얼' 통신으로 알려져 있다. 왜 그렇게 불리냐면 다른 각각의 데이터의 비트를 서로 다른 곳으로 전송(다중 비트들을 동시에 서로 보내기) 하기 때문이다.

The first hardware that we’ll look at interfacing with is the excellent **Arduino** prototyping platform.  Arduino is, in its own words, an *“open-source electronics prototyping platform based on flexible, easy-to-use hardware and software… intended for artists, designers, hobbyists, and anyone interested in creating interactive objects or environments.*”  It’s easy to see why there’s a lot of overlap between communities of people interested in using openFrameworks and Arduino!  With Arduino, it’s quick to get your openFrameworks app hooked up to sensors (like light sensors, proximity sensors, or other methods of environmental input), actuators (like lights, motors, and other outputs), and real-time interaction.  You're free to move out of the realm of pixels and into the physical world.
첫번째 하드웨어로 훌륭한 **Arduino** 프로토타입 플랫폼을 보게 될 것이다. 아두이노는 그들의 말로
*"오픈 소스 일렉트로닉 프로토타이핑 플랫폼기반의 유연하고, 사용하기 쉬운 하드웨어와 소프트웨어 이다...(중략) 아티스트, 다자이너, 취미로 즐기는 사람, 관심있는 사람 모두가 오브젝트나 환경을 창조 하는것을 목표로 하고 있다 "*
왜 그들의 커뮤니티나 사람들의 관심에서 오픈프레임웍스와 아두이노가 오버랩 되는지 쉽게 알 수 있다. 아두이노와 함께라면, 센서(발광센서, 근접센서, 또는 주변의 여러 기능을 가진 입력장치들)를 오픈프레임웍스와 연결 하고, 동작기(전구, 모터, 여타 아웃풋 장치), 그리고 실시간 인터랙션을 빠르게 구현 할 수 있다.

This chapter assumes that you have the Arduino IDE installed, in addition to the environment that you normally use for working with openFrameworks.  If not, you can download it from the Arduino website (arduino.cc) or the Arduino github (github.com/arduino).
이 챕터는 아두이노 개발환경의 설치와, 보통의 오픈프레임웍스 작업 환경에 붙이는 것을 맡고 있다. 아니면, 아두이노 웹사이트(arduino.cc) 또는 아두이노 깃허브(github.com/arduino) 에서 다운로드 할 수 있다.

Additionally, following along with the examples in this chapter requires you to have a few pieces of basic hardware.  You’ll need an Arduino (any generation; an Uno, Leonardo, or Duemilanove will look the most like the graphics in this chapter but any USB-connected Arduino will work just fine) and the appropriate USB cable to connect to your computer.  
추가로, 이 챕터의 예제를 계속 따라 오려면, 몇몇의 기본적인 하드웨어를 필요로 한다. 당신은 아마 아두이노(어떤 종류, Uno , Leonardo, 또는 Duemilanove 은 이챕터의 대부분의 그래픽과 유사할 것이나, 어떤 USB연결도 작업에는 무난하다)가 필요 할 것이며 적절한 USB 케이블이 당신의 컴퓨터와 연결되어야 한다.

[** Callout - The Leonardo differs from earlier boards in that it has built-in USB communication, eliminating the need for a secondary processor. This allows the Leonardo to appear to a connected computer as a mouse and keyboard, in addition to a virtual serial port. This makes setting up interactive applications a very simple procedure - in your openFrameworks app all you need to do is check for a key press! **]
[** 참고 - Leonardo 는 빌드인된 USB 통신(인터페이스)을 가진 다른 보드들과 다르며,  두번째 프로세스를 제거 할 필요가 있다. 이것은 Leonardo가 컴퓨터의 마우스와 키보드 같은 것을 연결 하는 것을 나타내며, 게다가 가상 시리얼 포트로 연결된다. 이것은 간단한 절차의 인터랙티브 어플리케이션 설정을 하게 해주며, 당신의 오픈프레임웍스 앱의 모든 key press를 체크할 필요가 있다.**]

## getting started with serial communication
##시리얼 통신 시작 하기

**SERIAL: ONE AFTER THE OTHER**
**시리얼: 한발 더 들어가기(? 번역하기 애매한 부분)
Serial, in the most basic language sense, refers to things that come one after another; it’s a term often used to describe magazines, crimes, and television programs.  That meaning also applies when talking about serial data:  “serial communication” means that all information between two entities is being sent one piece at a time, following in a single stream.  One piece of data, or one bit, is just a binary piece of information: you’re either sending a 0 or a 1.  Using the terminology of digital electronics, these are frequently referred to as “high” and “low”; 0 is low (like turning a light off) and 1 is high (flipping it back on).  8 bits (for example the stream 01000001, which represents the letter A) are sometimes packaged together to create a single byte.
시리얼, 대부분 기본적인 언어 감각 안에, 한발 더 들어 가가는 것을 조회; 그것은 매거진을 정기적으로 구독 하기, 범죄, 그리고 텔레비전 프로그램들이다. 또한 그것이 의미하는 바는 시리얼 데이터를 얻을 때 요청한다. 단일 스트림에 따라서 “시리얼 통신”은 두 엔트리 사이에 모든 정보를 의미, 한번에 한 조각이 보내지기 시작 한다. 한조각의 데이터, 혹은 한 비트는 정보의 한 조각 바이너리일 뿐이고, 또한 0 혹은 1을 보낼 때도 그러하다. 디지털 전자 용어를 사용 하고, “high” 와 ”row” 같은 것을 자주 이용 한다. 0은 low 이고 그리고, 1 은 high 이다(불을 켰다 끄는 것 과 같은)(flipping it back on). 8비트는 간혹 같이 팩키지되어 단일 바이트를 생성 한다(예를 들어 01000001는 A를 나타낸다)

Serial communication is actually a very broad topic and there are many serial protocols, including audio-visual protocols such as DMX (based on RS-485) and MIDI (serial at 31,250 bits per second) which we'll briefly cover in this chapter. The most common serial protocol is called RS-232 and computers used to be equipped with RS-232 serial ports (remember them?) but today they are rarely present, which is why serial communications involving a computer will typically require an RS-232 to USB adaptor (found on-line or at your local electronics store).
시리얼 통신은 사실 매우 폭넓은 주재이며, 거기에는 많은 시리얼 프로토콜이 있고, DMX(based on RS-485) 와 MIDI(serial at 31,250 bits per second) 와 같은 오디오 비주얼 프로토콜을 포함 하며, 우리는 이 챕터에서 잠시 이것들을 잠시 덮어둘 것이다. 대개 보통의 시리얼 프로토콜은 RS-232로 불리우고, 컴퓨터들은 RS-232를 장착해 왔다.(기억하는가?) 그러나 오늘날 그들은 잘 보이지 않고, USB가 RS-232 보다 컴퓨터의 보통 시리얼 통신으로 자리잡게 된 이유이다.
![RS-232 to USB adaptor](images/USB-rs232.jpg "RS-232 to USB adaptor")

However, if you're connecting to an Arduino, it already appears to the computer as a virtual serial port and you just need a regular USB cable (the exact type is dependent on which model Arduino you have). The Arduino also has a built-in library which handles reading and writing to the serial port that appears on your computer. Additionally, the Arduino has bi-directional RS-232 serial ports which can be used to connect to other external serial devices. In short - the Arduino is well equipped for serial communications and does most of the hard work for you!
그러나 당신이 만약 아두이노와 연결을 한다면, 이미 보여진 가상 시리얼 포트 같은 컴퓨터와 일반적인 USB 케이블이 필요하다. (정확한 타입은 당신이 가지고 있는 아두이노 모델에 달려있다.) 또한 아두이노는 내장된 당신의 컴퓨터에서 보이는 시리얼 포트를 읽고 쓰는 바이너리 핸들을 가지고 있다. 추가로, 아두이노는 외부 시리얼 디바이스의와 가능한 쌍방향 연결이 가능한 RS-232 시리얼 포트를 가지고 있다. 간추려서 아두이노는 아주 좋은 시리얼 통신과 대부분의 어려운 일을 잘 할 수 있는 것을 구비 하고 있다.
 **note: expand on Serial library**
 **노트: 확장된 시리얼 라이브러리**

The speed at which data is transmitted between the Arduino and your software is measured in bits per second, or bps, a fairly self-explanatory unit of measurement.  The rate of bits per second is commonly referred to as the baud rate, and will vary based on your application.  For example, the standard baud rate of 9600bps will transfer data more slowly than a rate of 115200, but the faster baud rate may have more issues with byte scrambling.
아두이노와 당신의 소프트웨어 사이의 데이터 교환속도는 초당 비트 수, 또는 bps에 의해 결정 되며, 상당히 자명한 단위의 측정이다. 초당 비트수의 속도는 흔히 컴퓨팅 속도와 관련되며, 각기다른 당신의 어플리케이션도 영향이 있다. 예를 들어 기본적인 보드 속도는 115200bps 보다 9600bps이 데이터 전송이 더 느리지만, 더 빠른 보드 속도는 바이트가 엉키는 문제가 비교적 많이 발생 할 수 있다.
```
-- editor joshuajnoble I think adding some explanation of what rs232 is (a picture of an oscilloscope would be good) the flow of using:
-- editor joshuajnoble : 제 생각에는 rs232 사용에 대한 에 대한 설명이 추가되어야 할 것 같습니다. (오실로스코프 이미지가 좋지 않을까요)

enumerateDevices()
setup()
available()
close()

So you can find all serial devices, open the device, check if it has data, close the port and release the file handle.
그럼 연결된 장치의 모든 시리얼 장치를 찾을 수 있고, 만약 데이터를 가진다면, 포트를 닫거나 파일핸들로 릴리즈 된다.(???? 너무 , 로 열거 하는 거 아닌지.. )
Might be nice to have the Arduino serial example mirror the DMX example, like:
아마도 DMX의 연습으로 아두이노는 좋은 시리얼 예제가 될 것으로 생각한다.

here's some Arduino code to kick this off
여기에 두이노를 시작 할 수 있는 몇가지 코드가 있다.

int redPin   = 9;   // Red LED
int greenPin = 10;  // Green LED
int bluePin  = 11;  // Blue LED

int color[4];
long int inByte;
int wait = 10; //10ms

void setup()
{
  pinMode(redPin,   OUTPUT);   // sets the pins as output
  pinMode(greenPin, OUTPUT);   
  pinMode(bluePin,  OUTPUT);

  Serial.begin(9600);
}

void outputColour(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green);    
}

void setColor() {
  int i = 0;

  //wait and be patient
  while (i < 4)
  {
    if (Serial.available() > 0) {
        color[i] = Serial.read();
        i++;
    }
  }
}

// Main program
void loop()
{
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();

     if (inByte == 'C') {
      getColour();
      analogWrite(redPin, color[1]);
      analogWrite(bluePin, color[2]);
      analogWrite(greenPin, color[3]);
    }
  }
  delay(wait);
}

-- end editor
```

## digital and analog communication
## 디지털과 아날로그 통신

**USING SERIAL MONITOR WITH ARDUINO**
**아두이노와 시리얼 모니터의 사용**

The Arduino IDE has a built-in Serial monitor, which enables you to "tune in" to the data coming across a serial port at a specified baud rate.  You can find the Serial Monitor either under Tools - Serial Monitor in the Arduino menu bar, or in the "magnifying glass" icon at the top of the IDE.
아두이노 개발환경은 데이터가 시리얼포트로 들어오는 특정 보드의 속도를 체크하는 “tune in”이 가능한 시리얼 모니터를 내장 하고 있다. 툴안에 다른 시리얼 모니터툴을 발견 할 수 있다 – 이 시리얼 모니터는 개발환경의 가장 위에 “돋보기” 아이콘으로 아두이노의 메뉴바 안에 있다.

In the Arduino sketch, set up Serial communication and print a basic "Hello world!" phrase to the Serial monitor in the setup() function:
아두이노 스케치안에, 시리얼 통신을 셋업 할 수 있고, 시리얼 모니터의 setup() 함수로 기본적인 “Hello world” 구문을 프린팅 할 수 있다.


```cpp
Serial.begin(9600);
Serial.println("Hello world!");

```
Open the Serial monitor and make sure that your monitor is set to the same baud rate as your sketch (the variable that you set in Serial.begin() ). Note that the TX/RX lights on your Arduino flash once on setup - you can press the reset button on your Arduino (on most devices) to run setup again to see this more clearly.  The Arduino itself is sending the printed text over Serial and the Serial Monitor is picking up that text and printing it for us to read.
시리얼 모니터를 여는것은 당신의 스케치처럼 보드속도를 동일 하게 맞추는 것을 보장한다.(Serial.begin()안에서 이 변수가 할당 된다.) 셋업할때 아두이노위에 TX/RX 라이트의 한차례 깜빡임을 참고 하여 아두이도의 리셋버틍 으로 (대부분의 장치를) 깔끔하게 리셋 할 수 있다. 아두이노는 스스로 시리얼을 통하여 텍스트 출력을 전송 하고 시리얼 모니터는 우리가 읽을 수 있도록 그 텍스트와 출력을 받는다.

Of course, you can also use the Serial monitor to reflect more interesting data coming from devices that are connected to your Arduino.  You can print both digital and analog input data to Serial.
물론, 시리얼 모니터는 연결된 아두이노 장치의 데이터가 오는 것을 흥미롭게 보여지게 할 수 있다. 디지털 신호와 아날로그 입력 데이터를 시리얼로 출력 하는 것도 가능하다.

Digital inputs like pushbuttons, or a switch that only has open and closed positions, will send a binary value as their status.  You can walk through an example of connecting a pushbutton to your Arduino in the excellent Arduino tutorial found here:
디지털 입력은 푸쉬버튼과 같고, 스위치는 오직 열거나 닫는 것만 가지며, 그것의 바이너리 값의 상태를 보낼것이다. 당신은 아두이노의 푸쉬버튼이 연결되는 탁월한 예제를 여기서 발견 할 수 있다.

http://arduino.cc/en/tutorial/button

To print the value of the pushbutton to Serial, store the returned value from digitalRead in a variable and print that variable to Serial, just as done previously with the "hello world!" example.  Here, though, print in the loop() function rather than setup() so that the value updates continuously rather than only once on reset.


```cpp
buttonState = digitalRead(buttonPin);
Serial.println( buttonState );
```

If you're feeling limited by the binary nature of the pushbutton, you can also read from an analog input, using a component like a potentiometer, photoresistor, or any of the wide variety of sensors that provide non-binary input.

Analog inputs can only be connected on pins A0-A5 on a standard Arduino.  These analog-specific pins have an ADC (analog-digital converter) chip which enables them to convert the amount of voltage returning from the circuit into a digital-readable number between 0 and 1023.

There are a number of examples and tutorials for working with analog input; a basic one using a potentiometer can be found here:

http://arduino.cc/en/Tutorial/AnalogInput

Printing the incoming variables to the Serial monitor is the same as with a digital input, except that you'll be using the Arduino function for analogRead() rather than digitalRead():

```cpp
sensorValue = analogRead(sensorPin);
Serial.println( sensorValue );
```



## using serial for communication between arduino and openframeworks

In the same way that Arduino uses Serial communication for communication between hardware and the Serial monitor, it can also use Serial communication to communicate between the Arduino board and any other running application, including openFrameworks.  This can be done quite simply using the ofSerial class, native to openFrameworks.  This class sets up a Serial listener at a specified baud rate and Serial port, giving it access to the same streaming data as the Serial library in the native Arduino IDE.  

There's a good, heavily commented demonstration of this in the communications folder of examples that comes bundled with openFrameworks.  The basic components needed to get this working are a Serial object, a toggle for knowing whether a message has been sent or not, and an array for storing the data that we receive.


**USING FIRMATA AS A SERIAL PROTOCOL**

Though it’s possible to navigate all serial communication manually, you’ll reach the limitations of what you’re able to do fairly quickly - as soon as you start wanting to address different devices or have multiple inputs, you’ll fall into a spiral of packet management and be much more prone to getting corrupt packets or inaccurate and scrambled data.  Rather than deal with this manually, it’s much simpler to use Firmata, an open source protocol for managing multiple Serial streams.

**OFARDUINO**

ofArduino, the built-in Arduino communication class for openFrameworks, is based on Firmata protocol.  Using ofArduino assumes that a default Firmata sketch is loaded onto the Arduino.  This sketch, found in the Arduino examples folder, enables all of the pins of the Arduino for communication through both analog and digital communication, as well as more specific addressing of pins for servomotor control.  

**EXAMPLE**: Work through the same LED blink sketch as done previously with only Arduino, but with OF.


The basic flow of what we’re going to do looks like this: (graphic missing)

* Make an ofArduino object
* Connect to the Arduino object at the correct port and baud rate
* Set up an event listener to determine whether we’re successfully connected to the Arduino
* Set up a pin to communicate with, and specify whether that communication is analog or digital
* Poll for data from the serial port
* Send HIGH and LOW (or analog value) arguments to that pin

**Make an ofArduino object**

The first step is to add an ofArduino object into the header file of your project (usually, testApp.h).  I'll call this myArduino.

```cpp
void setup();
void update();
void draw();

ofArduino myArduino;
```

Now we've extended the capabilities of the native openFrameworks ofArduino class into our sketch, and we can work with the object myArduino.

**Connect to the Arduino object at the correct port and baud rate**

In the setup() of testApp.cpp, use the ofArduino `connect()` function to set up a connection at the appropriate port and baud rate.  `connect()` takes two parameters: the first is a String of the serial port name, which should match the serial port name you connected to in the Arduino application; the second is the baud rate.  Firmata uses a standard baud rate of 57600 bps.

```cpp
ard.connect("/dev/tty.usbserial-a700fiyD", 57600);
```

**Set up an event listener to determine whether we’ve successfully connected to the Arduino**

If you're working only within the Arduino IDE, it's easy to have functions (like setting up the pin modes) called only once at the start of the program -- you can just call those functions from within `setup()` with the confidence that they'll always be run once when the device initializes.   When you're communicating with other software like openFrameworks, however, it's important to have a checking system to ensure that any setup functions only occur after a connection has been established.  openFrameworks uses the ofEventUtils class to make this easier, relying on the default `ofAddListener()` and `ofRemoveListener()` functions to check for the connection event.

Within the openFrameworks app, we'll want to create an Arduino-specific `setup()` function, which is only called once as a result of the serial connection being established.  We'll declare this function first in testApp.h:

```cpp
void setupArduino(const int & version);
```

... and call it from testApp.cpp:

```cpp
void testApp::setupArduino(const int & version) {
    // Arduino setup tasks will go here
}
```

The argument that's being passed to the function, `const int & version`, is a default return from the listener we're about to set up, which always responds to a connection event by sending back an argument with the connected firmware version.  That can stay as it is.

In the `setup()` of testApp.cpp, create a listener using `ofAddListener()`.  `ofAddListener()` is a function of ofEventUtils, which takes the arguments (event object, callback object, callback function).  When the event object happens (in this case, when the ofArduino EInitialized event is triggered), ofAddListener tells the callback object (here, a pointer to the testApp itself, referred to as “this”) to perform the setupArduino function that we created in the last step.

```cpp
ofAddListener(myArduino.EInitialized, this, &testApp.setupArduino);
```

When the EInitialized event is triggered (when the connection to the Arduino is complete, and the Arduino responds by sending back information about its firmware version), the listener sends us to the callback function, which in this case is `setupArduino()`.

Within `setupArduino()`, we can remove the listener, because we know a connection has been established.  `ofRemoveListener()` takes the same arguments as its counterpart.

```cpp
ofRemoveListener(myArduino.EInitialized, this, &testApp.setupArduino);
```

**Set up a pin to communicate with, and specify whether that communication is analog or digital**

Now it's time to treat our Arduino setup function just like we would within a standard Arduino app, and set up our pins and pin modes.  Here, I'm going to set up my Arduino Pin 13 as a digital output, in preparation for making a basic LED blink.

```cpp
myArduino.sendDigitalPinMode(13, ARD_OUTPUT);
```

The other options for pin setup follow in line with standard Arduino pin settings:

```cpp
sendDigitalPinMode(PIN_NUMBER, ARD_INPUT) // digital input
sendAnalogPinMode(PIN_NUMBER, ARD_OUTPUT) // analog output
sendAnalogPinMode(PIN_NUMBER, ARD_INPUT) // analog input
```

**Poll for data from the serial port**

In order to continuously update with new information on the serial port, it's important to periodically call the ofArduino `update()` function.  This can be done in its own Arduino-specific function, or can be called directly from `testApp::update()`:

```cpp
myArduino.update();
```

That's it! Now you're ready to start sending digital signals to pin 13 on your Arduino.

There are any number of triggers that you can use to control this signalling: you could set up a timer, integrate it into a game event, use a camera input... the possibilities are endless!  Here, I'm going to trigger my Pin 13 LED to turn on and off based on the up and down arrow keys.

Because I'm controlling activity with keyboard keys, I'm going to use the `void testApp::keyPressed (int key)` function, but you could also place your triggers within `draw()` or another function depending on your desired effect.

```cpp
void testApp::keyPressed  (int key){
    switch (key) {
        case OF_KEY_UP:
   	         	ard.sendDigital(13, ARD_HIGH);  // turn LED on
   	         	break;
			case OF_KEY_DOWN:
				ard.sendDigital(13, ARD_LOW); // turn LED off
				break;
       		default:
           		break;
    	}
	}
```

When all the parts are together, run the app and toggle your UP and DOWN arrow keys to turn the on-board LED on your Arduino on and off!  You can also put in a 3mm or 5mm LED on pin 13 to make the effect more obvious.  Remember that pin 13 is the only Arduino pin with a built-in resistor, so if you want to add LEDs or other components on other pins, you'll need to build a full circuit with resistors to avoid burning out your parts.


## Lights On - controlling hardware via DMX

DMX (which stands for Digital Multiplex), also known as DMX512 (512 being the number of channels each output can accommodate), is a protocol for controlling lighting and stage equipment. It's been around since the 80's, and is sometimes referred to as the MIDI of the lighting world as it achieves a fairly similar outcome - the sequencing and controlling of hardware through the use of a computer. DMX can be used to control anything from strobes to RGB par-can lights to LED fixtures. It's even possible to drive LED strips by Pulse Width Modulation if you have the right hardware. The advantage of sending DMX through a custom openFrameworks app is that you can then integrate it via all the other goodness OF has to offer, including custom GUI's, custom sequencing algorithms, camera tracking - you name it.

![DMX Lighting](images/stutterspot.jpg "DMX Lighting")

**Overview of the DMX protocol**

In order to send DMX first of all you need a DMX to USB control interface. This is a special box that you'll need to purchase in order to enable your computer to send DMX data via a USB port. These interfaces can be easily purchased on-line in case you can't track one down locally. You'll also need some DMX cables to connect between the interface and the DMX device you want to control. Microphone cables with XLR connectors can be used to send DMX data, although the official standard for DMX is a 5-pin cable, unlike the 3-pins that XLR has to offer. There does exist adaptors between 5 and 3-pin connectors in case you need to mix and match them. In any case, hook up your hardware via cables to your DMX to USB device, install your drivers if required (Operating System dependent) and you are ready to send. As previously mentioned, each DMX output from your controller can send up to 512 channels of DMX data. In DMX terminology, each group of 512 channels is known as a "Universe". Multiple DMX Universes are often used in complex setups requiring lots of channels. Typically you won't need more than a single universe as a single coloured light will only use up around 3 channels (one each for red, green and blue).

**DMX data format**

A DMX packet, in other words the data sent to the hardware each frame, consists of 512 channels, with an 8-bit value sent per channels (i.e. 0-255). One of the idiosyncracies of DMX is that the channel numbering starts at 1, channel 0 being a start code and not a data channel. This means that when setting up an array to hold your per-frame DMX data, you'll need to make it a size of 513 bytes. In openFrameworks we almost always represent a byte as an unsigned char, though you can also represent this with other types.

```cpp
//setup the data structure
unsigned char dmxData[513];

// zero the first value
dmxData[0] = 0;

// channels are valid from here on up
dmxData[1] = 126;
```

A number of OF addons have sprung up around DMX, a quick search of ofxAddons.com will reveal the most up to date. Typically these addons will have set up all the necessary data structures, including the one above, so you won't need to worry about anything other than sending the right data to the right channels. The hardest part will probably be installing the drivers for your controller!

**Structure of an OF DMX application**

No matter which code or which addon you use, the way in which you'll send DMX data will be very similar to the following pseudo-code (replace the comments with the relevant code):

```cpp
void ofApp::setup() {
    //connect to your DMX controller
}

void ofApp::update() {

    //assign the relevant values to your DMX data structure

    //update the DMX controller with the new data
}

```
The only concern then becomes what colour you'll be setting your lights and how you'd like to dim them.






