## Programming Graphics

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
      * Example images: [hue](https://github.com/openframeworks/ofBook/blob/master/20_intro_to_graphics/images/EvolvingColor_ChangingHue.png), [saturation](https://github.com/openframeworks/ofBook/blob/master/20_intro_to_graphics/images/EvolvingColor_ChangingSaturation.png), [brightness](https://github.com/openframeworks/ofBook/blob/master/20_intro_to_graphics/images/EvolvingColor_ChangingBrightness.png)
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
  * [Example image](https://github.com/openframeworks/ofBook/blob/master/20_intro_to_graphics/images/CoordSystem_RepeatingSquareSpiral.png)

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
