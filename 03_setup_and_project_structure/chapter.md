
#openFrameworks project structure and setup

So, after you read a bit about C++ on chapter 2, let's get into openFrameworks, OF from now on. Chapter 1 talks about OF in very abstract and conceptual manner, which are really useful to understand in order to understand the decisions made to design the OF environment. So read it if you haven't.

I have found very useful to explain OF making analogies to cooking. Coding and cooking have a lot of things in common, and as almost everyone has experienced cooking it makes a lot of sense to me to use a cooking analogies/naming style.

##Welcome to your new kitchen##

###First things first###
You need to download the OF version and the IDE (acronym for Integrated Development Environment) that suit your platform. The IDE is a piece of software that will let you write, compile, run and debug the code you write. It is "Integrated" because this software uses other pieces of software to do each of the mentioned tasks, which you can also use in a separate way without using the IDE, but the IDE will make your programming life so much easier.

Go to [www.openframeworks.cc/downloads](www.openframeworks.cc/downloads "Download openFrameworks!") and download the version that you need. By the side of each available version you will find a link to the where to download the needed IDE and how to make it run.
So once you've done this and tested that installation went fine, by opening any example, compiling and running it without problems we are ready to continue.

###OF structure###

If you go into the uncompressed OF version that you downloaded you will find several folders, with several others inside, so let's take a look at what these are and how to use them.
We will call the OF root folder the one that your uncompressed OF download created, that should contain, at least, the following:

- addons
- apps
- examples
- libs
- other
- projectGenerator_
- scripts
####Addons####
Addons folder will contain the included "core" addons. Addons are extra pieces of code that extend OF's functionalities, allowing you to do almost anything with OF. Addons are usually written by third parties that have shared these. The "core" addons, the ones already included in your OF download, are addons that are used so frequently that it has been decided to include them as part of the oficial OF download. These are coded and mantained by the OF's core developers. 
You can go to [ofxAddons](http://ofxaddons.com/ "ofxaddons, a collection of OF addons") where you'll find almost every other Addon there is.
The included addons are the following:

- **ofx3DModelLoader**
Used for loading 3D models into your OF project. It only works with .3ds files.
- **ofxAssimpModelLoader**
Also loads 3D models into your OF project, but it is done using the [assimp](http://assimp.sourceforge.net/) library, which supports a wide variety of 3D file formats, even animated 3D objects.
- **ofxGui**
This is the default GUI (Graphical User Interface) for OF. It let's you add sliders and buttons so you can easily modify parameters while your project is running. It relies heavilly on ofParameters and ofParameterGroup. It allows you to save and load the values for the parameters that you've adjusted.
- **ofxKinect**
Recently added as a core addon. As you probably infer, it is to be able to use a Microsoft XBox Kinect 3D sensor with your OF project. This addon relies on [libfreenect](http://openkinect.org/wiki/Main_Page), so you can only access the depth and rgb images that the kinect reads and adjust some of it's parameters, like tilt and light. It includes some handy functions that allow you to convert kinect's data between several different kinds. Worth mentioning,  ofxKinect doesn't perform skeleton tracking. For such thing you need to use ofxOpenNI. 
- **ofxNetwork**
Lets you deal with network protocols such as UDP and TCP. You can use it to comunicate with other computers over the network. Check out chapter **[add correct chapter number]** about networking.
- **ofxOpenCv**
This is OF's implementation of the best and most used Computer Vision code library, openCV. Computer Vision is a complete world by itself, yet being able to use openCV right out-of-the-box is a super important and useful OF feature. Check chapter **[add correct chapter number]** that goes through several Computer Vision features and uses.
- **ofxOsc**
OSC (Open Sound Control) implementation for OF. OSC easily comunicates with other devices or applications within the same network. OSC is used to send mesagges and parameters from one app to another one. Check out chapter **[add correct chapter number]** which goes in depth with OSC and how to use it in the real word and chapter **[add correct chapter number]** that get into a more technical view of it.
- **ofxSvg**
Loads and displays SGV files. These are vector graphics files, usually exported from vector drawing programs such as Adobe Illustrator.
- **ofxThreadedImageLoader**
Loads images on a different thread, so your main thread (the one that draws to your screen) doesn't get stuck while loading images. Really useful when loading online images.
- **ofxVectorGraphics**
Used to write out EPS vector graphics files. It the same drawing syntax as OF's regular drawing syntax, so it is really easy to use. Check chapter **[add correct chapter numbre]** for more info about OF's drawing capabilities. 
- **ofxXmlSettings**
This is OF's old XML implementation. It is still here because a lot of addons and rely on it. The current XML implementation is called ofXml. The first uses the tinyxml library to parse the xml files, the latter uses Poco library to do such, which happens to be more powerful than tinyxml.

Check the examples/addons folder where you will find at least one example about how to use each of these addons.

####Apps####
This is the folder where you put your project files.
Your current OF download just contains the folder named "myApps" inside of "apps",
which just has an empty example project folder.
IMPORTANT: you have to respect the folder structure within the apps folder, otherwise your projects won't compile. This should be like this:
**[add image depicting a correct and incorrect apps folder structure usage]**

####Examples####
Quite obvious. A folder with examples, sorted out by topic. There are a big bunch of examples that cover almost all of OF's aspects. Each example is made with the idea of keeping it simple and focused to the particular aspect it tries to address, thus making it easily understandable and a good startpoint when you want to do something similar in your project.

####libs####
If you don't know what you are doing, **keep your hands out from this folder**.
Anything you change in here will affect your OF projects and probably you will not be able to compile.

####other##
Here you'll find an Arduino sketch for using with the serial example located at examples/communication/. This is handy to check that your serial communication with Arduino is setup correctly and working.

####projectGenerator_####
Here you'll find the OF project generator app. This is a super usefull app that lets you create new OF projects, add the addons you need to it and configure the project correctly so the addons work. Check the readme file inside where the usage of this app is described.

####scripts####
Just a few bash scipts usefull for compiling, cleaning and testing all the examples.
**[Should I add here how to use these bash scripts?]**

###IDE:###
- The main goal here would be to establish the similarities between all IDEs and explain where are the fundamental options needed to compile and solve common errors (missing include paths, linker errors).
- Adding files to the IDE, in particular adding addons (should we mention, as a sidenote Adam's xCode OF plugin?). How it must be done in each IDE.

As said before, the Integrated Development Environment, IDE, is the application you will be using to build your openFrameworks projects. It will let you write code, compile (bake it), test it and debug it (find out what is giving you problems, if there is any, and fix it).
There are several different IDEs, at least 1 for each platform you might be developing for.
The IDE is your new kitchen, where you'll find all the tools to cook incredible stuff. Yet there are a lot of different kitchen brands, just like IDEs. All do the same but things might be layed out and named in a slightly different way, but if you know how to use one you can use any other, you only need to get used to each one. This said, I will go through each IDE showing where you will find the most used commands, controls and settings. Only read for the IDE yo are going to use.

####Apple xCode####
xCode is Apple's IDE. Used both for iOS apps and desktop apps.
Even though there are other IDEs for MacOSX, xCode is a a pretty mature one, with lots of nice and useful features, specially for dealing with iOS apps.
The latest xCode version is 5.0.2 yet the OF projects can be opened in version 3 onwards. **[Cofirm this]**

####Microsoft Visual Studio####
**[add VS QUICK START GUIDE]**

#### Code::Blocks####
**[add C::B QUICK START GUIDE]**

####Eclipse####
**[add Eclipse QUICK START GUIDE]**


####The NO-IDE IDE.####
Using the terminal and makefiles.

- Possible scenarios where this is useful (rPI, remote compiling via SSH)
- How to deal with it. Installing the needed stuff to make it work (make, etc)
- How to use OF's make files. 
- Using addons

###The OF Pantry:###
Your default new kitchen will only have tools for coding, but the OF kitchen comes with a super nice pantry, filled up with really nice, cool and usefull stuff. 
Imagine that you want to cook a hamburger sandwich. There are lots of ingredients that you need. In the no-stuff-in-the-pantry scenario, you'll have to go out and buy all the needed ingredients, meaning that you won't be able to immediately cook and eat your delicious sandwich. What if you don't find the ingredients you need? You'll have to go out and kill a cow for its meat or grow up and harvest some veggies or both, all of which involve a lot of time and specific skills. And to make it worst you'll probably wont be able to do the best ones. All this means, cooking a sandwich is a real pain, and probably you will go out to the nearest fast food restaurant and buy there something. Just the usual stuff, not that deliciously homemade hamburger sandwich you envisioned at first. 
So, what happens when you have your pantry filled with OFs stuff? You will be able to cook and eat your sandwich, because some really good ingredients are already there. This will take you very little time to have it ready, letting you more time to get creative and try out new and more delicious recipes.

####What is inside the OF pantry####
Here you will find a lot of different things, from ingredients to tools, all ordered according to its use.

- 3d
    - Tools for drawing basic 3d poligonal objects, such as spheres, cubes, piramids, etc.
    - 3D cameras. For navigating and viewing your 3D scene. Either interactively or not.
    - 3D node. the base type for any 3d object, which allows it to be moved, rotated, scaled, parented
**[should I say "nested" instead]** and drawn.
    - 3D mesh. A collection of points in 3D space that allow you to draw them in several different ways,  such as points, lines, lines strips, triangles, triangles strips, and to attach textures (images) to these.
- app
- communication
    - Arduino communication via Firmata
    - Common serial port communication
- events
    - OF base events, event manager
- gl
    - OpenGL related handy things, such as VBOs (Vertex Buffer Object), FBOs (Frame Buffer Object), Renderers, Lights, Materials, Shaders, Textures, and several Gl utilities.
- graphics
    - 
- math
    - Vectors, Matrices, Quaternions and some really useful math helpers.
- sound
    - Sound player and sound grabber, with behind-the-scenes implementations for all the supported platforms.
    - Base sound object that allows to chain different sound objects, creating sound processing chains.
- types
    - A lot of different base types used extensively within OF.
- utils
    - 
- video
    - Video Grabbers and players.


###The recipes; .h and .cpp files:###
- Make a straight analogy between these files and recipes, the bill of materials, needed tools and instructions-steps.
- Why 2 files instead of just one.
- How these files are structured (in OF) -> setup, updat, draw, key, mouse and window events
- Peeking at others files, OF's files in search for some help.
- Some basic OOP, related to the idea of making a lot of the same recipe, how to deal with it. Link to the other chapters where OOP is covered.
