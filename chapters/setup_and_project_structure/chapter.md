#OF structure

*by [Roy Mcdonald](http://macrobio.cl/)*

Let's get into openFrameworks (I'll refer to it as OF from now on). The philosophy chapter talks about OF in very abstract and conceptual manner, which is really useful for understanding the design of the OF environment.  Now, let's take a look at what the OF download looks like.

I have found that it is very useful to explain OF by making analogies to cooking. Coding and cooking have a lot of things in common, and most people are familiar with the act of cooking. In this chapter, I'll be drawing connections between processes and terminology in cooking and openFrameworks.

##First things first##
You need to download the OF version and the IDE (Integrated Development Environment) that suits your platform. The IDE is a piece of software that will let you write, compile, run and debug the code you write. It is "integrated" because it uses other pieces of software to do each of the mentioned tasks. You can run your code without using the IDE, but the IDE will make your programming life much easier.

Go to [www.openframeworks.cc/downloads](www.openframeworks.cc/downloads "Download openFrameworks!") and download the version that you need. By the side of each available version you will find a link to the where to download the needed IDE and how to install it. 

##Welcome to your new kitchen

###IDE:

As said before, the *Integrated Development Environment*, IDE, is the application you will be using to build your openFrameworks projects. It will let you write code, compile (bake it), test it and debug it (find out what is giving you problems, if there is any, and fix it).
There are several different IDEs, at least one for each platform you might be utilizing.

The IDE is your new kitchen, where you'll find all the tools to cook incredible stuff. Yet there are a lot of different kitchen brands, just like IDEs. All do the same but things might be laid out and named in a slightly different way. If you know how to use one, you can use any other. For clarification, I will go through each IDE and show where you will find the most used commands, controls and settings. Only read for the IDE you are going to use.    

All IDEs have a similar interface:

![Abstract IDE interface](images/IDE_Interfase.jpg "Abstract IDE interface")

- Toolbar and Run Button: In the tool bar you'll find several useful buttons, such as open, save, save all, et cetera. The "run" button is very important. Usually it is labeled with a triangle pointing to the right, like the "play" button. When you press it, it will compile your code and if it went with no problem it will automatically run your code. Hence this is a frequently used button.
- File selector and project navigator area: Here you will see your project and the files associated with it. Usually it is displayed like a hierarchically ordered list of files. Here you'll find all the OF library files, as well as the files that are particular to your project.
- Editing area: When you open a file in the project navigation area, usually by double clicking it, it should open in the editing area. This looks just like any regular text-editing software, and behaves quite much the same.
- Console: This is where your app, when running, outputs messages. These messages are really useful for debugging, You can print text messages to the console using the `cout` comand  or `ofLog(...)` function.

####Apple Xcode

Xcode is Apple's IDE. Used both for iOS apps and desktop apps.
Even though there are other IDEs for MacOSX, Xcode is a a pretty mature one with lots of nice and useful features, especially for dealing with iOS apps.

Use the latest version of Xcode and read the setup guide. 

####Microsoft Visual Studio 2012 Express

This is Microsoft's IDE, it is aimed for Windows development. It's a commercial product, but there's a free version you can download called "Express". 

![VS screenshot](images/VS_ScreenShot.jpg "VS screenshot")

#### Code::Blocks

Code::Blocks is a free IDE. It runs on several platforms, but OF supports it for windows and linux. It is quite "light" in terms of downloading and we use it in workshops over VS, which can be a bit intimidating for beginners.  For windows, follow the setup instructions (including step "e") carefully.  For linux, there are scripts that help install dependencies and the codeblocks IDE. 


###Running examples

Find the OF version that you downloaded and decompress it. From now on we will refer to this folder as the OF root folder. You can place the OF root folder anywhere you like.   One thing to stress is that OF is designed to be self contained -- everything you need will stay in one folder and this folder can even be moved around on your drive if need be.  If you download another version of openframeworks, it should stay in it's own folder and don't try to merge them. 

Open it. Inside of it you will find several folders which we will describe below in more detail.  For now, navigate to the examples folder and let's try to compile examples/graphics/graphicsExample.   If you are on OSX, click on the graphicsExample.xcodeproj.  If you are using visual studio, choose the "sln" file.   On code::blocks, choose the "workspace" file.

*As a quick side note, about workspace files, the reason we ask you to open those rather then the project file is that they contain a sub-project to build the OF library also.   If you have any doubts, please read the readme for your given platform.*

Now your IDE should open and load this example. It should look like the IDE screenshots above. Locate the "Run" button or menu option and click on it. The example should compile (which might take a while, since the first time you compile you are comiling the OF library also).  You'll see alot of files being compiled the first time -- don't worry, this will just happen once, when the OF library needs to be rebuilt.  Feel free to get a cup of coffee or stretch.   Long compile times are great moments to take a screen break. 

If everything went well, a new window will pop up and display the example you just compiled. If this happened, congrats! You just have installed and compiled openFrameworks successfully and you are ready to go on. If this didn't happen, the first rule is, don't panic! check the notes below for each IDE and be sure to read the release notes that come with OF. 

- Xcode: make sure that the popdown menu just at the right of the run button has selected the item with the name of your example and not the one named "openFrameworks." There might be more than one item with the name of the example you are trying to run. Select anyone as long as it is not the one named "openFrameworks". This popdown menu selects the target you want to compile. If "openFrameworks" is selected you will just compile the openFrameworks core and not the example code. When you select the other items xcode will compile both the OF core and the code for your example and when done it will run the example. 
- VS: make sure you've opened the .sln file.  Visual studio express doesn't have a triangle button by default (I think it looks like a gear for debugging).  Locate the [run without debugging option](http://social.msdn.microsoft.com/Forums/vstudio/en-US/7b2182f9-0e46-4e6f-a8db-3ab5af39f14b/start-without-debugging-option-missing-from-debug-menu?forum=vsdebug), which you can add to the menu bar if you want to customize the IDE. 
- CB: make sure you've opened the .workspace file.   If you are opening up other projects, be sure to close the current workspace first, as CB doesn't handle multiple projects open very well.   
- With all IDEs, the play button will compile and run the project, but sometime you might need to hit the button twice if the window doesn't launch.

If the graphics example works, spend some time going through the other OF examples and running them.  Usually it's good practice to close the current project / workspace completely before you open another one.  Once the OF library is compiled It should be fun! 

If you have trouble, please keep track of what errors you have, what platform you are on, and start with using the [OF forum](http://forum.openframeworks.cc/).  There's years of experience there, and really helpful folks who can help answer questions.  First, try searching for a specific error and if you don't see it, post a question in the forum.  When you are beginning it can be quite frustrating, but the community is very good at helping each other out. 

Once done continue reading.

###OF folder structure###

Inside the OF root folder you will find several other folders, at least, the following:

####Addons####
The "addons" folder will contain the included "core" addons. Addons are extra pieces of code that extend OF's functionalities, allowing you to do almost anything with OF. Addons are usually written by third parties that have shared these. The "core" addons, the ones already included in your OF download, are addons that are used so frequently that it has been decided to include them as part of the official OF download. These are coded and maintained by OF's core developers.     
Check the examples/addons folder in your OF root folder where you will find at least one example about how to use each of these addons.
You can also go to [ofxAddons](http://ofxaddons.com/ "ofxaddons, a collection of OF addons") where you'll find a huge collection of additional addons from the community. 

####Apps####
This is the folder where you put your project files. Your current OF download contains the folder named "myApps" inside of "apps," which just has an empty example project folder. *IMPORTANT: you have to respect the folder structure within the apps folder, otherwise your projects won't compile.*   

This should be like this:
![Apps Folder structure](images/appsFolderStructure.png "Apps Folder Structure").

####Examples####
Quite obvious. A folder with examples, sorted out by topic. There are a big bunch of examples that cover almost all of OF's aspects. Each example is made with the idea of keeping it simple and focused to the particular aspect it tries to address, thus making it easily understandable and a good starting point when you want to do something similar in your project.

####libs####
If you don't know what you are doing, **keep your hands out from this folder**.
Anything you change in here will affect your OF projects and probably you will not be able to compile.

####other##
Here you'll find an Arduino sketch for using with the serial example located at examples/communication/. This is handy to check that your serial communication with Arduino is set up correctly and working.

####projectGenerator_####

OF now ships with a simple project generator which is really useful for making new projects.  One of the larger challenges has always been making a new project and this tool takes a template and modifies it, chaning the name to a new name that you choose and even allowing you to add addons. It allows you to place the project anywhere you want, and while we've structured all the examples to be a certain distance away from the root, you can change the height using this tool.  It's designed to make it easy / trivial to start sketching in code, without worrying too much about making a new project.  In the past we've always recommend that you copy an old project and rename it, but this is a more civilized approach to making projects. Check the readme file inside where the usage of this app is described. Further down there are some instructions on how to use the project generator **[Should I add these instructions or is it enough by pointing the reader to the readme file?]**

###The OF Pantry:###

Your default new kitchen will only have tools for coding, but the OF kitchen comes with a super nice pantry, filled up with really nice, cool and useful stuff. 

Imagine that you want to cook something but your kitchen has no pantry or if it has it is completely empty. In such conditions, cooking anything would be quite difficult, as you'll have to go out and buy the things you need and you probably won't find everything in one outing. This is not a nice scenario, especially if you want to get creative and make awesome things. 

So, what happens when you have your pantry filled with OF's components? You will be able to cook whatever you want because some really good ingredients are already there. Additionally, there are some really nice tools in there. This will let you complete recipes in a short amount of time, leaving you more time to get creative and try out new and more delicious recipes.

####What is inside the OF pantry####

Here you will find a lot of different things, from ingredients to tools, all ordered according to use.

- **3D**
    - Tools for drawing basic 3D polygonal objects, such as spheres, cubes, pyramids, etc.
    - 3D cameras. for navigating and viewing your 3D scene, either interactively or not.
    - 3D node. the base type for any 3d object, which allows it to be moved, rotated, scaled, nested and drawn.
    - 3D mesh. A collection of points in 3D space that allow you to draw them in several different ways such as points, lines, lines strips, triangles, triangles strips, and attach textures (images) to these. All of this is done very efficiently using your computer's GPU. 
    - Load and save 3D objects.
- **app**
    - Tools for setting and getting properties of your app such as window size, position, different drawing modes, framerate, et cetera.
- **communication**
    - Arduino communication via Firmata
    - Common serial port communication
- **events**
    - OF base events, event manager.
    - Listen to the base events, such as setup, draw, update, mouse, keys and window events.
    - You can also create your own custom events and listen to them, in a fast and straight forwards way, yet very reliable.
- **gl** 
    - OpenGL is the library for using the computer's GPU. 
    - OF comes with several openGL related stuff already implemented for multi-platform use, such as VBOs (Vertex Buffer Object), FBOs (Frame Buffer Object), Renderers, Lights, Materials, Shaders, Textures, and several other GL utilities.
    - OF implements different rendering pipelines, Fixed and Programable rendering pipelines as well as OpenGL ES (used on less powerful devices such as smartphones and the Raspberry Pi). You can choose to use the fixed or programable ones and OF takes care of handling everything needed for each rendering pipeline.
- **graphics**
    - There are a lot of capabilities here, such as loading and saving images of almost any kind, implementing several different methods for drawing in 2D, and exhibiting colors and styles. Most of the drawing tools rely on OpenGL so these are usually very fast. Graphics also allows you to render as PDF, and it features typography with several kinds of rendering options and utilities.
- **math**
    - Vectors, Matrices, Quaternions and some really useful math helpers.
- **sound**
    - Sound player and sound grabber, with behind-the-scenes implementations for all the supported platforms.
    - Base sound object that allows to chain different sound objects, creating sound processing chains.
- **base types**
    - A lot of different base types used extensively within OF.
- **utils**
    -  Utilities for file input and output, logging, threading, system dialogs (open, save, alert), URL file loader, reading and saving XML files (super useful for storing and reading your app's settings).
- **video**
    - Video Grabbers and players, with behind-the-scenes implementations for all the supported platforms. Get video from cameras attached to your computer or playback movies stored in it.s
 **[add image/drawing of the pantry]**

**[KL: It would help to go through and unify this list structure. Do full sentences come after each point on the list? If they're fragmented, how will you structure the list? Just be consistent in whatever method you choose so readers can follow along better. The same goes for lists below.]**

####Addons####
As mentioned before, addons extend OF core functionalities, and in each OF distribution there are several included addons, usually referred to as "core addons":

- **ofx3DModelLoader**
Used for loading 3D models into your OF project. It only works with .3ds files.
- **ofxAssimpModelLoader**
Also loads 3D models into your OF project, but it is done using the [assimp](http://assimp.sourceforge.net/) library, which supports a wide variety of 3D file formats, even animated 3D objects.
- **ofxGui**
This is the default GUI (Graphical User Interface) for OF. It lets you add sliders and buttons so you can easily modify parameters while your project is running. It relies heavilly on ofParameters and ofParameterGroup. It allows you to save and load the values for the parameters that you've adjusted.
- **ofxKinect**
Recently added as a core addon. As you probably infer, it's for using a Microsoft XBox Kinect 3D sensor with your OF project. This addon relies on [libfreenect](http://openkinect.org/wiki/Main_Page), so you can only access the depth and rgb images that the kinect reads and adjust some of its parameters, like tilt and light. It includes some handy functions that allow you to convert Kinect's data between several different kinds. Please note that ofxKinect doesn't perform skeleton tracking. For such thing you need to use ofxOpenNI. 
- **ofxNetwork**
Lets you deal with network protocols such as UDP and TCP. You can use it to communicate with other computers over the network. Check out chapter **[add correct chapter number]** about networking.
- **ofxOpenCv**
This is OF's implementation of the best and most used Computer Vision code library, openCV. Computer Vision is a complete world by itself, and being able to use openCV right out-of-the-box is a super important and useful OF feature. Check chapter **[add correct chapter number]** that goes through several Computer Vision features and uses.
- **ofxOsc**
OSC (Open Sound Control) implementation for OF. OSC easily comunicates with other devices or applications within the same network. OSC is used to send messages and parameters from one app to another one. Check out chapter **[add correct chapter number]** which goes in-depth with OSC and how to use it in the real word and chapter **[add correct chapter number]** that provides a more technical view of it.
- **ofxSvg**
Loads and displays SGV files. These are vector graphics files, usually exported from vector drawing programs such as Adobe Illustrator.
- **ofxThreadedImageLoader**
Loads images on a different thread, so your main thread (the one that draws to your screen) doesn't get stuck while loading images. Really useful when loading online images.
- **ofxVectorGraphics**
Used to write out EPS vector graphics files. It the same drawing syntax as OF's regular drawing syntax, so it is really easy to use. Check chapter **[add correct chapter numbre]** for more info about OF's drawing capabilities. 
- **ofxXmlSettings**
This is OF's old XML implementation. It is still here because a lot of addons rely on it. The current XML implementation is called ofXML. The first uses the TinyXML library to parse the XML files, the latter uses Poco library to do such, which happens to be more powerful than TinyXML.  

###The recipes of .h and .cpp files:###
Inside any OF project folder you will find a folder named "src" (short for source). Inside of it are the source code files used for each particular project. In the project navigator of your IDE you'll see this folder and its content listed. For any example or new project, at the most basic level, you'll see the following:
- main.cpp
- ofApp.h (testApp.h on older versions of OF)
- ofApp.cpp (testApp.cpp on older versions of OF) 

For now don't mind the "main.cpp" file as it only initializes the OF engine and starts your app, the one in the ofApp.h and ofApp.cpp files. We will focus on these two files. These are your app's recipes. 
Most cooking recipes have a list of materials, the needed tools, and the instructions. Your OF app also has these. The .h file is the list of materials and needed tools while the .cpp are the actual instructions and steps needed to compile and run (cook and eat) your app. In the most basic case we will just have one recipe, but you can have several other recipes used to create the main one. 
Why not have everything just in one big file? Actually you can, but it tends to be messier and a lot harder to read for anyone else.
If you are trying to understand someone else's code, it is much easier to do so when you have the .h and .cpp files. Or if, for example you want to use a certain addon, and you want to know which functions and methods are available you can simply go and read the .h file where you'll clearly see these listed, instead of going through a massive amount of text trying to figure out which are the available methods and functions.

Any OF app will have a predefined structure for coding it. 
Go to the examples and open the emptyExample. On your IDE's project navigator select the ofApp.h file and it should be displayed in the editing area.
It will look something like this

    #pragma once
    
    #include "ofMain.h"
	
	class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	};
Here is an explanation of whats going on line by line:  
````#pragma once```` Any line that starts with a # character is a preprocess directive. Before compiling happens all the needed files are stuck together. This directive says how this sticking together will commence. In the case of this line it is saying that this file must be included only once, otherwise you could have the same class defined more than once, which would lead into a compiler error. Usually, any .h file should have this at its very beginning.  
````#include "ofMain.h"```` This is another preprocess directive. It is saying to include the file ofMain.h, by which you'll have all the OF things available in your app. 
````class ofApp : public ofBaseApp{```` This is declaring a new class named ofApp (notice that usually classes are declared each on a separate file, with the filename the same as the class name. It is not a rule, it is just for tidiness). Then there is a colon that says this new class will inherit from another class, in this case the public methods and properties of ofBaseApp (the next chapter about object oriented programming (OOP) will explain this idea of inheritance).  
````public:```` This line is saying that the following declarations are public. This means that the declarations can be accessed from outside of this class. There also are "private", that only can be accessed by the class itself, and "protected" that can be accessed by the class itself or by a class that inherits from it.  

		void setup();
		void update();
		void draw();

These are OF's main loop methods (you should know what void means if you read the previous chapter).
````setup()```` is called only once when the app begins. This is where you set the initial parameters and initialize any object that your app is using that needs initialization. 
````update()```` is called constantly, once it finishes its execution it gets called again. How fast this happens depends on the framerate of your app, which you can set using ````ofSetFramerate(int )````, and the intensity of the tasks being done inside update(). These tasks usually have to do with processing data and updating variables, but not drawing.
````draw()```` is called every time the display refreshes, usually at 60Hz or 60 times per second. This speed depends on your computer settings. Inside of this method, you can say how things should be drawn into the screen. There are several chapters further on where you will learn how to draw in OF.    
By default the ````update()```` and ````draw()```` methods are synced, meaning that ````update()```` gets called first and then ````draw()````.
Like this:  
setup->update->draw->update->draw->.....  
You can set this with the function ````ofSetVerticalSync(bool bSync)````.  

Folks coming from processing, where there is just setup() and draw() often times wonder why we have two functions that repeat instead of one.  There's a couple of reasons: 

- Drawing in opengl is asynchronous, meaing after you fire off a bunch of commands to draw, they can be running in the background and return control back to your app.  If you separate out your drawing code from your non drawing code there's a potential your code will be faster.
- it's useful for debugging.  If you want to know why your code is running slow, now you can comment out the drawing and see if the visual representation that's slow or the updating.  


The next lines in the ofApp.h file are

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

All of these methods are event-driven, which means they get called when a particular event happens. The key and mouse methods are very self-explanatory. 
````windowResized(int w, int h)```` gets called when the window is resized, and its parameters are the new window size.   
````dragEvent(ofDragInfo dragInfo)```` is called whenever you drag and drop files over your OF app window. In its parameter there's a list of the files being dragged and dropped as well as the position over the window at which these were dropped.  
````gotMessage(ofMessage msg)```` this gets called when a message is received. OF has a simple messaging system that allows to send messages from one object to another.

Now if you look at your ofApp.cpp file you'll se the following:
(I removed the separator comments and the empty lines, just to make it shorter and clearer here).


	#include "ofApp.h"

	void ofApp::setup(){ }
	void ofApp::update(){ }
	void ofApp::draw(){ }
	void ofApp::keyPressed(int key){ }
	void ofApp::keyReleased(int key){ }
	void ofApp::mouseMoved(int x, int y){ }
	void ofApp::mouseDragged(int x, int y, int button){ }
	void ofApp::mousePressed(int x, int y, int button){ }
	void ofApp::mouseReleased(int x, int y, int button){ }
	void ofApp::windowResized(int w, int h){ }
	void ofApp::gotMessage(ofMessage msg){ }
	void ofApp::dragEvent(ofDragInfo dragInfo){ }

Here once again we find at the very beginning of the file a preprocess directive. ```#include "ofApp.h"```. This declaration is what actually sticks your .h and .cpp files. So it is very important to have it there.

All the following lines are the implementation of the methods defined in the .h file, hence this are the actual instructions or steps needed to follow.
What´s important here is what goes in between { and }. In this case as we are looking at the empty example there's nothing but in any other example you'll find instructions. Now that you know when and how each of these methods are called you can imagine what an OF app does just by reading the code. 

As an exercise, open any example, preferably a simple one (with not to much lines of code), and try to imagine what is going to happen just by reading the code. Once done, run the code. Did it happen the same as what you imagined? If not try to figure out what was that you imagined wrong. It should be useful to comment lines (by placing ```//``` at the beginning of the line) and see what happens, thus you can figure out what each instruction is doing. I think this a very useful way to strengthen your OF skills as well as your abstract thinking (which you'll need a lot if you pretend to go on with coding). 


###Project Generator###
**[Should I add instructions on how to use the PG or is it enough with its readme file?]**


###Using addons in your project###
First go through the addon examples to understand how to use it. Any decent addon should have at least one example.
Then, the easiest way to add addons to your project is using the project generator. Simply select the addon from the list and update your project. On the other hand you can manually add the addon files to your project, usually by dragging the addon folder into your IDE's project navigator. But be aware that you have to remove the addon examples, if it had any, from the project navigator otherwise your app will not compile. Additionally many addons rely on 3rd party libraries or code and the library search paths and/or include paths must be added manually also. To avoid all this hassle just use the project navigator :D

##Peeking at others or OF's files in search for some help.##
A very good way to learn how to code, and to use OF, is to read and try to understand other's code.
There are a lot of amazing projects out there that are opensourced that you can download and run in your computer.
You can start by looking at the github repositiories of the people that do addons.
At first, you might find that a project is very intimidating because it might have a lot of lines of code or the code itself might look intricate, but don't panic, disecting other's code shouldn't be to hard and it can be quite fun indeed.
Start by locating where the app begins it's execution and then follow the code from there. On any OF app you should start looking at the ofApp.h file (or testApp.h for older projects). Here, check which class instances are declared, this will be the app's objects. Also keep in mind any extra method declared.
Then, open the ofApp.cpp file and go to the setup() method. Here usually you'll find declared the initial values for the ofApp properties and any code that should be run just once when the app starts. Also here you might find calls to the app's objects initing methods. Some might be quite obvious but sometimes this won't or changing the parameters passed can give very different results, so you should dig a bit deeper and read what's going inside this method. In some cases you might go recursively doing this. Once you have understood what's going on in the setup() move to the update() and draw() methods. Remember how the execution flow happens, if both methods are in sync or not (by default this are in sync, so be aware of any call to ofSetVerticalSync(...)) and which properties they modify or depend on. Writting/drawing a flowchart can be very useful. Just as you did within the setup() method, look at what's being done, line by line, and if you find any call to an object method, go into it so to check what is being done. This time you have to keep in mind the looping nature of the update() and draw() methods. At first try to understand what's going on in just one loop. Once you are done try to imagine what happens when the loop happens more than once. Remember which variables and properties are modified and saved in each pass and how these affect the behaviour of the next pass. This can be a bit tricky so writing down notes either on the code or on a piece of paper will be quite helpful. Compare what you understood from reading the code with what you actually see that happens in the app. If you've done it correctly you should see the same that you imagined. Next take a look if there's any user interaction that affects the apps behaviour. Take a look at the mouse and keyboard callbacks, if there's any and imagine once again what happens when the mouse is pressed or dragged or a keystroke happens. You must keep in mind the idea behind this, that is to understand what other programmer did, so you can extract anything that can be useful for you. So always try to dig deeper into methods and functions as this usually give very important information about what's going on. And remember don't panic and a pen and piece of paper is always useful.

##Some basic OOP##
The next chapter is about object oriented programming or OOP. Before jumping into it let's recall the cooking recipe idea introduced in this chapter. OOP can be understood easily using the cooking analogy. Say you have a recipe for doing cookies. You can use the same recipe for doing one or a million cookies. The recipe won't change, just the amount of it that you want to do. OOP is essentially that. You write a piece of code, that is a class (a single recipe) and then you just declare as much instances of this class (objects) as you need. Just as for real objects, the OOP objects use space, and for each object you have to use a different space, thus it will be placed on a different location. In the same way each new object will have properties of its own. Like cookies, even they were made from the same recipe, each one will have a different amount and positioning of chocolate chips. OOP objects instanced from the same class will have the same variables, but depending on how it is written each object might have a different value for the same property, thus making each object unique, as unique as each cookie made from the same recipe.


##Into the oven (aka. compiling)

When you write code, your end goal is a compiled application - an .exe or .app that you can click on an run.  The job of the compiler is to make that executable for you, to turn text into compiled binary files. It's a 3 step process, and it's useful to know what's happening, especially since you can have errors at different steps along the way.  Most IDEs output out a very length file of the compiling, and this can be really useful if you are posting to the forums, for example.  Once you understand the process of how projects come to be, it can be easier to isolate errors.  Nothing is as frustrating or daunting as looking at 500+ errors in a project when you go to compile, but when you notice that there's a missing include, it's clear why and usually one thing will fix many of the problems. 

### preprocess

The first step is that a preprocessor modifies the text files themselves.  When you see the # symbol, that's a preprocessor operation.  The most common preprocessor statement you'll see is: 

`#include "xxxxx.h"`

which actually means, take the content of this file and put it right here.  **[NOTE: more on "" vs <> ]**  You'll also see things like: 

`#define PI 3.1428`

This means, when you see the word PI in the code, change it to this variable.  This isn't a variable, this is literally modifying text. 

Another common preprocessor step is asking a question. you can say things like: 

	#ifdef windows
		#include "windows.h"
	#else
	 	#include "nonWindows.h"
	#endif

As you can imagine this is increadibly useful for cross platform compilcation.  If you want to see preprocessor craziness, look at ofConstants.h. 

One common error you'll have in the preprocess phase is a file not found error, if you include a file like

	#include "opencv.h"
	
and it can't find the file, you will get an error at the preprocessing stage. The way to fix this is to add header search paths, basically the places (folders) the IDE goes to look for a file.  This is a common error when using a new library and one of the things the project generator is deisgned to help with when adding an addon. 

**[more on ofMain.h]**

### compile

Once the text has been modified, the job of the compiler is simply to take .cpp files and turn them into object code.  It's taking the text and turning it into machine language instructions (also referred to as assembly).  It doesn't touch the h files at all, it only thinks about .cpp files.  In the previous phase the .cpp file has all the h files it uses added to it recursively. 

This recursive h inclusion  is one reason while you will see include guards on the top of h files.  They will either look like:
	
	#ifndef SOMEWORD
	#define SOMEWORD
	...
	#endif
	
or the more modern 

	#pragma once

This is because if a file is included twice into a .cpp file the compiler could be confused.  If it's sees the same definition twice, like: 

	float position;
	float position;

it will not know which one is which.  The include guard prevents the file from being included twice. 

there are plenty of errors that can happen at compile time -- using a variable that you haven't defined for example.  The compiler will stop when it hits an error and the IDEs are designed to make it easy for you to see where the errors are and fix them.  

The compilers job in life is to take the .cpp files and turn them into .o files.  These are individual object files that it will compbine in the next phase, linking. 

### link

Finally, after we have a bunch of object files, our job is to link them into one thing -- in our case an application (alternatively, compilers can compile code into a library, for example).  This is what the linker does.  As you can imagine, there are jumps from one thing to another.  For example, in ofApp you could call a graphics call from ofGraphics: 

	void ofApp::draw(){
		ofCircle(100,100,20);
	}
	
This code is calling a function in another object.  The linker figures out the links from object to object (in this case between ofApp.o and ofGraphics.o) and links them together into one file. 

In addition to header search paths, there are also setting in the IDE for dealing with linker paths and libraries to link against.  A common error you might see is a link error, where the code in your project compiles fine, but it's having trouble linking because some object is missing.  For example, if you forget to include a .cpp file from the source code, the other code will comiple fine, but when the linker goes to make that jump, it can't find where to jump to.  Linker errors are described as "undefined reference" errors and occur at the end of the compile process. 





