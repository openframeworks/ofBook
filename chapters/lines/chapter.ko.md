# 선 그리기

*[Davide Prati](http://edapx.com) 작성

## 소개 ...

이 튜토리얼에서는 오픈프레임웍스에서 어떻게 선을 그리는지에 대해 살펴볼것입니다. 튜토리얼에서 사용되는 코드의 대부분은 [이곳](https://github.com/ofZach/VAW_workshop/tree/master/drawingWorkshop)이며, [Zach Lieberman](http://thesystemis.com/)에 의해 열린 워크샵에서 사용되었습니다.

선은 아마도 그리기 중 가장 추상적이고 기본적인 형태일것입니다. 아이들에게는 그리는것을 배울때엔 이것이 가장 먼저일 것이며, 역시 우리들에게도 표현에 뭔가를 그리기엔 가장 본능적인 방법중 하나이지요. 하지만 결국엔, 이것은 점들을 서로 연결한 것입니다; 오픈프레임웍스는 점을 연결해 선을 쉽게 그릴 수 있는 클래스를 제공하고 있습니다: [ofPolyline](/documentation/graphics/ofPolyline/)이죠. 어떻게 사용하는지 한번 살펴보도록 합시다!

## 선 그리기
이 예제에서는 간단히 마우스를 드래그하여 선을 그릴 것입니다. 이를 위해 점의 컨테이너를 만드는 것부터 시작해보죠. 프로젝트 생성기로 새 앱을 만들고 `App.h`파일에 아래의 코드를 추가합니다:

```cpp
ofPolyline line;
```

`setup`, `draw`, `mouseDragged` 그리고 `mousePressed`를 아래와 같이 작성합니다:

```cpp
void ofApp::setup(){
    ofBackground(0,0,0);
}

void ofApp::draw(){
    line.draw();
}

void ofApp::mouseDragged(int x, int y, int button){
    ofPoint pt;
    pt.set(x,y);
    line.addVertex(pt);
}

void ofApp::mousePressed(int x, int y, int button){
    line.clear();
}
```

가장 흥미로운 일은 `mouseDragged`메소드에서 벌어집니다. 마우스 왼쪽버튼을 누르고 드래그하면, 마우스 위치에 대응되는 좌표의 점이 `ofPolyline`의 `line`인스턴스에 추가됩니다. `line.draw()`를 호출하면, ofPolyine은 자동으로 점들을 연결해 화면에 선을 그립니다. 마우스버튼을 떼면, `line.clear()`가 이전에 추가됐던 점들을 모두 삭제하고, 새 선을 그릴 준비를 합니다.



## 약간의 노이즈A bit of noise 

Once that we have the points in the `ofPolyline` we can edit them in the `update` method, before drawing them. Let's move the points one pixel up or down along the x and y axis. Edit the `update` method as follow:
`ofPolyline`에서 점들을 갖게 되면 그것들을 그려내기 전에 `update`메소드에서 이것들을 편집할 수 있습니다. x, y축으로 이 점들을 이동시켜봅시다. `update`메소드를 아래와 같이 작성합니다:

```cpp
for (auto &vert : line.getVertices()){
    vert.x += ofRandom(-1,1);
    vert.y += ofRandom(-1,1);
}
```
You should see something like this:

![line noise](images/line-noise.gif)

Note the `&` in the loop. If we would have ommit it, we wouldn't have been able to edit the position of the vertices. The `&` is telling to c++ that we are using a reference of the vertice contained in the `ofPolyline`, and we need a reference because we want to change the values inside the `ofPolyline`. When you simple want to read the values of the point inside the `ofPolyline`, do not use `&`. When you want to edit them, like in this case, use it.

## A web of lines 

Let's try something more complex. In this example we are going to create lines with `ofDrawLine` an `ofPoint`. Create a new app with the project generator and edit the `ofApp.h` file as follow:
```cpp
#include "ofMain.h"

class Line {
public: 
    ofPoint a;
    ofPoint b;
};

class ofApp : public ofBaseApp{

  public:
    // ...
    //leave everything as it is
    // ...
    vector < ofPoint > drawnPoints;
    vector < Line > lines;
};
```
In this header file we have defined a new class, the class `Line`. This class simply consist of 2 points, `a` and `b`, this 2 points define where the line begins and where the line ends. We have also defined two new [vectors](/tutorials/11_c++%20concepts/001_stl_vectors_basic/), `drawnPoints`, and `lines`. In the `App.cpp` file we are going to see why we need them:

```cpp
void ofApp::setup(){
    ofBackground(255,255,255);
}

void ofApp::draw(){
    ofEnableAlphaBlending();
    ofSetColor(30,30,30,30);
    
    for (auto line : lines) {
        ofDrawLine(line.a, line.b);
    }
}

void ofApp::mouseDragged(int x, int y, int button){
    for (auto point : drawnPoints){
        ofPoint mouse;
        mouse.set(x,y);
        float dist = (mouse - point).length();
        if (dist < 30){
            Line lineTemp;
            lineTemp.a = mouse;
            lineTemp.b = point;
            lines.push_back(lineTemp);
        }
    }
    drawnPoints.push_back(ofPoint(x,y));
}
```
The `draw()` method is pretty easy, we use the `Line` class that we have created in the header file to obtain the values of the point `a` and `b`. Then we use `ofDrawLine` to connect them. `ofDrawLine` simply draws a line from one point to another.
The `mouseDragged` method is a bit more complex. Let's start from the easyest part, `drawnPoints.push_back(ofPoint(x,y))`. Everytime we drag the mouse, we are saving the position of the mouse in the `drawnPoints` vector. This vector is like the history of all the movements of the mouse on the screen. Now let's have a look at the loop that starts with `for (auto point : drawnPoints)`. In this loop we are taking the current position of the mouse `ofPoint mouse`, and we are confronting it with all its previous position. If the distance between the current position and a previous position is less than 30 pixel, we create a `Line lineTemp` that connects the position of the mouse with the point in the history vector `drawnPoints` which distance is less than 30px. After that we push the `Line` in the `lines` vector, ready do be drawned on the screen.
Try to move the mouse around, you should be able to draw something like this.

![webby drawing](images/web.png)


## Make a smooth line in movement in a 3D space
Now that we know how to use `ofPolyline`, we can combine it togehter with `ofNode`, and draw a lines that moves smoothly on the screen. `ofNode` is a class that defines a point in a 3D space and can be chained to other nodes. If we make 2 nodes, A and B, and we difne the node A as a parent of B. moving the A node will also move the node B. Let's see how `ofNode` and `ofPolyline` can play together. First, edit your `App.h` file as follow:

```cpp
ofNode baseNode;
ofNode childNode;
ofNode grandChildNode;
ofPolyline line;
ofEasyCam cam;
```
The `EasyCam` class is used to see a scene in 3D space. Dragging the mouse around will allow you to move the camera around your scene. You do not need to worry for now about how does that work, `EasyCam` is taking care of everything. Now, edit the `App.cpp` file as follow:

```cpp
void ofApp::setup(){
    ofEnableDepthTest();
    baseNode.setPosition(0, 0, 0);
    childNode.setParent(baseNode);
    childNode.setPosition(0, 0, 200);
    grandChildNode.setParent(childNode);
    grandChildNode.setPosition(0,50,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    baseNode.pan(1);
    childNode.tilt(3);
    
    line.addVertex(grandChildNode.getGlobalPosition());
    if (line.size() > 200){
        line.getVertices().erase(
                                 line.getVertices().begin()
                                 );
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    //uncomment these 3 lines to understand how nodes are moving
    //baseNode.draw();
    //childNode.draw();
    //grandChildNode.draw();
    line.draw();
    cam.end();
}
```
You should see an image like this:

![line nodes](images/line-nodes.gif)

Lets' go through the code. In the `setup` method we create a chain of 3 nodes and we assign them a position. Each node is parent to the previous one using `setParent`. In the `update` method we tell to the `baseNode` to rotate 1 degree on the y axis. This will have a percussion also on the 2 other nodes. We also tell to the `childNode` to rotate 3 degree on the x axis. These 2 rotation are enough to give to the last node of the chain, the `grandChildNode`, an elegant movement around the 2 nodes. In the following lines, we are capturing the points from this movement and we are puttin them in the `ofPolyline`. We keep only 200 points in the line, erasing the old ones as soon as new points are pushed in. Try to increase this value to see how the line change. 



