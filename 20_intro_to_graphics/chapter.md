# Graphics #

**Introduction TDB**

I'm aiming to make sure we don't lose any beginners, so I realize that this chapter may be overly pedantic.  It can be tightened up in revisions.

## 0. Outline
- 1. [Drawing Shapes. Then Drawing Many, Many, Many Shapes](#1-drawing-shapes--then-drawing-many-many-many-shapes)
	- 1.1 [Predefined Shapes](#11-predefined-shapes)
		-  1.1a [Drawing to the screen!](#11a-drawing-to-the-screen)
		-  1.1b [Drawing to the screen! The fun bits.](#11b-drawing-to-the-screen-the-fun-bits)
	- 1.2 Freeform Shapes
		-  1.2a Drawing to the screen, again!
		-  1.2b The fun bits, again!
- 2. Moving Coordinate System
- 3. Recursion

## 1. Drawing Shapes.  Then Drawing Many, Many, Many Shapes ##

This section needs an introduction explaining the flow of this section - we are making generative brushes because it is allows for us to jump into graphics with minimal math+conceptual overhead but it still allows for hitting all the graphical concepts.  (But it still leaves room for adding in advanced math+concepts.)

**[Note: Insert Section on Setup/Update/Draw]**

**[Note: Insert Section on XY coordinate system]**

To get started creating brushes, we need to find the basic building blocks of graphics.  You can classify the 2D graphics functions that openFrameworks provides into two categories: predefined shapes and freeform shapes.  The predefines shapes are rectangles, circles, triangles and straight lines.  The freeform shapes are polygons and paths.

### 1.1 Predefined Shapes ###

#### 1.1a Drawing to the screen! ####

Okay, okay.  Time for actual code.  Add the following line to your `draw()` function and like magic you will have an empty, empty, black void of a window on your screen.


	ofBackground(0);


Now that we have our background in place, we can start drawing on top of it.  Let's draw a rectangle, a circle, an ellipse, a triangle and some straight lines by adding the following lines to the end of the `draw()` function:

	ofSetColor(0);
	
	// Let's draw some filled shapes
	ofRect(50, 50, 100, 100);
	ofCircle(250, 100, 50);
	ofEllipse(400, 100, 80, 100);
	ofTriangle(500, 150, 550, 50, 600, 150);
	ofLine(700, 50, 700, 150);

The first line of code tells openFrameworks what color it should be using when drawing.  You can think of it as telling openFrameworks to pull out a particular colored sharpie - it will draw in that color until you tell it to switch to another color.  We'll be exploring how you can specify color as we go, but for now, we are using grayscale colors.  If you pass in a single integer value (between 0 and 255) to [`ofSetColor`](http://openframeworks.cc/documentation/graphics/ofGraphics.html#show_ofSetColor "ofColor Documentation Page"), openFrameworks will interpret that as a grayscale color where 0 is black (i.e. no light) and 255 is white (i.e. all light).

Now that we have color squared away, we make use of some handy functions to draw shapes: `ofRect`, `ofCircle`, `ofEllipse`, `ofTriangle` and `ofLine`.  The documentation page for [`ofRect`](http://openframeworks.cc/documentation/graphics/ofGraphics.html#!show_ofRect "ofRect Documentation Page") shows that we can create a rectangle in a number of different ways.  Here, we are passing in the x and y values of the top left corner as well as the width and height that we would like, all in that order.  For [`ofCircle`](http://openframeworks.cc/documentation/graphics/ofGraphics.html#show_ofCircle "ofCircle Documentation Page"), we are passing in the x and y values of the center of the circle and the radius.  With [`ofEllipse`](http://openframeworks.cc/documentation/graphics/ofGraphics.html#show_ofEllipse "ofEllipse Documentation Page"), we are passing in the x and y values of the center as well as the width and height.  For [`ofTriangle`](http://openframeworks.cc/documentation/graphics/ofGraphics.html#show_ofTriangle "ofTriangle Documentation Page"), we pass in the x and y positions of the three corners of the triangle.  Finally, with [`ofLine`](http://openframeworks.cc/documentation/graphics/ofGraphics.html#show_ofLine "ofLine Documentation Page"), we pass in the x and y coordinates of the two endpoints of our desired straight line.

And when you run all of that, you should see some filled shapes hanging out in your black void.

But what if you only wanted to draw the outline of the shapes?  There are two functions, [`ofFill`](http://openframeworks.cc/documentation/graphics/ofGraphics.html#!show_ofFill "ofFill Documentation Page") and [`ofNoFill`](http://openframeworks.cc/documentation/graphics/ofGraphics.html#!show_ofFill "ofNoFill Documentation Page") that will allow you to toggle between drawing filled shapes and drawing outlines.  Let's modify our `draw` function again, so that it looks like this:

	ofBackground(0);
	
	ofSetColor(255);
	
	ofFill(); // If you omit this and leave ofNoFill(), all the shapes will be outlines!
	
	// Let's draw some filled shapes
	ofRect(50, 50, 100, 100);
	ofCircle(250, 100, 50);
	ofEllipse(400, 100, 80, 100);
	ofTriangle(500, 150, 550, 50, 600, 150);
	ofLine(700, 50, 700, 150);
	
	ofNoFill(); // If you omit this and leave ofFill(), all the shapes will be filled!
	
	// Let's draw some shape outlines
	ofRect(50, 250, 100, 100);
	ofCircle(250, 300, 50);
	ofEllipse(400, 300, 80, 100);
	ofTriangle(500, 250, 550, 50, 600, 150);
	ofLine(700, 250, 700, 350);

Here, we've redraw our same shapes but without the fill and shifted down 200 pixels on the screen.  Much like `ofSetColor`, `ofFill` tells openFrameworks that it should be ready to draw filled shapes until it sees `ofNoFill`. (And `ofNoFill` says to draw outlines until the next `ofFill`.)

**[Note: mention why ofLine is lighter than full white]** 

And if you want to control the thickness of the outlines (or the straight lines drawn with `ofLine`), you can use [`ofSetLineWidth`](http://openframeworks.cc/documentation/graphics/ofGraphics.html#show_ofSetLineWidth "ofSetLineWidth Documentation Page").  Again, like `ofSetColor`, `ofSetLineWidth` will effect all lines drawn until the thickness is changed again.  Add the following lines to your `draw` function:

	// Code omitted for clarity ...
	
	ofFill(); // If you omit this and leave ofNoFill(), all the shapes will be outlines!
	ofSetLineWidth(1); // Default value is 1
	
	// Code omitted for clarity ...
	
	ofNoFill(); // If you omit this and leave ofFill(), all the shapes will be filled!
	ofSetLineWidth(2); // Try playing with the value
	
	// Code omitted for clarity ...

Okay, so you've got the recipes for some basic shapes down.  Before we start putting those snippets of code to some creative uses, there's one more line of code that you should add, [`ofEnableAntiAliasing`](http://openframeworks.cc/documentation/graphics/ofGraphics.html#show_ofEnableAntiAliasing "ofEnableAntiAliasing Documentation Page").  You might have noticed that your outlines (and ofLines) look a bit blocky.  The lines look like paths of jagged pixels.  We can smooth out these pixels using an anti-aliasing technique.  Luckily, you don't have to do anything other than add `ofEnableAntiAliasing();` to your `setup` function, and poof, smoother lines.  (If you want to understand what's happening under the hood, check out the wiki on [anti-aliasing](http://en.wikipedia.org/wiki/Spatial_anti-aliasing "Wiki on spatial anti-aliasing").

![Anti-aliasing](images/intrographics_antialiasing.png "Line with and without anti-aliasing")
![Basic Shapes](images/intrographics_basicshapes.png "Basic shapes with and without a fill")

**[Note: Include something about rounded rect]**
**[Note: Include something about layering, explaining screen buffer]**
**[Note: Include something about setting rect mode, circle resolution]**
**[Note: Include something about RGB colors]**


#### 1.1b Drawing to the screen! The fun bits. ####

You surivived the boring bits!

Well, the necessary bits.  Why draw a single rectangle, when you can draw a bagillion?

![Many Rectangles](images/intrographics_lotsofrectangles.png "Drawing lots and lots of rectangles")

Let's create a new openFrameworks project and call it something like ShapeBrush.  We are going to just use the basic recipes from the last section and mix in some randomness and repetition to create a digital 'brush.'  When we click somewhere on the screen, we will draw a ton of shapes.  But we need a canvas that doesn't constantly erase itself. openFrameworks clears the screen on with each invocation of `draw`, so enter [`ofSetBackgroundAuto`](http://openframeworks.cc/documentation/graphics/ofGraphics.html#show_ofSetBackgroundAuto "ofSetBackgroundAuto Documentation Page"), which allows us to stop openFrameworks from clearing the screen on each update.  Add the following lines into your `setup` function:

	ofSetBackgroundAuto(false);
	ofBackground(0); // If you omit this, the screen will be a default gray color

`ofSetBackgroundAuto` takes a boolean value, so pass in `false` and then we draw a black background.  **[Note: point to c++ chapter's description of bools?]**   Great!  We've created an exceptionally empty space that we can overload with shapes.

Since we will be doing all our drawing inside of the `draw` function, what we need to create some variables that let us know 1) where the mouse is located on the screen and 2) whether or not the left mouse button is currently pressed.

For 1), we can use two built-in openFrameworks variables `mouseX` and `mouseY`.  These variables are updated internally by openFrameworks. We can use them inside our `draw` function as we would any other integer variables.

For 2), we should take a look at two functions inside your openFrameworks source file (.cpp) that you probably haven't had a need to use yet: [`mousePressed(int x, int y, int button)`](http://www.openframeworks.cc/documentation/application/ofBaseApp.html#show_mousePressed "mousePressed Documentation Page") and [`mouseReleased(int x, int y, int button)`](http://www.openframeworks.cc/documentation/application/ofBaseApp.html#show_mouseReleased) "mouseReleased Documentation Page").  These functions are called by openFrameworks anytime a mouse button is pressed or released.  It recieves the x and y position of the mouse when the mouse was pressed/released as well as an integer representing which mouse button was pressed/released.   We can thus set up a boolean variable, isLeftMousePressed, and change its value inside of these two functions.

So add this to your header file (.h):

	bool isLeftMousePressed;

And add this into the `setup` function of your source file (.cpp):

	isLeftMousePressed = false;  

Now that the boolean variable is set up, add these lines to your `mousePressed` and `mouseReleased` functions:

	void testApp::mousePressed(int x, int y, int button){
	    if (button == OF_MOUSE_BUTTON_LEFT) isLeftMousePressed = true;
	}
	
	void testApp::mouseReleased(int x, int y, int button){
	    if (button == OF_MOUSE_BUTTON_LEFT) isLeftMousePressed = false;
	}

Whenever a button on the mouse is pressed or released, we want to check if that button is the left mouse button.  If it is, then we can adjust our `isLefMousePressed` boolean appropriately.  The `button` variable is an integer that identifies which button is pressed/released, and openFrameworks provides some handy constants that we can use to identify the button in a human-readable way (`OF_MOUSE_BUTTON_LEFT`, `OF_MOUSE_BUTTON_MIDDLE` and `OF_MOUSE_BUTTON_RIGHT`).  If you really wanted, you *could* just say `button == 0` to test for whether the pressed/released button is the left mouse button.

Let's hop into the `draw` function and start making use of our mouse information:

	if (isLeftMousePressed) {
	    ofSetColor(255);
	    ofSetRectMode(OF_RECTMODE_CENTER);
	    ofRect(mouseX, mouseY, 50, 50);
	}

[`ofSetRectMode`](http://www.openframeworks.cc/documentation/graphics/ofGraphics.html#show_ofSetRectMode "ofSetRectMode Documentation Page") allows us to control how the x and y positions we pass into `ofRect` are used to draw a rectangle.  Like with the mouse button constants, openFrameworks provides some rectangle mode constants for us to use: `OF_RECTMODE_CORNER` and `OF_RECTMODE_CENTER`.  By default rectangles are drawn by interpreting the x and y values you pass to it as the coordinates of the upper left corner (`OF_RECTMODE_CORNER`).  For our purposes, it is more convient for us to specify the center of the rectangle (`OF_RECTMODE_CENTER`) so that our rectangle is centered over the mouse position.  So we draw the center of our white, 50 x 50 rectangle at the mouse position using `mouseX` and `mouseY`.

Boring! We are going to make this a bit more interesting by 1) adding randomness and 2) adding repeptition.

Randomness makes your openFrameworks sketches dark, mysterious and unpredictable.  So meet one of your new friends, [`ofRandom`](http://openframeworks.cc/documentation/math/ofMath.html#!show_ofRandom "ofRandom Documentation Page").  `ofRandom` can be used in two different ways: by passing in two values `ofRandom(float min, float max)` or by passing in a single value `ofRandom(float max)`.  If you pass in two values, they are the minimum and maximum values you want your random value to take.  If you pass in a single value, it is considered to be the maximum value you want and the minimum is assumed to be 0.  So when we go to specify the color of the rectangle we are about to draw, we can substitute a random value:

	ofSetColor(ofRandom(50, 255));

**[Note: Aside on what computer randomness is?]**

**[Note: Point to c++ section on float vs int and casting?]**

Remember that we are using grayscale colors and that they take on values between 0 and 255.  We can exlude some of the deep black colors because they won't be visible to us when drawing on a black background.  

**[Note: change image to cursive 'hi'?]**

![Rectangle Snake](images/intrographics_rectanglesnake.png "Drawing a snake of rectangles")

**[Note: reference to c++ loops section?]**

So whenever you are done drawing weird rectangle snakes, we can move on to adding repetition.  Instead of drawing a single rectangle every frame during which the left mouse button is pressed, we can draw a burst of randomized rectangles.  To create that burst, we are going use a for loop to generate a set some number of rectangles where each rectangle's parameters are randomly chosen from a set of values.  So what can we randomize?  Grayscale color, width and height are easy candidates.  We can also use a small positive or negative value to randomly offset each rectangle from mouse position.  Modify your `draw` function to look like this:  

	if (isLeftMousePressed) {
	    ofSetRectMode(OF_RECTMODE_CENTER);
	    int numRects = 10;
	    for (int r=0; r<numRects; r++) {
	        ofSetColor(ofRandom(50, 255));
	        float width = ofRandom(5, 20);
	        float height = ofRandom(5, 20);
	        float xoffset = ofRandom(-40, 40);
	        float yoffset = ofRandom(-40, 40);
	        ofRect(mouseX+xoffset, mouseY+yoffset, width, height);
	    }
	}

But let's add one more thing before you hit run.  Into `setup`, add:

	ofSetFrameRate(60);

**[Note: do I need to explain framerate?]**

Why do we care about setting the framerate here?  We want to be able to accurately know (and control) how many rectangles our code will draw.  We are drawing 10 every time the `draw` function is called, but without setting the framerate, we don't know ahout many times the `draw` function will be called per second.  By setting the framerate to 60 frames per second, then we can say that our code will generate `10 rectangles per frame * 60 frames per second = 60 rectangles per second`.

So what happens when you try using your new rectangle brush?  You get a box-shaped, messy spread of random rectangles.  Things are slowly becoming more interesting.  But you might have been expecting to see a circular spread?  Since we said that `xoffset` and `yoffset` could be random values between -40 and 40, we were actually picking values from a rectangular region of space.  You can imagine the boundries of that region by thinking about what happens when `xoffset` and `yoffset` take on their extreme values (e.g. [`xoffset`, `yoffset`] values of [-40, -40], [40, -40], [40, 40], [-40, 40]).

To generate a circular spread, we need to introduce a tiny pinch of mathematics.  If we want to pick a random point that lives within a circle that has a particular size, it helps to think in terms of angles.  Image you are at the center of a circle.  If you rotate a random amount (let's call this the *polar angle*) and then move a random distance (let's call this the *polar radius*), you will end up in a random location within the circle (assuming you don't walk so far that you cross the boundry of your circle).  You've defined a point in space by a polar angle and a polar radius instead of using an x coordinate and a y coordinate.  What you've done is think in terms of what are called [polar coordinates](http://en.wikipedia.org/wiki/Polar_coordinate_system "Polar Coordinates Wiki").  (In contrast, using x and y values to define a point is the [Cartesian coordinate system](http://en.wikipedia.org/wiki/Cartesian_coordinate_system "Cartesian coordinate system"].)

**[Note: This could use a simple visual to show cartesian vs polar coords]**

So where does this leave us in terms of our code?  If we start at the mouse position, we want to pick a random direction (polar angle) and random distance (polar distance).  Once we have those, we can convert them back to Cartesian coordinates (x and y values) to be used for our `xoffset` and `yoffset`.  So modify your for loop inside your `draw` function to look like this:

**[Note: Explain the trig conversion from polar to cartesian, or point to the math chapter section?]**

	for (int r=0; r<numRects; r++) {
	    ofSetColor(ofRandom(50, 255));
	    float width = ofRandom(5, 20);
	    float height = ofRandom(5, 20);
	    float angle = ofRandom(2.0*PI);
	    float distance = ofRandom(35);
	    float xoffset = cos(angle) * distance;
	    float yoffset = sin(angle) * distance;
	    ofRect(mouseX+xoffset, mouseY+yoffset, width, height);
	}

**[Note: explain radians vs degrees]**

**[Note: if there is room, add in a gaussian distribution via box-muller transform]**

![Cartesian Versus Polar Spreads](images/intrographics_cartesianvspolarspread.png "Cartesian brush spread versus polar brush spread")

**[Note: Insert an image using the rectangle brush]**

:) You are a rectangle master now.  But the circles, ellipses, lines and triangles probably feel neglected.  Since we are going to create a few more brushes, let's add two things to our code 1) the ability to erase the screen and 2) the ability to switch between brushes.

For erasing the screen, add the following lines (check the comments to see where to put them):
	
	// Add to your header (.h):
	bool isRightMousePressed;
		
	// Add to setup()
	isRightMousePressed = false;
		
	// Add to mousePressed()
	if (button == OF_MOUSE_BUTTON_RIGHT) isRightMousePressed = true; 
	
	// Add to mouseReleased()
	if (button == OF_MOUSE_BUTTON_RIGHT) isRightMousePressed = false;
	
	// Add to the beginning of draw()
	if (isRightMousePressed) ofBackground(0);

Now we can right click to get a fresh screen.  For adding the ability to switch between brushes, we are going to define an integer `drawingMode` and each number from 0 through 3 will represent a unique mode.  To make our code more human-readable, we will define an integer variable for each of those modes, e.g. `rectangleMode = 0`, etc.  Inside of `draw`, we can then check the drawingMode variable to determine what code to execute.  Then finally, we will use keyboard inputs to switch between the different brush modes.

Add these variables to your header file (.h):

	int drawingMode;
	int rectangleMode = 0;
	int ellipseMode = 1;
	int circleMode = 2;
	int lineMode = 3;
	int triangleMode = 4;

In your `.cpp` function, initialize your drawing mode to the rectangle brush:

	drawingMode = rectangleMode;

We are going to reorganize the `draw` function, so that it looks like this:

	// If right mouse button pressed, erase the screen
	if (isRightMousePressed) ofBackground(0);
	
	// If left mouse button pressed, draw the appropriate brush
	if (isLeftMousePressed) {
	
	if (drawingMode == rectangleMode) {
	    // Insert the rectangle drawing code you wrote here
	}
	
	else if (drawingMode == circleMode) {
	}
	
	else if (drawingMode == lineMode) {
	}
	
	else if (drawingMode == triangleMode) {
	}
	}

And for getting keyboard inputs, we are going to make use of the [`keyPressed(int key)`](http://openframeworks.cc/documentation/application/ofBaseApp.html#!show_keyPressed keyPressed "Documentation Page") function that is already built into your openFrameworks code.  Like `mousePressed`, this function is called any time a key is pressed.  We just need to use that integer that is passed in to keyPressed to switch our `drawingMode`.  "r" for rectangle mode, "c" for circle mode, etc.  

But how exactly does an integer tell us which key has been pressed?  Well that integer is actually the ASCII code for the key that was pressed.  You can check out the [ASCII wiki](http://en.wikipedia.org/wiki/ASCII "ASCII Wiki Page") for details, but for this chapter, it is enough to just know that ASCII is an agreed upon system for assigning numbers to characters.  And it turns out to be quite easy to check if that ASCII integer `key` is a particular character.  Let's see what this looks like in code.  Add these lines to your `keyPressed` function:

	if (key == 'r') drawingMode = rectangleMode;
	else if (key == 'c') drawingMode = circleMode;
	else if (key == 'l') drawingMode = lineMode;
	else if (key == 't') drawingMode = triangleMode;

In c++, you can compare an integer like `key` with a character through an inequality.  

**[Note: Explain char vs int, the double quote vs single quote.  Or is this in c++ chapter]**

**[Note: the constants that oF provides for key presses]**

Whew! Now when you run your code, you should be able to clear your screen and switch between brushes.  Now let's fill in those circle, line and triangle brushes!

With our circle brush, let's play with transparency and then add in some color.  Unlike what we did with rectangles, we are going to layer our circles on top of each other until they become hazy and indistinct.  We are going to draw a giant transparent circle, then draw a slightly smaller transparent circle, then repeat, repeat, repeat.

Transparency? So far, we've only used opaque grayscale colors, but you can make your colors transparent by adding an extra parameter to `ofSetColor`, like `ofSetColor(255, 50)`.  That second parameter that we passed in is the alpha channel.  It takes a value from 0 to 255 where 0 is completely transparent and 255 is completely opaque.  But before we use colors that have alpha, we need to enable something called alpha blending.  This just means that when two transparent colors occupy the same space on the screen, their colors get mixed.  Alpha blending is disabled by default because it requires additional computational power over drawing opaque colors.  In the `setup` function, add the following line:

	ofEnableAlphaBlending();

Now we can start working on our `draw` function.  We will use the `angle`, `distance`, `xoffset` and `yoffset` code like we did with the rectangle brush.  The difference is that our loop will control the radius of our circle.  We will start with drawing a large radius circle and slowly reduce our radius to 0.  So add the following to `draw`:

	int maxRadius = 100;
	int radiusStepSize = 5;
	int alpha = 3;
	int maxOffsetDistance = 100;
	for (int radius=maxRadius; radius>0; radius-=radiusStepSize) {
	    float angle = ofRandom(2.0*PI);
	    float distance = ofRandom(maxOffsetDistance);
	    float xoffset = cos(angle) * distance;
	    float yoffset = sin(angle) * distance;
	    ofSetColor(255, alpha);
	    ofCircle(mouseX+xoffset, mouseY+yoffset, radius);
	}

The result is something like drawing with glowing light.  You can play with the maxRadius, radiusStepSize, alpha and maxOffsetDistance to get make that glowing effect stronger, weaker, narrower or wider.

![Circle Glow Brush](images/intrographics_circleglow.png "Results of using the circle glow brush")

Kind of cool right?  You are probably tired of having to live in moody shades of gray for so long.  Well, `ofSetColor` has some alternate forms that make use of the RGB color model.  If you haven't heard of RGB before, you can check out the [wiki](http://en.wikipedia.org/wiki/RGB_color_model "Wiki on RGB Color Model").  It allows you to specify a color through quantifying the amount of red, blue and green light in the color.  We refer to these color components as channels, and each channel can take on a value from 0 to 255.  (Alpha is another possible channel.) So here are the forms of `ofSetColor` we can now use:

**[Note: would it be helpful to somewhere explain 24-bit/32-bit color and where 256 comes from?]**

**[Note: would it be helpful to have a RGB diagram?]**

	ofSetColor(255); // Opaque grayscale white
	ofSetColor(255, 10); // Very transparent grayscale white
	ofSetColor(255, 0, 0); // Opaque red! Hooray for color :)
	ofSetColor(255, 0, 0, 10); // Very transparent red

So go ahead and modify your `ofSetColor` line of code inside of your circle brush to use some color you like.  I'll just leave this orange here: `ofSetColor(255, 103, 0, 3);`

There's another way we can use `ofSetColor` that is useful.  Meet [`ofColor`](http://openframeworks.cc/documentation/types/ofColor.html "ofColor Documentation Page"].  This is a handy class that openFrameworks provides for handling colors that allows you to do some color math (among other things). Here are some examples of defining and modifying colors:

	ofColor orange(255, 132, 0); // Opaque orange color - specified using RGB
	
	ofColor blue(0, 0, 255, 50); // Transparent blue color - specified using RGBA
	
	// You can access the red, green, blue and alpha channels like this:
	ofColor green(0, 0, 255, 255);
	cout << "Red channel:" << green.r << endl;
	cout << "Green channel:" << green.g << endl;
	cout << "Blue channel:" << green.b << endl;
	cout << "Alpha channel:" << green.a << endl;
	
	// You can also set the red, green, blue and alpha channels like this:
	ofColor yellow;
	yellow.r = 255;
	yellow.b = 0;
	yellow.g = 255;
	yellow.a = 255;

Now, let's say that instead of just using an orange or a red color for our circle brush, what if we wanted to pick a random color in-between orange and red?  `ofColor` has a solution for using what is called [linear interpolation](http://en.wikipedia.org/wiki/Linear_interpolation "Wiki for Linear Interpolation"].  Replace your `ofSetColor` line of code with these four lines of code: 

**[Note: explain lerp for the math averse and explain the syntax]**

	ofColor orange(255, 132, 0, alpha);
	ofColor red(255, 6, 0, alpha);
	ofColor inbetween = orange.getLerped(red, ofRandom(1.0));
	ofSetColor(inbetween);
	
Maybe you aren't a fan of circles?  You can turn your circle into an ellipse using:

	ofEllipse(mouseX+xoffset, mouseY+yoffset, radius*ofRandom(0.8, 1.2), radius*ofRandom(0.8, 1.2));

What about using outlines instead of solid shapes inserting `ofNoFill();` into your circle brush code?  If you do that, try increasing your `alpha` to 10 and lowering your `radiusStepSize` to 1.  (Don't forget that if you start using `ofNoFill` in your circle brush, you should add `ofFill` to your rectangle brush!)

![Circle Squiggle Brush](images/intrographics_circlesquiggles.png "Results of using the circle brush without fill")

**[Note: opportunity to explain push/pop style]**

**[Note: if there is time, extension with using an exponential decay for circle radius]**

**[Note: Why does the hue break when using alpha == 1?]**

	int numShapes = 50;
	int minLength = 50;
	int maxLength = 250;
	for (int i=0; i<numShapes; ++i) {
	    float distance = ofRandom(minLength, maxLength);
	    float angle = ofRandom(2.0*PI);
	    float xoffset = cos(angle) * distance;
	    float yoffset = sin(angle) * distance;
	    float alpha = ofMap(distance, minLength, maxLength, 50, 0);
	    ofSetColor(255, alpha);
	    ofLine(mouseX-xoffset/2.0, mouseY-yoffset/2.0, mouseX+xoffset/2.0, mouseY+yoffset/2.0);
	}

### 1.2 Freeform Shapes ###

#### 1.2a Drawing to the screen, again! ####

#### 1.2b The fun bits, again! ####



