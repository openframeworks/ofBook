# Threads

*by [Arturo Castro](http://arturocastro.net)*

## What's a thread when to use it

Sometimes in an application we need to execute tasks that will take a while to finish, the perfect example is reading something from disk, in the computer the CPU is way faster than accessing the memory which is way faster than accessing the hard disk. So accesing for example an image from the HD can take a while compared to the normal flow of the application.

In openFrameworks and in general usually when working with openGL, our application will run in an infinite loop calling update/draw every cycle of the loop, if we have vertical sync enabled, and our screens works at 60Hz, every of thos cycles will last around 16ms (1s/(60frames/s))*1000(ms/s). Loading an image from disk can take way more than those 16ms so if we try to load an image from our update method for example, we'll notice a apuse in our animation.

To solve this we usually use threads. Threads are a way of executing certain tasks inside an application outside of the amin flow. Indeed every application has at least 1 thread in the case of openFrameworks that's the thread in which the setup/update/draw loop happens. We'll call this the main thread or in our case the openGL thread. But we can create more threads and each of them will run separately from the others.

That way instead of loading our image in update, we can create a thread that loads the image for us. The problem with this is that once we create a thread the main thread, in principle doesn't know when it has finished, so we need to be able to communicate the results from our auxiliary thread to the main one. There's also problems that might arrise from accessing the same areas in memory from different threads. Mostly when one of the writes to that memory so we'll need some mechanisms to synchronize the access to shared memory between 2 or more threads.

But first let's see how to create a thread in openFrameworks.

## ofThread

As we've said in the previous section, every application has at least one thread the main thread also called the GL thread when we are working with openGL.

But we can create auxiliary threads to do certain tasks that would take too long to run in the main one. In openFrameworks we can do that using the ofThread class. ofThread is not meant to be used directly, instead we inherit from it, implement a `threadedFunction` which will later get called from the auxiliary thread once we start it:

```cpp
class ImageLoader: public ofThread{
    void setup(string imagePath){
        this->imagePath = imagePath;
    }
    
    void threadedFunction(){
        ofLoadImage(path,image);
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

When we call `startThread()`, `ofThread` starts a new thread and returns immediately, that thread will call our `threadedFunction` and will finish when the funciton ends.

This way the loading of the image happens in the background and our application doesn't stop.

Now how do we know when our image is loaded? The thread will run separately from the main thread of our application:

<img src="simple_thread.svg" height="300"/>

As we see in the image the duration of the loading of the image and thus the duration of the call to threadedFunction, of the new thread is not known to the main thread. There's a simple way to know from the main thread when the image has been loaded and that's by asking the thread if it has finished already:

```cpp
class ImageLoader: public ofThread{
    void setup(string imagePath){
        this->imagePath = imagePath;
    }
    
    void threadedFunction(){
        ofLoadImage(path,image);
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
        img.getPixelsRef() = imgLoader.img;
        img.update();
        loading = false;
    }
}

void ofApp::draw(){
    img.draw(0,0);
}

void ofApp::keyPressed(int key){
    if(!loading){
        imgLoader.setup("someimage.png");
        loading = true;
        imgLoader.startThread();
    }
}
```


Now as you can see we can only load a new image when the first one has finished loading, the problem with this is that we might want to load more than one, a possible solution would be to start a new thread and ask it it's been loaded already, like:

```cpp
class ImageLoader: public ofThread{
    ImageLoader(){
        loading = false;
    }
    
    void load(string imagePath){
        this->imagePath = imagePath;
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
        if(imgLoaders[i].loaded){
            if(imgs.size()<=i) imgs.resize(i+1);
            
            imgs[i].getPixelsRef() = imgLoaders[i].img;
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

Another possibility would be to use 1 thread only, starting threads is kind of expensive in terms of cpu usage and although we could have a better structure, in the previous example we are leaking the old threads. A possible solution would be to use a queue in our loading thread, whenever we want to load a new image we insert it's path in the queue, when the threadedFunction finishes loading one image it checks the queue and it there's a new image it loads it and removes it from the queue.

The problem with this is that we will be trying to access the queue from 2 different threads, as we've mentioned in the memory chapter, when we add or remove elements to a memory structure there's the posibility that the memory will be moved somewhere else. If that happens while one thread is trying to access it we can easily end up with a dangling pointer and the applciation will crash. Imagine the next sequence of instruction calls from the 2 different threads:

        loader thread: finished loading an image
        loader thread: pos = get memory address of next element to load
        main thread:   add new element in the queue
        main thread:   queue moves in memory to an area with enough space to allocate it
        loader thread: try to read element in pos  <- crash pos is no longer a valid memory address
        
At this point we might be accessing a memory address that doesn't contain anymore a string or even trying to access a memory address that it's outside of the memory asigned to our application, the OS will kill it then sending a segmentation fault signal to it as we've seen in the memory chapter.

The reason this happens is that we don't know when thread 1 and 2 are going to run or get interrupted, we need a way to ensure that thread 1 cannot access the queue while thread 2 is running, for that we'll use some kind of lock, in c++ usually a mutex, in openFrameworks an ofMutex.

But before seeing mutexes let's see briefly how openGL and threads behave together.

## Threads and openGL

You might have noticed in the previous examples:

```cpp
class ImageLoader: public ofThread{
    ImageLoader(){
        loaded = false;
    }
    void setup(string imagePath){
        this->imagePath = imagePath;
    }
    
    void threadedFunction(){
        ofLoadImage(path,image);
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
        img.getPixelsRef() = imgLoader.img;
        img.update();
        imgLoader.loaded = false;
    }
}

void ofApp::draw(){
    img.draw(0,0);
}

void ofApp::keyPressed(int key){
    if(!loading){
        imgLoader.setup("someimage.png");
        imgLoader.startThread();
    }
}
```


That instead of using an ofImage to load images, we are using an ofPixels and then in the main thread using an ofImage to put the contents of ofPixels into it. This is done like that because openGL, in principle can only work with 1 thread, that's why we call our main thread the GL thread.

As we mention in the advanced graphics chapter and other parts of this book, openGL works asynchonously in some kind of client/server model, where our application is the client sending data and drawing instructions to the openGL server which will send them to the graphics card in it's own times.

Because of that openGL knows how to work with one thread, the thread from which the openGL context was created, what we've been calling the main or GL thread. But if we try to do openGL calls from a different thread, will most surely crash the application or at least not get the desired results.

When we call `img.loadImage(path)` on an ofImage, it'll actually do some openGL calls, mainly create a texture and upload to it the contents of the image. If we did that from a thread that it's not the GL thread our application will probably crash.

There's a way to tell ofImage and most other objects that contain pixels and textures in openFrameworks to not use those textures and instead work only with pixels, that way we could use an ofImage to load the images to pixels and later in the main thread activate the textures to be able to draw the images:

```cpp
class ImageLoader: public ofThread{
    ImageLoader(){
        loaded = false;
    }
    void setup(string imagePath){
        image.setUseTexture(false);
        this->imagePath = imagePath;
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
    imageLoader.image.draw(0,0);
}

void ofApp::keyPressed(int key){
    if(!loading){
        imgLoader.setup("someimage.png");
        imgLoader.startThread();
    }
}
```

There's ways to use openGL from different threads, for example creating a shared context to upload textures in a different thread or using PBO's to map a memory area and later upload to that memory area from a different thread, but that's out of the scope of this chapter. In general remember that accessing openGL outside of the GL thread is not safe so in openFrameworks you should only do operations that involve openGL calls from the main thread, that is from the calls that happen in the setup/update/draw loop, the key and mouse events, and the related ofEvents. If you start a thread and call an ofEvent from it that call will also happen in the auxiliary thread so be careful to not do any GL calls from there.

Also when working with sound in openFrameworks, mostly with ofSoundStream, sound API's create their own threads since sound needs that timing is super precise and nothing interrupts it or we might hear noises. So when working with ofSoundStream be careful to not use any openGL calls and in general apply the same logic as if you where inside the threadedFunction of an ofThread. Will see more about this in the next sections.


## ofMutex

Before we started the openGL and threads section we were talking about how accessing the same memory area from 2 different threads cna cause problems mostly if we write from one of the threads causing the data structure to move in memory or make a location invalid. To avoid that we need something that allows us to lock the access to that data to only one thread for a while then unlock and let the other thread access to it. That lock is called a mutex and it works more or less like this:

        thread 1: lock mutex
        thread 1: pos = access memory to get position to write
        thread 2: lock mutex <- now thread 2 will stop it's execution till thread 1 unlocks it so better be quick
        thread 1: write to pos
        thread 1: unlock mutex
        thread 2: read memory
        thread 2: unlock mutex
        
        
As it's explained in the sequence of instructions, when we lock a mutex from one thread and another thread tries to lock it, that stops it's execution so we should try to do only fast operations while we have the mutex locked in order to not lock the execution of the main thread for too long.

In openFrameworks we have a class called ofMutex that allows to do this kind of locking, the syntax for the previous sequence would be something like:

        thread 1: mutex.lock();
        thread 1: vec.push_back(something);
        thread 2: mutex.lock(); // now thread 2 will stop it's execution till thread 1 unlocks it so better be quick
        thread 1: // end of push_back()
        thread 1: mutex.unlock();
        thread 2: somevariable = vec[i];
        thread 2: mutex.unlock();
        
As you can see, the execution of a thread can be interrupted even while doing something like a `push_back()`, when we try to call `push_back()`, the vector internally calculates the next position to write but then the operating system interrupts it and gives the execution to thread 1 which if it weren't for the mutex would try to access a possibly invalid location. since we have the mutex, the second thread is stopped at that point and the first thread can continue writing to the vector without problem.

In multicpu machines like it's the norm nowadays both operations might be happening simultaneously but the mutex again prevents that from happening.

ofThread, contains a mutex that we can use, we just need to call `lock()` and `unlock()` from inside our threadedFunction and from outside when trying to use shared memory:

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
    while(!numberGenerator.empty()){
        cout << numberGenerator.front() << endl;
        numberGenerator.pop_front();
    }
    numberGenerator.unlock();
}
```

This example is kind of useless :) but should explain the usage of the mutex in ofThread.

As we've said before when we lock a mutex we stop the access from other threads so we should try to keep the lock time as small as possible.

## External threads and double buffering

Some times we don't have a thread that we've created ourselves but instead we are using a library that creates it's own thread and calls our application on a callback from that thread or threads. Let's see an example with an imaginary video library that calls us in callback whenever there's a new frame from the camera:

```cpp
class VideoReader{
public:
    void setup(){
        pixels.allocate(640,480,3);
        texture.allocate(640,480,GL_RGB);
        videoLibrary::setCallback(&frame_cb);
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
    
    static void frame_cb(unsigned char * frame, int w, int h){
        pixels.setFromPixels(frame,w,h,3);
        newFrame = true;
    }
    
    ofPixels pixels;
    bool newFrame;
    ofTexture texture;
}
```

Here, even if we don't use a mutex, our application won't crash, since the memory in pixels is preallocated in setup and it's size never changes so the memory won't move from it's original location. The problem is that both update and the frame_cb might be running at the same time so we will probably end up seeing [tearing](http://en.wikipedia.org/wiki/Screen_tearing), the same kind of efect we can see when we draw to the screen without activating the vertical sync.

To avoid it we might want to use a mutex:

```cpp
class VideoReader{
public:
    void setup(){
        pixels.allocate(640,480,3);
        texture.allocate(640,480,GL_RGB);
        videoLibrary::setCallback(&frame_cb);
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
    
    void frame_cb(unsigned char * frame, int w, int h){
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


That will solve the tearing but we are stopping the main thread while the frame_cb is updating the pixels and stopping the camera thread while the main one is uploading the texture. For small images is usually ok but for bigger images it can make us loose some frames. A possible solution is use a technique called double or even triple buffering:

```cpp
class VideoReader{
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

    void frame_cb(unsigned char * frame, int w, int h){
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

With this we are locking the mutex for a really short time, in the frame callback only to set `newFrame = true` in the main thread, to check if there's a new frame and then to swap the front and back buffers, swap, is overrided for ofPixels and what it does is that it swaps the internal pointers to memory inside `frontPixels` and `backPixels` to point to one another, so after calling it, now `frontPixels` is now pointing to what `backPixels` was pointing before and viceversa. This operation only involves copying the values of a couple of memory addresses plus the size and number of channels so it's way faster than copying the whole image or uploading to a texture.

Triple buffering is a similar technique that involves using 3 buffers instead of 2 and is useful in some cases but we won't see it in this chapter.

## ofScopedLock

Some times we need to lock a function until it returns a function, or lock for the duration of a full block, that's what a scoped lock does, if you've read the memory chpater probably you remmeber about what we called stack semantics, or RAII [Resource Adquisition Is Initialization](http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization). A scoped lock makes use of that technique to lock a mutex while a block lasts:

For example the previous example could be turned into:

```cpp
class VideoReader{
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

As you can see in some cases it makes more sense than others but it's also a good way of avoiding problems because we forgot to unlock a mutex and allows us to usethe `{}` to define the duration of the lock which is more natural to c++.

There's one case when the only way to properly lock is by using a scoped lock and that's when we want to return a value and keep the function locked until after the value was returned, in that case we can't use a normal lock:

```cpp

ofPixels accessSomeSharedData(){
    ofScopedLock lock(mutex);
    return modifiedPixels(pixels);
}

```

In this case we could make a copy internally and return that later, but still with this pattern we avoid a copy and the syntax is shorter.


## Poco::Condition

A condition in threads terminology, is an object that allows to synchronize 2 threads. The pattern is something like this: one thread waits for something to happen to start it's processing, when it finishes instead of finishing the thread, it locks in the condition and waits till there's new data to process. An example could be the image loader class we were working with some sections ago. Instead of starting one thread for every image we want to load we might have a queue of images to load, the main thread adds image paths into that queue and the auxiliary thread loads the images from that queue till is empty then locks on a condition till there's more images to load.

Such an example would be too long to write in this book but if you are interested into how something like that might work take a look at ofxThreadedImageLoaded which does just that.

Instead let's see a simple example, imagine a class where we can push urls so it pings those adresses in a different thread, something like:

```cpp
class ThreadedHTTPPing: public ofThread{
    void pingServer(string url){
        mutex.lock();
        queueUrls.push(url);
        mutex.unlock();
    } 
    
    void threadedFunction(){
        while(isThreadRunning()){
            mutex.lock();
            string nextUrl = queueUrls.front();
            queueUrls.pop();
            mutex.unlock();
            
            ofHttpUrlLoad(url);   
        }
    }
    
private:
    queue<string> queueUrls;
}
```

The problem with that example is that the auxiliary thread keeps running as fast as possible in a loop consuming a full cpu from our computer which is not a very good idea.

A tipical solution to this problem is to sleep for a while at the end of each cycle like:

```cpp
class ThreadedHTTPPing: public ofThread{
    void pingServer(string url){
        mutex.lock();
        queueUrls.push(url);
        mutex.unlock();
    } 
    
    void threadedFunction(){
        while(isThreadRunning()){
            mutex.lock();
            string nextUrl = queueUrls.front();
            queueUrls.pop();
            mutex.unlock();
            
            ofHttpUrlLoad(url);
            ofSleepMillis(100);   
        }
    }
    
private:
    queue<string> queueUrls;
}
```

That alleviates the problem slightly but not completely, the thread won't consume as much cpu now, but it sleeps for a while unnecesarily when there's still urls to load and continues to run in the background even when there's no more urls to ping. Specially in small devices powered by batteries like a phone this pattern will drain the battery in a few hours.

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
            if (queue.empty()){
                condition.wait(mutex);
            }
            string nextUrl = queueUrls.front();
            queueUrls.pop();
            mutex.unlock();
            
            ofHttpUrlLoad(url);   
        }
    }
    
private:
    Poco::Condition condition;
    queue<string> queueUrls;
}
```

When we call `condition.wait(mutex)` the mutex needs to be locked before, then the condition unlocks the mutex and blocks the execution of that thread until `condition.signal()` is called. When the condition awakes the thread because it's been signaled, it locks the mutex again and continues the execution, there, we can read the queue without problem because we know that the other thread won't be able to access it since we are holding the mutex, copy the next url to ping and unlock the mutex to keep the lock time to a minimum. Then outside the lock we ping the server and start the process again.

Whenever the queue gets emptied the condition will block the execution of the thread avoiding to have to run it constantly in the background. 


*This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.*

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>

