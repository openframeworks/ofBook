# Threads

*by [Arturo Castro](http://arturocastro.net)*

## What's a thread and when to use it

Sometimes in an application we need to execute tasks that will take a while to finish. The perfect example is reading something from disk. In the computer the CPU is way faster than accessing the memory which is way faster than accessing the hard disk. So accessing, for example, an image from the HD can take a while compared to the normal flow of the application.

In openFrameworks, and in general, usually when working with openGL, our application will run in an infinite loop calling update/draw every cycle of the loop. If we have vertical sync enabled, and our screens works at 60Hz, each of those cycles will last around 16ms (1s/(60frames/s))*1000(ms/s). Loading an image from disk can take way more than those 16ms, so if we try to load an image from our update method for example, we'll notice a apuse
 __[BD: ?]__ in our animation.

To solve this we usually use threads. Threads are a way of executing certain tasks inside an application outside of the amin flow **[BD: This could be more clear]**. Indeed every application has at least 1 thread. In openFrameworks thread is where the setup/update/draw loop happens. We'll call this the main (or openGL) thread. But we can create more threads and each of them will run separately from the others.

Instead of loading our image in update, we can create a thread that loads the image for us. The problem with this is that once we create a thread, the main thread doesn't know when it has finished, so we need to be able to communicate the results from our auxiliary thread to the main one. There's also problems that might arrise from different threads accessing the same areas in memory. We'll need some mechanisms to synchronize the access to shared memory between 2 or more threads.

First let's see how to create a thread in openFrameworks.

## ofThread

Every application has at least one thread, the main thread (also called the GL thread), when it's using openGL.

But we can create auxiliary threads to do certain tasks that would take too long to run in the main thread. In openFrameworks we can do that using the ofThread class. ofThread is not meant to be used directly, instead we inherit from it. Implement a `threadedFunction` which will later get called from the auxiliary thread once we start it:

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

**[BD: ^ Should `imagePath` be `path`?]**

When we call `startThread()`, `ofThread` starts a new thread and returns immediately, that thread will call our `threadedFunction` and will finish when the function ends.

This way the loading of the image happens in the background and our application doesn't stop **[BD: slow?]**.

Now how do we know when our image is loaded? The thread will run separately from the main thread of our application:

<img src="images/simple_thread.svg" height="300"/>

~~As we see in the image the duration of the loading of the image and thus the duration of the call to threadedFunction of~~ The new thread is not automatically known to the main thread. We can check if the image has loaded using `isThreadRunning()`:

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


Now as you can see we can only load a new image when the first one has finished loading. What if we want to load more than one? A possible solution would be to start a new thread and ask it if it's been loaded already:

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

Another possibility would be to use 1 thread only. Starting threads is kind of expensive in terms of CPU usage and although we could have a better structure **[BD: doing what?]**, in the previous example we are leaking the old threads. A possible solution would be to use a queue in our loading thread whenever we want to load a new image. To do this we insert it's path in the queue and when the threadedFunction finishes loading one image it checks the queue. If there's a new image it loads it and it is removed from the queue.

The problem with this is that we will be trying to access the queue from 2 different threads, and as we've mentioned in the memory chapter, when we add or remove elements to a memory structure there's the possibility that the memory will be moved somewhere else. If that happens while one thread is trying to access it we can easily end up with a dangling pointer that will cause the application to crash. Imagine the next sequence of instruction calls from the 2 different threads:

        loader thread: finished loading an image
        loader thread: pos = get memory address of next element to load
        main thread:   add new element in the queue
        main thread:   queue moves in memory to an area with enough space to allocate it
        loader thread: try to read element in pos  <- crash pos is no longer a valid memory address

At this point we might be accessing a memory address that doesn't contain a string anymore, or even trying to access a memory address that is outside of the memory assigned to our application. In this case the OS will kill it sending a segmentation fault signal as we've seen in the memory chapter.

The reason this happens is that we don't know when thread 1 and 2 are going to run or get interrupted. We need a way to ensure that thread 1 cannot access the queue while thread 2 is running. For that we'll use some kind of lock: In C++ usually a mutex, in openFrameworks an ofMutex.

But before seeing mutexes, let's see briefly how openGL and threads behave together.

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


Instead of using an ofImage to load images, we are using an ofPixels and then in the main thread we use an ofImage to put the contents of ofPixels into it. This is done because openGL, in principle, can only work with 1 thread. That's why we call our main thread the GL thread.

As we mention in the advanced graphics chapter and other parts of this book, openGL works asynchronously in some kind of client/server model. Our application is the client sending data and drawing instructions to the openGL server which will send them to the graphics card in it's own times.

Because of that, openGL knows how to work with one thread, the main thread from which the openGL context was created. But if we try to do openGL calls from a different thread we will most surely crash the application, or at least not get the desired results.

When we call `img.loadImage(path)` on an ofImage, it'll actually do some openGL calls, mainly create a texture and upload to it the contents of the image. If we did that from a thread that isn't the GL thread, our application will probably crash.

There's a way to tell ofImage, and most other objects that contain pixels and textures in openFrameworks, to not use those textures and instead work only with pixels. That way we could use an ofImage to load the images to pixels and later in the main thread activate the textures to be able to draw the images:

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

There are ways to use openGL from different threads, for example creating a shared context to upload textures in a different thread or using PBO's **[BD: Maybe explain PBOs]** to map a memory area and later upload to that memory area from a different thread (but that's out of the scope of this chapter). In general remember that accessing openGL outside of the GL thread is not safe. In openFrameworks you should only do operations that involve openGL calls from the main thread, that is, from the calls that happen in the setup/update/draw loop, the key and mouse events, and the related ofEvents. If you start a thread and call an ofEvent from it, that call will also happen in the auxiliary thread, so be careful to not do any GL calls from there.

Sound APIs in openFrameworks create their own threads since sound's timing needs are super precise. So when working with ofSoundStream be careful not to use any openGL calls and in general apply the same logic as if you where inside the threadedFunction of an ofThread. We'll see more about this in the next sections.


## ofMutex

Before we started the openGL and threads section we were talking about how accessing the same memory area from 2 different threads can cause problems. This mostly occurs if we write from one of the threads causing the data structure to move in memory or make a location invalid. To avoid that we need something that allows us to lock ~~the access to that data to only one thread for a while and then unlock it granting the other thread access to it~~**[BD: and unlock the data from multiple threads at will. Maybe something else... That sentence was just a bit strange]**. That lock is called a mutex and it works more or less like this:

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

As you can see, the execution of a thread can be interrupted even while doing something like a `push_back()`. When we try to call `push_back()`, the vector internally calculates the next position to write but is then interupted by the operating system and it gives the execution to thread 1, which if it weren't for the mutex, would try to access a possibly invalid location **[BD: A bit wordy]**. Becuase we have the mutex, thread 2 is stopped at that point and thread 1 can continue writing to the vector without problem.

With today's multicpu machines both operations **[BD: specify which opperations]** might be happening simultaneously but the mutex prevents that from happening.

We just need to call `lock()` and `unlock()` on our ofMutex from inside of our `threadedFunction()` and from outside **[BD: clarify outside]** when trying to use shared memory:

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

**[BD: Does `NumberGenerator` need to extend `ofThread`? Perhaps I am mistaken. Where exactly is the ofMutex?]**

This example is kind of useless, but should explain the usage of the mutex in ofThread :).

As we've said before, when we lock a mutex we stop other threads from accessing it. It is important that we try to keep the lock time as small as possible **[BD: small statement on why]**.

## External threads and double buffering

Sometimes we don't have a thread that we've created ourselves, but instead we are using a library that creates it's own thread and calls our application on a callback. Let's see an example with an imaginary video library that calls us in callback **[BD: Elaborate on "calls us in callback"]** whenever there's a new frame from the camera:

**[BD: Can it be assumed that people even know what a callback is?]**

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

Here, even if we don't use a mutex, our application won't crash. That is because the memory in pixels is preallocated in setup and it's size never changes. For this reason the memory won't move from it's original location. The problem is that both the update and frame_cb functions might be running at the same time so we will probably end up seeing [tearing](http://en.wikipedia.org/wiki/Screen_tearing). Tearing is the same kind of effect we can see when we draw to the screen without activating the vertical sync.

To avoid tearing we might want to use a mutex:

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


That will solve the tearing, but we are stopping the main thread while the frame_cb **[BD: Do you mean to be referring to these function_names as `function_names`. Also, why the underscore instead of camelCase?]** is updating the pixels and stopping the camera thread while the main one is uploading the texture. For small images this is usually ok, but for bigger images we could loose some frames. A possible solution is to use a technique called double or even triple buffering:


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

With this we are locking the mutex for a very short time in the frame callback to set `newFrame = true` in the main thread. We do this to check if there's a new frame and then to swap the front and back buffers. swap **[BD: ?]**, is overridden for ofPixels and swaps the internal pointers to memory inside `frontPixels` and `backPixels` to point to one another. After calling it **[BD: Be explicit about what "it" is referring to]**, `frontPixels` will be pointing to what `backPixels` was pointing to before, and viceversa. This operation only involves copying the values of a couple of memory addresses plus the size and number of channels. For this reason it's way faster than copying the whole image or uploading to a texture.

Triple buffering is a similar technique that involves using 3 buffers instead of 2 and is useful in some cases. We won't see it in this chapter.

## ofScopedLock

Sometimes we need to lock a function until it returns a function **[BD: Perhaps just "returns"]**, or lock for the duration of a full block. That is exactly what a scoped lock does. If you've read the memory chapter you probably remember about stack semantics, or RAII [Resource Adquisition Is Initialization](http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization). A scoped lock makes use of that technique to lock a mutex while a block lasts **[BD: A block lasts what? Sorry, I don't mean to be this nitpicky, I am just trying to assume as naive a position as possible.]**:

For example, the previous example could be turned into:

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

As you can see, in some cases it makes more sense than others **[BD: What really illustrates that?]**. It's **[BD: Define what it is]** also a good way of avoiding problems because we forgot to unlock a mutex and allows us to use the `{}` to define the duration of the lock which is more natural to C++ **[BD: I think its capitalized but I could be wrong]**.

There's one particular case when the only way to properly lock is by using a scoped lock. That's when we want to return a value and keep the function locked until after the value was returned. In that case we can't use a normal lock:

```cpp

ofPixels accessSomeSharedData(){
    ofScopedLock lock(mutex);
    return modifiedPixels(pixels);
}

```

We could make a copy internally and return that later, but with this pattern we avoid a copy and the syntax is shorter.


## Poco::Condition

A condition, in threads terminology, is an object that allows **[BD: Allows what?]** to synchronize 2 threads. The pattern is something like this: one thread waits for something to happen before starting it's processing. When it finishes, instead of finishing the thread **[BD: Waiting for the thread to finish?]**, it locks in the condition and waits till there's new data to process. An example of this could be the image loader class we were working with earlier. Instead of starting one thread for every image, we might have a queue of images to load. The main thread adds image paths to that queue and the auxiliary thread loads the images from that queue until it is empty. The auxiliary thread then locks on a condition until there's more images to load.

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

The problem with that example is that the auxiliary thread keeps running as fast as possible in a loop, consuming full CPU from our computer which is not a very good idea.

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

When we call `condition.wait(mutex)` the mutex needs to be locked before **[BD: Be specific about before what]**, then the condition unlocks the mutex and blocks the execution of that thread until `condition.signal()` is called. When the condition awakens the thread because it's been signaled, it locks the mutex again and continues the execution. We can read the queue without problem because we know that the other thread won't be able to access it. We copy the next url to ping and unlock the mutex to keep the lock time to a minimum. Then outside the lock we ping the server and start the process again.

Whenever the queue gets emptied the condition will block the execution of the thread to avoid it from running in the background.

**[BD: Perhaps some sort of conclusion would be nice here]**

<em style="font-size:0.8em; text-align:center; display:block;">This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.</em>

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>
