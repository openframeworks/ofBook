# Threads

*by [Arturo Castro](http://arturocastro.net)*

*corrections by Brannon Dorsey*

## What's a thread and when to use it

Sometimes in an application we need to execute tasks that will take a while to finish. The perfect example is reading something from disk. In the computer the CPU is way faster than accessing the memory which is way faster than accessing the hard disk. So accessing, for example, an image from the HD can take a while compared to the normal flow of the application.

In openFrameworks, and in general, usually when working with openGL, our application will run in an infinite loop calling update/draw every cycle of the loop. If we have vertical sync enabled, and our screens works at 60Hz, each of those cycles will last around 16ms (1s/(60frames/s))*1000(ms/s). Loading an image from disk can take way more than those 16ms, so if we try to load an image from our update method, for example, we'll notice a pause in our animation.

To solve this we usually use threads. Threads are a way of executing certain tasks inside an application outside of the main flow. That way we can run more than one task at once so things that are slow don't stop the main flow of the application. We can also use threads to accelerate tasks by dividing them in several smaller tasks and running each of those at the same time. You can think of a thread as a subprogram inside your program.

Every application has at least 1 thread. In openFrameworks, that thread is where the setup/update/draw loop happens. We'll call this the main (or openGL) thread. But we can create more threads and each of them will run separately from the others.

So if we want to load an image in the middle of our application, instead of loading our image in update, we can create a thread that loads the image for us. The problem with this is that once we create a thread, the main thread doesn't know when it has finished, so we need to be able to communicate the results from our auxiliary thread to the main one. There's also problems that might arrise from different threads accessing the same areas in memory. We'll need some mechanisms to synchronize the access to shared memory between 2 or more threads.

First let's see how to create a thread in openFrameworks.

## ofThread

Every application has at least one thread, the main thread (also called the GL thread), when it's using openGL.

But as we've said we can create auxiliary threads to do certain tasks that would take too long to run in the main thread. In openFrameworks we can do that using the ofThread class. ofThread is not meant to be used directly, instead we inherit from it and implement a `threadedFunction` which will later get called from the auxiliary thread once we start it:

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

This way the loading of the image happens simultaneously to our update/draw loop and our application doesn't stop while waiting till the image is loaded from disk.

Now, how do we know when our image is loaded? The thread will run separately from the main thread of our application:

![Simple Thread](images/simple_thread.png "Simple Thread")

As we see in the image the duration of loading of the image and thus the duration of the call to threadedFunction is not automatically known to the main thread. Since all our thread does is load the image, we can check if the thread has finished running which will tell us that the image has loaded. For that ofThread has a method: `isThreadRunning()`:

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
        ofLoadImage(image,path);
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
    imgLoaders.back()->load("someimage.png");
}
```

Another possibility would be to use 1 thread only. To do that a possible solution would be to use a queue in our loading thread whenever we want to load a new image. To do this we insert it's path in the queue and when the threadedFunction finishes loading one image it checks the queue. If there's a new image it loads it and it is removed from the queue.

The problem with this is that we will be trying to access the queue from 2 different threads, and as we've mentioned in the memory chapter, when we add or remove elements to a memory structure there's the possibility that the memory will be moved somewhere else. If that happens while one thread is trying to access it we can easily end up with a dangling pointer that will cause the application to crash. Imagine the next sequence of instruction calls from the 2 different threads:

        loader thread: finished loading an image
        loader thread: pos = get memory address of next element to load
        main thread:   add new element in the queue
        main thread:   queue moves in memory to an area with enough space to allocate it
        loader thread: try to read element in pos  <- crash pos is no longer a valid memory address

At this point we might be accessing a memory address that doesn't contain a string anymore, or even trying to access a memory address that is outside of the memory assigned to our application. In this case the OS will kill it sending a segmentation fault signal as we've seen in the memory chapter.

The reason this happens is that since thread 1 and 2 run simultaneously we don't know in which order their instructions area going to get executed. We need a way to ensure that thread 1 cannot access the queue while thread 2 is modifying it and viceversa. For that we'll use some kind of lock: In C++ usually a mutex, in openFrameworks an ofMutex.

But before seeing mutexes, let's see briefly some particulars of using thread while using openGL.

## Threads and openGL

You might have noticed in the previous examples:

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

As we mentioned in the advanced graphics chapter and other parts of this book, openGL works asynchronously in some kind of client/server model. Our application is the client sending data and drawing instructions to the openGL server which will send them to the graphics card in it's own times.

Because of that, openGL knows how to work with one thread, the main thread from which the openGL context was created. But if we try to do openGL calls from a different thread we will most surely crash the application, or at least not get the desired results.

When we call `img.loadImage(path)` on an ofImage, it'll actually do some openGL calls, mainly create a texture and upload to it the contents of the image. If we did that from a thread that isn't the GL thread, our application will probably crash or just don't load the texture properly.

There's a way to tell ofImage, and most other objects that contain pixels and textures in openFrameworks, to not use those textures and instead work only with pixels. That way we could use an ofImage to load the images to pixels and later in the main thread activate the textures to be able to draw the images:

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

To avoid that we need something that allows to access that data to only one thread simultaneously. For that we use something called mutex. When one thread want's to access the shared data, it locks the mutex and when a mutex is locked any other thread trying to lock it will get blocked there until the mutex is unlocked again. You can think of this as some kind of token that each thread needs to have to be able to access the shared memory. 

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

