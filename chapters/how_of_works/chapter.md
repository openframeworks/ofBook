# How openFrameworks works
## Brief description about common patterns used in the OF code

*by [Arturo Castro](http://arturocastro.net)*

openFrameworks is an open source C++ toolkit designed to assist the creative process by providing a simple and intuitive framework for experimentation. The toolkit is designed to work as a general purpose glue, and wraps together several commonly used libraries.

openFrameworks uses a few patterns so it's easy to understand how things work. Once you understand what these patterns are, it should be easier to use any of the functionality in openFrameworks.

If you are a developer contributing to OF then this document will also be useful to you, to know how to code your classes so they behave in a consistent way with the rest of openFrameworks

## setup, update, draw

Most functionality in openframeworks works using this pattern. In every example ofApp there's also always setup, update and draw methods.

### setup()

The setup method is called only once at the beginning of the application and it's used to initialize other objects or variables usually declared in `ofApp.h`.

__ofApp.h__

~~~~{.cpp}
ofVideoPlayer player;
int counter;
~~~~

__ofApp.cpp__

~~~~{.cpp}
void ofApp::setup(){
    player.loadMovie("movie.mov");
    counter = 0;
}
~~~~

In C++ it's super important to initialize variables since by default they are not initialized. For example, if we don't do `counter = 0;`, `counter` can have any value.


### update/draw()

Update and draw are called in an infinite loop one after another in that order, until we finish the application.

Update is meant to be used for updating the state of our application, do any calculations we need to do and update other objects like video players, grabbers, or any computer vision analysis we might be doing...

In draw we draw to the screen.


__ofApp.h__

~~~~{.cpp}
float x;
~~~~

__ofApp.cpp__

~~~~{.cpp}
void ofApp::setup(){
    x = 0;
}

void ofApp::update(){
    x++;
}

void ofApp::draw(){
    ofDrawCircle(x,120,30);
}
~~~~

will draw a circle at y=120 moving from the left to the right of the screen.

## Classes

openFrameworks is mostly organized in classes. There's 3 types of classes:

### Utility classes

These are classes that do something. They are classes like ofVideoGrabber, ofVideoPlayer, ofSoundPlayer, ofImage... Most of these classes work using the setup/update/draw pattern. Of course, for some of them draw won't make sense, e.g. an ofSoundPlayer doesn't have a draw method.

These classes also follow a shared pointer pattern. That means that when they are copied the copy is actually what is called a shallow copy. A shallow copy is only a reference to the object, not a copy of its contents.

For example, if you copy a video player and then modify the copy somehow that will also modify the original:

__ofApp.h__

~~~~{.cpp}
ofVideoPlayer player;
~~~~

__ofApp.cpp__

~~~~{.cpp}
void ofApp::update(){
    ofVideoPlayer player2 = player;
    player2.setFrame(100);
}
~~~~

will set the current frame to 100 both in player and player2 since actually both player and player2 are a reference to the same object


### Data containers

These classes contain data and can do some operations on the data they contain. Examples are classes like ofPixels or ofBuffer.

These classes follow an allocate/loadData pattern. Allocate reserves memory in the container to then put data in it using loadData. The names of these functions change depending on the class but the functionality is the same. Copying these classes makes a depth copy, that means that a copy is a whole new object with the same contents as the original so modifying the copy won't touch the original.

__ofApp.h__

~~~~{.cpp}
ofPixels pixels1, pixels2;
ofTexture tex1, tex2;
~~~~

__ofApp.cpp__

~~~~{.cpp}
void ofApp::setup(){
    pixels1.allocate(640,480,OF_IMAGE_COLOR);
    pixels1.set(0);
    pixels2 = pixels1;
    pixels2.setColor(10,10,ofColor(255,255,255));

    tex1.allocate(640,480,GL_RGB);
    tex2.allocate(640,480,GL_RGB);
    tex1.loadData(pixels1);
    tex2.loadData(pixels2);
}

void ofApp::draw(){
    tex1.draw(0,0);
    tex2.draw(660,0);
}
~~~~

will draw a completely black image in the left of the screen and a black image with a white pixel at 10,10 in the right. When we call `pixels2 = pixels1`,  `pixels2` is allocated with the same size and number of channels as `pixels1` and the data in `pixels1` is copied to `pixels2`.

### GL Data containers

GL data containers are a special case of data containers. The functionality is pretty similar to other data containers and they also follow the allocate/loadData pattern. These are classes like ofTexture, ofFbo, ofVbo or ofVboMesh. All of them are in the gl folder, although not everything in the gl folder is a data container, like ofShader or ofLight, which are GL utility classes and usually behave exactly the same as other utility classes.

The main difference between GL data containers and other data containers is that GL data containers follow a shallow copy pattern. The main reason for this is performance; making a copy of resources in the GPU is usually slow, so we don't copy them by default.

For example:

__ofApp.h__

~~~~{.cpp}
ofTexture tex1, tex2;
~~~~

__ofApp.cpp__

~~~~{.cpp}
void ofApp::setup(){
    tex1.allocate(640,480,GL_RGB);
    ofPixels pixels;
    pixels.allocate(640,480,OF_IMAGE_COLOR);
    pixels.set(0);
    tex1.loadData(pixels);
    tex2 = tex1;
    pixels.setColor(10,10,ofColor(255,255,255));
    tex2.loadData(pixels);
}

void ofApp::draw(){
    tex1.draw(0,0);
    tex2.draw(660,0);
}
~~~~

will draw a black rectangle with a white pixel at 10,10 in both left and right sides of the screen. This is because in this case we are copying the GL resource, which is actually just a reference to the texture ID of the first texture, not a full copy, so when modifying it we are also modifying the original.

### Data types

These are classes that represent types in openFrameworks like `ofRectangle`, `ofVec3f` or `ofMatrix4x4`.

## Functions

Some functionality in openFrameworks is provided through plain C functions. These are usually utility functions like `ofToString()`, `ofRandom()`, `ofDrawBitmapString()` and simple draw functions like `ofDrawCircle()`, `ofDrawRectangle()`.
