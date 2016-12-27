#C++의 메모리#

*[Arturo Castro](http://arturocastro.net)* 에 의해 작성


메모리를 정확히 사용하는것은 C++에서 가장 까다로운 부분입니다. Java, Python, 및 다른 일반적인 언어와 가장 큰 차이점이라면, C++에서는 메모리를 사용하려면 예약하고 해제하는 것을 명확히 명시해야 하나, 다른 언어들은 "가비지 컬렉터"라는 녀석이 대신 일을 해준다는 점입니다.

또다른 중요한 차이가 있는데, C++에서는 두가지의 메모리 영역이 있는데, 힙과 스택입니다. 프로세싱이나 자바, 파이선과 같은 언어에서는 모두 힙영역을 사용하게 되어있습니다.

나중에 따로 이 두 차이점을 살펴보겠지만 우선, 메모리가 무엇이고, 프로그램에서 변수를 생성하면 어떤일이 벌어지는지 알아보도록 합니다.

## 컴퓨터 메모리와 변수 ##

고 수준에서 컴퓨터 메모리가 어떻게 동작하는지 정도는 아시는것이 도움이 될것입니다.

컴퓨터는 다른 종류의 메모리를 갖고 있는데, 이 섹션에서는 RAM(Random Access Memory) 메모리에 대해 살펴보려고 합니다. 매 순간 무언가를 실앵하는 프로그램을 위한 명령과 이 프로그램이 사용하는 데이터를 저장하는 곳입니다.

여러분의 컴퓨터는 아마도 대략 4기가 정도의 램을 갖고 있을것입니다. C++에서는 메모리의 대부분에 접근할 수 있으며, 이를 위해 변수를 생성합니다. 메모리는 바이트(byte)로 나뉘어지는데, 이는 C++ 어플리케이션에서 일반적으로 사용할 수 있는 최소 메모리 사이즈입니다. char, int, float..와 같은 각각 데이터 타입은 byte를 단위로 서로 다른 크기를 갖습니다. 이들은 플랫폼마다 달라질 수 있지만, 대부분 아래와 같은 크기를 갖습니다:

	- char:  1 byte
	- short: 2 bytes
	- int:   4 bytes
	- float  4 bytes
	- double 8 bytes

배열이나 문자열과 같은 다른 타입들은 포함하고있는 내용에 따라 가변적인 크기를 가질 수 있습니다.

변수를 선언하는 예제는 아래와 같습니다:

```cpp
int i;
```

위의 예제에서 우리는, 4기가바이트 중 4바이트를 정수를 저장하기 위해 예약했습니다. 여기서 정수를 저장하든, 다른 데이터형을 저장하든 상관없습니다. int냐, char냐, float냐 혹은 string이냐에 따라 크기만 달라질 뿐, 메모리의 타입은 언제나 같습니다.

내부적으로, 컴퓨터는 메모리 영역에 대해서 `i`가 아닌, 메모리 주소로써 이해합니다. 메모리 주소는 4Gb의 메모리 내에서 특정 byte를 가리키는 숫자입니다.

`int i`와 같이 메모리를 생성하면, 프로그램에게 4byte의 메모리를 예약하라고 말하고, 이 4byte중 첫번째 byte의 메모리 주소를 변수명인 `i`와 연관시킨 뒤, 이 4byte에 우리가 저장할 데이터의 타입인 정수만 저장되게끔 제한시킵니다.

![Int i](images/int_i.svg "")

일반적으로 메모리 주소는 [16진수](http://ko.wikipedia.org/wiki/십육진법)로 표현됩니다. C++에서는 `&`연산자를 사용하여 메모리 주소를 얻을 수 있습니다. 아래와 같이요:


```cpp
cout << &i << endl;
```

위 cout의 결과가 바로 우리가 방금 생성한 변수 `i`의 첫번째 byte 메모리 주소입니다.

이후에 위 변수에 값을 할당하면, 변수를 선언함으로써 예약된 메모리 영역에 이 값이 저장됩니다. 따라서 우리가 아래와 같이 하면:

```cpp
i = 0;
```


메모리는 내부적으로 이렇게 보여집니다:

![Int i equals 0](images/int_i_equals_0.svg "")

int형인 byte들이 메모리 내에서 어떠한 순서로 구성되어지는지는 컴퓨터의 아키텍쳐에 따라 달라집니다. 아마도 [리틀 엔디안, 빅 엔디안](https://ko.wikipedia.org/wiki/%EC%97%94%EB%94%94%EC%96%B8)에 대해 어디선가 들어본 적이 있을겁니다. 이는 데이터형의 바이트들을 메모리에 나열할 때, 큰 단위를 앞에서 혹은 뒤에서부터 나열하는 것을 의미합니다. 대부분의 경우 이것에 대해서 알아야 할 필요는 없지만, 최신 현대 컴퓨터 아키텍쳐들은 리틀 엔디안을 사용합니다.

여러분이 C++ 언어를 사용해왔었다면, 아마도 잘못된 메모리 참조(bad memory access)로 인해 프로그램이 죽는 경험을 해보셨을 겁니다. 일반적으로 `segmentation fault...`라는 메시지를 뱉어냅니다. 이게 대체 무슨 의미일까요?

여러분이 프로그램에서 변수를 생성하면, 심지어 c++에서도, 보안상의 이유로 실제로 컴퓨터의 메모리에 접근할 수 없습니다. 웹브라우저에서 은행계좌를 열었다고 생각해봅시다, 만약 아무 프로그램이든 컴퓨터의 모든 메모리에 접근이 가능하다면, 특정 악성 프로그램이 브라우저의 메모리에 접근해 정보를 취득하거나 심지어 수정할 수 있을것입니다. 이를 방지하기 위해 운영체제에서는 모든 프로그램에 일정량의 메모리를 할당합니다. 여러분의 프로그램은 이 할당된 `일부`메모리에 접근할 수 있습니다. 나중에 변수를 하나 생성할 때, 이 `일부` 메모리에 충분한 메모리가 남아있다면, 여러분의 변수는 이곳에 저장됩니다. 만일 충분한 메모리가 이 `일부`영역에 남아있지 않다면, 운영체제는 어플리케이션에 새로운 메모리를 더 할당해주고, 이를 사용할 수 있게 합니다. 허나 만약 여러분이 여러분의 어플리케이션에 할당되지 않은 영역에 접근하려 하면, 운영체제는 보안상의 위험을 피하기 위해 어플리케이션을 죽여버립니다.

어떻게 일반적으로 발생하냐고요? 뭐, 배부분의 경우 이 숫자들로 메모리주소에 접근하지는 않죠, 그렇담 대체 어떻게 변수에 접근하는데 segmentation fault가 발생할까요. 대부분 이러한 상황의 경우는 더이상 존재하지 않는 변수에 접근하려고 할 때 발생합니다. 일반적으로 메모리에 포인터를 저장해두고 메모리를 해제하거나 혹은 다른 어딘가로 이동했을 때 말입니다. 이에 대해서는  나중에 좀더 자세히 다루도록 하죠.

## 스택 변수, 함수내의 변수 vs 오브젝트내의 변수

이 챕터의 초반부에서 언급했듯이, C++에서는 두가지 타입의 메모리가 있습니다, 바로 스택과 힙입니다. 우선 스택에 대해서 알아보도록 하죠. 스택은 가장 쉽게 사용할 수 있는  메모리 타입이자, 오픈프레임웍스에서 가장 자주 사용하게 될 메모리타입이기도 합니다.

스택은 포인터나 new 키워드를 사용하지 않은 한, 함수 안, 혹은 클래스의 .h 내에서 변수가 선언될 때 사용되는 메모리 타입입니다.

스택이라고 불리우는 이유는 이것이 [스택](https://ko.wikipedia.org/wiki/%EC%8A%A4%ED%83%9D)과 같이 구성되어있기 떄문입니다. 프로그램에서 함수를 호출할 때, 메모리 내부에는 함수**호출**로 할당된 메모리 영역이 존재합니다. 이 특정 함수**호출**이 존재하는 동안 이 영역에 변수들이 생성될 수 있습니다.

이러한 변수들은 함수호출이 끝날때 사라집니다. 따라서 아래와 같은 예제는 동작할 수 없습니다:

```cpp
void ofApp::setup(){
	int a = 0;
}

void ofApp::update(){
	a = 5; // setup의 바깥에서는 존재하지 않으므로 에러
}
```

또한 이 함수가 다시 호출된다 하더라도, 이전 함수 호출시에 스택변수에 저장되었던 값을 기대할 수 없습니다. 즉 스택변수에는 값을 저장할 수 없습니다.

일반적으로 블록내에서 선언된 변수는 해당 블록 내에서만 존재한다고 말할 수 있습니다. c++에서 블록이란 `{}`로 명시됩니다. 따라서 아래의 예제 또한 동작하지 않습니다:

```cpp
for (int i=0;i<10;i++){
	int a = 5;
}
cout << a << endl; // for{} 블록 바깥에서는 존재하지 않으므로 에러 
```

심지어 이렇게도 할 수 있습니다:

```cpp
void ofApp::setup(){
   {
		int a = 0;
		// do something with a
   }
	   {
		int a = 0;
		// do something with a
   }
}
```
위의 예제는 흔하지 않은 경우지만 함수 내에서 변수의 수명을 지정하기 위해 가끔 사용합니다. 대부분 이 변수들은 리소스를 갖고 있는 오브젝트이며, 특정한 기간에만 쥐고 있길 원할 때 사용하죠.

변수의 수명은 `변수영역(scope)` 이라고도 불립니다.

Apart from creating variables inside functions we can also create variables in the class declaration in our .h like:
함수 내에서 변수를 선언하는 부분을 .h파일의 클래스 선언부에서 변수를 선언하도록 분리해봅시다. 다음과 같이요:

```cpp
class Ball{
public:
	void setup();
	float pos_x;
}
```

이런 종류의 변수를 '인스턴스 변수' 라고 합니다. 이는 모든 클래스의 인스턴스나 오브젝트들은 카피되기 떄문입니다. 이러한 동작은 함수내에서 스택 변수들을 선언할떄의 동작과 완벽히 같습니다. 이들은 이들이 선언된 {} 내에서만 존재하며, 위의 경우 오브젝트의 {} 내에서 존재하게 됩니다.  

이러한 변수들은 클래스 내 어디에서든 접근이 가능하기 떄문에 이 데이터들이 필요할 경우엔, 위에서 선언한 클래스 오브젝트 내 함수를 통해서 접근할 수 있습니다.

스택 내의 메모리는 제한적인데, 사용하고 있는 컴퓨터의 아키텍쳐, 운영체제, 그리고 심지어 컴파일러에 따라서 사이즈가 달라집니다. 어떠한 시스템의 경우 어플리케이션이 실행중인 때에도 크기가 바뀌기도합니다. 하지만 대부분은 이 한계에 다다를 일은 없습니다. 

만일 모든 변수들을 스택에 생성했다 하더라도, 일반적으로 오브젝트들(예를들어 벡터라든가, 오픈프레임웍스의 ofPixels와 같은)은 내부적으로 컴퓨터에서 사용가능한 전체 메모리의 크기에 제한을 받는 힙영역을 사용하기 때문에, 우리가 걱정할 필요는 없습니다.

다음 섹션에서는 힙메모리가 어떻게 동작하는지, 그리고 힙과 스택을 사용할때의 장점들을 살펴보겠습니다.

## 포인터와 레퍼런스 ##

힙메모리에 대해 얘기하기 전에 우선, C++에서의 포인터와 레퍼런스가 어덯게 동작하는지, 사용 문법, 그리고 포인터나 레퍼런스를 사용할 때 실제로 메모리에서 어떻게 동작하는지에 대해서 살펴보도록 합니다. 

앞에서 보셨다시피 변수의 실제 메모리 주소를 얻기 위해서는 이렇게 하면 됩니다:

```cpp
cout << &i << endl;
```

이렇게 하면 변수의 타입과 상관 없이, 변수의 첫번째 바이트의 메모리 주소를 얻어올 수 있습니다.
이 메모리 주소를 다른 변수에 저장할 때, C++에서는 이것을 포인터라고 합니다. 문법은 이와 같습니다:

```cpp
int i = 0;
int * p = &i;
```

우리가 메모리에서 얻을 수 있는 것은 이와 같습니다:

	![Pointer](images/pointer.svg "")

포인터는 대체로 4 또는 8바이트를 차지하는데(32비트 혹은 64비트 프로그램을 사용하느냐에 따라 달라집니다), 여기서는 이해를 돕기 위해 그냥 1바이트로 표현하였습니다. 보시다시피 값을 직접 담는 대신 값을 가리키고 있는 메모리 주소를 담고 있다는 변수임을 알 수 있습니다. 그렇게 때문에 포인터라고 불리우는 것이죠.

포인터는 힙 또는 스택 메모리를 가리킬 수 있습니다.

이제, C++에서 프로그래밍을 할 때 아주 중요한 것들에 대해서 설명하고자 합니다. 지금까지 여러분이 봐왔던 것처럼, 아래와 같이 변수를 선언할때:

```cpp
int i;
```
메모리의 레이아웃은 다음과 같습니다:

![Int i](images/int_i.svg "")

보는 것과 같이, 이 메모리 영역에는 아무런 값이 없습니다. 프로세싱과 같은 다른 언어에서는 이와 같이 동작합니다:

```java
int i;
println(i);
```

(역자 주 : 내용이 조금 이상하므로 재확인이 필요)
이는 유효하지 않는데, 컴파일러는 초기화 됮 이낳은 변수를 사용하려 한다고 알려줍니다. C++에서는, 명백하게 유효하지만, 해당 변수의 내용은 지정되있지 않습니다. 대부분의 경우 0의 값을 갖고 있는데, 이는 운영체제에서 프로그램에게 메모리를 할당하기 전에 해당 메모리를 소거하기 때문입니다, 이는 보안적인 이유이기 때문이죠. 하지만 한번 할당된 뒤 다시 사용하는 메모리라면, 이 메모리 영역은 값을 유지하고 있으며, 결과적으로 프로그램은 지정되어있지 않게 됩니다.

is illegal, the compiler will tell us that we are trying to use a variable that is not initialized. In c++ though, that's perfectly legal but the contents of that variable are undefined. Most of the times we'll get 0 because the operating system will clear the memory before assigning it to our program, again, for security reasons. But if we are reusing memory that we had already assigned, then, that memory area will contain anything, and the results of our program will be undefined.

예를들어 뭔가를 그리기는데 위치를 지정하기 위해 변수를 사용한다고 할때, 초기화하는데 실패하면 그려지는 오브젝트들의 위치는 알 수 없게 됩니다.

대부분의 오브젝트들은 그들의 값을 초기화하는 기본 생성자를 가지고 있어서(예를들어 0으로 초기화), 일반적으로는 값을 줄 필요가 없습니다.

초기화되지 않은 포인터를 사요할때는 어떤일이 벌어질까요? 포인터는 메모리 주소를 담고 있기 때문에, 만약 가리키는 주소가 자신의 프로그램과 상관없는 영역인데다가 그 값을 얻거나 수정하려고 하면 운영체제는 세그멘테이션 폴트 신호와 함께 해당 프로그램을 강제로 죽여버립니다.

포인터로 다시 돌아와서, 포인터는 아래와 같이 생성합니다:

```cpp
int i = 5;
int * p = &i;
```
그리고 포인터를 직접 사용할려면 이렇게 사용하면 됩니다:

```cpp
cout << p <<< endl;
```

위의 결과는 값 5가 아닌, 메모리의 주소를 얻게 됩니다. 그렇다면 포인터가 가리키고 있는 값은 어떻게 얻어올 수 있을까요? `&`의 반대 연산자를 사용하면 됩니다: `&`는 가리키고있는 메모리의 주소를, `*`는 가리키고 있는 메모리주소의 실제 값을 알려줍니다.

```cpp
cout << *p << endl;
```

위와 같이 입력함으로써, 값 5를 출력할 수 있습니다. 또한 아래와 같이 해도 동일하게 동작합니다:

```cpp
int j = *p;
cout << j << endl;
```

j는 p가 가리키고 있는 값을 복사했기 때문에, 똑같이 값 5를 얻어올 수 있습니다.

`&`연산자는 *참조 연산자(레퍼런스 연산자, reference operator)*라고 합니다. 메모리 주소를 이용해 변수를  참조해주기 때문이죠, `*`연산자는 반대로, *역 참조 연산자(dereference operator*라고 하며, 포인터가 가리키는 값을 얻어올 수 있습니다, 메모리 주소 즉 참조의  역 참조인거죠. 따라서 주소 대신 값에 접근할 수 있게 됩니다.


지금까지는, int형으로 살펴봤습니다만, float, short, char, unsigned int...와 같은  다른 어떠한 원론적인 값과도 동일하게 동작합니다. 또한 오브젝트들과도 마찬가지입니다.

만약 Java를 사용해 온 분들이라면, Java와 C++에서 아래와 같은 상황을 겪어보셨을 겁니다:

```cpp
int a = 5;
int b = a;
a = 7;
cout << "a: " << a << " b: " << b << endl;
```

위의 코드는 동일하게 동작합니다(당연히 cout의 부분은 Java의 문법으로 바꿔줘야겠죠). `a`는 7이 되고, `b`는 5가 됩니다. 이것을 C++에서 오브젝트로 사용하보면, C++과 Java에서는 다르게 동작합니다. 예를들어 Ball클래스를 갖고 있다고 해봅시다:


```cpp
class Ball{
public:
    void setup();
    //...

    ofVec2f pos;
}
```

프로세싱에서는 아래와 같겠지요:

```java
class Ball{
    void setup();

    PVector pos;
}
```

C++에서 아래와 같이 하면:

```cpp
Ball b1;
b1.pos.set(20,20);
Ball b2;
b2 = b1;
b2.pos.set(30,30);
```

C++에서는 b1의 pos는 20, 20이, b2는 30,30이 되지만, Java에서는 b1과 b2가 동일하게 30,30이 됩니다:


```java
Ball b1 = new Ball();
b1.pos.set(20,20);
Ball b2;
b2 = b1;
b2.pos.set(30,30);
```

Java에서의 예제에서 첫번째 ball은 new를 사용했지만, second에서는 그렇지 않았다는 점에 유의하세요. Java에서 오브젝트는 힙영역을 가키리는 포인터역할을 하기 때문에, `b2 = b1` 부분에서 실제로 b2는 b1의 참조역할을 합니다. 그래서 나중에 b2의 값을 바꾸면, b1역시 함께 바뀌는 것이지요.

C++에서는, `b2 = b1`을 수행할때는 반대로, b1의 값을 b2로 복사하므로, 실제로는 참조대신 서로 다른 2개의 값을 갖고 있게 됩니다. 따라서 b2를 수정해도, b1의 값은 변화가 없습니다.

두 언어 모두 `=`의 의미는 `=`를 기준으로 우변의 값을 좌변의 변수로 복사한다는 의미입니다. 차이점이 있다면 Java에서는 오브젝트가 `b1` 또는 `b2`의 내용인 오브젝트의 메모리주소를 가리키는 포인터이지, 오브젝트 자체가 아니라는 것입니다. C++에서는 오브젝트 자체를 의미합니다. 

이것이 바로 Java와 C++에서의 메모리입니다:

![Objects Java C](images/objects_java_c.svg "")

보시다시피 C++에서 메모리 내의 오브젝트는 자신의 멤버변수일 뿐입니다. 이 오브젝트를 다른 변수에 할당하면, 기본적으로 C++에서는 `=` 우측의 오브젝트 전체를 좌측으로 복사합니다.

자 만약 이와 같은 클래스를 갖고 있고:

```cpp
class Particle{
public:
    void setup();
    //...

    ofVec2f pos;
    ParticleSystem * parent;
}
```

이렇게 한다면:

```cpp
Particle p1;
Particle p2;
ParticleSystem ps;

p1.pos.set(20,20);
p1.parent = &ps;
p2 = p1;
```

앞서 말했다시피, C++은 p1의 콘텐츠 자체를 p2로 복사하므로, p1이 갖고 있는 콘텐츠 즉 2개의 float인 x, y를 담고 있는 p1의 ofVec2f, ParticleSystem을 가리키는 포인터가 복사됩니다. ParticleSystem자체는 복사되지 않고, 그것을 가리키고 있는 포인터만 복사횝니다, 따라서 p2는 p2의 위치와, 같은 ParticleSystem을 가리키는 포인터가 복사되는 결과를 낳게 됩니다. 중요한건 단 하나의 particle system을 갖는다는 것이죠.

![Object pointers](images/object_pointers.svg "")

중요한 것은 디폴트로 복사되는 것과 오브젝트들이 스택에 저장되는데, 이것이 포인터를 사용하는 것에 비해 항상 장점을 갖고 있는 것입니다. 예를들어 아래와 같은 C++에서의 벡터 또는 particle의 배열과 같이 우리가 앞서 살펴봤던 예제를 살펴볼까요?:

```cpp
vector<Particle> particles;
```

메모리 내의 particle들은 서로 연속적이므로, 만약 이들을 실제 메모리의 서로 다른 위치에 있고 그것을 가리키는 포인터를 사용한다고 했을 때보다 훨씬 빠른 접근이 가능하다는 것입니다. 다른 챕터의 주제이지만 이는 또한 C++의 벡터를 openGL 메모리 구조로 쉽게 변환할 수도 있습니다.

또한 우리가 함께 알아두어야 할 사항은, 함수로 파라메터로써 오브젝트가 전달 될 때, C++에서는 디폴트로 복사된다는 점입니다. 예를들어:

```cpp
void moveParticle(Particle p){
    p.x += 10;
    p.y += 10;
}

...

Particle p1;
moveParticle(p1);
```

위는 완벽하게 유효한 코드이지만, 함수는 particle의 복사된 값을 전달받으므로, 이 값을 수정하더라도 원래의 값에 영향을 주지 않습니다.

이렇게 할 수 있습니다:

```cpp
Particle moveParticle(Particle p){
    p.x += 10;
    p.y += 10;
    return p;
}
...

Particle p1;
p1 = moveParticle(p1);
```

이렇게 하면, 함수에 particle의 복사본을 전달하여 그것의 값을 변경한 다음, 수정된 값을 리턴(이는 p1을 다시 복사한 값입니다)할 수 있습니다. 앞 문장에서 얼마나 많이 복사라는 말을 언급했지요? 컴파일러는 이 과정을 최적화 하기 때문에 작은 오브젝트들은 전혀 문제가 없지만, 이렇게 수행한다면 어떨까요 ?:


```cpp
vector<Particle> moveParticles(vector<Particle> ps){
    for(int i=0;i<ps.size();i++){
        ps[i].x += 10;
        ps[i].y += 10;
    }
    return ps;
}
...

vector<Particle> ps;
...
ps = moveParticles(ps);
```

만일 백만개의 particle을 갖고 있다면, 엄청나게 느려질 것입니다. 메모리는 cpu에 비해 엄청나게 느리므로, 복사에 관련된 무엇이든 혹은 메모리를 새로 할당하는 것들은 일반적으로 반드시 피해야할 사항입니다. 그렇다면 어떻게 하면 복사의 과정을 피할 수 있을까요?

포인터를 사용할 수 있지 않을까요?

```cpp
void moveParticle(Particle * p){
    p->x += 10;
    p->y += 10;
}

...

Particle p1;
moveParticle(&p1);
```

자, 여기 새로운 게 있네요, 여기서 오브젝트를 가리키는 변수들을 취하기 위해 . 대신 `->` 연산자를 사용했다는 사실에 주목해주세요. 포인터에서 오브젝트의 변수에 접근할 때 역참조를 사용하지 않으려면:

```cpp
(*p).x +=10;
```

`->` 를 사용할 수 있습니다.

```cpp
p->x += 10;
```

자 이렇게 오브젝트의 값을 복사하는 것 대신 포인터를 사용하여 문제를 해결 할 수 있습니다. 메모리주소의 참조를 전달하는 것이죠. 이렇게 하면 함수는 실제 원본을 수정할 수 있게 됩니다.

하지만 여기서 문제점이라고 한다면 문법이 이상해진다는 점입니다. 두번째 예시에서 벡터의 포인터를 전달한다고 하면 어떻게 될까요?:
The main problem with this is that the syntax is kind of weird, imagine how would look like if we passed a pointer for the second example, the one with the vector:

```cpp
vector<Particle> moveParticles(vector<Particle> ps){
    for(int i=0;i<ps.size();i++){
        ps[i].pos.x += 10;
        ps[i].pos.y += 10;
    }
    return ps;
}
...

vector<Particle> ps;
...
ps = moveParticles(ps);
```

Now, the function will look like:
함수는 이렇게 작성되어야 할것입니다:

```cpp
void moveParticles(vector<Particle> * ps){
```

여기서 문제는 벡터의 요소들에 접근하기 위해 []연산자를 사용할수 없다는 점입니다. ps는 포인터이지, 벡터가 아니니까요. 
게다가 아래의 코드는

the problem is that now we can't use the [] operator to access the elements in the vector cause ps is not a vector anymore but a pointer to a vector. What's more this

```cpp
ps[i].x += 10;
```

실제로 컴파일은 되지만, 메모리 엑세스 에러, 즉 세그멘테이션폴트를 발생시킵니다. 현재 ps는 포인터이고, 포인터를 사용할 때 '[]'는 벡터의 배열인것처럼 동작하기 떄문이죠!

would actually compile but would mostly sure give as a memory access error, a segmentation fault. ps is now a pointer and when using pointers the `[]' behaves like if we had an array of vectors!

이 부분에 대해서는 메모리 구조에 관한 섹션에서 더 깊게 설명하도록 하겠습니다. 하지만 포인터 문법이 아닌, 레퍼런스(참조)를 전달하는 방법을 살펴보도록 하죠. C++에서는 레퍼런스라 불리우며 이렇게 작성합니다:

We'll explain this in more depth in the section about memory structures, but let's see how to pass a reference that doesn't have pointer syntax. In c++ is called a reference and it looks like:

```cpp
void moveParticles(vector<Particle> & ps){
    for(int i=0;i<ps.size();i++){
        ps[i].pos.x += 10;
        ps[i].pos.y += 10;
    }
}

vector<Particle> ps;
...
moveParticles(ps);
```

이제 포인터 문법을 사용하지 않고 원본 오브젝트의 참조를 전달했지만, 일반적인 오브젝트와 마찬가지로 사용할 수 있음을 볼 수 있습니다.

Now we are passing a reference to the original object but instead of having to use pointer syntax we can still use it as if it was a normal object.

> 고급 사항 : 종종 함수에 오브젝트를 전달할 떄, 복사를 피하기 위해 레퍼런스를 사용하면서, 동시에 전달되는 오브젝트의 원본이 변경되지 못하도록 할 때가 있습니다. 그럴 때에는 아래와 같이 const를 사용하는 것을 추천드립니다:

> Advanced note: Some times we want to use references to avoid copies but still be sure that the function we pass our object to, won't modify its contents, in that case it's recommendable to use const like:

>
    ofVec2f averagePosition(const vector<Particle> & ps){
        ofVec2f average;
        for(int i=0;i<ps.size();i++){
            average += ps[1].pos;
        }
        return average/float(ps.size());
    }
    vector<Particle> ps;
    ...
    ofVec2f averagePos = averagePosition(ps);


> const를 사용하면 그것이 참조(레퍼런스)일 지라도 해당 변수를 수정하지 못하도록 합니다. 또한 추후 누구라도 해당 함수를 수정할 때에도 입력값(즉 파티클)이 수정되지 않고 유지되어야 한다는 점을 알게 할 수도 있습니다.

> const only makes it impossible to modify the variable, even if it's a reference, and tells anyone using that function that they can pass their data into it and it won't be changed, also anyone modifying that function knows that in the future it should stay the same and the input, the particle system shouldn't be modified.

파라메터 이외에, 참조(레퍼런스)는 몇가지 특별한 특성을 갖고 있습니다.
Outside of parameters, references have a couple of special characteristics.


첫 번째로, 한번 생성되면 레퍼런스의 내용은 수정할 수 없습니다. 예를들어 이렇게 작성할 수 있겠죠:
First we can't modify the content of a reference once it's created, for example we can do:

```cpp
ofVec2f & pos = p.pos;
pos.x = 5;
```

하지만 아래와 같이 레퍼런스 자체를 변경하려고 하면:
but trying to change the reference itself like in:


```cpp
ofVec2f & pos = p.pos;
pos.x = 5;
pos = p2.pos;  // 에러가 발생합니다, 레퍼런스는 선언부에서만 지정될 수 있습니다.
```

또한, 레퍼런스를 리턴할 수 있지만, 그 레퍼런스가 무엇을 가리키고 있는지에 따라서 좋지 않은 경우가 될 수도 있습니다:

Also you can return a reference but depending on what that reference it's pointing to it can be a bad idea:

```cpp
ofVec2f & averagePosition(const vector<Particle> & ps){
    ofVec2f average;
    for(int i=0;i<ps.size();i++){
        average += ps[1].pos;
    }
    average/=float(ps.size());
    return average;
}
```

위 코드는 실제로 컴파일이 됩니다만, 아마도 경우에 따라 동작하지만 이상한 값을 내뱉거나, 세그멘테이션폴트 오류가 날 것입니다. 여기서 보면 스택에 `average`라는 변수를 선언했기 떄문에 해당 변수는 메모리가 *삭제*될 것이고, 따라서 함수가 리턴하는 레퍼런스는 더이상 평균값을 갖고 있지 않는 메모리 영역일 것입니다. 어쩌면 덮어씌워진 이상한 값을 얻을 수 있을수도 있지만, 참조하고 있는 메모리 영역이 더이상 우리의 프로그램 영역이 아닐 수도 있지요.

Will actually compile but will probably result in a segmentation fault at some point or even just work but we'll get weird values when calling this function. The problem is that we are creating the variable `average` in the stack so when the function returns it'll be *deleted* from memory, the reference we return will be pointing to a memory area that is not reserved anymore for average and as soon as it gets overwritten we'll get invalid values or a pointer to a memory area that doesn't belong to our program anymore.

이것이 바로 C++에서 가장 골치아픈 문제점입니다. 댕글링 포인터(대롱대롱 매달린 포인터, dangling pointer)라고도 불리는 이것은 이미 해제되어버린 메모리 영역을 가리키거나 참조할때 발생합니다.
This is one of the most annoying problems in c++ it's called dangling pointers or in this case references and it's caused when we have a pointer or a reference that points to a memory area that is later freed somehow.

더 현대적인 언어들의 경우 다양한 방법으로 이러한 문제를 해결하는데, 예를 들어 Java의 경우 레퍼런스가 범위를 벗어나기 전까지는 오브젝트를 삭제하지 못하도록 했는데, 이는 그때그때 오브젝트의 메모리를 훓어보며 참조되는 메모리가 있는지를 확인하고, 만일 그렇다면 삭제하는 가비지 콜렉터라는 기법을 사용합니다. 이 방법으로 문제를 해결했지만 오브젝트가 실제로 언제 삭제되는지는 알기 어렵습니다. C++의 최신 버전 및 보다 더 현대적인 언어에서는 오브젝트의 소유를 지정하는 새로운 종류의 포인터를 사용하여 문제를 해결하는데, 이것은 스마트 포인터라는 것으로 이 챕터의 끝에서 다루도록 하겠습니다.

More modern langauges solve this with diferent strategies, for example Java won't let this happen since objects are only deleted once the last reference to them goes out of scope, it uses something called a garbage collector that from time to time goes through the memory looking for objects which have no more references pointing to them, and deletes them. This solves the problem but makes it hard to know when objects are going to get really deleted. c++ in its latest versions, and more modern languages try to solve this using new kinds of pointers that define ownership of the object, we'll talk about it in the latest section of this chapter, smart pointers.

## 힙(heap) 영역에서의 변수들##

이제 포인터의 문법과 그 의미를 알았으니, 힙 영역을 어떻게 사용하는지 살펴보겠습니다. 힙은 모든 어플리케이션이 함께 사용할 수 있는 메모리 영역이며, 어떠한 함수든 이 영역에 변수를 생성하고 다른 함수와 공유하여 사용할 수 있습니다. 힙영역을 사용하기 위해서는 새로운 키워드 `new`를 사용해야 합니다:

```cpp
Particle * p1 = new Particle;
```

프로세싱 혹은 Java언어에서 이와 비슷한 것을 본 경험이 있는 분들도 있을겁니다, 그렇죠? 요놈은 Java 오브젝트와 정확하게 같습니다: `new`키워드를 사용하면, 스택이 아닌, 힙에 변수를 선언합니다. `new`는 힙영역의 메모리 주소를 가리키는 포인터를 리턴하는데, C++에서는 `p1`변수에 어디에 기록할 것인지 정확히 명시해둘 필요가 있습니다. `p1`는 선언부에서 `*`를 사용했다시피 바로 포인터입니다.

If you know processing or Java that looks a little bit like it, right? indeed this is exactly the same as a Java object: when we use `new` we are creating that variable in the heap instead of the stack. `new` returns  a pointer to a memory address in the heap and in c++ we explictly need to specify that the variable `p1` where we are going to store it, is a pointer by using the `*` in the declaration.

오브젝트를 가키리는 함수 혹은 변수에 접근하기 위해서는, 이전에 살펴보았다 시피`->`연산자를 사용합니다. 따라서 이렇게 해야 합니다:

```cpp
Particle * p1 = new Particle;
p1->pos.set(20,20);
```

또는 이렇게 말이지요:

```cpp
Particle * p1 = new Particle;
p1->setup();
```

포인터는 여타 변수들과 마찬가지로 초기화 없이 선언이 가능합니다:

```cpp
Particle * p1;
p1->setup() // 이부분은 컴파일은 되지만, 실행되지 않을것입니다.
```

스택을 지역 메모리(local memory)라 한다면, 힙은 일종의 전역 메모리(global memory)라고 생각할 수 있습니다. 스택에서는 블록내에서만 소유할 수 있지만, 힙은 선언된 블록 범주 바깥에서도, 그리고 어떠한 함수에서도 레퍼런스(포인터)를 갖고 있는 한 접근이 가능합니다. 예를 들어볼까요:

We can imagine the heap as some kind of global memory as opposed to the stack being local memory. In the stack only the block that owned it could access it while things created in the heap outlive the scope in which they were created and any function can access them as long as they have a reference (a pointer) to them. For example:

```cpp
Particle * createParticle(){
    return new Particle;
}

void modifyParticle(Particle * p){
    p->x += 10;
}

...

Particle * p = createParticle();
modifyParticle(p);
```
`createParticle` 함수는 힙 영역에 새 `Particle`를 생성합니다. 따라서 이 createParticle함수가 종료되더라도 이 `Particle`은 여전히 존재합니다.
따라서 함수의 바깥영역에서, 다른 함수로 레퍼런스를 전달할 수 있습니다..

그렇다면, 해당 변수를 더이상 사용하고 싶지 않을때에는요? `delete`키워드를 사용합니다:
So how can we say that we don't want to use that variable anymore? we use the keyword `delete`:

```cpp
Particle * p1 = new Particle;
p1->setup();
...
delete p1;
```

이것은 힙 영역을 사용할 때 아주아주 중요합니다. 만약 이 부분을 건너뛰면, 메모리 누수(memory leak)라고 불리는 문제가 발생합니다. 어느곳에서도 참조되지 않는 메모리이지만 여전히 힙영역에 남아있어서, 컴퓨터에 사용가능한 메모리가 다 찰때까지 프로그램이 점점 더 많은 메모리를 계속해서 잡아먹기 떄문입니다:

This is important when using the heap, if we fail to do this we'll get with what is called a memory leak, memory that is not referenced by anyone but continues to leave in the heap, making our application use more and more memory over time till it fills all the available memory in our computer:

```cpp
void ofApp::draw(){
    Particle * p1 = new Particle;
    p1->setup();
    p1->draw();
}
```

위 예제에서, `draw`함수를 호출할 때, 새로운 particle을 생성하게 되는데, 매번 `draw`함수가 호출된 뒤 *p1 레퍼런스를 잃지만, new를 사용하여 할당된 메모리는 함수의 끝부분에서 해제되지 않았으므로, 프로그램은 조금씩 점점 더 많은 메모리를 사용하게 됩니다. 이는 시스템 모니터도구를 사용하여 확인할 수 있습니다. (역자 주 : 윈도우의 경우 작업 관리자, 맥의 경우 Activity Monitor)

every time we call `draw`, it'll create a new particle, once each `draw` call finishes we loose the reference *p1 to it but the memory we allocated using new is not freed when the function call ends so our program will slowly use more and more memory, you can check it using the system monitor.

앞에서 언급했듯이 스택 메모리는 제한적이므로, 가끔은 힙 메모리를 사용할 필요가 있는데, 가령 예를들어 백만개의 파티클을 스택에 생성한다면 stack overflow 문제가 발생할 것입니다. 따라서 일반적으로 대부분의 경우 C++에서는 적어도 힙을 직접적으로 사용하지 않고, vector, ofPixels 혹은 힙 메모리를 사용할 수 있는 다른 메모리 구조와 같은 클래스를 사용합니다. 하지만 여전히 stack의 개념을 사용합니다. 가령 아래와 같은 예를 살펴봅시다:

As we've mentioned before the stack memory is limited so sometimes we need to use the heap, trying to create 1 million particles in the stack will probably cause a stack overflow. In general, though, most of the time in c++ we don't need to use the heap, at least not directly, classes like vector, ofPixels and other memory structures allow us to use heap memory but still have stack semantics, for example this:


```cpp
void ofApp::draw(){
    vector<Particle> particles;
    for(int i=0; i<100; i++){
        particles.push_back(Particle())
        particles.back().setup();
        particles.back().draw();
    }
}
```

위 코드의 vector는 내부적으로 힙영역을 사용하지만, particles 변수가 범주를 벗어날 떄마다 vector의 소멸자(destructor)에서 메모리의 해제를 자동으로 담당해줍니다. (여기서는 현재 draw호출이 끝났을 때를 말합니다)

is actually using heap memory since the vector is internally using that, but the vector destructor will take care of freeing that memory for us as soon as the particles variable goes out of scope, when the current call to draw finishes.

## 메모리 구조, 배열과 vector ##

배열은 C++에서 오브젝트들의 집합체를 가장 쉽게 생성할 수 있는 방법입니다. C++의 다른 타입 또한 스택 혹은 힙에 생성할 수 있지만 말이죠. 비록 스택 내에서 배열은 크기의 제한이 있지만, 배열을 선언할 때 미리 크기를 지정해주어야 하며, 이후 크기를 변경할 수 없습니다.

Arrays are the most simple way in c++ to create collections of objects, as any other type in c++ they can also be created in the stack or in the heap. Arrays in the stack have a limitation though, they need to have a predifined size that needs to be specified in its declaration and can't change afterwards:

```cpp
int arr[10];
```

다른 타입들과 마찬가지로, 위의 선언부에서는 이미 10개의 정수형만큼의 메모리를 예약해두었는데, 여기서 우리는 new를 사용할 필요가 없으며, 이 메모리들은 초기화 되지 않습니다. 여기에 접근하려면, 이전 챕터에서 살펴보았듯이 이렇게 작성하면 됩니다:

the same as with any other type, the previous declaration already reserves memory for 10 ints, we don't need to use new, and that memory will be uninitialized. To access them, as you might know from previous chapters you can just do:

```cpp
int arr[10];
arr[0] = 5;
int a = arr[0];
```

if we try to do:
만약 아래와 같이 코드를 작성하면:

```cpp
int arr[10];
int a = arr[5];
```

a의 값은 배열이 생성된 이후 초기화 되지 않았으므로 undefined의 값을 같습니다.
또한 아래와 같이 작성하면:

```cpp
int arr[10];
int a = arr[25];
```

대부분의 프로그램은 죽게 되는데, 이는 arr + 25가 운영체제에서 프로그램에 할당해준 메모리의 범위를 벗어나기 때문입니다. 

가만, 방금 arr + 25라고 했죠? 이게 대체 무슨말이죠? 이전에 우리는 변수란 메모리의 특정한 공간이라고 했으며, 변수에 할당된 메모리의 첫번째 byte의 메모리 주소라고 했습니다. 배열의 경우 이와 정확히 똑같습니다. 예를들어 int형이 메모리에서 4byte를 차지하는것을 알고 있으므로, 10개의 길이를 갖는 int 배열은 40byte를 차지할 것이며, 이 byte들은 연속적으로 위치해 있습니다:

We've just said arr + 25? what does that mean? As we've seen before a variable is just some place in memory, we can get its memory address which is the first byte that is assigned to that variable in memory. With arrays is pretty much the same, for example since we know that an int occupies 4 bytes in memory, an array of 10 ints will occupy 40 bytes and those bytes are contiguous:

![Array](images/array.svg "")

메모리 주소는 16진수로 표시되므로, 40 == 0x0028이 됩니다. 자 이제 배열의 주소를 얻어와볼까요, 아래의 예시처럼 다른 변수들과 마찾가지로 `&`연산자를 사용하면 됩니다:

```cpp
int arr[0];
int * a = &arr[0];
```

배열의 첫 요소의 주소, 즉 배열의 주소를 얻어올 수 있습니다. 하지만 배열은 사실 포인터입니다:
That gives us the address of the first element of the array which is indeed that of the array, but with arrays, the same variable is actually a pointer itself:

```cpp
int arr[10];
int * a = &arr[0];
cout << "a: " << a << " arr: " << arr << endl;
```

위의 코드에서 a와 arr은 같은 값을 출력합니다. 즉 배열은 메모리 주소를 가리키는 포인터일 뿐입니다. 한가지 다른 점이 있다면, 해당 메모리 주소는 (즉 여기서는 10개의 정수를 위해 할당되기에 충분한) 예약된 메모리의 시작 주소라는 점입니다. 이 모든 정수들은 각각 인접해 있으므로, `arr[5]`에 접근하기위한 메모리의 주소는 배열의 주소 + 5개의 정수(int)크기가 됩니다. 만약 배열이 `0x0010`을 시작하고, 정수(int)형이 `4 byte`씩 차지한다고 하면, arr[5]의 주소는 `16` *(16진수로는 0x0010)* ` + 4 * 5 = 36`, 16진수로 `0x0024`가 됩니다. 실제로 코드에서도 동작합니다:

will print the same value for both a and arr. So an array is just a pointer to a memory address with the only difference that, that memory address is the beginning of reserved memory enough to allocate, in our case, 10 ints. All those ints will be one after another, so when we do `arr[5]` we are just accessing the value that is in the memory address of our array + the size of 5 ints. If our array started in `0x0010`, and ints occupy `4 bytes`, arr[5] would be `16` *(the decimal for 0x0010)* ` + 4 * 5 = 36` which in hexadecimal is `0x0024`. We can actually do this in our code:

```cpp
int arr[10];
arr[5] = 20;
cout << "&arr[5]: " << &arr[5] << "arr+5: " << arr+5 << endl;
cout << "arr[5]: " << arr[5] << "*(arr+5): " << *(arr+5) << endl;
```
이것을 포인터 연산이라고 하는데, 정말로 괴상하므로 대부분의 경우 이렇게 사용할 필요가 없습니다. 첫번째 줄cout에서 처음 출력되는 값은 `&`를 사용하여 `arr[5]`의 주소를 출력하는 것이고, 두번째는 첫번째 주소인 `arr`에 5을 직접 더해 `arr+5`를 출력합니다. 두번째 줄의 cout에서는 `arr[5]`를 사용해 메모리 위치의 값을 얻거나, `*`연산자를 이용하여 `arr+5`의 주소를 역참조 하여 값을 얻는 것을 보여줍니다.

now, that's really weird and most of the time you won't use it, it's called pointer arithmetic. The first cout will print the address in memory of the int at position 5 in the array in the first case using the `&` operator to get the address of `arr[5]` and in the second directly by adding 5 to the first address of `arr` doing `arr+5`. In the second cout we print the value at that memory location, using `arr[5]` or dereferencing the address `arr+5` using the `*` operator.

여기서 배열의 주소에 `5`를 더했는데, 이것은 byte를 더한것이 아니라, 해당 타입이 담고 있는 값의 byte크기라는 것에 주의하시기 바랍니다. 즉 `+5`는 실제로 `+20`byte인 것이지요. 아래의 코드로 확인할 수 있습니다:

Note that when we add `5` to the adress of the array it's not bytes we are adding but the size in bytes of the type it contains, in this case `+5` actually means `+20` bytes, you can check it by doing:

```cpp
int arr[10];
arr[5] = 7;
cout << "arr: " << arr << "arr+5: " << arr+5 << endl;
```

또한 계산기로 16진수값을 뺄셈해보시기 바랍니다. 만약 프로그램에서 아래와 같이 뺄셈을 해보면:
and substracting the hexadecimal values in a calculator. If you try to substract them in your program like:


```cpp
int arr[10];
arr[5] = 20;
cout << "arr: " << arr << "arr+5: " << arr+5 << endl;
cout << "(arr+5) - arr: " << (arr+5) - arr << endl;
```
`5`로 끝남을 알수 있습니다. 마찬가지로 언급했듯이 포인터 연산은 byte가 아니라 타입의 크기로 동작하기 때문입니다.

포인터 연산의 문법은 복잡할 뿐더러, 여기서 보여드린 예시들은 포인터 연산을 제대로 보여드린것은 아니지만, 배열이라는것이 단지 메모리에서 서로 연속되어 배치되어있다는 것을 알 수 있었으므로, 설령 여러분이 문법에 대해서 완벽하게 이해히지 못했다 하더라도 너무 걱정마시기 바랍니다. 아마도 이렇게 사용할 필요는 없을테니까요. 다만 배열변수는 포인터처럼 동작한다는 사실을 기억하시면 됩니다. 배열을 `[]`연산자 없이 취급할때에는, 그것이 메모리 주소이지, 그것이 담고 있는 값이 아니라는 것입니다.

The syntax of pointer arithmetics is kind of complicated, and the idea of this part wasn't really to show pointer arithmetics itself but how arrays are just a bunch of values one after another in memory, so don't worry if you haven't fully understood the syntax, it's probably something you won't need to use. It is also important to remember that an array variable acts as a pointer so when we refer to it without using the `[]` operator we end up with a memory address not with the values it contains.

지금까지 우리는 배열을 스택내에 생성했으므로, 커다란 배열을 사용할때 주의하지 않으면 문제가 발생할 수 있습니다.

힙 내에 배열을 생성할때에는 다른 방법과 마찬가지로 `new`키워드를 사용해야 합니다:

```cpp
int arr[] = new int[10];
```

or

```cpp
int * arr = new int[10];
```

보시다시피 앞서서 언급했던 사항을 다시한번 확인하고 있습니다. 배열 변수는 단지 포인터이므로 `new int[10]`이라고 하면, 10개의 정수형을 저장할 메모리를 할당한 다음, 해당 메모리의 첫번째(즉 배열의 첫번째 정수)의 byte 메모리 주소를 리턴하는데, 이것을 두번째 예제의 포인터 혹은 `int arr[]`(정해지지 않은 크기의 배열을 선언) 에 저장합니다.

As you can see this confirms what we've said before, an array variable is just a pointer, when we call `new int[10]` it allocates memory to store 10 integers and returns the memory address of the first byte of the first integer in the array, we can keep it in a pointer like in the second example or using `int arr[]` which declares an array of unkown size.

힙에 생성하는 다른 변수들과 마찬가지로, 수동으로 삭제해줘야 하기 때문에, 작업을 마친 후에는 `delete`키워드를 사용하여 메모리를 해제해야합니다. 힙에 배열을 생성하는 경우 문법은 약간 특별합니다:

```cpp
int arr[] = new int[10];
...
delete[] arr;
```
여기서 `[]`키워드를 사용하지 않고 삭제를 하면, (배열의) 첫번째 값만 해제를 하게 되며, 결국 메모리 누수를 일으킬 것입니다.


배열의 문법에는 몇가지 주의사항이 있습니다. 예를들어 아래와 같습니다:
There's also some problems with the syntax of arrays, for example this:


```cpp
int arr[10];
int arrB[10];
arrB = arr;
```

위의 코드는 컴파일 되지 않습니다. 또한 아래의 경우:


```cpp
int arr[] = new int[10];
int arrB[] = new int[10];
arrB = arr;
```

실제로 컴파일은 되지만, 다른 변수들과 마찬가지로 arr의 메모리 주소가 arrB로 복사하는 것이지, 실제 값이 복사되는 것이 아닙니다. 이러한 상황의 경우 두개의 포인터가 같은 메모리위치를 가리키고 있는 상황이 됩니다. arr과 arrB는 각자 메모리를 할당받았으나, arrB를 초기화했을때 할당된 메모리는 잃게 되는 상황이 발생하는 것이죠. 즉, 메모리 누수가 발생한다는 것입니다. `int arrB[] = new int[10]`에서 메모리를 할당받았지만, 이 메모리는 더이상 어떤 변수로부터 참조되지 않기 때문에 더이상 삭제할 수도 없습니다. 메모리를 복사하려면, memcpy라는 **c**(c++가 아닙니다)의 함수를 사용할 수 있지만, 문법이 좀 복잡합니다. 그렇기 때문에 C++에서는 vector를 사용하는것을 추천드립니다.

C++의 vector는 배열과 아주 비슷합니다. 메모리내에서의 레이아웃이 배열과 같죠. 값의 집합들이 메모리 내에 연속적으로 위치해 있으며, 항상 힙에 할당됩니다. 그러면서도 문법이 훨씬 훌륭하고 *스택 개념*입니다. vector에 10개의 정수를 할당하려면 아래와 같이 하면 됩니다:

```cpp
vector<int> vec(10);
```
또한 이 10개의 정수에 초기값을 주고 싶다면 아래와 같이 하면 됩니다:

```cpp
vector<int> vec(10,0);
```

또한 예를들어 vector를 다른 vector로 복사하고 싶다면, 아래와 같이 하면 됩니다. 생각하는 그대로 동작하지요:

```cpp
vector<int> vec(10,0);
vector<int> vecB = vec;
```

위 코드는 vec의 복사본을 vecB로 생성합니다. 

또한 만약 vector가 사용하는 메모리가 힙영역임에도 불구하고, 아래의 예시와 같이 vector가 scope 영역내에 선언되었으므로, vector자체는 스택에 생성되어있는데, 이 vector의 선언이 끝나 scope를 벗어나면, 자체적인 소멸자가 트리거되어 사용하고 있었던 힙 영역내의 메모리 삭제를 담당하게 됩니다. 

```cpp
void ofApp::update(){
    vector<int> vec(10);
    ...
}
```

이렇기 때문에 메모리를 일일히 관리해주지 않으면 허상 포인터, 메모리 누수와 같은 문제를 발생시킬 위험이 있는 배열에 비해서 vector를 사용하는 것이 훨씬 쉽습니다. 게다가 문법이 더 쉽지요.

vector는 이 외에도 더 많은 기능이 있는데, 성능향상을 꾀하거나 멀티스레딩 어플리케이션을 위해 사용할때에는 까다로운 경우가 대부분입니다만, 이러한 부분은 이 챕터의 범위를 벗어납니다. vector에 관한 튜토리얼은 [vectors basics](http://openframeworks.cc/tutorials/c++%20concepts/001_stl_vectors_basic.html)을 참고하시면 되는데, 오픈프레임웍스 사이트의 소개중 하나입니다. 또한 고급 개념에 관한 설명은 [std::vector](http://arturocastro.net/blog/2011/10/28/stl::vector/)을 참고하시기 바랍니다.

Vectors have some more features and using them properly might be tricky mostly if we want to optimize for performance or use them in multithreaded applications, but that's not the scope of this chapter, you can find some tutorials about vectors, this is an introductory one in the openFrameworks site: [vectors basics](http://openframeworks.cc/tutorials/c++%20concepts/001_stl_vectors_basic.html) and this one explains more advanced concepts [std::vector](http://arturocastro.net/blog/2011/10/28/stl::vector/)

## 다른 메모리 구조, 리스트와 맵 ##

이 외에도 메모리의 다른 오브젝트가 있다는 것은 대부분 우리가 원하는 다른 기능을 위한 것입니다. 메모리의 내용을 연속적으로 혹은 랜덤으로 접근하더라도 엄청 빠르게 동작하길 바라는것이죠. vecto는 내부적으로는 단순히 배열이므로, 가령 예를들어 20번째 위치에 접근하려고 하면, 실제 내부적으로는 첫번째 메모리 주소를 얻은 다음 거기에 20을 더하는 방식으로 접근하게 됩니다. 어떤 경우에는, vector는 최적화된 메모리 구조가 아닐 때도 있습니다. 예를 들어, vector의 중간위치에 빈번하게 어떠한 요소를 더하거나 삭제할 경우를 생각해봅시다. vector는 메모리의 스트립이라고 생각하면 됩니다. 즉 중간에 추가를 하면 추가한 위치부터 vector의 끝까지의 요소들을 우측으로 이동시킨 뒤, 비어있는 공간에 새 요소를 넣어야 하는 것이죠. 베보리에서는 이동시킨다는 개념이 없습니다. 인접한 메모리의 이동이라는 것은 복사를 의미하는 것이고, 이전에도 언급했듯이, 메모리의 복사는 상대적으로 느린 연산입니다.

![Vector inserting](images/vector_inserting.svg "")

간혹, 요소들을 한칸씩 우측으로 이동시킬때 이동/복사할때 메모리가 부족할 경우, vector 전체를 새로운 메모리 위치로 복사해야 합니다. 만약 이러한 작업을 수천개의 요소들로, 게다가 자주 하게 되면(예를 들어 매 프레임마다), 이는 엄청나게 느리게 동작할 겁니다.

이를 해결하기 위해서, 리스트와 같은 다른 메모리 구조가 있습니다. 리스트에서는, 메모리는 연속적이지 않은 대신, 각 요소들은 이전 및 다음 요소들을 가리키는 포인터를 가지고 있습니다. 따라서 새로운 요소를 삽입하면, 이 포인터들을 새로 추가되는 요소들을 가리키도록 해주면 됩니다. 리스트에서는 요소들을 이동시킬 필요는 없지만, 가장 큰 단점이라면 요소들이 메모리 내에서 연속적으로 위치해 있지 않으므로 vector에 비해서 살짝 느리다는 점입니다. 또한 반드시 연속적인 메모리를 요구하는 그래픽카드에 데이터를 업로드 해야 하는 상황과 같은 특수한 경우에도 사용할 수 없습니다. 

![List](images/list.svg "")

리스트의 또다른 문제점이라면, 리스트의 중간 요소들에 접근(랜덤 접근이라고도 합니다)하는 것이 느리다는 점입니다. 원하는 요소에 접근하려면 우리가 원하는 요소에 다다를때까지 리스트의 모든 요소들을 거쳐야 하기 때문이죠. 즉, 리스트는 리스트의 중간쯤에 빈번하게 추가/삭제를 하거나, 아주 가끔 랜덤한 위치에 접근할 필요가 있을때 사용합니다. 리스트의 상세 문법들은 [c++ documentation on lists](http://www.cplusplus.com/reference/list/list/)에서 확인하실 수 있습니다.

vector와 리스트 이외에도, C++의 표준 라이브러리 혹은 다른 C++ 라이브러리에는 몇몇 메모리 구조들이 있는데, 이중 맵(map)에 대해서만 간략히 살펴보도록 하겠습니다.

가끔은 요소의 위치에 관한 접근이 필요없거나, 정렬된 리스트를 가지는 것과 상관없지만, 인덱스 혹은 키와 같은 요소들의 딕셔너리로 접근이 필요한 때가 있는데, 이것이 바로 맵입니다. 맵에서는 요소들을 (키,값)의 쌍으로 저장하고, 키로 값을 찾을 수 있습니다. 예를들어서 이름을 갖는 오브젝트들의 집합이 있고, 각 이름이 유일하다고 해봅시다. 우리는 이것들을 맵으로 저장하고, 이것들을 이름으로 검색할 수 있습니다:

```cpp
map<string, NamedObject> objectsMap;

NamedObject o1;
o1.name = "object1";
objectsMap[o1.name] = o1;
```

이후, 아래와 같이 이름으로 오브젝트를 검색할 수 있습니다:

```cpp
objectsMap["object1"].doSomething();
```

주의해야 할 사항은, 만약 검색한 값이 존재하지 않는다면, `[]`연산자를 사용할때 새로운 오브젝트를 생성한다는 점입니다. 따라서 확실치 않을 경우, 일반적으로 우선 검색해보고, 값이 존재할때만 동작하도록 하는것이 좋습니다:


```cpp
if(objectsMap.find("object1")!=objectsMap.end()){
    objectsMap["object1"].doSomething();
}
```

맵에 관한 레퍼런스는 [c++ documentation for maps](http://www.cplusplus.com/reference/map/map/)에서 살펴볼 수 있습니다.

## 스마트 포인터 ##

이전에 말씀드렸듯, 전통적인 C 포인터들은 종종 문제를 발생시키는 *raw pointer*라고도 불리웁니다. 자주 발생하는 문제는 바로 허상포인터: 한때는 유효했지만, 유효하지 않은 메모리를 가리키고 있는 포인터로써, 널포인터를 역참조하려고 하고, 이 잘못된 메모리 주소를 잃기 전에 제대로 해제해주지 않으면 메모리 누수를 발생시킬 가능성이 있지요..

스마트 포인터는 우리가 스택 체계라고 불렀던 방식으로 메모리를 할당하는 것으로 문제를 해결하는데, 정확한 명칭은 RAII: [Resource Acquisition Is Initialization](http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization)라고 합니다. 이의 의미는 스택에 오브젝트를 생성하고, 나중에 사용할 리소스를 할당한다는 의미입니다.  변수가 유효범주를 벗어나  이것의 소멸자가 호출될때, 오브젝트의 소멸자는 사용된 모든 리소스를 반환합니다. RAII에는 더 많은 것들을 의미하고 있지만, 이것이 바로 이 챕터와 관련이 있다고 할 수 있습니다.

Smart pointers try to solve that by adding what we've been calling stack semantics to memory allocation, the correct term for this is RAII: [Resource Acquisition Is Initialization](http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization) And means that the creation of an object in the stack, allocates the resources that it'll use later. When it's destructor is called because the variable goes out of scope, the destructor of the object is triggered which takes care of deallocating all the used resources. There's some more implications to RAII but for this chapter this is what matters to us more.

스마트포인터는 이 기술을 사용함으로써 앞서 raw 포인터를 직접 사용했을 때 발생할 수 있는 문제들을 해결합니다. 오브젝트 혹은 할당된 메모리의 소유자가 누구인지를 더 잘 정의하는 방법을 사용해서 말이지요. Till now we've seen how things allocated in the stack belong to the function of block that creates them we can return a copy of them(or in c++11 or later, move them) out of a function as a return value but their ownership is always clear.

힙메모리를 사용하는 경우라면, 소유권은 훨씬 복잡해집니다. 만약 어떤 녀석이 입에 아래와 같이 변수를 하나 생성했다고 생각해봅시다:

```cpp
int * createFive(){
    int * a = new int;
    *a = 5;
    return a;
}
```

자, 다른 누군가가 저 함수를 호출했다고 하면, `new int`의 소유권은 누구에게 있을까요? 만일 다른 함수 혹은 오브젝트로 해당 메모리의 포인터를 전달한다고 하면? 이는 훨씬 복잡해집니다.


```cpp
// ofApp.h
int * a;
SomeObject object;

// ofApp.cpp
void ofApp::setup(){
    a = createFive();
    object.setNumber(a);
}
```

당최 해당 메모리의 소유자는 누가 될까요? ofApp? 오브젝트? 소유권이 무엇인가를 간단히 생각해보자면, 더이상 사용되지 않을 때, 해당 메모리를 지워야 할 책임이 누구에게 있는지라고 정리할 수 있을텐데, 지금 보면 ofApp와 오브젝트 모두가 해당 메모리를 참조하고 있습니다. 만약 오브젝트가 해당 메모리의 작업을 완료하기 전에 ofApp가 삭제를 해버린다면, 오브젝트가 삭제된 메모리 영역을 접근하려고 할것이고, 어플리케이션은 죽어버릴겁니다. 위의 예제에서는 ofApp이 오브젝트와 포인터인 int a 두 녀석으 알고 있으므로, 삭제를 책임질 필요가 있다고 볼 수 있는데요, 만약 아래와 같이 변경을 한다면 어떨까요? :
who is now the owner of that memory? ofApp? object? The ownership defines among other things who is responsible for deleting that memory when it's not used anymore, now both ofApp and object have a reference to it, if ofApp deletes it before object is done with it, object might try to access it and crash the application, or the other way around. In this case it seems logical that ofApp takes care of deleting it since it knows about both object and the pointer to int a, but what if we change the example to :


```cpp
// ofApp.h
SomeObject object;

// ofApp.cpp
void ofApp::setup(){
    int * a = createFive();
    object.setNumber(a);
}
```

혹은 심지어 아래와 같이 변경한다면요?:



```cpp
// ofApp.h
SomeObject object;

// ofApp.cpp
void ofApp::setup(){
    object.setNumber(createFive());
}
```

이 경우, ofApp는 할당된 메모리에 관해 아는게 없지만 
now ofApp doesn't know anymore about the allocated memory but both cases are possible so we actually need to know details of the implementation of object to know if we need to keep a reference of that variable to destroy it later or not. That, among other things breaks encapsulation, that you might now from chapter 1. We shouldn't need to know how object works internally to be able to use it. This makes the logic of our code really complicated and error prone.

스마트 포인터는 오브젝트의 소유권이 누구에게 있는지를 명확하게 정의하여, 소유자가 파괴되었을 때 할당되었던 메모리를 자동으로 삭제하여 문제를 해결합니다. 어떤 경우엔, 몇몇의 소유자들에게 하나의 오브젝트를 공유해야할 필요가 있습니다. 이러한 경우에 우리에겐 공유포인터(shared pointer)라고 불리우는, 특별한 타입의 스마트 포인터가 있습니다. 공유소유자를 지정하여 모든 소유자들이 변수를 사용하지 않을때에만 할당된 메모리를 해제합니다.

Smart pointers solve this by clearly defining who owns an object and by automatically deleting the allocated memory when the owner is destroyed. Sometimes, we need to share an object among several owners. For that cases we have a special type of smart pointers called shared pointers that defined a shared ownership and free the allocated memory only when all the owners cease to use the variable.

지금까지는 아주 간략하게만 살펴보았지만, 웹 상에는 이밖에도 스마트포인터의 사용방법 예제들과 레퍼런스들이 있습니다. 하지만 가장 중요한것은 raw pointer와 다르게 스마트포인터가 어떻게 소유권을 명확히 정의하여 문제를 해결하는지를 이해하는 것입니다.

We are only going to see this briefly, there's lots of examples in the web about how to use smart pointers and reference to their syntax, the most important is to understand how they work by defining the ownership clearly compared to raw pointers and the problems they solve.

### unique_ptr

unique_ptr은, 이름 그대로, 오브젝트의 유일한 소유권을 지정하는 포인터입니다. 
A unique_ptr, as it's name suggests, is a pointer that defines a unique ownership for an object, we can move it around and the object or function that has it at some point is the owner of it, no more than one reference at the same time is valid and when it goes out of scope it automatically deletes any memory that we might have allocated.

To allocate memory using a unique_ptr we do:

```cpp
void ofApp::setup(){
	unique_ptr<int> a(new int);
	*a = 5;
}
```

As you can see, once it's created it's syntax is the same as a raw pointer, we can use the `*` operator to dereference it and access or modify it's value, if we are working with objects like:

```cpp
void ofApp::setup(){
	unique_ptr<Particle> p(new Particle);
	p->pos.set(20,20);
}
```

We can also use the `->` to access it's member variables and functions.

When the function goes out of scope, since unique_ptr is an object, it's destructor will get called, which internally will call `delete` on the allocated memory so we don't need to call delete on unique_ptr at all.

Now let's say we want to move a unique_ptr into a vector:

```cpp
void ofApp::setup(){
	unique_ptr<int> a(new int);
	*a = 5;

	vector<unique_ptr<int> > v;
	v.push_back(a);  // error
}
```

That will generate a long error, depending on the compiler, really hard to understand. What's going on, is that `a` is still owned by ofApp::setup so we can't put it in the vector, what we can do is move it into the vector by explicitly saying that we want to move the ownership of that unique_ptr into the vector:

```cpp
void ofApp::setup(){
	unique_ptr<int> a(new int);
	*a = 5;

	vector<unique_ptr<int> > v;
	v.push_back(move(a));
}
```

There's a problem that unique_ptr doesn't solve, we can still do:


```cpp
void ofApp::setup(){
	unique_ptr<int> a(new int);
	*a = 5;

	vector<unique_ptr<int> > v;
	v.push_back(move(a));

	cout << *a << endl;
}
```

The compiler won't fail there but if we try to execute the application it'll crash since `a` is not owned by ofApp::setup anymore, having to explicitly use `move` tries to solve that problem by making the syntax clearer. After using move, we can't use that variable anymore except through the vector. More modern langauages like [Rust](http://www.rust-lang.org/) completely solve this by making the compiler detect these kinds of uses of moved variables and producing a compiler error. This will probably be solved at some point in c++ but for now you need to be careful to not use a moved variable.


###shared_ptr

As we've seen before, sometimes having unique ownership is not enough, sometimes we need to share an object among several owners, in c++11 or later, this is solved through `shared_ptr`. The usage is pretty similar to `unique_ptr`, we create it like:
앞에서 살펴본것처럼, 종종 유일한 소유권을 갖는것만으론 부족하기 때문에, 여러 소유자에게 오브젝트를 공유할 필요가 있습니다. c++11 또는 그 이후에서는, `shared_ptr`를 통해 이를 해결합니다. 사용법은 `unique_ptr`과 아주 흡사하며, 아래와 같이 생성할 수 있습니다:

```cpp
void ofApp::setup(){
	shared_ptr<int> a(new int);
	*a = 5;

	vector<shared_ptr<int> > v;
	v.push_back(a);
}
```

The difference is that now, both the vector and ofApp::setup, have a reference to that object, and doing:
여기서 차이점이 있다면, vector와 ofApp::setup 둘다 이 오브젝트에 대한 레퍼런스를 갖는다는 것입니다. 그리고 아래의 수행은:

```cpp
void ofApp::setup(){
	shared_ptr<int> a(new int);
	*a = 5;

	vector<shared_ptr<int> > v;
	v.push_back(a);

	cout << *a << endl;
}
```
완벽하게 동작합니다. shared_ptr의 동작방법은, 얼마나 많이 참조되는지 그 횟수를 유지하는 것입니다. 오브젝트의 복사본을 만들때마다, 카운터가 1씩 증가하며, 레퍼런스가 삭제되면, 카운터가 1씩 줄어듭니다. 레퍼런스 카운트가 0에 다다르면, 할당된 메모리를 해제합니다. 레퍼런스 카운트는 atomically하게 수행되는데, 이 말은 즉 카운트와의 문제 없이 shared_ptr를 스페르끼리 공유할 수 있다는 것을 의미합니다. 그렇다고 해서 멀티 스레드 어플리케이션에서 이것에 담겨있는 데이터를 안전하게 접근할 수 있다는 것은 아닙니다, 단지 다른 스레드끼리 shared_ptr를 전달하더라도, 레퍼런스 카운트가 틀릴 수 없다는 것 뿐입니다.

