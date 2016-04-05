# 쓰레드

*[Arturo Castro](http://arturocastro.net) 작성*

*Brannon Dorsey에 의해 수정됨*

## 쓰레드란 무엇이고 언제 사용해야 하는가 

Sometimes in an application we need to execute tasks that will take a while to finish. The perfect example is reading something from disk. In the computer the CPU is way faster than accessing the memory which is way faster than accessing the hard disk. So accessing, for example, an image from the HD can take a while compared to the normal flow of the application.

가끔 어플리케이션 내에서는 특정한 작업을 실행하면 끝날떄까지 시간이 걸립니다. 적절한 예를 들자면 디스크에서 뭔가를 읽는 것입니다. 컴퓨터에서는 하드디스크에 접근하는것보다 메모리에 접근하는것이 빠르며, CPU는 훠얼씬 빠릅니다. 접근하는데 있어서 예를들면 하드디스크에서 이미지를 불러오는것은 다른 일반적인 작업에 비교했을때 시간이 훨씬 오래 걸립니다.

In openFrameworks, and in general, usually when working with openGL, our application will run in an infinite loop calling update/draw every cycle of the loop. If we have vertical sync enabled, and our screens works at 60Hz, each of those cycles will last around 16ms (1s/(60frames/s))*1000(ms/s). Loading an image from disk can take way more than those 16ms, so if we try to load an image from our update method, for example, we'll notice a pause in our animation.

일반적으로 오픈프레임웍스에서는, openGL로 작업할 때 대체로 어플리케이션은 update/draw를 반복문의 매 사이클마다 무한대로 호출합니다. 만약 수직동기화를 활성화하면, 화면은 60Hz로 동작하게 되며, 각 사이클은 대략 16ms(1초/(60프레임/초))*1000(ms/s)정도 간격이 됩니다. 이미지를 디스크에서 불러오는것은 16ms보다 더 오래걸리죠, 따라서 한 예로 이미지를 불러오는것을 update메소드에서 시도하게 된다면, 애니메이션이 버벅이는 것을 볼 수 있습니다.

To solve this we usually use threads. Threads are a way of executing certain tasks inside an application outside of the main flow. That way we can run more than one task at once so things that are slow don't stop the main flow of the application. We can also use threads to accelerate tasks by dividing them in several smaller tasks and running each of those at the same time. You can think of a thread as a subprogram inside your program.
이 문제를 해결하기 위해서는 일반적으로 스레드를 사용합니다. 스레드는 어플리케이션 내의 특정한 작업을 main flow의 바깥에서 실행하는 방법입니다. 이 방법을 사용하면 한번에 하나 이상의 작업을 수행하므로 어플리케이션의 main flow를 멈추지 않아 느려지는것을 방지할 수 있습니다. 또한 스레드를 사용하면 작은 작업들로 쪼갠 뒤 동시에 구동시켜 작업을 가속시킬수도 있습니다. 간단히 말해 스레드란 프로그램 하나를 내부의 서브-브로그램으로 생각하시면 됩니다.

Every application has at least 1 thread. In openFrameworks, that thread is where the setup/update/draw loop happens. We'll call this the main (or openGL) thread. But we can create more threads and each of them will run separately from the others.

모든 어플리케이션은 최소 하나의 스레드를 갖습니다. 오픈프레임웍스에서는, 이 스레드에서 setup/update/drar 루프가 발생합니다. 이것을 main(또는 openGL) 스레드라고 합니다. 하지만 더 많은 스레드를 만들고, 각 스레드를 다른 스레드와 별도로 구동시킬 수도 있습니다.

So if we want to load an image in the middle of our application, instead of loading our image in update, we can create a thread that loads the image for us. The problem with this is that once we create a thread, the main thread doesn't know when it has finished, so we need to be able to communicate the results from our auxiliary thread to the main one. There's also problems that might arrise from different threads accessing the same areas in memory. We'll need some mechanisms to synchronize the access to shared memory between 2 or more threads.

따라서 만약 update내에서 이미지를 불러오는 대신, 어플리케이션의 중간에서 이미지를 불러오고 싶다면, 이미지를 불러오는 스레드를하나 만들면 됩니다. 여기서 발생하는 문제는 스레드를 한번 만들면, 메인 스레드는 우리가 만든 스레드가 언제 끝날지 모른다는 점에 있습니다. 따라서 우리의 보조 스레드의 결과가 메인 스레드와 통신할 필요가 있는것이죠. 또다른 문제는 서로 다른 스레드들이 메모리 내의 같은 공간을 접근할 수도 있다는 것입니다. 이를 위해 2개 이상의 스레드들이 공용 메모리에 접근하기 위해 일종의 동기화 매커니즘이 필요합니다.

우선 오픈프레임웍스에서 스레드를 어떻게 만드는지 살펴봅시다.

## ofThread

모든 어플리케이션은 최소 하나의 스레드를 갖고 있으며, 이것을 메인 스레드라고 합니다. (openGL를 사용한다면, GL 스레드라고도 불립니다)

하지만 앞서 언급했듯이, 어떤 작업의 경우 메인스레드 내에서 동작할 때 오랜 시간이 걸리는 경우가 있으므로 이를 위해 보조 스레드를 생성할 수 있습니다. 오픈프레임웍스에서는 ofThread 클래스를 사용하여 스레드를 생성할 수 있습니다. ofThread는 직접 사용되는것이 아니고, 이 클래스를 상속받아 보조스레드로부터 호출되어 사용할 `threadedFunction`를 구현합니다:

```cpp
class ImageLoader: public ofThread{
    void setup(string imagePath){
        this->path = imagePath;
    }

    void threadedFunction(){
        ofLoadImage(image, path);
    }

    ofPixels image;
    string path;
}

//ofApp.h

ImageLoader imgLoader;


// ofApp.cpp
void ofApp::keyPressed(int key){
    imgLoader.setup("someimage.png");
    imgLoader.startThread();
}
```

When we call `startThread()`, `ofThread` starts a new thread and returns immediately, that thread will call our `threadedFunction` and will finish when the function ends.
`startThread()`를 호출하면, `ofThread`는 새 스레드를 시작시켜 즉시 이것을 리턴합니다. 리턴된 스레드는 `threadedFucntion`을 호출하며, 이 함수가 끝나면 종료됩니다.

This way the loading of the image happens simultaneously to our update/draw loop and our application doesn't stop while waiting till the image is loaded from disk.
이방법으로 이미지를 불러오면 update/draw 루프와 동시에 동작하며 어플리케이션은 이미지를 디스크로부터 불러올떄까지 기다리지 않으므로 멈추지 않습니다.

Now, how do we know when our image is loaded? The thread will run separately from the main thread of our application:
자 여기서, 이미지가 불러와졌는지 어떻게 알수 있을까요? 스레드는 어플리케이션의 메인 스레드와 별도로 분리되어 동작할 것입니다:

![Simple Thread](images/simple_thread.png "Simple Thread")

As we see in the image the duration of loading of the image and thus the duration of the call to threadedFunction is not automatically known to the main thread. Since all our thread does is load the image, we can check if the thread has finished running which will tell us that the image has loaded. For that ofThread has a method: `isThreadRunning()`:
위 이미지를 불러오는 동안을 나타내는 그림에서 보시다시피, threadedFunction을 호출하는 것은 메인 스레드에 자동으로 알려지지 않습니다. 우리가 만든 스레드는 이미지를 불러오기만 하므로, 이미지가 불려왔는지를 알려면, 스레드가 작업을 끝냈는지의 여부로 확인할 수 있을것입니다. 이를 위해 ofThread 메소드는 `isThreadRunning()`메소드를 갖고 있습니다:

```cpp
class ImageLoader: public ofThread{
    void setup(string imagePath){
        this->path = imagePath;
    }

    void threadedFunction(){
        ofLoadImage(image, path);
    }

    ofPixels image;
    string path;
}

//ofApp.h
bool loading;
ImageLoader imgLoader;
ofImage img;

// ofApp.cpp
void ofApp::setup(){
    loading = false;
}

void ofApp::update(){
    if(loading==true && !imgLoader.isThreadRunning()){
        img.getPixelsRef() = imgLoader.image;
        img.update();
        loading = false;
    }
}

void ofApp::draw(){
    if (img.isAllocated()) {
        img.draw(0, 0);
    }
}

void ofApp::keyPressed(int key){
    if(!loading){
        imgLoader.setup("someimage.png");
        loading = true;
        imgLoader.startThread();
    }
}
```


Now as you can see we can only load a new image when the first one has finished loading. What if we want to load more than one? A possible solution would be to start a new thread and ask it if it's been loaded already:

자 보시다시피 첫 스레드의 로드가 끝나면 새 이미지를 불러오는것이 전부입니다. 만약 하나 이상을 불러오고 싶다면? 가능한 방법은 새 스레드를 시작하고 이미 로드가 되었는지를 물어보는 것입니다:

```cpp
class ImageLoader: public ofThread{
    ImageLoader(){
        loading = false;
    }

    void load(string imagePath){
        this->path = imagePath;
        loading = true;
        startThread();
    }

    void threadedFunction(){
        ofLoadImage(path,image);
        loaded = true;
    }

    ofPixels image;
    string path;
    bool loading;
    bool loaded;
}

//ofApp.h
vector<unique_ptr<ImageLoader>> imgLoaders;
vector<ofImage> imgs;

// ofApp.cpp
void ofApp::setup(){
    loading = false;
}

void ofApp::update(){
    for(int i=0;i<imgLoaders.size();i++){
        if(imgLoaders[i]->loaded){
            if(imgs.size()<=i) imgs.resize(i+1);

            imgs[i].getPixelsRef() = imgLoaders[i].image;
            imgs[i].update();
            imgLoaders[i].loaded = false;
        }
    }
}

void ofApp::draw(){
    for(int i=0;i<imgLoaders.size();i++){
        imgs[i].draw(x,y);
    }
}

void ofApp::keyPressed(int key){
    imgLoaders.push_back(move(unique_ptr<ImageLoader>(new ImageLoader)));
    imgLoaders.back().load("someimage.png");
}
```

Another possibility would be to use 1 thread only. To do that a possible solution would be to use a queue in our loading thread whenever we want to load a new image. To do this we insert it's path in the queue and when the threadedFunction finishes loading one image it checks the queue. If there's a new image it loads it and it is removed from the queue.
다른 방법은 하나의 스레드만 사용하는 것입니다. 이를 위해 가능한 구현방법이라면 이미지를 불러오는 스레드에 큐를 사용하는 것입니다. 불러올 이미지의 경로를 유ㅔ 삽입하고 threadedFunction 함수가 이미지를 불러오는것을 마치면 큐에 체크하는 것이죠. 만약 불러온 새 이미지가 있다면 큐에서 제거하면 됩니다.

The problem with this is that we will be trying to access the queue from 2 different threads, and as we've mentioned in the memory chapter, when we add or remove elements to a memory structure there's the possibility that the memory will be moved somewhere else. If that happens while one thread is trying to access it we can easily end up with a dangling pointer that will cause the application to crash. Imagine the next sequence of instruction calls from the 2 different threads:

이방법의 문제는 두개의 다른 스레드가 하나의 큐에 접근하려 한다는 것입니다, 그리고 우리가 아미ㅣ 메모리 챕터에서 언급했듯이, 메모리 구조에 추가, 삭제를 할경우 접근할려고 하는 메모리 영역이 다른 곳으로 이동되었을 가능성이 있다는 것입니다. 만일 하나의 스레드가 한 영역에 접근할려고 할 때, 널포인터를 가리키게 되어 어플리케이션이 죽게 됩니다. 아래의 예제에서 두개의 다른 스레드가 다음 수행을 호출하는것을 상상해봅시다:

        loader thread: finished loading an image
        loader thread: pos = get memory address of next element to load
        main thread:   add new element in the queue
        main thread:   queue moves in memory to an area with enough space to allocate it
        loader thread: try to read element in pos  <- crash pos is no longer a valid memory address

        로더 스레드 : 이미지 로드를 마침
        로더 스레드 : pos = 불러올 다음 요소의 주소를 얻음
        메인 스레드 : 새 요소를 큐에 추가
        메인 스레드 : 큐는 새 요소를 위한 공간을 할당하기 위해 메모리 내의 다른 영역으로 이동
        로더 스레드 : pos에서 요소를 읽으려고 시도 <- 유효한 메모리 주소가 아니므로 pos가 죽음(crash)

At this point we might be accessing a memory address that doesn't contain a string anymore, or even trying to access a memory address that is outside of the memory assigned to our application. In this case the OS will kill it sending a segmentation fault signal as we've seen in the memory chapter.
여기서 접근한 메모리 주소에는 문자열값이 더이상 존재하지 않거나, 심지어 어플리케이션에서 할당한 메모리의 바깥영역의 메모리주소를 접근하려 할 수도 있습니다. 이러한 경우 메모리챕터에서 살펴봤듯 운영체제는 segmentation fault 신호를 보내 프로세스를 죽입니다.

The reason this happens is that since thread 1 and 2 run simultaneously we don't know in which order their instructions area going to get executed. We need a way to ensure that thread 1 cannot access the queue while thread 2 is modifying it and viceversa. For that we'll use some kind of lock: In C++ usually a mutex, in openFrameworks an ofMutex.
이러한 상황이 발생하는 이유는 스레드 1과 2가 동시에 실행되어 어떤 순서로 실행이 되는지 알 수 없다는 것입니다. 스레드 2가 큐를 수정하는동안 스레드 1이 큐에 접근할 수 없도록(반대의 경우도 마찬가지) 해야할 필요가 있습니다. 이를 위해 lock이라는 방법을 사용할 것입니다: C++에서는 흔히 mutex라고 하며, 오픈프레임웍스에서는 ofMutex라고 합니다.

But before seeing mutexes, let's see briefly some particulars of using thread while using openGL.
mutex에 대해 살펴보기 전에, openGL에서의 일반적인 스레드 사용법에 대해서 간략히 살펴보도록 합시다. 

## 스레드와 openGL

You might have noticed in the previous examples:
앞의 예제에서 이부분을 보셨을 겁니다:

```cpp
class ImageLoader: public ofThread{
    ImageLoader(){
        loaded = false;
    }
    void setup(string imagePath){
        this->path = imagePath;
    }

    void threadedFunction(){
        ofLoadImage(image, path);
        loaded = true;
    }

    ofPixels image;
    string path;
    bool loaded;
}

//ofApp.h
ImageLoader imgLoader;
ofImage img;

// ofApp.cpp
void ofApp::setup(){
    loading = false;
}

void ofApp::update(){
    if(imgLoader.loaded){
        img.getPixelsRef() = imgLoader.image;
        img.update();
        imgLoader.loaded = false;
    }
}

void ofApp::draw(){
    if (img.isAllocated()) {
        img.draw(0, 0);
    }
}

void ofApp::keyPressed(int key){
    if(!loading){
        imgLoader.setup("someimage.png");
        imgLoader.startThread();
    }
}
```


Instead of using an ofImage to load images, we are using an ofPixels and then in the main thread we use an ofImage to put the contents of ofPixels into it. This is done because openGL, in principle, can only work with 1 thread. That's why we call our main thread the GL thread.
이미지를 불러오기 위해 ofImage 대신, ofPixels를 사용했고, 그리고 나서 메인 스레드에서 ofImage를 사용해 ofPixels의 콘텐츠를 넣었습니다. 이는 openGL때문에 가능한 것인데요, 이론적으로, 하나의 스레드로만 가능한 작업입니다. 이것이 바로 메인 스레드를 GL 스레드라고 부르는 이유이지요. 

As we mentioned in the advanced graphics chapter and other parts of this book, openGL works asynchronously in some kind of client/server model. Our application is the client sending data and drawing instructions to the openGL server which will send them to the graphics card in it's own times.
고급 그래픽스 챕터와 이 책의 다른 파트에서 에서 언급했듯, openGL은 클라이언트/서버 모델과 같이 비동기적으로 동작합니다.어플리케이션은 자신만의 시간내에서 클라이언트로써 데이터와 그리는 방법을 openGL서버에 전송하죠. 즉 그래픽카드로 보내는 것입니다.

Because of that, openGL knows how to work with one thread, the main thread from which the openGL context was created. But if we try to do openGL calls from a different thread we will most surely crash the application, or at least not get the desired results.
이렇기 떄문에, openGL은 하나의 스레드로 작업하는 방법을 압니다. openGL 콘텍스트가 생성했던 메인 스레드 말이죠. 하지만 만일 다른 스레드에서 openGL을 호출하려고 한다면 분명히 어플리케이션이 죽거나, 적어도 원하는 결과를 볼 수 없을것입니다.

When we call `img.loadImage(path)` on an ofImage, it'll actually do some openGL calls, mainly create a texture and upload to it the contents of the image. If we did that from a thread that isn't the GL thread, our application will probably crash or just don't load the texture properly.

우리가 ofImage에서 `img.loadImage(path)`를 호출할 때, 이는 사실 openGL호출을 하는것입니다. 텍스쳐를 생성하고 이미지의 콘텐츠를 그곳에 업로드 하는 것이죠. 만일 우리가 GL 스레드가 아닌 스레드로 호출하면, 어플리케이션이 죽거나 혹은 텍스쳐를 올바르게 로드하지 못할것입니다.

There's a way to tell ofImage, and most other objects that contain pixels and textures in openFrameworks, to not use those textures and instead work only with pixels. That way we could use an ofImage to load the images to pixels and later in the main thread activate the textures to be able to draw the images:
오픈프레임웍스의 다른 대부분의 오브젝트들은 픽셀과 텍스쳐를 포함하고 있으므로, 이러한 텍스쳐를 사용하지 못하게 하고 대신에 픽셀과만 작업하도록 ofImage에게 시킬 수 있습니다. 이 방법으로 ofImage에게 pixels

```cpp
class ImageLoader: public ofThread{
    ImageLoader(){
        loaded = false;
    }
    void setup(string imagePath){
        image.setUseTexture(false);
        this->path = imagePath;
    }

    void threadedFunction(){
        image.loadImage(path);
        loaded = true;
    }

    ofImage image;
    string path;
    bool loaded;
}

//ofApp.h
ImageLoader imgLoader;

// ofApp.cpp
void ofApp::setup(){
    loading = false;
}

void ofApp::update(){
    if(imgLoader.loaded){
        imgLoader.image.setUseTexture(true);
        imgLoader.image.update();
        imgLoader.loaded = false;
    }
}

void ofApp::draw(){
    if (imgLoader.image.isAllocated()){
        imgLoader.image.draw(0,0);
    }
}

void ofApp::keyPressed(int key){
    if(!loading){
        imgLoader.setup("someimage.png");
        imgLoader.startThread();
    }
}
```

There are ways to use openGL from different threads, for example creating a shared context to upload textures in a different thread or using PBO's to map a memory area and later upload to that memory area from a different thread but that's out of the scope of this chapter. In general remember that accessing openGL outside of the GL thread is not safe. In openFrameworks you should only do operations that involve openGL calls from the main thread, that is, from the calls that happen in the setup/update/draw loop, the key and mouse events, and the related ofEvents. If you start a thread and call a function or notify an ofEvent from it, that call will also happen in the auxiliary thread, so be careful to not do any GL calls from there.

A very specific case is sound, sound APIs in openFrameworks, in particular ofSoundStream, create their own threads since sound's timing needs to be super precise. So when working with ofSoundStream be careful not to use any openGL calls and in general apply the same logic as if you where inside the threadedFunction of an ofThread. We'll see more about this in the next sections.


## ofMutex

Before we started the openGL and threads section we were talking about how accessing the same memory area from 2 different threads can cause problems. This mostly occurs if we write from one of the threads causing the data structure to move in memory or make a location invalid. 
"스레드와 openGL" 전의 섹션에서 서로다른 두 스레드가 같은 메모리영역에 접근했을 때 발생하는 문제에 대해서 살펴봤습니다. 이는 대부분 둘중 한 스레드가 메모리영역을 이동시켜 다른 스레드가 비유효 영역을 접근하기 떄문입니다.

To avoid that we need something that allows to access that data to only one thread simultaneously. For that we use something called mutex. When one thread want's to access the shared data, it locks the mutex and when a mutex is locked any other thread trying to lock it will get blocked there until the mutex is unlocked again. You can think of this as some kind of token that each thread needs to have to be able to access the shared memory. 

이를 피하기 위해 스레드가 동시에 동작할 떄 단 하나의 스레드만 데이터에 접근할 수 있도록 해야합니다. 이를 위해 mutex라 불리우는 것을 사용할 것입니다. 한 스레드가 공용 데이터에 접근하지 않을 때, mutex를 clock 

Imagine you are with a group of people building a tower of cards, if more than one at the same time tries to put cards on it it's very possible that it'll collapse so to avoid that, anyone who wants to put a card on the tower, needs to have a small stone, that stone gives them permission to add cards to the tower and there's only one, so if someone wants to add cards they need to get the stone but if someone else has the stone then they have to wait till the stone is freed. If more than one wants to add cards and the stone is not free they queue, the first one in the queue gets the stone when it's finally freed.

A mutex is something like that, to *get the stone* you call lock on the mutex, once you are done, you call unlock. If some other thread calls lock while another thread is holding it, they are put in to a queue, the first thread that called lock will get the mutex when it's finally unlocked:

        thread 1: lock mutex
        thread 1: pos = access memory to get position to write
        thread 2: lock mutex <- now thread 2 will stop it's execution till thread 1 unlocks it so better be quick
        thread 1: write to pos
        thread 1: unlock mutex
        thread 2: read memory
        thread 2: unlock mutex

When we lock a mutex from one thread and another thread tries to lock it, that stops it's execution. For this reason we should try to do only fast operations while we have the mutex locked in order to not lock the execution of the main thread for too long.

In openFrameworks, the ofMutex class allows us to do this kind of locking. The syntax for the previous sequence would be something like:

        thread 1: mutex.lock();
        thread 1: vec.push_back(something);
        thread 2: mutex.lock(); // now thread 2 will stop it's execution until thread 1 unlocks it so better be quick
        thread 1: // end of push_back()
        thread 1: mutex.unlock();
        thread 2: somevariable = vec[i];
        thread 2: mutex.unlock();


We just need to call `lock()` and `unlock()` on our ofMutex from the different threads, from `threadedFunction` and from the update/draw loop when we want to access a piece of shared memory. ofThread actually contains an ofMutex that can be locked using lock()/unlock(), we can use it like:

```cpp
class NumberGenerator{
public:
    void threadedFunction(){
        while (isThreadRunning()){
            lock();
            numbers.push_back(ofRandom(0,1000));
            unlock();
            ofSleepMillis(1000);
        }
    }

    vector<int> numbers;
}

// ofApp.h

NumberGenerator numberGenerator;

// ofApp.cpp

void ofApp::setup(){
    numberGenerator.startThread();
}

void ofApp::update(){
    numberGenerator.lock();
    while(!numberGenerator.numbers.empty()){
        cout << numberGenerator.numbers.front() << endl;
        numberGenerator.numbers.pop_front();
    }
    numberGenerator.unlock();
}
```

As we've said before, when we lock a mutex we stop other threads from accessing it. It is important that we try to keep the lock time as small as possible or else we'll end up stopping the main thread anyway making the use of threads pointless.

## External threads and double buffering

Sometimes we don't have a thread that we've created ourselves, but instead we are using a library that creates it's own thread and calls our application on a callback. Let's see an example with an imaginary video library that calls some function whenever there's a new frame from the camera, that kind of function is called a callback because some library *calls us back* when something happens, the key and mouse events functions in OF are examples of callbacks.

```cpp
class VideoRenderer{
public:
    void setup(){
        pixels.allocate(640,480,3);
        texture.allocate(640,480,GL_RGB);
        videoLibrary::setCallback(this, &VideoRenderer::frameCB);
        videoLibrary::startCapture(640,480,"RGB");
    }

    void update(){
        if(newFrame){
            texture.loadData(pixels);
            newFrame = false;
        }
    }

    void draw(float x, float y){
        texture.draw(x,y);
    }

    void frameCB(unsigned char * frame, int w, int h){
        pixels.setFromPixels(frame,w,h,3);
        newFrame = true;
    }

    ofPixels pixels;
    bool newFrame;
    ofTexture texture;
}
```

Here, even if we don't use a mutex, our application won't crash. That is because the memory in pixels is preallocated in setup and it's size never changes. For this reason the memory won't move from it's original location. The problem is that both the update and frame_cb functions might be running at the same time so we will probably end up seeing [tearing](http://en.wikipedia.org/wiki/Screen_tearing). Tearing is the same kind of effect we can see when we draw to the screen without activating the vertical sync.

To avoid tearing we might want to use a mutex:

```cpp
class VideoRenderer{
public:
    void setup(){
        pixels.allocate(640,480,3);
        texture.allocate(640,480,GL_RGB);
        videoLibrary::setCallback(this, &VideoRenderer::frameCB);
        videoLibrary::startCapture(640,480,"RGB");
    }

    void update(){
        mutex.lock();
        if(newFrame){
            texture.loadData(pixels);
            newFrame = false;
        }
        mutex.unlock();
    }

    void draw(float x, float y){
        texture.draw(x,y);
    }

    void frameCB(unsigned char * frame, int w, int h){
        mutex.lock();
        pixels.setFromPixels(frame,w,h,3);
        newFrame = true;
        mutex.unlock();
    }

    ofPixels pixels;
    bool newFrame;
    ofTexture texture;
    ofMutex mutex;
}
```


That will solve the tearing, but we are stopping the main thread while the `frameCB` is updating the pixels and stopping the camera thread while the main one is uploading the texture. For small images this is usually ok, but for bigger images we could loose some frames. A possible solution is to use a technique called double or even triple buffering:


```cpp
class VideoRenderer{
public:
    void setup(){
        pixelsBack.allocate(640,480,3);
        pixelsFront.allocate(640,480,3);
        texture.allocate(640,480,GL_RGB);
        videoLibrary::setCallback(this, &VideoRenderer::frameCB);
        videoLibrary::startCapture(640,480,"RGB");
    }

    void update(){
        bool wasNewFrame = false;
        mutex.lock();
        if(newFrame){
            swap(pixelsFront,pixelsBack);
            newFrame = false;
            wasNewFrame = true;
        }
        mutex.unlock();

        if(wasNewFrame) texture.loadData(pixelsFront);
    }

    void draw(float x, float y){
        texture.draw(x,y);
    }

    void frameCB(unsigned char * frame, int w, int h){
        pixelsBack.setFromPixels(frame,w,h,3);
        mutex.lock();
        newFrame = true;
        mutex.unlock();
    }

    ofPixels pixelsFront, pixelsBack;
    bool newFrame;
    ofTexture texture;
    ofMutex mutex;
}
```

With this we are locking the mutex for a very short time in the frame callback to set `newFrame = true` in the main thread. We do this to check if there's a new frame and then to swap the front and back buffers. `swap` is a c++ standard library function that swaps 2 memory areas so if we swap 2 ints `a` and `b`, `a` will end up having the value of `b` and viceversa, usually this happens by copying the variables but `swap` is overridden for ofPixels and swaps the internal pointers to memory inside `frontPixels` and `backPixels` to point to one another. After calling `swap`, `frontPixels` will be pointing to what `backPixels` was pointing to before, and viceversa. This operation only involves copying the values of a couple of memory addresses plus the size and number of channels. For this reason it's way faster than copying the whole image or uploading to a texture.

Triple buffering is a similar technique that involves using 3 buffers instead of 2 and is useful in some cases. We won't see it in this chapter.

## ofScopedLock

Sometimes we need to lock a function until it returns, or lock for the duration of a full block. That is exactly what a scoped lock does. If you've read the memory chapter you probably remember about what we called initially, *stack semantics*, or RAII [Resource Adquisition Is Initialization](http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization). A scoped lock makes use of that technique to lock a mutex for the whole duration of the block, even any copy that might happen in the same `return` call if there's one.

For example, the previous example could be turned into:

```cpp
class VideoRenderer{
public:
    void setup(){
        pixelsBack.allocate(640,480,3);
        pixelsFront.allocate(640,480,3);
        texture.allocate(640,480,GL_RGB);
        videoLibrary::setCallback(&frame_cb);
        videoLibrary::startCapture(640,480,"RGB");
    }

    void update(){
        bool wasNewFrame = false;

        {
        ofScopedLock lock(mutex);
            if(newFrame){
                swap(fontPixels,backPixels);
                newFrame = false;
                wasNewFrame = true;
            }
        }

        if(wasNewFrame) texture.loadData(pixels);
    }

    void draw(float x, float y){
        texture.draw(x,y);
    }

    static void frame_cb(unsigned char * frame, int w, int h){
        pixelsBack.setFromPixels(frame,w,h,3);
        ofScopedLock lock(mutex);
        newFrame = true;
    }

    ofPixels pixels;
    bool newFrame;
    ofTexture texture;
    ofMutex mutex;
}
```

A ScopedLock is a good way of avoiding problems because we forgot to unlock a mutex and allows us to use the `{}` to define the duration of the lock which is more natural to C++.

There's one particular case when the only way to properly lock is by using a scoped lock. That's when we want to return a value and keep the function locked until after the value was returned. In that case we can't use a normal lock:

```cpp

ofPixels accessSomeSharedData(){
    ofScopedLock lock(mutex);
    return modifiedPixels(pixels);
}

```

We could make a copy internally and return that later, but with this pattern we avoid a copy and the syntax is shorter.


## Poco::Condition

A condition, in threads terminology, is an object that allows to synchronize 2 threads. The pattern is something like this: one thread waits for something to happen before starting it's processing. When it finishes, instead of finishing the thread, it locks in the condition and waits till there's new data to process. An example of this could be the image loader class we were working with earlier. Instead of starting one thread for every image, we might have a queue of images to load. The main thread adds image paths to that queue and the auxiliary thread loads the images from that queue until it is empty. The auxiliary thread then locks on a condition until there's more images to load.

Such an example would be too long to write in this section, but if you are interested in how something like that might work, take a look at ofxThreadedImageLoaded (which does just that).

Instead let's see a simple example. Imagine a class where we can push urls to pings addresses in a different thread. Something like:

```cpp
class ThreadedHTTPPing: public ofThread{
public:
    void pingServer(string url){
        mutex.lock();
        queueUrls.push(url);
        mutex.unlock();
    }

    void threadedFunction(){
        while(isThreadRunning()){
            mutex.lock();
            string url;
            if(queueUrls.empty()){
                url = queueUrls.front();
                queueUrls.pop();
            }
            mutex.unlock();
            if(url != ""){
                ofHttpUrlLoad(url);
            }
        }
    }

private:
    queue<string> queueUrls;
}
```

The problem with that example is that the auxiliary thread keeps running as fast as possible in a loop, consuming a whole CPU core from our computer which is not a very good idea.

A typical solution to this problem is to sleep for a while at the end of each cycle like:

```cpp
class ThreadedHTTPPing: public ofThread{
public:
    void pingServer(string url){
        mutex.lock();
        queueUrls.push(url);
        mutex.unlock();
    }

    void threadedFunction(){
        while(isThreadRunning()){
            mutex.lock();
            string url;
            if(queueUrls.empty()){
                url = queueUrls.front();
                queueUrls.pop();
            }
            mutex.unlock();
            if(url != ""){
                ofHttpUrlLoad(url);
            }
            ofSleepMillis(100);
        }
    }

private:
    queue<string> queueUrls;
};
```

That alleviates the problem slightly but not completely. The thread won't consume as much CPU now, but it sleeps for an unnecesarily while when there's still urls to load. It also continues to run in the background even when there's no more urls to ping. Specially in small devices powered by batteries, like a phone, this pattern would drain the battery in a few hours.

The best solution to this problem is to use a condition:

```cpp
class ThreadedHTTPPing: public ofThread{
    void pingServer(string url){
        mutex.lock();
        queueUrls.push(url);
        condition.signal();
        mutex.unlock();
    }

    void threadedFunction(){
        while(isThreadRunning()){
            mutex.lock();
            if (queueUrls.empty()){
                condition.wait(mutex);
            }
            string url = queueUrls.front();
            queueUrls.pop();
            mutex.unlock();

            ofHttpUrlLoad(url);
        }
    }

private:
    Poco::Condition condition;
    queue<string> queueUrls;
};
```

Before we call `condition.wait(mutex)` the mutex needs to be locked, then the condition unlocks the mutex and blocks the execution of that thread until `condition.signal()` is called. When the condition awakens the thread because it's been signaled, it locks the mutex again and continues the execution. We can read the queue without problem because we know that the other thread won't be able to access it. We copy the next url to ping and unlock the mutex to keep the lock time to a minimum. Then outside the lock we ping the server and start the process again.

Whenever the queue gets emptied the condition will block the execution of the thread to avoid it from running in the background.

## Conclusion

As we've seen threads are a powerfull tool to allow for several tasks to happen simultaneously in the same application. They are also hard to use, the main problem is usually accessing shared resouces, usually shared memory. We've only seen one specific case, how to use threads to do background tasks that will pause the execution of the main task, there's other cases where we can parallelize 1 task by dividing it in small subtasks like for example doing some image operation by dividing the image in for subregions and assigning a thread to each. For those cases there's special libraries that make the syntax easier, OpenCv for example can do some operations using more than one core through [TBB](https://www.threadingbuildingblocks.org/) and there's libraries like the same TBB or [OpenMP](http://openmp.org/wp/) that allow to specify that a loop should be divided and run simultaneol¡usly in more than one core

