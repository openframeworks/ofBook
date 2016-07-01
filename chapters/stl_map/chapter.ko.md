# Map과 함께 놀아봅시다, 정확히 std::map말이죠

*Joshua Noble에 의해 작성 *

## 소개 : map이 무엇인가요?

In the previous tutorial you learned about the std::vector but that's not the only kind of container that C++ provides for you. In fact, for almost any kind of data storage that you can think of, there's a container that's going to allow you to express it elegantly. In this little tutorial we're going to look at one that's really handy when you need something more specific than a vector. Maps are containers that store elements formed by a combination of a key value and a mapped value, following a specific order. If you've used Javascript or Ruby or Python you're already familiar with these and you've used them any time you want to do something like:

이전 튜토리얼에서는, std::vector에 대해서 배웠습니다만, C++이 제공하는 컨테이너는 그것만이 아닙니다. 사실, 여러분이 생각할 수 있는 데이터를 저장하는 어떠한 방법이라도, 그것을 우아하게 표현할 수 있는 컨테이너가 있습니다. 이 작은 튜토리얼에서는 여러분들이 vector보다 좀더 구체적인 뭔가가 필요할 때 정말 유용할 방법에 대해 살펴보고자 합니다. map은 특수한 방법에 따라 `키(key)와 값(value)`의 조합으로 이루어진 요소들을 저장하는 컨테이너입니다. 여러분중에 자바스크립트나 루비, 파이썬의 경험이 있으시다면, 이것들에 대해 이미 친숙하므로 이전에 언제든지 원하는대로 아래처럼 사용했을 것입니다:

```cpp
images["Portland"].draw();
```

간결하죠? vector를 훑어서 적절한 이미지를 찾을 필요 없이, 잠시 후에 살펴보겠지만, 데이터를 보다 편리하게 다루는 방법인 키(key)를 이용해서 데이터를 저장할 수 있습니다. 한번이라도 이렇게 시도해본 적이 있으신가요?:

```cpp
int theImageIWant, otherImageIWant;
vector<ofTexture> images;
```

아마도 map을 사용하는것을 고려하고 있는겁니다. 여러분이 말하려는것은 이것과 같기 때문이죠: 인덱스를 이용해서 오브젝트를 저장하는 좋은 방법이 필요해 (사실, 이게 바로 "키"입니다!) 따라서 나중에 키를 이용해서 얻을수 있어. 하지만 인덱스를 사용할때 vector를 재정렬하거나, 뭔가를 추가하기 시작할때나, 뭔가를 삭제하거나 하기 시작하면, 인덱스는 더이상 아무 의미가 없게되는 큰 문제가 생깁니다.  이렇게 하는것이 좀더 훌륭하지 않을까요?

```cpp
string firstImageKey = "Portland", secondImageKey = "Tokyo";
map<string, ofTexture> images;
```

이 방법은 몇몇 장점을 가집니다: "Portland"와 "Tokyo"는 map을 사용하여 무슨짓을 하더라도, 이름이 사람이 읽을 수 있기 때문에 항상 같은 ofTexture를 가리킬 것입니다: 그냥 읽으면 그게 뭔지를 알 수 있죠. 아주 간단한 예제를 살펴보도록 합니다. ofApp.h파일에서, 아래와 같이 추가하였습니다.

```cpp
map<string, ofImage> images;
```

이 말은 "이미지들을 문자열 키로 저장하겠다."라고 하는것입니다. 
cpp파일에서, 이렇게 작성할 수 있습니다:

```cpp
void ofApp::setup(){
    // 저장하기 위해 2개의 이미지를 만든다 
    ofImage pImage;
    pImage.loadImage("portland.jpg");
    
    ofImage tImage;
    tImage.loadImage("tokyo.jpg");
    
    // 이제 이것들을 훌륭한 이름으로 저장한다
    images["Portland"] = pImage;
    images["Tokyo"] = tImage;
}

void ofApp::draw(){
    // 이제, 이름으로 이미지들에 접근할 수 있다.
    images["Portland"].draw(0, 0, 100, 100);
    images["Tokyo"].draw(100, 0, 100, 100);
}
```

You can see how, though this isn't the most powerful example of that, that it might be really nice to be able to keep track of things by something concrete that will keep it's "location" no matter what. So, in a general sense in a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this key. What kinds of things can you use as a value? Anything. Really, anything can be a value. You will want to be careful storing pointers, but unlike a vector, once inserted into a map objects don't move around even if other elements are added or removed, however, storing pointers is good, especially if you're working with lots of textures or other large data objects. Make sure you don't invalidate your pointers (i.e. delete the object that is being pointed to) and you'll be good to go.

이 예시가 map의 아주 강력한 예제는 아닐지는 모르겠지만, 아주 굳건하게 데이터의 "위치"를 유지할 수 있다는 것이 정말 훌륭하다는 것을 알 수 있습니다. map에서는 이 키와 함께 매핑된 값이 저장되므로, 정렬이나 요소를 확인할 때에 대개 키값이 사용됩니다. 값으로 어떠한 것들이 가능하냐구요? 뭐든지 가능합니다. 정말로 뭐든지 값으로 사용될 수 있습니다. 포인터를 저장할때에는 조심해야겠지만, vector와 달리, 한번 map에 삽입된 오브젝트는 다른 요소들이 추가되거나 삭제되더라도 움직이지 않습니다. 하지만 포인터를 저장하는것도 좋습니다. 특히 엄청난 양의 텍스쳐나 다른 거대한 데이터 오브젝트들을 다룰 때 말이죠. 포인터를 확실히 유효하게 유지한다면 (예를들어 가리키고 있는 오브젝트를 지워준다든가 하여서) map에 포인터를 저장해도 좋습니다.

## map에 값 삽입하기

뭔가를 추가할려면, 이렇게 합니다:

```cpp
 map[key] = value;
```

맵에 추가된 오브젝트를 보는 방법이 하나만 있는것은 아닙니다. map안의 각 요소들은 쌍으로 이루어져 있습니다. 쌍은 키, 값 부분의 조합으로 이루어져 있죠. 
이 쌍의 선언은 그저 map 자체의 선언처럼 보여집니다:

```cpp
typedef pair<const Key, T> value_type;
```
아직 특별하게 나타나진 않는군요, 하지만 잠시 기다려봅시다.
map에 요소를 추가하는것이 map에 쌍을 추가한다고 생각해보자구요. 
C++에서는 이를 위해 다른 방법을 사용합니다. 3개의 도시를 인스턴스화 해봅시다.

```cpp
ofImage bImage;
bImage.loadImage("Berlin.jpg");

ofImage lImage;
lImage.loadImage("London.jpg");

ofImage pImage;
pImage.loadImage("Paris.jpg");
```
이것들을 어떻게 map에 추가할까요? 가장 일반적인 방법중 하나는 `make_pairs`와 `insert`메소드의 조합을 사용하는 것입니다.

```cpp
images.insert(make_pair("Berlin", bImage));
```
또한 `insert`와 `pair`를 사용할 수 있습니다.


```cpp
images.insert(pair<string, ofTexture>("London", lImage));
```
또는 std::pair 구조를 사용할 수 있습니다.

```cpp
images.insert(map<string, ofTexture>::value_type("Paris", pImage));
```

## map에서 요소 삭제하기

map에서 요소를 삭제할려면, `erase`를 사용합니다.
```cpp
images.erase("London");
```

map을 완전히 비울려면, `clear`를 사용합니다.
```cpp
images.clear();
```

## map을 훑기 

자, 이제 우리는 map에 뭔가를 넣거나 얻어올 수 있습니다. 하지만 그것을 훑으며 살펴볼려면 어떻게 해야하죠? vector처럼 정수를 사용하여 훑을수는 없습니다. 따라서 iterator를 사용해야 합니다. 자, 잠시 map과 키/값의 쌍은 잠시 놓아두고 iterator에 대해서 애기해보도록 하죠. 왜냐하면 iterator는 map을 보다 더 쉽게 사용할수 있게 해주기 때문이죠:


iterator는 C++의 std 버전 포인터입니다. 이것을 컨테이너에서 위치를 가리키도록 사용하고 있죠. 마치 vector에서 인덱스로 관심있어하는 레퍼런스를 추적하듯이 말이죠. iterator는 인덱스 같은 것입니다만, 이 녀석은 그보다 더한 vector 내의 오브젝트 입니다. 모든 컨테이너는 컨테이너의 시작(첫번째 요소)을 가리키고 있는 iterator를 리턴하는 begin()함수와, 컨테이너의 끝에 해당하는 iterator를 리턴하는 end()함수를 가지고 있습니다. 한번 for 반복문과 iterator로 코드를 상성하여 얼마나 이것이 조금 더 나은지 살펴봅시다:

```cpp
map<float,string>::iterator it; // make the iterator, say it's going to iterate over a map<float, string>
for ( it = aMap.begin(); // say the iterator should point to the beginning of a map called "aMap"
      it != aMap.end();  // say let's stop when we get to the end aMap
      ++it) {            // increment the iterator
}
```
ofimage의 vector를 위한 iterator는 이와 같을 것입니다: `vector<ofImage>::iterator`. 문자열 키와 ofMatrix4x4값으로 이루어진 map을 위한 iterator는 이와 같습니다: `map<string, ofMatrix4x4>::iterator`. iterator를 앞으로 이동할려면 ++를, 반대로 이동할려면 --를 사용합니다. 흥미로운 사실은: iterator를 두단계만큼 앞으로 이동할려면 (it,2), 앞으로 20만큼 이동할려면 (it, 20)을 사용할 수 있다는겁니다. 굳이 절대 이렇게 할 필요가 없지만 말이죠. 좋습니다, 다시 map으로 돌아와서, 우리의 map을 iterator로 훑어서 화면에 그것들을 그려봅시다:

```cpp
void ofApp::draw(){
    int xpos = 0;
    for (map<string, ofTexture>::iterator it=cities.begin(); it!=cities.end(); ++it){
        // it->first contains the key
        cout << " this is the key " << it->first << endl;
        // it->second contains the value
        it->second.draw(xpos, 0, 100, 100);
        xpos+= 100;
    }
}
```
자, 저 iterator가 무엇을 가리기고 있지요? 쌍이죠, 위의 경우, `string, ofTexture`입니다. 이와 같이요 :

```cpp
pair<string, ofTexture> p;
```

C++ 11에서는 map을 훑는 단축방법인 `auto`를 제공합니다. 이런식으로 사용할 수 있습니다:

```cpp
for (auto& pic : images )
  cout << pic.first << endl;
```

여기서 `pic->first`가 아닌 `pic.first`를 사용하였다는 것을 기억하세요. 이는 앞의 예제에서처럼 포인터가 아닌, `pic`이 쌍을 참조(`&`입니다)하고 있기 때문입니다.
이 경우, map을 훑으면서 map의 값을 변경할 수 있습니다. 
하지만 만약 map에서 값을 변경하는것이 아니라, 단순히 값을 읽기를 원한다면요? 
이러한 경우 `constant`키워드를 사용합니다. 이 키워드를 사용하면 어떠한 map의 값들도 변경되지 않습니다.

```cpp
for (const auto& pic : images )
  cout << pic.first << endl;
```

## map에서 요소 찾기

`find`가 아니라면 어떤 메소드 이름이 map에서 요소를 검색하는 키워드로 사용될까요?

```cpp
  if (cities.find("Berlin") != cities.end())
    cout << it->first << " founded!" << endl;
  else
    cout << "city not found" << endl;
```

end()가 호출되는걸 보셨죠? 이는 find()역시 실제로 iterator를 리턴하기 때문입니다. 따라서 만약 map내에 요소가 있다면 그것을 가리키는 iterator를 얻을것이며, 만약  그렇지 않다면, iterator의 끝을 가리키는 iterator를 얻게 될 것입니다. map에서 제공하는 다른 메소드들은 약간 축약된 리스트로 살펴보겠습니다:

## map에 오브젝트 저장하기

map에서 키를 사용하여 어떤 작업들을 할 수 있을까요? 흠. 분명 여러분이 하고싶은 모든걸 할수 있을것입니다: 문자열, float, 같은것들요. 비록 약간의 제약이 있지만, 아래와 같은 것들을 시도할 수 있을겁니다:

```cpp
map<ofVec2f, string> locations;
```

그리고 이것은 상당히 애매한 에러를 내밷을 것입니다, 이러한 것들처럼요: "/usr/include/c++/4.2.1/bits/stl_function.h:227:20: error: invalid operands to binary expression ('const ofVec2f' and 'const ofVec2f')". 이것은 사실 vector에서 "보다 작은(<)" 의 개념이 다소 이상하기 때문에 그렇습니다. 이것에 대한 수학적 정의가 있습니다만, 상식적으로 맞지 않고, 수학적으로도 맞지 않은 상식이죠. 하지만 이게 중요한게 아닙니다.  중요한 것은, "<" 연산자같은 것들이 키로 사용될 수 있다는 점입니다. 하나를 만들어보죠:

```cpp
class vec2Key
{
    
public:
    
    float x, y;
    
    vec2Key( float xValue, float yValue )
    {
        x = xValue;
        y = yValue;
    }
    
    bool operator < ( const vec2Key& other) const
    {
        if ( x == other.x ) {
            return y < other.y;
        }
        
        return x < other.x;
    }
    
};
```

< 연산자를 봅시다. 이것은 map이 갖고 있는 모든 값들을 어떻게 관리할지 알려주기 때문에 키입니다. 따라서 값들을 상대적으로 빨리 훑을 수 있습니다. map은 일반적으로 하는 역할때문에 레드-블랙 트리의 종류라고 할 수 있습니다.([한번 읽어보세요:레드-블랙트리](https://ko.wikipedia.org/wiki/%EB%A0%88%EB%93%9C-%EB%B8%94%EB%9E%99_%ED%8A%B8%EB%A6%AC)). 좋습니다. 우리에겐 사용할수 있는 키 오브젝트를 갖고 있으니, 계속 진행하여 사용해봅시다:


```cpp
vec2Key k1(100, 200, 1);
vec2Key k2(100, 300, 1);
vec2Key k3(100, 400, 1);

map<vec2Key, string> stringToLocation;

stringToLocation[k1] = "first";
stringToLocation[k2] = "second";
stringToLocation[k3] = "third";
```

좋습니다, 테스트해봅시다:

```cpp
cout << stringToLocation[vec2Key(100, 300)] << endl; // prints "second", all good
```

리스트에 추가되는 그것이 다른 것들보다 클지 작을지는 아무도 모릅니다. 현재 우리가 괴상한 쿼드트리(역자 주:자식노드가 4개인 트리)같은 것을 하고 있으로, 애매한 방법으로 살펴보도록 하죠. < 연산자가 좀더 많은 일을 할 수 있도록 만들 수 있습니다. 우리의 vector에게 좀더 유동적으로 비교하는 연산자를 제공해봅시다:

```cpp
    bool operator < ( const vec2Key& other) const
    {
        if ( fabs(x - other.x) < 0.1 ) {
              return fabs(y - other.y) > 0.1;
        }
        
        return x < other.x;
    }
```

이제:

```cpp
 cout << stringToLocation[vec2Key(100.01, 299.99)] << endl; // 100, 300은 모두 < 0.1만큼 차이가 나므로 "second"를 리턴합니다.
```


## multimap이란 무엇인가요?

I`map`의 각 키는 유일합니다. 이는 즉 앞에서 봤던 map `map<string, ofTexture> images`에서 두 도시의 image가 같은 이름의 키를 갖는 것이 불가능하다는 의미입니다. "London"과 같이요.
`multimap`에서는, 이러한 규칙이 없습니다. `multimap`은 같은 키로 이루어진 쌍을 포함할 수 있습니다. 예를 보죠:

```cpp
  multimap<string, int> coldestCities;
  coldestCities.insert(make_pair("moskow",2015));
  coldestCities.insert(make_pair("chicago",2014));
  coldestCities.insert(make_pair("moskow",2013));
  coldestCities.insert(make_pair("moskow",2012));
  coldestCities.insert(make_pair("helsinki",2011));

  cout "coldest cities in the last 5 years" << endl;
  cout "disclaimer: this data are just an example" << endl;

  for (const auto& cityYear : coldestCities )
    cout << cityYear.first<< "year: "<< cityYear.second << endl;
```
map을 사용할때에는 키는 한번만 등장하였지만, multimap을 사용할때에는 이러한 디테일은 필요없습니다.

## 다른 유용한 메소드들

`empty` - 컨테이너가 비어있으면 true를, 그렇지 않으면 false를 리턴합니다.

`size` - map의 요소들의 갯수를 리턴합니다.

`lower_bound` - 이는 추어진 값보다 작지 않은 요소(주어진 값)로 iterator를 되돌립니다.

`upper_bound` - 주어진 값보다 큰 첫번째 요소로 iterator를 리턴합니다.

As an example of these two:

```cpp
map<float, string> floatToString;

floatToString[3.14] = "PI";
floatToString[2.71] = "E";
floatToString[2.29] = "UPC";
floatToString[0.83] = "Gauss's constant";

cout << floatToString[0.83] << endl;

map<float, string>::iterator lb = floatToString.lower_bound(2.6);
map<float, string>::iterator ub = floatToString.upper_bound(2.8);
```

이로써 std::map에 대한 탐험을 마쳤습니다. map에 관한 완성된 설명을 원하신다면, [cppreference](en.cppreference.com/w/cpp/container/map)를 읽어보십시오. <!-- 계속 전진하시고, 적절한 곳에 사용해보십시오. -->


## 추가 참고 자료 (역자에 의해 추가됨)
stl::map과 관련된 자료는 한빛미디어서에 제공하는 [C++ STL::map](http://www.hanbit.co.kr/network/view.html?bi_id=1618)에서도 보실 수 있습니다. <br/>
혹은 소프트웨어공학연구소에서 제공되는 [C++고급과정](http://soen.kr/lecture/ccpp/cpp4/cpp4.htm)중에서 41장-2절의 맵 부분을 참고하실 수도 있습니다.
