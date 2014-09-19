# philosophy

*by [Zach Lieberman](http://thesystemis.com)*

openFrameworks is guided by a number of goals: it should be collaborative, usable and simple, consistent and intuitive, cross-platform, powerful, and extensible. openFrameworks is also driven by a "do it with others" (DIWO) philosophy.

### Collaborative

openFrameworks development is collaborative. It thrives on the contributions of many people who engage in frequent discussion, and collaborate on addons and projects. We encourage people to make openFrameworks their own and contribute to the ecosystem.

openFrameworks is developed in a collaborative way. We use git, a distributed versioning system, which means that people can branch, experiment, and make suggestions. If you look at the network diagram on GitHub, it looks like some alien diagram, full of weaving branches, code pulling apart and coming together. There's a huge community all over the world working on the core code: fixing bugs, submitting pull requests, and shaping the tool the way they want to see it. It's a world wide project and it's common to wake up in the USA to an inbox full of pull requests and issues emails from coders in Asia and Europe. Over 70 people have contributed to the openFrameworks core directly, and hundreds of people have forked the code or contributed in other ways.

### Simplicity

openFrameworks tries to balance usability and simplicity. The earliest versions of openFrameworks used the core as a tool for teaching C++ and OpenGL, but over time the examples have become the best way to learn while the core takes advantage of more advanced features. In exchange, we've created many more examples that come with openFrameworks, with the goal of trying to make simple, hackable starting points for experimentation.

We want openFrameworks to be as simple as possible, especially for folks coming from other languages and environments. C++ is a "large" language, large in the sense that you can write very different types of C++ code. If you go to the bookstore, you'll see hundreds of C++ books. We want to create a library where you don't need to be an expert, where at most you might need a book or two, but that the patterns, approaches and style of the code is simple and intuitive. We were especially interested in achieving a sort of parity with Processing, where many of the functions are similar, allowing easier movement from one framework to another.

### Consistent and Intuitive

openFrameworks is consistent and intuitive: it should operate on the principle of least surprise, so that what you learn about one part of openFrameworks it can be applied to other parts of it. Beginners can use openFrameworks to learn about common programming patterns, and advanced users will be able to apply their experience from other languages and toolkits.

Student first is the motto. A lot of the thinking guiding openFrameworks is: what would I would have liked in a tool 5 or 10 years ago? We want the patterns of coding to be simple and to make it as easy as possible to type. This means having self-explanatory function names like "play" and "stop" for video players, and variable names that are intuitive. We have lots of discussions about intuition, driven by a desire to make the code as straightforward as possible. You should learn by typing, autocomplete should be helpful, etc.

### Cross-platform

openFrameworks is a cross-platform toolkit. openFrameworks supports as many development environments and operating systems as possible. When you download openFrameworks, you can pick your platform and development environment of choice, and have projects and examples ready to learn from and play with. Difficult to port code is kept out of the core, and kept in addons instead.

openFrameworks is designed to work on a multitude of platforms: OS X, Windows, Linux, iOS, Android, embedded ARM Linux systems, as well as experimental platforms such as BlackBerry PlayBook. openFrameworks developers have devised some clever ways of interfacing with other languages, such such as Java in the case of Android, or Objective-C in the case of iOS.

The joy of a cross-platform library is that it's easy to port your ideas from platform to platform. You can sketch on your laptop then immediately run it on your phone. It allows your ideas to come first, without worrying about the grunt work in making something work across platforms.

### Powerful

openFrameworks is powerful: it allows you to leverage advanced libraries like OpenCV, use hardware like your graphics card efficiently, and connect peripherals like cameras and other devices.

We chose C++ because it's a fairly low level language but can still be programmed in a high level way. Because C++ is an extension of the older C programming language, it's possible to write very low level, oldschool C code or higher level C++ code. In openFrameworks, we try to harness both approaches and present simple, clear, yet powerful ways of working with code. Using C++ also makes it easier to interface to the many libraries that have been written in C and C++ without needing to rely on a wrapper for another language.

openFrameworks essentially wraps other libraries such as OpenGL, Cairo, FreeType, FreeImage, and OpenCV. You can think of openFrameworks as a layer of code between user code (the code you will write) and these libraries. The libraries have different styles, idioms, approaches, etc. and our job is to wrap them in a way which makes them more consistent and intuitive.

### Extensible

openFrameworks is extensible. When you find something missing from openFrameworks it's easy to create addons that extend it. The core addons for openFrameworks generally wrap libraries rather than solving problems in novel ways. When openFrameworks wraps libraries, the libraries are left exposed for further hacking.

One mental image of openFrameworks is a scaffolding, or shoulders to stand on, while building what you want. One thing that helps keep the core light is that rather than try to include everything we can, openFrameworks has an "addon" system that allows for additional code, libraries, and approaches to be shared between users and woven into projects as necessary.

An openFrameworks addon can be a snippet of code, or it might wrap much more complex libraries such as OpenNI, Tesseract, or Box2d. Addon names usually begin with the prefix "ofx", allowing you to easily see the difference between "core" code and non core code. In addition, we include "core addons", addons that we think people will probably want to use, such as ofxOpenCv, but aren't essential for every project.

We try to organize and support the community developing addons through the http://ofxaddons.com site, which automatically collects addons from GitHub by looking for repos that contain the term "ofx" in the title. Right now there are more than 1,500 addons.

### Do it with others (DIWO)

<<<<<<< HEAD
The driving philosophy behind openFrameworks is "do it with others" (DIWO). We love do it yourself (DIY) culture, which has been heavily promoted and facilitated by the rise of tutorial websites like Instructables or Make. But we're also excited about the idea of "making socially" ("with others"). We practice DIWO through workshops, developer conferences, hackathons/labs, knitting circles and meetups in person, and online in the form of mailing lists, forum posts, and so on. We even have a gang sign. Because if you have a gang, you have to have a gang sign. The most important thing we want to stress is that you are not alone, that there's a great group of people out there learning, teaching, hacking, making and exploring the creative side of code.

## OF structure

The most important thing to understand about OF is that it has been designed to be a self contained structure.  You download OF from the website and that version of OF can go anywhere on your hard drive.   You shouldn't mix different versions of OF and while older projects might work in newer versions of OF, that's not always a guarantee, especially if there's been a major release. 

Because OF can go anywhere on your hard drive, all the internal links are relative.  A project file, for example, looks to `../../../libs` rather then a fixed path like `C:Documents and Settings\OF` (on windows) or `/Users/name/Desktop/OF` (on linux / osx).  This means that you have to be extremely careful about the depth that a project is away from the root of the OF folder.  This is one of the most common mistakes beginners make, they have a project that they either move too shallow or too deeply, or they find and use other people's code but don't put it in the right spot.  I simply can't stress this point enough: project files have relative paths.  It's sweet, because it means you can share projects easily (it doesn't have a fixed path with your name on it, for example) and you can move the whole OF folder around, but it still trips many beginners up.  



**[NOTE: I think below here belongs in Roy's chapter.... this chapter is more historical and conceptual, these are more practical]**



## project generator

OF now ships with a simple project generator which is really useful for creating new projects.  One of the larger challenges has always been making a new project and this tool takes a template and modifies it, chaning the name to a new name that you choose and even allowing you to add addons, additional libraries that come with OF or that you can download.  It allows you to pick where you want the project to go, and while we've structured all the examples to be a certain distance away from the root, you can change the height using this tool.  It's designed to make it easy to start sketching in code without worrying too much about making a new project.  In the past we've always recommend that you copy an old project and rename it, but this is a more civilized approach to making projects. 


## .h and .cpp

In OF (which is C++) you'll see .cpp and .h files (they are sometimes labeled as cxx or hpp files, respectively).  The h files are the header files and cpp files are the implementation files.  Header files are definitions -- they show what's going to be in the code and implementation files are the actual steps.  One anology is like a book, the header file is like the the table of contents of the book and describes the layout of the book and the implementation files are like the chapters, where the book is written.  Another analogy is a recipe, where you have the list of ingedients (header files) and the actual steps (implementation files).   It's useful to know about this split as a lot of modern languages don't have this split.  

**MORE**

## setup/update/draw

OF runs in a kind of game loop model - where we get you a context to draw into and try to run as fast as we can and repetedly draw.  There are 3 main functions that you'll see a majority of the code in (as well as the event functions like mousePressed, keyPressed, etc) 

* setup()
* update()
* draw()

Setup gets called once, at the first moment we have a window context and it's a good place for initializing variables and loading in files.   Update and draw get called repeatedly.  Update is for doing non visual changes, such as altering variables or performing analysis, draw is where we do any drawing.   The order they get called in is: 

setup->update->draw->update->draw->.....

Folks coming from processing, where there is just setup() and draw() often times wonder why we have two functions that repeat instead of one.  There's a couple of reasons: 

* Drawing in opengl is asynchronous, meaing after you fire off a bunch of commands to draw, they can be running in the background and return control back to your app.  If you seperate out your drawing code from your non drawing code there's a potential your code will be faster.
* it's useful for debugging.  If you want to know why your code is running slow, now you can comment out the drawing and see if the visual representation that's slow or the updating. 

## preprocessor/compiler/linker

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

=======
The driving philosophy behind openFrameworks is "do it with others" (DIWO). We love do it yourself (DIY) culture, which has been heavily promoted and facilitated by the rise of tutorial website like Instructables or Make. But we're also excited about the idea of "making socially" ("with others"). We practice DIWO through workshops, developer conferences, hackathons/labs, knitting circles and meetups in person, and online in the form of mailing lists, forum posts, and so on. We even have a gang sign. Because if you have a gang, you have to have a gang sign. The most important thing we want to stress is that you are not alone, that there's a great group of people out there learning, teaching, hacking, making and exploring the creative side of code.
>>>>>>> upstream/master
