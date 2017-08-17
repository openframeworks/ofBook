# Case Study: Memo (TODO: need title!)
Title candidates:

- Particle Mayhem (I think this already exists as a plugin or something for something)
- Particle Madness
- Wafty goodness
- Particle Wafter
- Interactive particle madness
- Boom, shake shake shake the room


## Introduction
### What this chapter is, and what it isn't
Welcome to my chapter on XXXXX.
Unlike a lot of the other great chapters in this book, this chapter is not about one particular topic, but instead brushes over many different topics, and focuses on bringing them together to create a real world live project.
Hopefully you will have read some (or all) of the other chapters, and now you'll see an example of how it can all be connected. While a lot of the book is like a lasagne, with each chapter building up layer by layer to a delicious cresendo, these few 'case study' chapters will meander all over the place and hit many different areas. More like a meatloaf.

In this chapter, our journey will take us through topics such as: capturing live video from camera (ofVideoGrabber), loading playing and controlling video files (ofVideoPlayer), object oriented programming and polymorphism (ofBaseVideo), C++ pointers, computer vision, frame differencing, image processing, image morphology, optical flow, image transforms, addons, github, fluid simulations, particle systems, custom classes, dynamics, vector math, drawing with opengl, vertex arrays, vertex buffer objects, meshes (ofMesh), shaders (ofShader), vertex shaders, fragment shaders, post effects.

Wow sounds like a lot, but it hopefully it isn't and we'll plough through just fine.

### So what exactly are we going to create?
I'm glad you asked. It's actually not one project, but quite a few.
All the projects I'm about to mention, share the exact same codebase, probably about 95% same code! (shhh don't tell anyone).
The only difference between each one are the settings (which is why I'm always going on about how important it is to play with those sliders!), and some tweaks to the final output.

These projects are: Body Paint, Gold, Reincarnation, Depeche Mode Fragile Tension, U2 Invisible. **[LINKS, IMAGES]**.
We will create an application, which - just by changing the numbers and settings - can behave and look like (or very similar to) the mentioned apps.


### What you should know before continuing
I'm assuming you have at least used openFrameworks and C++ a little bit, and you're comfortable with a simple "Hello World" openFrameworks application. You understand the basic notion of what an IDE is, and familiar with how an openFrameworks application is structured and where to write your code (i.e. how to use ofApp::setup, ofApp::update, ofApp::keyPressed etc). You understand what variables are, functions, for loops and other programming 101 concepts. You don't need to be a hardcore OOP C++ guru, but it will help if you understand what a Class is, how to instantiate an Instance of a class, and even create your own Class etc. In short it's probably best that you look at and get comfortable with at least the first 3-4 chapters of this book **[CHECK THIS]**

It isn't an **essential** prerequisite that you will have read *all* of the previous chapters on image processing, computer vision, advanced graphics, shaders etc. **[LINKS TO CHAPTERS?]** As I will very briefly explain those concepts below. But if you do read those chapters first it will definitely help you understand better. If you haven't read them and you're feeling brave, feel free to dive straight in. But if something isn't clear, please do refer to the relevant chapter!

Alrighty then, Let's go!


## Summary of what we're going to do
Before we start writing any code, let me explain what the application we're going to write does. I.e. a very top level pseudocode.

Actually before I do that, watch the videos **[LINK TO VIDEOS]** and see if you can guess what the process is. They may all look a bit different, so lets start with a **Body Paint** type behaviour **[LINK TO VIDEO]**. Write down all the steps you think we need to program.


I'm going to give the answer below, in *successively increasing level of detail*. I.e. when I start to progam something, I usually have no idea exactly what needs to be done. And I don't like massive planning sessions either, I like to dive into coding as quickly as I can. However when you have no idea what you're doing, it helps to think about it first a *little* bit.

I'll first develop a rough idea of what needs to be done in my head (or on paper). Try to find holes in it, try to visualize it, and refine the process. As soon as I have something which is concrete enough to code, I'll implement that, then I'll step back and look at what I've done, see what's missing, see what needs to be added or changed, and carry on. Then repeat, adding layers and layers of new behaviours. I don't like planning *too* much beforehand but a little bit always helps.

P.S. If some bits aren't very clear when reading the section below, don't worry, I will repeat it with more detail once we get into the code.


So,

**[SECTION BELOW NEEDS SKETCHES]**

### Top level process attempt #1:

	1. Read video input from camera
	2. Analyze video input
	3. Create particles
	4. Move particles
	5. Draw particles

That was easy!

But there's nothing here for us to code. It's too vague.
So let's think about it a bit more, and flesh it out. How are we going to analyse the video? We want the particles to move in the direction that the video is moving. E.g. if there's a person waving their right hand up and their left hand down, we want the particles near the right hand to fly up, and the particles near their left hand down.
If you've read the chapter on Computer Vision **[LINK]** you may already have an idea. *Optical Flow*. Optical flow is a general term for finding movement of points / pixels / objects in a scene through visual analysis.
There's quite a few different algorithms for doing this, some of which are mentioned in in the Computer Vision chapter **[LINK]**. For now let's just say: you give the optical flow algorithm the current video frame and the previous video frame, and *for every pixel of that image, it tells you the direction in which that pixel moved from previous frame to current frame*. I.e. a vector field. (we'll cover this in more detail when we get to writing the code).

Also, when and where will we create the particles? That's an easy one, let's start by saying "let's create particles when there's movement, at the place where movement occured"

**[TODO: at the end mention why I chose optical flow and not something else like background subtraction, skeleton, contours etc.]
**
### Top level process attempt #2:

	1. Read video input from camera

	2. Analyze video input
		- use optical flow to get motion vector fields <<< NEW

	3. Create particles
		- where there's movement <<< NEW

	4. Move particles
		- with the movement from the video <<< NEW

	5. Draw particles
		- as dots <<< NEW


Thats much better, we've almost got something to code.


But there's still a few things which are too vague and bugging me:

- In step #3 how do we know where there's movement?
- In step #4 what does 'move particles with movement from video' actually mean?

Let's try and address these.

- In step #3 how do we know where there's movement?  
We could use the optical flow. I.e. for every pixel in the video frame, look at the velocity of that pixel (from the optical flow).
If it's moved faster than a threshold, create a particle. This is perfectly viable. But for reasons I will dig into more later I choose not to do this (mainly for ease). I in fact prefer to use the *frame difference* with the previous frame. This will give a very similar result, but we have more flexibiliy in applying image processing to this frame difference image to create a dynamic *particle_creation_map* and it's easier to visualize the results. I'll explain that in more detail later. For now let's just say that we *frame difference* current frame with previous frame. This gives us an image (lets call it the *frame_difference*) where the black (or dark) areas show areas where there was no movement, and the bright areas show where there was movement. (This is actually quite an innaccurate statement, but for the purposes of this paragraph it will do!)

- In step #4 what does 'move particles with movement from video' actually mean?  
Well, what we want to do is:

	- when the particle is created, give it an initial velocity which we read from the optical flow at that pixel. This is relatively straight forward.
	- while the particles are flying around, affect their velocity with the video. Ie. make the movement in the video affect the particles. This also shouldn't be too hard. As the particles are moving, we just need to read the optical flow at each position and affect the particle.

It looks like we're getting somewhere and we're almost ready to start coding. There's still quite a bit we need to figure out, but we can try and figure the rest out *as* we code.

However, to save some time, I'm going to let you in on a little secret. If we were to implement this as is, we wouldn't be very happy. There is a fundamental problem in the approach above (actually it's less of a fundamental problem, more of an undesired effect). Raw Optical flow is not going to give us the results that we're after. Due to the nature of what it does, and how it does it.

If you were to implement the above (and you should try it, as an execerise), you will see that you get lots of random spikes all over the place. If you were to wave your arm, all along your arm you'll see particles flying in all kinds of random looking directions. A particle which is aligned perfectly with the edge of your arm might fly off at an incredible speed to the left, while a particle which is right next to that one might fly off at an incredible speed in the opposite direction, while a particle right next to that one might not move at all, because the optical flow at that point returns zero. It's all in the nature of how optical flow works. You can play with the settings of optical flow to tweak it, but you won't get very far.

You're going to need to *process* the results of the optical flow for it to be usuable. The problem we have is that the results are too *noisey*, and are too *localized*. Luckily there is a very quick and easy solution which you can try to address both of these issues. Blur the hell out of the optical flow (yes just like a photoshop blur, it is an image after all. Also known as a *low pass filter*). This actually kind of works, it'll simultaneously remove the spikes (the noise) and spread values across a wider range (reduce localization). This isn't what I use in the projects I mention above, but it still can give semi-decent results.

### Top level process attempt #3:
	1. Read video input from camera

	2. Analyze video input
		- use optical flow to get motion vector fields
		- blur the hell out of the optical flow <<< NEW
		- use frame differencing to see where there was movement <<< NEW

	3. Create particles
		- where there's movement (we can use the frame difference for this <<< NEW)

	4. Move particles
		- particles inherit velocity from the blurred optical flow when they're born <<< NEW
		- particles velocity is affected by blurred optical flow at all times <<< NEW

	5. Draw particles
		- as dots


We're really close. In fact we could start trying to code this now. However to save time I'll tell you the secret. I don't use a normal blur, I use a very special blur. In fact it isn't even a blur at all. I use a fluid simulation to act as a *lowpass filter on the optical flow*.

What this means is, when I create particles, or affect their velocity, I don't use the optical flow at all. Instead I use the optical flow data to *inject velocities into a fluid simulation*, and then I use the fluid simulation to *add forces to the particle system*. The fluid simulation acts as a soft, bouncy, gooey, rubbery, absorby, organic buffer between the noisey and localized optical flow and our particles.

This adds a bit of a radical change to our top level process:

### Top level process attempt #4:

	1. Read video input from camera

	2. Analyze video input
		- use optical flow to get motion vector fields
		- use frame differencing to see where there was movement

	3. Inject optical flow velocities into fluid simulation <<< NEW

	4. Create particles
		- where there's movement (we can use the frame difference for this)

	4. Move particles
		- particles inherit velocity from the fluid simulation (<<< NEW) when they're born
		- particles velocity is affected by fluid simulation (<<< NEW) optical flow at all times

	5. Draw particles
		- as dots


And that's it. That is the skeleton which we can code.

We have a skeleton, but maybe we can have some more interesting little bits and bobs? E.g. why don't we make it rain particles? Instead of just creating particles where there's movement, we could create particles fall from the top of the screen, or rise from the bottom, and *those* are affected by the optical flow / fluid simulation. Or mabe they're still created where there's movement, but a wind blows them across the screen, as well as the fluid simulation. Or maybe we don't look for movement, but we look for the video *edges* and create particles there. Or maybe we have a bunch of attractors around the place, maybe the mouse, or even controlled by a tablet or mobile. And we can definitely do more than dots for the drawing.

**Protip:** Also when working with applications that deal with live camera input, it's always a good idea to set your application up so that it can work with live camera input OR a video file. So if you're working on a bus, or a train, you don't want to have to get up and wave your arms around like a madman just to test your code, you want to be able test and debug code *as if there were someone interacting with it*. Also, it's immensely helpful to try and get some proper test footage of your installation setup. E.g. if your installation will have a camera that's hanging 7m in the air pointing down, it's best that you setup a camera hanging 7m in the air hanging pointing down, record some test footage, and develop your code *using that footage*. You don't need the space or that camera any more for your development. You can carry on developing in your bedroom or the bus or starbucks or whereever you like to work. You have good footage to work off, and once you're in the installation setup, you can just flip your code to use live camera instead of video, and everything will switch over seamlessly and work right out of the box (yea right. well it will be close).



### Top level process attempt #5:

	1. Read video input
		- from camera <<< NEW
		- or from video file <<< NEW

	2. Analyze video input
		- use optical flow to get motion vector fields
		- use frame differencing to see where there was movement
		- use edge finding algorithm to find edges <<< NEW
		- add image processing controls to frame difference and optical flow for more control  <<< NEW
			- blur, median, threshold, erode, dilate, open, close etc. <<< NEW
		- apply image transform to move source image around in output frame <<< NEW

	3. Inject optical flow velocities into fluid simulation

	4. Create particles
		- where there's movement (we can use the frame difference for this)
		- on edges of the video
		- at random positions on screen <<< NEW
		- at edges of the screen (top, left, bottom, right) <<< NEW
		- at specific points on the screen specified by mouse, or sent wirelessly from a tablet or mobile  <<< NEW

	4. Move particles
		- particles inherit velocity from the fluid simulation when they're born
		- particles velocity is affected by fluid simulation optical flow at all times
		- add global wind force (adds a constant velocity to each particle) <<< NEW
		- add global gravity force (adds a constant acceleration to each particle) <<< NEW
		- add attractors and repulsors <<< NEW
		- add noisefield <<< NEW

	5. Draw particles
		- as dots
		- as line segments connected to previous position of particle (i.e. like motion blur) <<< NEW
		- as line segments connected to neighboring particles <<< NEW
		- as lines connected to random other particles <<< NEW

	6. Apply Post FX - draw everything to an offscreen texture and apply post effects
		- sparkle
		- fade
		- blur
		- bloom
		- etc.

That's a badass list of features. If we put all of those on sliders and toggle boxes, you have enough to play with for years. And of course why stop there, keep adding!


So now we have the **big picture** of what the application will do. A lot of these items may still be quite vague in your head, but don't worry, we'll flesh each out as we dig into the code.

Now let's code it!


**[NEXT: All of the above, but now with code! probably only a quarter done :/]**
