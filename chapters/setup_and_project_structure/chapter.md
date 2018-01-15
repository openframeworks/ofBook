# oF structure

*by [Roy Macdonald](https://github.com/roymacdonald/)*

Let's get into openFrameworks (I'll refer to it as oF from now on). The philosophy chapter talks about oF in a very abstract and conceptual manner, which is really useful for understanding the design of the oF environment. Now, let's take a look at what the oF download looks like.

I have found it very useful to explain oF by making analogies to cooking. Coding and cooking have a lot of things in common, and most people are familiar with the act of cooking. In this chapter, I'll be drawing connections between processes and terminology in cooking and oF.

## First things first

You need to download the oF version and the [IDE](https://en.wikipedia.org/wiki/Integrated_development_environment "Wikipedia article on IDE") (Integrated Development Environment) that suits your platform. The IDE is a piece of software that will let you write, compile, run and debug the code you write. It is "integrated" because it uses other pieces of software to do each of the mentioned tasks. You can run your code without using the IDE, but the IDE will make your programming life much easier.

Go to [http://openframeworks.cc/download](http://openframeworks.cc/download "Download openFrameworks!") and download the version that you need. By the side of each available version, you will find a link to download the matching IDE and how to install it.

## Welcome to your new kitchen

### IDE

As said before, the *Integrated Development Environment*, IDE, is the application you will be using to build your oF projects. It will let you write code, compile (bake it), test it and debug it (find out what is giving you a problem, if there is any, and fix it). There are several different IDEs, at least one for each platform you might be utilizing.

The IDE is your new kitchen, where you'll find all the tools to cook incredible stuff. Yet there are a lot of different kitchen brands, just like IDEs. All do the same basic things but might be laid out and named in a slightly different way. If you know how to use one, you can use any other. For clarification, I will go through each IDE and show where you will find the most used commands, controls, and settings. Only read the IDE you are going to use.    

All IDEs have a similar interface:

![Abstract IDE interface](images/IDE_Interface.jpg "Abstract IDE interface")

- Toolbar and Run Button: In the tool bar you'll find several useful buttons, such as open, save, save all, et cetera. The "run" button is very important. Usually, it is labeled with a triangle pointing to the right, like the "play" button. When you press it, your code will compile and if no problems are encountered it will automatically run your code. Hence this is a frequently used button.
- File selector and project navigator area: Here you will see your project and the files associated with it. Usually, it is displayed as a hierarchically ordered list of files. Here you'll find all the oF library files, as well as the files that are particular to your project.
- Editing area: When you open a file in the project navigation area, usually by double-clicking it, it should open in the editing area. This looks just like any regular text-editing software and behaves much the same.
- Console: This is where your app, when running, outputs messages. These messages are really useful for debugging. You can print text messages to the console using the `cout` command or [`ofLog(...)`](http://openframeworks.cc/documentation/utils/ofLog.html "ofLog Documentation Page") function.

#### Apple Xcode

[Xcode](https://developer.apple.com/xcode/ "Xcode website") is Apple's IDE. It is used both for iOS apps and desktop apps. Even though there are other IDEs for OS X, Xcode is a pretty mature one with lots of nice and useful features, especially for dealing with iOS apps.

Use the latest version of Xcode and read the setup guide.

![Xcode screenshot](images/XcodeScreenShot.jpg "XCode screenshot")

#### Microsoft Visual Studio 2012 Express

[Visual Studio](http://visualstudio.com/ "Visual Studio website") is Microsoft's IDE, which is aimed at Windows development. It's a commercial product, but there's a free version you can download called "Express".

![Visual Studio screenshot](images/VS_ScreenShot.jpg "Visual Studio screenshot")

#### Code::Blocks

[Code::Blocks](http://codeblocks.org/ "Code::Blocks website") is a free/libre IDE. It runs on several platforms, but oF supports it for Microsoft Windows and Linux. It is quite "light" in terms of downloading and we (the contributors to this book) use it in workshops over Visual Studio, which can be a bit intimidating for beginners. For Microsoft Windows, follow the setup instructions (including step "e") carefully. There are scripts that help install dependencies and the Code::Blocks IDE for Linux.

![Code::Blocks screenshot](images/oF_codeblocks_1.png "Visual Studio screenshot of empty project")

## Running examples

Find the oF version that you downloaded and decompress it. From now on we will refer to this folder as the oF root folder. You can place the oF root folder anywhere you like. One thing to stress is that oF is designed to be self-contained -- everything you need will stay in one folder and this folder can even be moved around on your drive if need be. If you download another version of openFrameworks, it should stay in its own folder and don't try to merge them.

Open it. Inside of it, you will find several folders which we will describe below in more detail. For now, navigate to the examples folder and let's try to compile examples/graphics/graphicsExample. If you are on OS X, click on the graphicsExample.xcodeproj. If you are using Visual Studio, choose the ".sln" file. On Code::Blocks, choose the ".workspace" file.

*A quick side note about workspace files. The reason we ask you to open those rather than the project file is that they contain a sub-project to build the oF library also. If you have any doubts, please read the readme for your given platform.*

Now your IDE should open and load this example. It should look like the IDE screenshots above. Locate the "Run" button or menu option and click on it. The example should compile (which might take a while, since the first time you compile you are also compiling the oF library). You'll see a lot of files being compiled the first time -- don't worry, this will just happen once when the oF library needs to be rebuilt. Feel free to get a cup of coffee or stretch. Long compile times are great moments to take a screen break.

If everything went well, a new window will pop up and display the example you just compiled. If this happened, congrats! You just have installed and compiled openFrameworks successfully and you are ready to go on. If this didn't happen, the first rule is, don't panic! Check the notes below for each IDE and be sure to read the release notes that come with oF.

- Xcode: make sure that the pop-down menu just at the right of the run button has selected the item with the name of your example and not the one named "openFrameworks." There might be more than one item with the name of the example you are trying to run. Select any one of them as long as it is not the one named "openFrameworks". This pop-down menu selects the target you want to compile. If "openFrameworks" is selected you will just compile the openFrameworks core and not the example code. When you select the other items Xcode will compile both the oF core and the code for your example and when done, run the example.
- Visual Studio: make sure you've opened the .sln file. Visual Studio Express doesn't have a triangle button by default (I think it looks like a gear for debugging). Locate the [run without debugging option](http://social.msdn.microsoft.com/Forums/vstudio/en-US/7b2182f9-0e46-4e6f-a8db-3ab5af39f14b/start-without-debugging-option-missing-from-debug-menu?forum=vsdebug), which you can add to the menu bar if you want to customize the IDE.
- Code::Blocks: make sure you've opened the .workspace file. If you are opening up other projects, be sure to close the current workspace first, as Code::Blocks doesn't handle multiple open projects very well.   
- all IDEs: the play button will compile and run the project, but sometimes you might need to hit the button twice if the window doesn't launch.

If the graphics example works, spend some time going through the other oF examples and running them. Usually, it's good practice to close the current project / workspace completely before you open another one. Once the oF library is compiled, the projects should build quite quickly!

If you have trouble, please keep track of what errors you have, what platform you are on, and start using the [oF forum](http://forum.openframeworks.cc/) to find help. There are years of experience there, and really helpful folks who can help answer questions. First, try searching for a specific error and if you don't see it, post a question on the forum. When you are beginning it can be quite frustrating, but the community is very good at helping each other out.

Once done continue reading.

## oF folder structure

Inside the oF root folder you will find several other folders, at least, the following:

### Addons
The "addons" folder will contain the included "core" addons. Addons are extra pieces of code that extend oF's functionalities, allowing you to do almost anything with oF. Addons are usually written by third parties that have shared these. The "core" addons, the ones already included in your oF download, are addons that are used so frequently that it has been decided to include them as part of the official oF download. These are coded and maintained by oF's core developers.     
Check the examples/addons folder in your oF root folder where you will find at least one example of how to use each of these addons.
You can also go to [ofxAddons](http://ofxaddons.com/ "ofxaddons, a collection of oF addons") where you'll find a huge collection of additional addons from the community.

### Apps
This is the folder where you put your project files as you make new projects. Your current oF download contains the folder named "myApps" inside of "apps", and this is where the project generator will default to when you make a new project. One important thing to note is that the project is positioned relatively to the libs folder, i.e. if you were to look inside the project file you'd see relative folder paths, i.e. `../../../libs`. This image is showing how `../../../libs` might work visually:

![app position to root](images/projectPlacement.png)

A key thing to note is that your project files always have to live at this depth from the root. If you alter their depth, they won't find the other pieces they need to compile. This is a very common mistake for beginners, especially as you start to find example projects and bring them in oF to test, etc. Please make sure you understand that projects are always setup relative to the root level. This is what makes the whole oF folder able to be anywhere on your hard drive -- it's a self-contained package. This is probably the #1 issue beginners have, so it's worth emphasizing.


### Examples

This is a folder with examples, sorted by topic. There are a big bunch of examples that cover almost all of aspects oF. Each example is made with the idea of keeping it simple and focused on the particular aspect it tries to address. Therefore it should be easily understandable and a good starting point when you want to do something similar in your project.

### libs

These are the libraries that openFrameworks uses to compile your project. They include things like [FreeType](http://freetype.org/ "FreeType website") for typography support, [FreeImage](http://freeimage.sourceforge.net/ "FreeImage project website") for image loading, glfw for windowing, etc. Also, the code for openFrameworks is in libs, as well as the project files that help compile oF. If you need to look at the source code, here's where to look.

### other
Here you'll find an [Arduino](http://www.arduino.cc/ "website if the Arduino single-board microcontroller") sketch for using the serial example located at examples/communication/. This is handy to check that your serial communication with Arduino is set up correctly and working.

### projectGenerator

oF now ships with a simple project generator which is really useful for making new projects. One of the larger challenges has always been making a new project. This tool takes a template (located in the scripts folder) and modifies it, changing the name to a new one that you choose and even allowing you to specify addons. It allows you to place the project anywhere you want, and while we've structured all the examples to be a certain distance away from the root, you can set the position using this tool (e.g. if you put the project deeper, it will change the `../../../libs` to `../../../../libs`). It's designed to make it easy / trivial to start sketching in code, without worrying too much about making a new project. In the past, we've always recommended that you copy an old project and rename it, but this is a more civilized approach to making projects. Check the readme file where the usage of this app is described.

## The oF Pantry

Your default new kitchen will only have tools for coding, but the oF kitchen comes with a super nice pantry, filled up with really nice, cool and useful stuff.

Imagine that you want to cook something but your kitchen has no pantry or if there is one it is completely empty. Cooking anything would be quite difficult under such conditions, as you'd have to go out and buy the things you need and you probably won't find everything in one outing. This is not a nice scenario, especially if you want to get creative and make awesome things.

So, what happens when you have your pantry filled with oF's components? You will be able to cook whatever you want because some really good ingredients are already there. Additionally, there are some really nice tools in there. This will let you complete recipes in a short amount of time, leaving you more time to get creative and try out new and more delicious recipes.

### What is inside the oF pantry

Here you will find a lot of different things, from ingredients to tools, all ordered according to use. This is a breakdown of how oF code is organized (as well as the examples) and should give you a sense of what oF contains:

- **3D**
    - tools for drawing basic 3D polygonal objects, such as spheres, cubes, pyramids, etc.
    - [`ofCamera`](http://openframeworks.cc/documentation/3d/ofCamera.html "ofCamera Documentation Page"), [`ofEasyCam`](http://openframeworks.cc/documentation/3d/ofEasyCam.html "ofEasyCam Documentation Page"), 3D cameras for navigating and viewing your 3D scene, either interactively or not
    - [`ofNode`](http://openframeworks.cc/documentation/3d/ofNode.html "ofNode Documentation Page"), a 3D point in space, which is the base type for any 3D object, allowing it to be moved, rotated, scaled, nested and drawn
    - [`ofMesh`](http://openframeworks.cc/documentation/3d/ofMesh.html "ofMesh Documentation Page"), a primitive for batching points in 3D space that allows you to draw them in several different ways such as points, lines, line strips, triangles, triangle strips, and attach textures (images) to these. All of this is done very efficiently using your computer's GPU
    - functions to help load and save 3D objects
- **app**
    - tools for setting and getting properties of your app such as window size, position, different drawing modes, frame rate, etc.
    - different windowing systems, such as [`ofAppNoWindow`](http://openframeworks.cc/documentation/application/ofAppNoWindow.html "ofAppNoWindow Documentation Page") which sets up openFrameworks in a windowless context
- **communication**
    - [`ofSerial`](http://openframeworks.cc/documentation/communication/ofSerial.html "ofSerial Documentation Page") provides simple serial port communication
    - [`ofArduino`](http://openframeworks.cc/documentation/communication/ofArduino.html "ofArduino Documentation Page") allows openFrameworks to communicate via [Firmata](http://playground.arduino.cc/Interfacing/Firmata "Arduino reference for Firmata")
- **events**
    - the oF event manager, allowing you to tap into app events if you need or even creating your own events
- **gl**
    - [OpenGL](https://en.wikipedia.org/wiki/OpenGL "Wikipedia article on OpenGL"), the library for using the computer's [GPU](https://en.wikipedia.org/wiki/Graphics_processing_unit "Wikipedia article on the graphics processing unit")
    - contains GL specific functionality such as VBOs (Vertex Buffer Object), FBOs (Frame Buffer Object), Renderers, Lights, Materials, Shaders, Textures, and several other GL utilities
    - oF implements different rendering pipelines (fixed, programmable & OpenGL ES (used on less powerful devices such as smartphones and the Raspberry Pi)) -- most of this code is found in the gl folder
- **graphics**
    - capabilities such as loading, drawing and saving images of almost any kind, e.g. via [`ofImage`](http://openframeworks.cc/documentation/graphics/ofImage.html "ofImage Documentation Page")
    - also allows you to render as PDF
    - several different methods for drawing in 2D, and exhibiting colors and styles
    - most of the drawing tools rely on OpenGL so these are usually very fast
    - typography with several kinds of rendering options and utilities e.g. [`ofTrueTypeFont`](http://openframeworks.cc/documentation/graphics/ofTrueTypeFont.html "ofTrueTypeFont Documentation Page"), a library for loading and drawing [TrueType fonts](https://en.wikipedia.org/wiki/TrueType "Wikipedia article on TrueType font format")
- **math**
    - mostly math related tools
    - vectors (i.e. [`ofVec2f`](http://openframeworks.cc/documentation/math/ofVec2f.html "ofVec2f Documenation Page"), [`ofVec3f`](http://openframeworks.cc/documentation/math/ofVec3f.html "ofVec3f Documentation Page"))
    - matrices (i.e. [`ofMatrix3x3`](http://openframeworks.cc/documentation/math/ofMatrix3x3.html "ofMatrix3x3 Documenation Page"), [`ofMatrix4x4`](http://openframeworks.cc/documentation/math/ofMatrix4x4.html "ofMatrix4x4 Documenation Page"))
    - quaternions (i.e. [`ofQuaternion`](http://openframeworks.cc/documentation/math/ofQuaternion.html "ofQuaternion Documentation Page"))
    - useful math help functions like [`ofRandom`](http://openframeworks.cc/documentation/math/ofMath.html#!show_ofRandom "ofRandom Documentation Page") and [`ofNoise`](http://openframeworks.cc/documentation/math/ofMath.html#!show_ofNoise "ofNoise Documentation Page").
- **sound**
    - low level sound access directly on sound card, e.g. [`ofSoundStream`](http://openframeworks.cc/documentation/sound/ofSoundStream.html "ofSoundStream Documentation Page")
    - higher level code for playing samples and sound effects, e.g. [`ofSoundPlayer`](http://openframeworks.cc/documentation/sound/ofSoundPlayer.html "ofSoundPlayer Documentation Page")
- **base types**
    - a lot of different base types for common elements used extensively within oF
    - mostly for folks that want to understand the architecture of oF,
- **utils**
    - utilities for
      - file input and output (also via URLs)
      - logging
      - threading
      - system dialogs (open, save, alert)
      - reading and saving [XML](https://en.wikipedia.org/wiki/XML "Wikipedia article on XML") files (super useful for storing and reading your app's settings)
    - e.g. [`ofDirectory`](http://openframeworks.cc/documentation/utils/ofDirectory.html "ofDirectory Documentation Page") can help iterate through a directory
- **video**
    - video grabber and player, with behind-the-scenes implementations for all the supported platforms.
    - [`ofVideoGrabber`](http://openframeworks.cc/documentation/video/ofVideoGrabber.html "ofVideoGrabber Documentation Page") helps with grabbing from a webcam or attached camera
    - [`ofVideoPlayer`](http://openframeworks.cc/documentation/video/ofVideoPlayer.html "ofVideoPlayer Documentation Page") helps with playing video files


### Addons

As mentioned before, addons extend oF core functionalities. In each oF distribution there are several included addons, usually referred to as "core addons":

- **ofx3DModelLoader**
Used for loading 3D models into your oF project. It only works with .3ds files.
- **ofxAssimpModelLoader**
Also loads 3D models into your oF project, but it is done using the [assimp](http://assimp.sourceforge.net/) library, which supports a wide variety of 3D file formats, even animated 3D objects.
- **ofxGui**
This is the default GUI (Graphical User Interface) for oF. It lets you add sliders and buttons so you can easily modify parameters while your project is running. It relies heavily on ofParameters and ofParameterGroup. It allows you to save and load the values for the parameters that you've adjusted.
- **ofxKinect**
As you probably infer, it's for using a [Microsoft XBox Kinect](https://en.wikipedia.org/wiki/Kinect) 3D sensor with your oF project. This addon relies on [libfreenect](http://openkinect.org/wiki/Main_Page), so you can only access the depth and RGB images that the Kinect reads and adjust some of its parameters, like tilt and light. It includes some handy functions that allow you to convert Kinect's data between several different kinds. Please note that ofxKinect doesn't perform skeleton tracking. For such thing you need to use ofxOpenNI.
- **ofxNetwork**
Lets you deal with network protocols such as UDP and TCP. You can use it to communicate with other computers over the network. Check out the network chapter for more information.
- **ofxOpenCv**
This is oF's binding to one of the best and most used computer vision code library, [OpenCV](http://opencv.org/). Computer vision is a complete world in itself, and being able to use OpenCV right out-of-the-box is a super important and useful oF feature.
- **ofxOsc**
OSC (Open Sound Control) implementation for oF. OSC easily communicates with other devices or applications within the same network. OSC is used to send messages and parameters from one app to another one. Several chapters in this book discuss OSC.
- **ofxSvg**
Loads and displays [SVG](https://en.wikipedia.org/wiki/Scalable_Vector_Graphics "Wikipedia article on SVG") files. These are vector graphics files, usually exported from vector drawing programs such as Inkscape or Adobe Illustrator.
- **ofxThreadedImageLoader**
Loads images on a different thread, so your main thread (the one that draws to your screen) doesn't get stuck while loading images. Really useful when loading online images.
- **ofxVectorGraphics**
Used to write out [EPS](https://en.wikipedia.org/wiki/Encapsulated_PostScript "Wikipedia article on encapsulated PostScript (eps)") vector graphics files. It the same drawing syntax as oF's regular drawing syntax, so it is really easy to use. Check chapter **[add correct chapter number]** for more info about oF's drawing capabilities.
- **ofxXmlSettings**
This is oF's simple XML implementation used mostly for loading and saving settings.

That's what's in the pantry.  What do you want to cook?

![pantry, image courtesy [http://resultsroom.co.nz/stock-pantry-fridge/](http://resultsroom.co.nz/stock-pantry-fridge/)](images/pantry.jpg)
