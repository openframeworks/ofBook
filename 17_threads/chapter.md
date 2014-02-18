# Threads

*by [Arturo Castro](http://arturocastro.net)*

*<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.*

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

<img src="https://rawgithub.com/openframeworks/ofBook/master/17_threads/simple_thread.svg" height="300"/>

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

3. threads and openGL
4. ofMutex
5. ofScopedLock
5. Poco::Condition
