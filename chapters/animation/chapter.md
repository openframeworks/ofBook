#Animation

*by [Zach Lieberman](http://thesystemis.com)* 

*with edits from Kayla Lewis*

## Background 

The word animation is a medieval term stemming from the Latin animare, which means ‘instill with life’. In modern terms, it's used to describe the process of creating movement from still, sequential images. Early creators of animation used spinning discs (phenakistoscopes) and cylinders (zoetropes) with successive frames to create the illusion of a smooth movement from persistence of vision.   In modern times, we're quite used to other techniques such as flip books and cinematic techniques like stop motion. Increasingly, artists have been using computational techniques to create animation -- using code to "bring life" to objects on the screen over successive frames. This chapter is going to look at these techniques and specifically try to address a central question: how can we create compelling, organic, and even absurd movement through code?

As a side note, I studied fine arts, painting and printmaking, and it was accidental that I started using computers. The moment I saw how you could write code to move something across the screen, even as simple as silly rectangle, I was hooked. I began during the first dot-com era working with flash / actionscript and lingo / director and have never looked back.

This chapter will first explain some basic principles that are useful to understanding animation in OF, then attempt to show a few entrypoints to interesting approaches. 

## Animation in OF / useful concepts: 

### Draw cycle 
The first point to make about animation is that it's based on successive still frames. In openFrameworks we have a certain loop cycle that's based roughly on game programming paradigms. It goes like this: 

- setup()
- update()
- draw()
- update() 
- draw()
- ....

Setup gets called once, right at the start of an OF apps lifecycle and update / draw get called repeatedly. Sometimes people ask why two functions get called repeatedly, especially if they are familiar with Processing, which has only a setup and a draw command. There are a few reasons. The first is that drawing in openGL is asynchronous, meaning there's a chance, when you send drawing code to the computer, that it can return execution back to your program so that it can perform other operations while it draws. The second is that it's generally very practical to have your drawing code separated from your non-drawing code. If you need to quickly debug something–say, for example, your code is running slow–you can comment out the draw function and just leave the update running. It's separating out the update of the world from the presentation and it can often help clean up and organize your code. Think about it like a stop frame animator working with an overhead camera that might reposition objects while the camera is not taking a picture then snap a photograph the moment things are ready.  In the update function you would be moving things around and in the draw function you draw things exactly as they are at that moment. 

### Variables

The second point to make about animation is that it requires variables. A variable is a placeholder for a value, which means that you can put the value in and you can also get the value out. Variables are essential for animation since they "hold" value from frame to frame–e.g., if you put a value into a variable in the setup function or update function, you can also get it out from memory in the draw function. Take this example: 

**[note: simple animation example here]**

### Frame rate

The third point to make about OF and animation is frame rate.  We animate in openFrameworks using successive frames.  Frame rate refers to how quickly frames get drawn.  In OF there are several important functions to know about.

- [`ofGetFrameRate()`](http://openframeworks.cc/documentation/application/ofAppRunner.html#!show_ofGetFrameRate "ofGetFrameRate Documentation Page") returns the current frame rate (in frames per second). 
- [`ofSetFrameRate( float targetFrameRate )`](http://openframeworks.cc/documentation/application/ofAppRunner.html#!show_ofSetFrameRate "ofSetFrameRate Documentation Page") sets the maximum frame rate. If the software is animating faster than this, `ofSetFrameRate` will slow it down. Think of it like a speed limit. It doesn't make you go faster, but it prevents you from going too fast. Set the value to 0 to run as fast as possible.

In addition, openGL works with an output display and will attempt to synchronize with the refresh rate of the monitor -- sometimes called vertical-sync or vertical blanking.  If you don't synchronize with the refresh rate, you can get something called frame tearing, where the non-synchronization can mean frames get drawn before and after a change, leading to horizontal lines of discontinuity, called [screen tearing](http://en.wikipedia.org/wiki/Screen_tearing) 

**[note: frame rip graphic here]**

We have a function in OF for controlling this. Some graphics card drivers (see for example Nvidia's PC drivers) have settings that override application settings, so please be sure to check your driver options. 

- [`ofSetVerticalSync (bool bUseSync)`](http://openframeworks.cc/documentation/application/ofAppRunner.html#!show_ofSetVerticalSync "ofSetVerticalSync Documentation Page") set this true if you want to synchronized vertically, false if you want to draw as fast as possible. 

By default, OF enables vertical sync and sets a frame rate of 60FPS. You can adjust the VSYNC and frame rate settings if you want to animate faster, but please note that by default OF wants to run as fast as possible. It's not uncommon if you are drawing a simple scene to see frame rates of 800 FPS if you don't have VSYNC enabled (and the frame rate cap set really high or disabled).

Another important point which is a bit hard to cover deeply in this chapter is frame rate independence. If you animate using a simple model -- say for example, you create a variable called xPos, increase it by a certain amount every frame and draw it. 

```cpp
void testApp::setup(){
    xPos = 100;
}

void testApp::update(){
    xPos += 0.5;
}

void testApp::draw(){
    ofRect(xPos, 100, 10, 10);
}
```

This kind of animation works fine, but it assumes that your frame rate is constant.  If your app runs faster, say by jumping from 30fps to 60fps, the object will appear to go twice as fast, since there will be 2x the number of update and draw functions called per second.   Typically more complex animation will be written to take this into account, either by using functions like time (explained below) or mixing the frame rate or elapsed time into your update.  For example, a solution might be something like: 

```cpp
void testApp::update(){
    xPos += 0.5 * (30.0 / ofGetFrameRate());
}
```

If ofGetFrameRate() returns 30, we multiply 0.5 by 1, if ofGetFrameRate() returns 60, we multiply it by 1/2, so although we are animating twice as fast, we take half sized steps, therefore effectively moving at the same speed regardless of frame rate.  Frame rate independence is fairly important to think about once you get the hang of things, since as observers of animation, we really do feel objects speeding up or slowwing down even slightly, but in this chapter I will skip it for the sake of simplicity in the code. 

### Time functions

Finally, there are a few other functions that are useful for animation timing: 

- [`ofGetElapsedTimef()`](http://openframeworks.cc/documentation/utils/ofUtils.html#!show_ofGetElapsedTimef "ofGetElapsedTimef Documentation Page") returns the elapsed time in floating point numbers, starting from 0 when the app starts. 
- [`ofGetElapsedTimeMillis()`](http://openframeworks.cc/documentation/utils/ofUtils.html#!show_ofGetElapsedTimeMillis "ofGetElapsedTimeMillis Documentation Page") similarly returns the elapsed time starting from 0 in milliseconds.
- [`ofGetFrameNum()`](http://openframeworks.cc/documentation/utils/ofUtils.html#!show_ofGetFrameNum "ofGetFrameNum Documentation Page") returns the number of frames the software has drawn. If you wanted, for example, to do something every other frame you could use the mod operator, e.g., `if (ofGetFrameNum() % 2 == 0)`.

### Objects

In these examples, I'll be using objects pretty heavily. It's helpful to feel comfortable with OOP to understand the code. One object that is used heavily is [`ofPoint`](http://openframeworks.cc/documentation/types/ofPoint.html "ofPoint Documentation Page"), which contains an x,y and z variable. In the past this was called "ofVec3f" (vector of three floating point numbers), but we just use the more convenient ofPoint. In some animation code, you'll see vectors used, and you should know that ofPoint is essentially a vector.  

You will also see objects that have basic functionality and internal variables. I will typically have a setup, update and draw inside them. A lot of times, these objects are either made because they are useful recipes to have many things on the screen or they help by putting all the variables and logic of movement in one place. I like to have as little code as possible at the testApp / ofApp level. If you are familiar with ActionScript / Flash, this would be similar to having as a little as possible in your main timeline. 


## Linear movement

### Getting from point a to point b

One of the most important things to think about when it comes to animation is answering the simple question:

*How do you get from point A to point B?*  

In this chapter we will look at animating movement (changing position over time) but we could very well be animating any other numeric property, such as color, the width or height of a drawn shape, radius of a circle, etc.  

The first and probably most important lesson of animation is that we **love** numbers between 0 and 1. 

**[note: love picture here]**

The thing about numbers between 0 and 1 is that they are super easy to use in interesting ways. We typically refer to these kinds of numbers as percent, and you'll see me use the shorthand `pct` in the code–this is a floating point number between 0 and 1. If we wanted to get from point A to point B, we could use this number to figure out how much of one point and how much of another point to use. The formula is this: 

```cpp
((1-pct) * A) + (pct * B)
```

To add some detail if we are 0 pct of the way from A to B, we calculate 

```cpp
((1-0) * A) + (0 * B)
```

which simplifies to `(1*A + 0*B)` or A. If we are 25 percent of the way, it looks like 

```cpp
((1-0.75) * A) + (0.25 * B)
```

which is 75% of A + 25% of B. Essentially by taking a mix, you get from one to the other. The first example shows how this is done.

**[note: linear example code here]**

*As a side note, the function `ofMap`, which maps between an input range, uses pct internally. It takes a value, converts it into a percentage based on the input range, and then uses that pct to find the point between the output range.*  **[note: see omer's chapter]**

### Curves

One of the interesting properties of numbers between 0 and 1 is that they can be easily adjusted / curved.  

The easiest way to see this is by raising the number to a power.  A power, as you might remember from math class, is multiplying a number by itself,  e.g., 2^3 = `2*2*2 = 8`. Numbers between 0 and 1 have some interesting properties. If you raise 0 to any power it equals 0 (`0x0x0x0 = 0`). The same thing is true for 1 (`1*1*1*1 = 1`), but if you raise a number between 0 and 1 to a power, it changes. For example, 0.5 to the 2nd power = 0.25.

Let's look at a plot of pct raised to the second power: 

**[note: plot graphic here]**

**[note: better explanation of how to read the chart]**
Think about the x value of the plot as the input and y value as the output. If put in 0, we get out a y value of 0, if we put in 0.1, we get out a y value of 0.01, all the way to putting in a value of 1 and getting out a value of 1.   

As a side note, it's important to be aware that things in the world often don't move linearly. They don't take "even" steps. Roll a ball on the floor, it slows down. It's accelerating in a negative direction. Sometimes things speed up, like a baseball bat going from resting to swinging. Curving pct leads to interesting behavior. The objects still take the same amount of time to get there, but they do it in more lifelike, non-linear ways.

![nonlinear](images/atob_nonlinear.png)

If you raise the incoming number between 0 and 1 to a larger power it looks more extreme. Interestingly, if you raise this value between 0 and 1 to a fractional (rational) power (i.e., a power that's less than 1 and greater than 0), it curves in the other direction.  

The second example shows an animation that uses pct again to get from A to B, but in this case, pct is raised to a power: 


In the 4th example (**4_rectangleInterpolatePowfMultiple**), you can see a variety of these rectangles, all moving with different shaping functions.  They take the same amount of time to get from A to B, but do it in very different ways. I usually ask my students to guess which one is moving linearly -- see if you can figure it out without looking at the code: 

![xeno diagram](images/multiCurved.png)

http://en.wikipedia.org/wiki/12_basic_principles_of_animation#Slow_in_and_slow_out

**[note: can we get rights for a screenshot of masahiko sato curves DVD ? ]**

Raising percent to a power is one of a whole host of functions that are called "shaping functions" or "easing equations." Robert Penner wrote about and derived many of these functions so they are also commonly referred to as "Penner Easing Equations."  [Easings.net](http://easings.net/) is a good resource, as well there are several openFrameworks addons for easing. 

- http://sol.gfxile.net/interpolation/#c1
- http://easings.net/

### Zeno
**[TNT This section begins with Zeno and then changes to Xeno for the code samples and images. Suggest this be made consistent. ]**

A small twist on the linear interpolation is a technique that I call "Zeno" based on Zeno the greek philosopher's *dichotomy paradox*: 

> Imagine there is a runner in a race and the runner covers 1/2 of the distance in a certain amount of time, and then they run 1/2 of the remaining distance in the same amount of time, and run 1/2 of that remaining distance, etc. Do they finish the race?  There is always some portion of the distance left remaining to run one half of.  The idea is that you can always keep splitting the distance.

If we take the linear interpolation code but always alter our own position instead (e.g., take 50% of our current position + 50% of our target position), we can animate our way from one value to another. I usually explain the algorithm in class by asking someone to do this: 

1. Start at one position in your room.
2. Pick a point to move to.
3. Calculate the distance between your current position and that point.
4. Move 50% closer.
5. Go to (3).

![xeno diagram](images/xeno.png)

In code, that's basically the same as saying 

```cpp
currentValue = currentValue + ( targetValue - currentValue ) * 0.5.
```

In this case `targetValue - currentValue` is the distance. You could also change the size of the step you make every time, for example, taking steps of 10% instead of 50%: 

```cpp
currentValue = currentValue + ( targetValue - currentValue ) * 0.1.
```

If you expand the expression, you can write the same thing this way: 

```cpp
currentValue = currentValue * 0.9 + targetValue * 0.1.

```
This is a form of smoothing: you take some percentage of your current value and another percentage of the target and add them together. Those percentages have to add up to 100%, so if you take 95% of the current position, you need to take 5% of the target (e.g., currentValue * 0.95 + target * 0.05).

In Zeno's paradox, you never actually get to the target, since there's always some remaining distance to go. On the computer, since we are dealing with pixel positions on the screen and floating point numbers at a specific range, the object appears to stop.  

In the 5th example **(5_rectangleXeno)**, we add a function to the rectangle that uses xeno to catch up to a point: 

```cpp
void rectangle::xenoToPoint(float catchX, float catchY){
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 
}
```

Here, we have a value, `catchUpSpeed`,  that represents how fast we catch up to the object we are trying to get to.   It's set to 0.01 (1%) in this example code, which means take 99% of my own postion, 1% of the target position and move to their sum.  If you alter this number you'll see the rectangle catch up to the mouse faster or slower.  0.001 means it will run 10 times slower, 0.1 means ten times faster. 

This technique is very useful if you are working with noisy data -- a sensor for example.  You can create a variable that catches up to it using xeno and smoothes out the result.  I use this quite often when I'm working with hardware sensors / physical computing, or when I have noisy data.  The nice thing is that the catch up speed becomes a knob that you can adjust between more real-time (and more noisy data) and less real-time (and more smooth) data.  Having that kind of control comes in handy!

## Function based movement

In this section of the book we'll look at a few examples that show function based movement, which means using a function that takes some input and returns an output that we'll use for animation. For input, we'll be passing in counters, elapsed time, position, and the output we'll use to control position. 

### Sine and Cosine

Another interesting and simple system to experiment with motion in openFrameworks is using sin and cos.

Sin and cos (sine and cosine) are trigonometric functions, which means they are based on angles. They are the x and y position of a point moving in a constant rate around a circle. The circle is a unit circle with a radius of 1, which means the diameter is `2*r*PI` or `2*PI`.  In OF you'll see this constant as `TWO_PI`, which is 6.28318... 

*As a side note, sometimes it can be confusing that some functions in OF take degrees where others take radians. Sin and cos are part of the math library, so they take radians, whereas most openGL rotation takes degrees. We have some helper constants such as `DEG_TO_RAD` and `RAD_TO_DEG`, which can help you convert one to the other.*

Here's a simple drawing that helps explain sin and cos. 

![sin](images/atob_circle.png)

All you have to do is imagine a unit circle, which has a radius of 1 and a center position of 0,0.  Now, imagine a point moving counterclockwise around that point at a constant speed.  If you look at the height of that point, it goes from 0 at the far right (3 o'clock position), up to 1 at the top (12 o'clock), back at 0 at the left (9 o'clock) and down to -1 at the bottom (6 o'clock).  So it's a smooth, curving line that moves between -1 and 1.  That's it.  Sin is the height of this dot and cos is the horizontal position of this dot.  At the far right, where the height of this dot is 0, the horizontal position is 1.  When sin is 1, cos is 0, etc.   They are in sync, but shifted. 

#### Simple examples

It's pretty easy to use sin to animate the position of an object.  

Here, we'll take the sin of the elapsed time `sin(ofGetElpasedTimef())`. This returns a number between negative one and one. It does this every 6.28 seconds.  We can use ofMap to map this to a new range. For example 

```cpp
void ofApp::draw(){
    float xPos = ofMap(sin(ofGetElpasedTimef()), -1, 1, 0, ofGetWidth());
    ofRect(xPos, ofGetHeight/2, 10,10);
}

```
This draws a rectangle which moves sinusoidally across the screen, back and forth every 6.28 seconds. 

You can do simple things with offsets to the phase (how shifted over the sin wave is).  In example 7 **(7_sinExample_phase)**, we calculate the sin of time twice, but the second time, we add PI: `ofGetElapsedTimef() + PI`.  This means the two values will be offset from each other by 180 degrees on the circle (imagining our dot, when one is far right, the other will be far left.  When one is up, the other is down).  Here we set the background color and the color of a rectangle using these offset values.  It's useful if you start playing with sin and cos to manipulate phase. 

```cpp
//--------------------------------------------------------------
void testApp::draw(){
    
    
    float sinOfTime                = sin( ofGetElapsedTimef() );
    float sinOfTimeMapped        = ofMap( sinOfTime, -1, 1, 0, 255);
    
    
    ofBackground(sinOfTimeMapped, sinOfTimeMapped, sinOfTimeMapped);

    
    float sinOfTime2            = sin( ofGetElapsedTimef() + PI);
    float sinOfTimeMapped2        = ofMap( sinOfTime2, -1, 1, 0, 255);
    
    ofSetColor(sinOfTimeMapped2, sinOfTimeMapped2, sinOfTimeMapped2);
    ofRect(100,100,ofGetWidth()-200, ofGetHeight()-200);
    
}
```

*As a nerdy detail, floating point numbers are not linearly precise, e.g., there's a different number of floating point numbers between 0.0 and 1.0 than 100.0 and 101.0. You actually lose precision the larger a floating point number gets, so taking sin of elapsed time can start looking crunchy after some time. For long running installations I will sometimes write code that looks like* `sin((ofGetElapsedTimeMillis() % 6283) / 6283.0)` *or something similar, to account for this. Even though ofGetElapsedTimef() gets larger over time, it's a worse and worse input to sin() as it grows.  ofGetElapsedTimeMillis() doesn't suffer from this problem since it's an integer number and the number of integers between 0 and 10 is the same as between 1000 and 1010.*

#### Circular movement

Since sin and cos are derived from the circle, if we want to move things in a circular way, we can figure this out via sin and cos. We have four variables we need to know: 

- the origin of the circle (xOrig, yOrig)
- the radius of the circle (radius)
- the angle around the circle (angle)

The formula is fairly simple: 

```cpp
xPos = xOrig + radius * cos(angle);
yPos = yOrig + radius * sin(angle);
```

This allows us to create something moving in a circular way.  In the circle example, I will animate using this approach.  

```cpp
float xorig = 500;
float yorig = 300;
float angle = ofGetElapsedTimef()*3.5;
float x = xorig + radius * cos(angle);
float y = yorig + radius * sin(angle);
```

*Note: In OF, the top left corner is 0,0 (y axis is increasing as you go down) so you'll notice that the point travels clockwise instead of counterclockwise.  If this bugs you (since above, I asked you imagine it moving counterclockwise) you can modify this line `float y = yorig + radius * sin(angle)` to `float y = yorig + radius * -sin(angle)` and see the circle go in the counterclockwise direction.*

For these examples, I start to add a "trail" to the object by using the [ofPolyline](http://openframeworks.cc/documentation/graphics/ofPolyline.html "ofPolyline Documentation Page") object. I keep adding points, and once I have a certain number I delete the oldest one. This helps us better see the motion of the object. 

If we increase the radius, for example by doing: 

```cpp
void testApp::update(){
    radius = radius + 0.1;
}
```

we get spirals. 

#### Lissajous figures

Finally, if we alter the angles we pass in to x and y for this formula at different rates, we can get interesting figures, called "Lissajous" figures, named after the French mathematician, Jules Antoine Lissajous. These formulas look cool.   Oftentimes I joke with my students in algorithm class about how this is really a course to make cool screen savers. 

### Noise

Noise is similar to sin/cos in that it's a function taking some input and producing output, which we can then use for movement.  In the case of sin/cos you are passing in an angle and getting a result back that goes back and forth between -1 and 1.  In openFrameworks we wrap code using [simplex noise](http://en.wikipedia.org/wiki/Simplex_noise), which is comparable to Perlin noise and we have a function [`ofNoise()`](http://openframeworks.cc/documentation/math/ofMath.html#!show_ofNoise "ofNoise Documentation Page") that takes an input and produces an output.  Both algorithms (Perlin, Simplex) provide a pseudo random noise pattern -- they are quite useful for animation, because they are continuous functions, unlike [ofRandom](http://openframeworks.cc/documentation/math/ofMath.html#!show_ofRandom "ofRandom Documentation Page") for example, which just returns random values.  

When I say continuous function, what I mean is if you pass in smaller changes as input, you get smaller output and if you pass in the same value you get the same result.  For example, `sin(1.7)` always returns the same value, and `ofNoise(1.7)` also always returns the same result.   Likewise if you call `sin(1.7)` and `sin(1.75)` you get results that are continuous (meaning, you can call `sin(1.71) sin(1.72)... sin(1.74)` to get intermediate results).  

You can do the same thing with ofNoise -- here, I write a for loop to draw noise as a line.  `ofNoise` takes an input, here i/10 and produces an output which is between 0 and 1.  [`ofSignedNoise`](http://openframeworks.cc/documentation/math/ofMath.html#!show_ofSignedNoise "ofSignedNoise Documentation Page") is similar but it produces an output between -1 and 1.

![noise line](images/noiseLine.png)

```cpp
ofBackground(0,0,0);
ofSetColor(255);

ofNoFill();
ofBeginShape();
for (int i = 0; i < 500; i++){
    
    float x = i;
    float noise = ofNoise(i/10.0);
    float y = ofMap(noise, 0,1, 0, 100);
    ofVertex(x,y);
}
ofEndShape();
```

If you alter the i/10.0, you can adjust the scale of the noise, either zooming in (ie, i/100.0), so you see more details, or zooming out (ie, i/5.0) so you see more variation. 

![noise with i divided by 100](images/noise_i_d_100.png)

![noise with i divided by 5](images/noise_i_d_5.png)
   
We can use noise to animate. Here, for example, we move an object on screen using noise: 

```cpp
float x = ofMap( ofNoise( ofGetElapsedTimef()), 0, 1, 0, ofGetWidth());
ofCircle(x,200,30);
```
  
If we move y via noise, we can take a noise input value somewhere "away" from the x value, ie further down the curved line: 

```cpp
float x = ofMap( ofNoise( ofGetElapsedTimef()), 0, 1, 0, ofGetWidth());
float y = ofMap( ofNoise( 1000.0+ ofGetElapsedTimef()), 0, 1, 0, ofGetHeight());
ofCircle(x,y,30);
```

Alternatively, ofNoise takes multiple dimensions.  Here's a quick sketch moving something in a path via ofNoise using the 2d dimensions

![noise via 2d](images/noise2d.png)
 
 The code for this example (note the 2 inputs into ofNoise, this is a 2-dimensional noise call.  It allows us to use the same value for time, but get different results):

```cpp
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float x = ofMap( ofNoise( ofGetElapsedTimef()/2.0, -1000), 0, 1, 0, ofGetWidth());
    float y = ofMap( ofNoise( ofGetElapsedTimef()/2.0, 1000), 0, 1, 0, ofGetHeight());
    ofNoFill();
    ofCircle(x,y,3);
    
}
```

There's a ton more we can do with noise, we'll leave it for now but encourage you to look at the noise examples that come with openframeworks, which show how noise can be use to create lifelike movement.  Also, we encourage readers to investigate the work of [Ken Perlin](http://mrl.nyu.edu/~perlin/), author of the simplex noise algorithm -- he's got great examples of how you can use noise in creative, playful ways. 


## Simulation

If you have a photograph of an object at one point in time, you know its position.  If you have a photograph of an object at another point in time and the camera hasn't changed, you can measure its velocity, i.e., its change in distance over time. If you have a photograph at three points in time, you can measure its acceleration, i.e., how much the speed changing over time.  

The individual measurements compared together tell us something about movement. Now, we're going to go in the opposite direction. Think about how we can use measurements like speed and acceleration to control position.

If you know how fast an object is traveling, you can determine how far it's traveled in a certain amount of time. For example, if you are driving at 50 miles per hour (roughly 80km / hour), how far have you traveled in one hour? That's easy. You've traveled 50 miles. How far have you traveled in two or three hours? There is a simple equation to calculate this distance:

```cpp
position = position + (velocity * elapsed time)
```

e.g.: 
    
```cpp
position = position + 50 * 1;   // for one hour away
```

or

```cpp
position = position + 50 * 2;   // for two hours driving


```
The key expression–position = position + velocity–in shorthand would be `p=p+v`.

*Note, the elapsed time part is important, but when we animate we'll be doing p=p+v quite regularly and you may see us drop this to simplify things (assume every frame has an elapsed time of one). This isn't entirely accurate but it keeps things simple. See the previous section on frame rate (and frame rate independence) for more details* 

In addition, if you are traveling at 50 miles per hour (apologies to everyone who thinks in km!) and you accelerate by 5 miles per hour, how fast are you driving in 1 hr? The answer is 55 mph. In 2 hrs, you'd be traveling 60 mph.  In these examples, you are doing the following: 

```cpp
velocity = velocity + acceleration
```

In shorthand, we'll use `v=v+a`. So we have two important equations for showing movement based on speed: 

```cpp
p = p + v;   // position = position + velocity
v = v + a;   // velocity = velocity + acceleration
```

The amazing thing is that we've just described a system that can use acceleration to control position. Why is this useful? It's useful–if you remember from physics class–because Newton had very simple laws of motion, the second of which says 

```cpp
Force = Mass x Acceleration
```

In shorthand, `F = M x A`.  This means force and acceleration are linearly related.  If we assume that an object has a mass of one, then force equals acceleration.  This means we can use force to control velocity and velocity to control position.  

The cool, amazing, beautiful thing is there are plenty of forces we can apply to an object, such as spring forces, repulsion forces, alignment forces, etc. 

I have several particle examples that use this approach, and while I won't go deeply into them, I'll try to explain some interesting ideas you might find. 

### Particle class

The particle class in all of the examples is designed to be pretty straight forward.  Let's take a look at the H file: 

```cpp
class particle{
    
    public:

        ofPoint pos;
        ofPoint vel;
        ofPoint frc;  
        float damping;
                        
        particle();
        void setInitialCondition(float px, float py, float vx, float vy);
           
        void resetForce();
        void addForce(float x, float y);
        void addDampingForce();
        
        void update();
        void draw();    
};
```

For variables, it has [ofPoint](http://openframeworks.cc/documentation/types/ofPoint.html "ofPoint Documentation Page") objects for position, velocity and force (abbreviated as pos, vel and frc).  It also has a variable for damping, which represents how much this object slows down over time.  A damping of 0 would mean not slowing down at all, and as damping gets higher, it's like adding more friction - imagine rolling a ball on ice, concrete or sand. It would slow down at different rates. 

In terms of functions, it has a constructor which sets some internal variables like damping and a setInitialCondition() that allows you to set the position and velocity of the particle.  Think about this as setting up its initial state, and from here you let the particle play out.   The next three functions are about forces (we'll see more) -- the first one, `resetForce()`, clears all the internal force variable frc.  Forces are not cumulative across frames, so at the start of every frame we clear it.  `addForce()` adds a force in a given direction, useful for constant forces, like gravity.  `addDampingForce()` adds a force opposite velocity (damping is a force felt opposite the direction of travel).   Finally, update takes force and adds it to velocity, and takes velocity and adds it to position.  Draw just draws a dot where position is. 

The particle class is really simple, and throughout these examples, we add complexity to it.  In general, formula you will see in all the examples is: 

```cpp
for (int i = 0; i < particles.size(); i++){
    particles[i].resetForce();
}

// <------ magic happens here --------->

for (int i = 0; i < particles.size(); i++){
    particles[i].update();
}
```

where the magic is happening between the resetForce and update.   Although these examples increase in complexity, they do so simply by adding new functions to the particle class, and adding more things between reset and update. 

**[note: add screenshot of simple particle examples]**

### Simple forces, repulsion and attraction

In the next few examples, I added a few functions to the particle object: 

```cpp
void addRepulsionForce( float px, float py, float radius, float strength);
void addAttractionForce( float px, float py, float radius, float strength);
void addClockwiseForce( float px, float py, float radius, float strength);
void addCounterClockwiseForce( float px, float py, float radius, float strength);
```

They essentially add forces the move towards or away from a point that you pass in, or in the case of clockwise forces, around a point.

![sin](images/particle.png)

The calculation of these forces is fairly straightforward - first, we figure out how far away a point is from the center of the force.  If it's outside of the radius of interaction, we disregard it.  If it's inside, we figure out its percentage, i.e., the distance between the force and the particle divided by the radius of interaction.  This gives us a number that's close to 1 when we are towards the far edge of the circle and 0 as we get towards the center.  If we invert this, by taking 1 - percent, we get a number that's small on the outside, and larger as we get closer to the center. 

This is useful because oftentimes forces are proportional to distance.  For example, a magnetic force will have a radius at which it works, and the closer you get to the magnet the stronger the force. 

Here's a quick look at one of the functions for adding force: 


```cpp
void particle::addAttractionForce( float px, float py, float radius, float strength){

    ofVec2f posOfForce;
    posOfForce.set(px, py);
    ofVec2f diff = pos - posOfForce;
    
    if (diff.length() < radius){ 
        float pct = 1 - (diff.length() / radius);
        diff.normalize();
        frc.x -= diff.x * pct * strength;
        frc.y -= diff.y * pct * strength;
    }
} 
```

`diff` is a line between the particle and the position of the force.  If the length of diff is less than the radius, we calculate the pct as a number that goes between 0 and 1 (0 on the outside of the radius of interaction, 1 as we get to the center of the force).  We take the line `diff` and normalize it to get a "directional" vector, its magnitude (distance) is one, but the angle is still there.  We then multiply that by pct * strength to get a line that tells us how to move.  This gets added to our force. 

You'll notice that all the code is relatively similar, but with different additions to force.  For example, repulsion is just the opposite of attraction: 

```cpp
        frc.x += diff.x * pct * strength;
        frc.y += diff.y * pct * strength;
```

We just move in the opposite direction.  For the clockwise and counterclockwise forces we add the perpendicular of the diff line.  The perpendicular of a 2d vector is just simply switching x and y and making one of them negative.

**[more: show example]**

### Particle interaction

Now that we have particles interacting with forces, the next step is to give them more understanding of each other.  For example, if you have a broad attraction force, they will all converge on the same point without any respect for their neighbors.  The trick is to add a function that allows the particle to feel a force based on their neighbor. 

We've added new functions to the particle object (looking in the h file):

```cpp
void addRepulsionForce(particle &p, float radius, float scale);
void addAttractionForce(particle &p, float radius, float scale);
```

This looks really similar to the code before, except here we pass in a particle instead of an x and y position. You'll notice that we pass by reference (using &) as opposed to passing by copy.  This is because internally we'll alter both the particle which has this function called as well as particle p -- ie, if you calculate A vs B, you don't need to calculate B vs A.
	
```cpp
void particle::addRepulsionForce(particle &p, float radius, float scale){
    
    // ----------- (1) make a vector of where this particle p is: 
    ofVec2f posOfForce;
    posOfForce.set(p.pos.x,p.pos.y);
    
    // ----------- (2) calculate the difference & length 
    
    ofVec2f diff    = pos - posOfForce;
    float length    = diff.length();
    
    // ----------- (3) check close enough
    
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    
    // ----------- (4) if so, update force
    
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
        frc.x = frc.x + diff.x * scale * pct;
        frc.y = frc.y + diff.y * scale * pct;
        p.frc.x = p.frc.x - diff.x * scale * pct;
        p.frc.y = p.frc.y - diff.y * scale * pct;
    }
}
```

The code should look very similar to before, except with these added lines: 

```cpp
frc.x = frc.x + diff.x * scale * pct;
frc.y = frc.y + diff.y * scale * pct;
p.frc.x = p.frc.x - diff.x * scale * pct;
p.frc.y = p.frc.y - diff.y * scale * pct;

```
This is modifying both the particle you are calling this on and the particle that is passed in.  

This means we can cut down on the number of particle interactions we need to calculate: 


```cpp
for (int i = 0; i < particles.size(); i++){
    for (int j = 0; j < i; j++){
        particles[i].addRepulsionForce(particles[j], 10, 0.4);
    }
}
```

You'll notice in this 2d for loop, the inner loop counts up to the outer loop, so when i is 0, we don't even do the inner loop.  When i is 1, we compare it to 0 (1 vs 0).  When i is 2, we compare it to 0 and 1 (2 vs 0, 2 vs 1).  This way we never compare a particle with itself, as that would make no sense (although we might know some people in our lives that have a strong self attraction or repulsion). 

**[note: maybe a diagram to clarify]**

One thing to note is that even though we've cut down the number of calculations, it's still quite a lot!  This is a problem that doesn't scale linearly.  In computer science, you talk about a problem using "O" notation, i.e. big O notation.  This is a bit more like O^2 / 2 -- the complexity is approximately 1/2 of a square.  If you have 100 particles, you are doing almost 5000 calculations (100 * 100 / 2).  If you have 1000 particles, it's almost half a million.  Needless to say, lots of particles can get slow...

We don't have time to get into it in this chapter, but there's different approaches to avoiding that many calculations.  Many of them have to deal with spatial hashing, ways of quickly identifying which particles are far away enough to not even consider (thus avoiding a distance calculation).

### local interactions lead to global behavior

![sin](images/multiForces.png)


## Where to go further

### Physics and animation libraries

