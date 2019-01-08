Rough Outlines-- What we have so far
=========


Here are the rough outlines altogether so you can see them as one. This is not a place for comments-- just a place
to get an overall picture of where you're all headed. To comment, you've all agreed on github/issues so everyone
should stick with that

As Zach pointed out in an email, questions to think about:
a) Does the scope of the outline look right?  Is it too broad or too narrow?
b) Is this outline detailed enough (some look a bit on the thin side, might be helpful to try to expand more)
c) Are there any massive overlaps that look wrong?   
d) Are there any gaps?  
e) Does the ordering look right, where should the case studies fit?  




Introduction (Zach)
=========

- OF history
- OF philosophy
  - Collaborative
  - Simplicity
  - Consistent and Intuitive
  - Cross-platform
  - Powerful
  - Extensible
  - Do it with others (DIWO)
- OF structure
- project generator
- .h and .cpp
- setup/update/draw
- first project a circle moving in the screen
- scary things in OF code (#ifdefs pragma once...)
- preprocessor/compiler/linker

(note, some of the text I wrote on http://openframeworks.cc/about/ re: philosophy would be useful in this chapter)



C++_basics (JTNimoy)
=========
- func
  returning early
- origin from Bell Labs, timing, intentions
- modern role of C++ amongst other languages
- C versus C++.
- Why did C become C++?
- other flavors of C, and why they exist.
- Variables
- calling functions
    - arguments
    - return
- defining your own functions
- conditionals
- for loop
- while loop
    - break
    - continue
- arrays
- header files
- structs
- classes
    - private
    - public
    - inheritance


OOPs! (Rui)
=========


OOPs! _ Object Orient Programming, OOP: a practical approach in OF
notes:

- trying to not be redundant with Josh's Chapter, this would be a direct approach / practical example to OOP in OF
- this will be loosely based on and extended from the OOPs tutorialhttp://www.openframeworks.cc/tutorials/first%20steps/003_ooops_object_oriented_programming.html
- brief notes about OOP:
    - what is OOP
        - Objects and Classes
        - example of basic class and object
            - make a very simple class with setup, update and draw methods (simple particle ?)
            - make your object from the class
            - make multiple objects the hard way
            - make an array of objects (the easy way) _ using a CONSTANT
            - make an array of objects (the easy way) _ array using pointers
            - make an array of objects (the easy way) _ dynamic size of array using stl::vector
            - make an array of objects (the easy way) _ dynamic size of array using stl::vector and destroying objects if they leave the screen
    - more OOPs! : Polymorphism -What is it / what does it mean ?
        - example of basic class and object (polymorphism)
            - make a simple class (simple particle?)
            - make different objects from the same class



Animation (Zach)
=========

note this will be loosely based on this class / code
https://github.com/ofZach/algo2012

- brief notes about animation and movement
- central question: how can we make things move in a lifelike and compelling way?
- animation in OF basics:
    - frame rate
    - update and render loop
    - point object
- variables for movement
    - pct based animation
    - linear interpolation 0-1,
    - easing functions, powf
    - zeno
- sin / cos based movement
- simulation
    - vector vs point (and disambiguate with std::vector)
    - particles system
    - attraction repulsion
    - vector field
- noise
- where to go further
    - more complex forces (ie: springs)
    - mixing forces (ie: flocking)
    - libraries (ie: box2d)
-- -- --



Advanced graphics (Arturo & ??)
==============

- 2D
- immediate mode vs ofPolyline/ofPath

- 3D
- Transformation matrices
    - ofTranslate/Rotate/Scale using ofMatrix4x4
    - ofNode
- ofCamera
- ofMesh
- ofVboMesh
- of3dPrimitive
- Applying simple textures to 3d primitives and ofFbo




Network (Arturo)
============

1. TCP vs UDP
2. OSC





Image_Processing_Computer_Vision (Golan)
=========


## 1. Introduction

[This outline is based on workshops Golan taught with Kyle.]
Some previous reference materials here:
-- http://futuretheater.net/wiki/Vision_Workshop
-- http://piratepad.net/resonate-cv
-- http://www.flong.com/texts/essays/essay_cvad/

Unedited copy-paste from Arturo email (not yet integrated):
looks great to me, something i always find useful to explain as introduction in CV workshops before going into software details is the differences between contour finding (manual input sessions / delicate baoundaries) / motion detection (memo's gold / damian's wind) / blob tracking (chris o'shea's audience) and how contour finding *usually* gives more "precise" information than motion detection while it requires a much more controlled environment (ie: lighting) and how blob tracking techniques are usually some combination of contour finding + motion detection. all of it seems to be in the different subsections of your outline, i find it useful to explain it as an introduction with examples so people get a general idea but perhaps for the book is better to explain it along with the different techniques
also explaining the physical setup of such installations, IR lighting, filters... how to make the computer see some things and humans others and in general how all the work you can do in the physical setup will make your live easier when coding: the first time zach explained to me how in mesa di voce the screen is flooded with IR so the computer has to do almost nothing in order to detect the performers, it totally changed my way of thinking about this kind of problems

========================================================
## 2. Preliminaries

- 2.1. Image data structures
   - 8u, 32f, etc.
   - 1C, 3C, 4C images, etc.
   - Back and forth between ofxCV, ofxOpenCV, unsigned char*, ofPixels.
   - Example: color space conversions; converting RGB to Gray.

- 2.2. Image Arithmetic: mathematical operations on images
   - adding two images together
   - subtracting two images
   - multiplying an image by a constant
   - mentioning ROI
   - Example: creating an average of several images (e.g. Jason Salavon)
   - Example: creating a circular alpha-mask from a computed Blinn spot

- 2.3. Convolution Filtering
   - Blurring an image
   - Edge detection
   - Advanced sidebar: dealing with boundary conditions

- 2.4. Suggestions for Further Experimentation:
   - Slit-Scanner
   - Toy version of Text Rain. Fun with edge detection.
   - Toy version of LASER Tag. Finding the brightest point, tracing a path.
   - Toy version of Memo Akten's Gold: Optical flow + particle system

========================================================
## 3. Scenario I. Basic Blobs (e.g. Manual Input Sessions)

- 3.1. The Why
   - Some examples of projects that use blob-tracking
   - and some scenarios that call for it.

- 3.2. Detecting and Locating Presence and Motion
   - Detecting presence with Background subtraction
   - Detecting motion with frame-differencing
   - Binarization, blob detection and contour extraction
      - Area thresholds for contour extraction (min plausible area, max plausible area, as % of capture size)
      - Finding negative vs. positive contours

- 3.3. Image Processing Refinements
   - Using a running average of background
   - Erosion, dilation, median to remove noise after binarization
   - Combining presence and motion in a weighted average
   - Compensating for perspectival distortion and lens distortion

- 3.4. Thresholding Refinements
   - Some techniques for automatic threshold detection
   - Dynamic thresholding (per-pixel thresholding)

- 3.5. The Vector space: Extracting information from Blob Contours
   - Area, Perimeter, Centroids, Bounding box
   - Calculcating blob orientation (central axis)
   - Locating corners in contours, estimating local curvature
   - 1D Filtering of contours to eliminate noise, i.e local averaging.
   - Convexity defects, contourFinder.getConvexityDefects()
   - Other shape metrics; shape recognition

- 3.6. Using Kinect depth images
   - Finding the "fore-point" (foremost point)
   - Background subtraction with depth images
   - Hole-filling in depth images
   - Computing normals from depth gradients

- 3.7. Suggestions for further experimentation:
   - Tracking multiple blobs with ofxCv.tracker
   - Box2D polygons using OpenCV contours, e.g. https://vimeo.com/9951522

========================================================   
## 4. Scenario II. Face Tracking.

- 4.1. Overview
    - Some examples of projects that use face-tracking
        - Golan & Zach's Re:Face
        - Mary Huang's face typography
        - Kyle & Arturo, face swapping

- 4.2. A basic face detector.
   - Face detection with classic OpenCV viola-Jones detector
   - How it works, and considerations when using it.
   - cvDazzle; Kyle & Aram ("How to Avoid Facial Recognition"

- 4.3. Advanced face analysis with the Saraghi FaceTracker

- 4.4. Suggestions for further experimentation:
   - Make a face-controlled puppet
   - Toy version of David Tinapple's "The Face of TV": Find the average face of a TV channel

========================================================  
## 5. A Computer-Vision lexicon, and where to find out more information

Computer vision is a huge field and we can't possibly cover all useful examples here.
Sometimes people lack the terminology to know what to google for.

- Camera calibration.
- Homography transforms and re-projection.




=========================================================
Information Visualization (Tega)
=========================================================

This chapter introduces some basic information visualisation techniques using OF.  
It is a very brief overview of dealing with data in OF. It overviews how to load and store datasets, useful functions for converting data and some examples of how to build basic plots.

1. Intro
	1.1 What is data/information? Some contextual background on what these terms mean.
	1.2 Defintition of terms and chapter structure
	1.3 Steps of visualising data ( as per ben fry) .  

2. Working with data
	2.1 Loading and saving data
	2.2 Using classes or structs to store data.
 	2.3 Conversion functions (ofSplitString, ofToString, ofToInt)
	2.3 Quick overview of some common file structures.
		-tsv, csv, html, xml, json, svg
	2.4 Notes on Parsing Data.

3. Basic examples of data visualisation
	3.1 Creating basic time series plots
	3.2 Scatter plot example
	3.3 Geolocated data example

4. Working with Real time data
	5.1 What are APIs?
	5.2 Interacting with URLS
	5.3 Using this data real time in an animation

5. Challenges and further resources





Game_Design (Phoenix)
=========


Integrating OSC with oF for Games
Category: advanced specialist chapter

Introduction:
This chapter explains how OSC can be implemented in openFrameworks, allowing developers to enable wireless communication between multimedia devices for real-time control. The project in this chapter is a game for 2 players, controlled by two OSC-enabled devices (e.g. smartphones with OSC apps). Player 1 uses their controller to manipulate their on-screen avatar; Player 2 uses their controller to add difficulty to the game (adding enemies, manipulating speeds, etc.). OSC is a useful tool for any oF developer interested in being able to remotely control their app’s properties (visuals, sounds, etc.) without having to build their own custom controller.

Terms:

●        OSC
●        Routing
●        IP addresses/ports


### Outline

●        Historical overview of OSC
●        Overview in general of how OSC works
●        OSC apps for smartphones/tablets
●        Setting up OSC
●        Types of messages
●        How routing messages works
●        Implement P1 controls
●        Implement P2 controls
●        Other projects made with OSC/further resources





Hardware (Caitlin/Pierre)
=========

- Anatomy of the Arduino hardware + IDE
- Basic intro of voltage, “high” and “low”, PWM
- Digital and analog hardware communication
- Bits, bytes, and serial communication
- Baud rate, USB serial access, communication “frequency”
- Serial RS-232 to TTL communication
- Basic serial communication: reading and writing bytes
    - looking for devices
    - checking serial availability
- Firmata overview
- Compare LED blink with Arduino IDE / LED blink with OF
- Digital input and output with Firmata / ofArduino
- Analog input and output with FIrmata / ofArduino
- Servo control with OF
-
- Creating a headless app for hardware control
- Serial communication on a single board computer (rPI/Beaglebone)

-- -- --

- Introduction to DMX
- Hooking up a DMX interface
- Controlling DMX hardware using OF
- Case Study: Controlling LEDs using DMX on an rPI

-- -- --

- Introduction to Networking
- TCP/IP protocol
- Routers/Switches/Hubs
- Open Sound Control (OSC) - networking made easy
- Communicate OF with an Arduino over ethernet
- Case Study: Sending wireless OSC packets on an rPI




Sound (Adam)
=====

- Why -1 to 1?
- Time domain vs Freq domain
- Sound files
- Threading and buffering concerns (probably introduce circular buffers here)
- Addon ecosystem
- Basic audio reactive toolbox
  - RMS
  - FFT
  - Pitch detection, Onset detection
  - Mel scale, Decibels
- Basic audio synthesis toolbox
  - ADSR
  - Reacting to MIDI
  - Working with external sound applications
  - Overview of non-insane synthesis techniques (i.e. http://en.wikipedia.org/wiki/Category:Sound_synthesis_types )
- Gotchas
  - Sample rates, Nyquist, aliasing
  - Popping, clipping
  - Latency

- Advanced sidebars

    - DSP stuff (windowing, filtering...)
    - Tricks for human voices (cepstrum and friends)
    - Constant Q (and why raw FFT can be not-so-great for music)
    - Maybe some insane synthesis techniques




iOS (Lukasz)
===

- What Objective-C looks like
- Differences between C++ and Obj-C
- brief overview of Obj-C memory management compared to C++ (retain/release and ARC)
- How C++ and Obj-C can be mixed together.
- How OF works on iOS, using OpenGL ES, UIViewController and App Delegate (basic iOS app structure)
- OpenGL ES1 & ES2 renderers, what are the differences.
- Shaders using ES2. Crossover between web ES2 shaders and nd iOS ES2 shaders.
- ofxiOS media playback classes, ofxiOSVideoPlayer, ofxiOSVideoGrabber, ofxiOSSoundPlayer, ofxiOSSoundStream
- ofxiOS utils, ofxiOSExtras, ofxiOSImagePicker, ofxiOSMapKit etc.
- Adding UIViews to an OF app, above and below the OF glView.
- openFrameworks as part of a larger app, several openFrameworks apps in one iOS app
- addons for ofxiOS
- App distribution, preparing your OF app for the app store.
- examples of OF iOS apps already in the app store.



- Advanced sidebars

    - GCD, blocks, "the main queue"
    - ARC and C++




Android (Arturo)
=========


1. setup guide
2. android specifics, java/c++
3. OFActivity
4. Android GUI (small intro + reference to android docs)
5. jni
6. ABIs
7. packaging for release
-- -- --




Memory (Arturo)
=========


1. computer memory, variables
2. stack variables, variables in functions vs variables in class/object
3. variables in heap, pointers and references
4. memory structures, arrays vs vectors
5. other memory structures, maps, sets and lists
6. smart pointers
-- -- --  




Threads (Arturo)
=========


1. what's a thread when to use it
2. ofThread
3. threads and openGL
4. ofMutex
5. Poco::Condition
-- -- --  




Introduction_to_version_control_with_git (Christoph)
=========


*This chapter will give a high-level overview over a pretty complex topic with a generous amount of links to more material to enable readers to easily find appropriate information. It's quite difficult to do it in anything approaching completeness in only a couple of pages, and a high-level overview  will be more useful to the reader.*

### What is version control, and why should you use it?

* VCS versus manual methods (e.g. backups in named folders)
* Which problems are avoided?
* Enables management of larger projects and/or collaboration in teams
* Popular systems and their major differences

### Introduction to Git
* What is Git?
* How does it work?
    - *short crash-course with generous links to deeper reading*
    - *KISS! this will be the major challenge considering Git's complexity*
    - introduce following terms:
        - repositories
        - commits&immutability
        - branches
        - merging, merge conflicts(!)
        - gitignore
        - remotes, push&pull.
        - ...
* Most often used commands and features
* List of popular GUI clients

### Github
* What is it?
* How does it work? What can it do for you: Pull requests, issue trackers, collaboration
* openFrameworks on Github.
* Your project(s) on Github

### Conclusion

* Where do you go from here? More complex & powerful VCS mechanisms out there (git flow, branching workflows,...)
* Where/how do you get help if things go wrong? (Stack Overflow, Git homepage, google, OF forum category "revision control")
* (more tools?)
-- -- --





Shaders (Patricio)
=========


### Intro

- The birth of the render pipeline and a brief history of the GPU
- Explanation of Vertex Shader and Frag shader


### Fragment Shader

- What are they for? How do they work? Comparison with old pixel-by-pixel operations. References
- First example: all red billboard (+ basic explanation of how to make a QUAD mesh with texCoords)
- Second example: make a grayscale // make a checkerboard using shaders
- Uniforms
- Third example: using 'uniform float’ to make animated patterns (passing ofGetElipsetime() sin() cos() to make interesting patterns)
- Fourth example: using ‘uniform vec2’ to get mouse interaction
- Fifth example: using ‘uniform texture2DRect’ to alpha mask and multi texturing (explanation of OF examples)
- Exercise: make simple shaders that emulate basic openCV operations such as: grayscale, brightness, contrast, threshold, absDiff


### Vertex Shader

- What are they for? How do they work?
- Varings
- Example: cheap DOF passing the alpha value from the vertex shader

### Advanced

- The Programmable-Render on OF
- Differences between openGL2, openGL ES and openGL3
- Using GPU not for rendering, instead using textures to pass information
- Sixth example: simple particle system (explanation of OF example)
- Exercise: Implement cool shaders from shaderToy in OF





# Intro_to_Graphics (Mike)

### Programming Graphics
Personal goals for chapter:

* Explain the basics in a way so as to not lose anyone who is just picking up programming
* Explain ways for thinking about generating visuals algorithmically
* Demonstrate some ways to get your work off of your computer and into the interwebs
* (Hopefully) include interesting things for those who are more advanced

#### Section 1: Simple Graphics Loop
* __Intent:__ Get comfortable the update/draw, background and 'foregrounds'
* __Project:__ Drawing a simple shapes at the mouse position  
  * Explain XY pixel coordinate system
  * Clearing the screen using background
  * Circle/Rect/Ellipse/Line (and ofSetRectMode)
  * Fill and stroke concepts in openFrameworks
  * Drawing multiple shapes, drawing order
  * Turning off auto background and using transparency for trail effect
    * If not covered in a previous chapter, effects of framerate


#### Section 2: Procedural Colors
* __Intent:__ Explain ofColor and ways to explore colors procedurally (using recursion).  Also, parameter searching.
* __Project:__ Explore the HSB way of thinking by making color compositions
  * Explain the ways color can be specified (grayscale, RGB, RGBA, HSB)
  * Using HSB dimensions to generate color palettes
    * Why not RGB?
    * Concept of recursion
    * Subdivide screen into smaller rectangles that change slowly along one of the HSB color dimensions
      * Example images: [hue](https://github.com/openframeworks/ofBook/blob/master/20_intro_to_graphics/EvolvingColor_ChangingHue.png), [saturation](https://github.com/openframeworks/ofBook/blob/master/20_intro_to_graphics/EvolvingColor_ChangingSaturation.png), [brightness](https://github.com/openframeworks/ofBook/blob/master/20_intro_to_graphics/EvolvingColor_ChangingBrightness.png)
      * Uses ofRect, ofRectangle, ofRandom and std::vector
    * Defining controllable parameters
      * Parameter searching interactively using mouseX, mouseY and key presses
* __Extension:__ Documenting your work (part 1)
  * Static work, saving an image (PNG or PDF)
    * Workarounds to make ofSaveScreen() work with ofSetBackgroundAuto(false) using ofImage
    * Saving images at a higher resolution than screen?
  * Moving work, saving a gif
    * Best for short animations, like here where we can show the process of the colors evolving in the recursion
    * Saving a series of images and compositing them
    * Possibly a section on ofxGifEncoder
    * Tips for compression

#### Section 3: Coordinate Systems Transformations
* __Intent:__ Explain power of moving coordinate system
* __Project:__ Trippy animated spiralling rectangles
  * Explain the 'moving the paper' analogy
  * Concept of repetition
  * Drawing expanding and sprialling rectangles
    * Same rectangle code, ofRect(0, 0, w, h)
    * Visual changes comes from ofRotate, ofScale, ofTranslate
    * Makes use of ofNoise for creating sprialling rotations
  * [Example image](https://github.com/openframeworks/ofBook/blob/master/20_intro_to_graphics/CoordSystem_RepeatingSquareSpiral.png)

#### Section 4: The Other Shapes
* __Intent:__ Finish off 2D graphics using curves, beziers, and custom shape
* __Project:__ Not yet sure what will go here...
 * Teach in the context of a project with generative visuals, like:
  * Cellular automata, like Conway's Game of Life
  * Dynamic drawing brushes
  * Using a movie or image to drive the creation of shapes
* __Extension:__ Documenting your work (part 2)
  * Sometimes a gif doesn't cut it, saving a movie
   * ofxVideoRecorder (doesn't work on windows, so I can only really link to it)
    * For interactive works, 3rd party recording software
    * For noninteractive works, creating a 'rendering' mode, saving frames and stiching them together using ffmpeg or openFrameworks

#### Section 5: Meshes
* This is pushing the limits of what can fit in a chapter, but I'd love to see coverage of 3D and meshes in the book...
* __Intent:__ Jump into meshes, cameras, and thinking about ways to generate meshes
* __Project:__ I could attempt to shorten up the [generative mesh tutorial](http://openframeworks.cc/tutorials/graphics/generativemesh.html) and include it
 * Basics of meshes
   * Modes, indicies, vertices
 * One way to think about creating a generative mesh
   * Loading image, getting pixels, using them as source data
    * Applying rules to the data to generate vertices and connections
 * ofEasyCam to navigate
 * How to handle the mesh to create simple animation and interactivity

#### Section 6: Links to Addons and Where to Learn More
* Addons
  * Adding Physics
    * ofxBullet
    * ofxBox2d
  * Computer Vision
    * ofxCv or ofxOpenCv
  * Vector Graphics
    * ofxSVG or ofxVectorGraphics
* Additional Resources
  * I'll sort this out in more detail once I have an idea of what the other chapters in the book will look like
  * ofBook will already have computer vision and shaders, so I'd like to point to resources on particle systems, opengl, vector math, and whatever else fits.
  * Links to cool openFrameworks projects
-- -- --





Project_Elliot
=========

- Brief documentation of install  (2 pages)
    - Images
    - Intentions of work
        - Lineage of work
            - Inspiration
            - Previous relevant work
            - Digital Emulsion concept

- Technical solution (1 page)
    - External constraints
    - System diagram
    - Hardware choices
    - Software choices
        - Online vs offline apps
        - Mixing with other frameworks
    - Development timeline retrospective (in reference to design timeline)

- Design time apps (2 pages)
    - Mixing custom and existing applications into workflows
    - Creating an interface for collaborators to use
    - addLinesToRoom app (a CAD app made in oF to design the install)
        - Problem
        - Speedy solution
        - Screenshots
        - Code snippets of nice features
        - Feedback from users back into install
        - Value for final install

- Calibration time apps (2 pages)
    - Requirements
    - Brief introduction to triangulation + structured light for Digital Emulsion projects
    - triangulateAProjector.app
        - Screenshots
        - Code snippets

    - mapLinesInRoom.app
        - Screenshots
        - Iterative design
        - Communicating with other frameworks

    - matchMapToScan.app
         - Screenshots






Project_Eva
=========

### Case Study
### "Choreographies for Humans and Stars"
(@dailyTLJ project)


1. Project
    - summary, image
    - background story: client, call, competition
    - timeline: from competition, ideation, prototyping, production, to opening
    - team: all the people involved
2. Ideation
    - process: work with choreographer
    - narrative: sequential structure
    - content: kids workshops, analog animation techniques
    - physical presence to define stage (steles)
3. Technical Solution
    - site, challenges (weather, camera placement, projector placement, trees, city network)
    - hardware choices, specs (camera, projector, computer)
    - system diagram
    - choice of tracking software > blobserver
        - method of tracking (HOG, background)
        - finetuning of tracking (challenges: weather, kids, overlapping)
        - screenshot camera view with tracking windows
    - choice of visualization software > OF
    - additional software used: processing, gstreamer, switcher, oscdump, ..

4. Viz Software (OF)
    - development setup: linux, codeblocks, sublime, github
    - externals used: ofxOsc, ofxOpenCv, ofxGui, ofEvents
    - input: tracking data
        - OSC communication: dealing with fsp diff, dummies for testing
        - blobs data structure with std::map, updating
        - perspective transformation
    - implementing video content
        - content preparation (quest for right format, tools used)
        - dynamic video elements (ofVideoPlayer, ofPtr)
        - preloading versus dynamic loading
    - sequential structure
        - structure with scenes, segments
        - transitioning with timers and/or events
    - event-driven animation
        - blob events (onEnterStage, onLost, onFreeze, onSteady, ..) driving video content
    - finetuning interaction
        - calibration of final behavior (importance of GUI)
        - screenshot of debug GUI
5. Fail-safes and dirty fixes!
    - worst case scenarios, the messiness of the real-world and how fixing bugs creates more bugs
    - segmentation faults: how to keep your app alife nevertheless
        - supervise (linux)
        - options for win/mac: launchd, lingon, ..
    - variables FPS: update animation with fps-dependent value
    - memory leaks, dropping FPS: regularly terminate app, seamless transitions
    - put limits on your number of objects (blobs, video elements)
    - video glitches on low FPS
    - optimizing: replace video with opengl-animation
    - investigate: ofLogToFile with dynamic date
    - investigate: monitor process times for operations to find the bottleneck
-- -- --        




Project_Joel
=========
-- -- --
- Possible inclusion in other places?

- CSM Course
http://joelgethinlewis.com/visualmachines/

- Basics of binary numbers, types, and intro to OF

- Case Studies:

- Divide by Zero - http://www.hellicarandlewis.com/2010/09/20/divide-by-zero/
- FeelTV - http://www.intworks.com/work/nike-feel-london
- Greenpeace Save The Arctic installation - http://www.youtube.com/watch?v=LwokmKqT0og&list=UUDYkJZXrR9gv6sQ2FQMeYYw&index=29

In each case, the planning documents, development schedule and eventual technical solution, with links to source.





Project_Memo
=========

## 0. intro
- what this chapter is, and what it isn't.
- what you should know before reading this.
- Not indepth coverage of any one topic, but covering each topic very briefly, to show how many different topics can come together to create an app
- summary of what we will create (Body Paint, Gold, Reincarnation, Depeche Mode Fragile Tension, U2 PUNK), areas we will cover, and how everything fits together

## 1. Video Input
- loading video files (ofVideoPlayer)
- reading live webcam input (ofVideoInput)
- How to write the app in a way to seamlessly switch between taking input from VideoPlayer (i.e. a file) vs Webcam Input (i.e. live)
- OOP / Polymorphism allows ofBaseVideo
- pro tips

## 2. Basic Image Processing + Computer Vision
#### Create particle-creation-map:
- frame differencing
- threshold (binary, top, bottom)
- adaptive threshold
- blur, median
- morphology (erode, dilate, open, close)

## Optical flow (to advect fluid simulation)
- blur
- threshold

## Misc
- align input image to desired position in output: image transforms
- pro tips

# 3. Fluid simulation
- non-core addons
- github
- advect fluid with optical flow
- pro tips

# 4. Particles
## Behaviours:
- create with particle-creation-map
- basic dynamics (F=ma, v = u + at)
- vector math (arithmetic, normalising, cross products, dot products etc.)
- gravity, wind, mass, drag, momentum, noisefields, mapping curves, adding variance, sparkles, etc.
- pro tips

## Drawing
- manually (easy way, old fashioned and slow)
- Vertex Array (vs VBO)
- ofMesh
- Vertex Shader?
- pro tips


# 5. Post FX (optional)?
 - fbo
 - fragment shader?
 - pro tips
