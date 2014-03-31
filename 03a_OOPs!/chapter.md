#Ooops! = Object Oriented Programming + Classes#

##Contents
• 1 - Overview

• 2 - What is OOP

• 3 - How to build your own Classes (simple Class)

• 4 - make an Object from your Class 

• 5 - make Objects from your Class

• 5.1- make more Objects from your Class

• 6 - make even more Objects from your Class: properties and  constructor

• 6.1 - make even more Objects from your Class

• 7 - make and delete as you wish  - vectors

• 8 - quick intro to polymorphism

##• 1 - Overview
This tutorial is an quick and practical introduction to Object Oriented Programming in openFrameworks and a how-to guide to build and use your own classes.
By the end of this chapter you should understand how to create your own objects and have a lot of balls bouncing on your screen!

##• 2 - What is OOP
Object Oriented Programming is a programming paradigm based on the use of objects and their interactions. Some terms and definitions used within OOP are listed below:

-A Class defines the characteristics of a thing - the object - and its behaviors; it defines not only its properties and attributes but also what it can do.

-An Object is an instance of a class.

-The Methods are the objects abilities and how we can call them.

A recurring analogy is to see a Class as a the cookie cutter and the cookies as the Objects. 

Note: please see chapter (Josh Nimoy's) for amore detailed explanation of Objected Oriented languages.

##• 3 - How to build your own Classes (simple Class)
Classes and objects are similar to the concepts of movie clips and instances in Flash and are also a fundamental part of Java programming. 
Because like coding, cooking is fun and we tend to experiment in the kitchen let's continue with the classic metaphor of a cookie cutter as a class and cookies as the objects.
Every class has two files: a header file, also known as a Declarations file with the termination '.h' and an implementation file, terminating in '.cpp'.
A very easy way of knowing what these two files do is to think of the header file (.h) as a recipe, a list of the main ingredients of your cookie. The implementation file (.cpp) is what we're going to do with them, how you mix and work them to be the perfect cookie!
So let's see how it works:

Declare a class in the header file (.h), otherwise known as the declarations file. In this case, the file name should be ofBall.h. 
Folllow the code below and type into your own ofBall.h file, please note the comments I've included to guide you along.


	#ifndef _OF_BALL // if this class hasn't been defined, the program can define it
	#define _OF_BALL // by using this if statement you prevent the class to be called more than once which would confuse the compiler
	#include "ofMain.h"
	class ofBall {
		
		public: // place public functions or variables declarations here
		
		// methods, equivalent to specific functions of your class objects
		void update();  // update method, used to refresh your objects properties
		void draw();    // draw method, this where you'll do the object's drawing 
		
		// variables
		float x;      // position
		float y;
		float speedY; // speed and direction
		float speedX;
		int dim;      // size
		ofColor color; // color using ofColor type
		
		ofBall(); // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
		private: // place private functions or variables declarations here
	}; // don't forget the semicolon!!
	#endif 


We have declared the Ball class header file (the list of ingredients) and now lets get to the cooking part **[KL: I wouldn't use an arrow symbol within this text.]** to see what these ingredients can do!
Please notice the '#include' tag, this is a way to tell the compiler which file to include for each implementation file. When the program is compiled these '#include' tags will be replaced by the original file they're referring to. 
The 'if statement' (#ifndef) is a way to prevent the repetition of header files which could easily occur, by using this expression it helps the compiler to only include the file once and avoid repetition. Don;t worry about this now, we'll talk about it later on!

Here's how you can write the class *.cpp file, the implementation file:

**[KL: did the previous chapter talk about how to create a new class in oF? If so, no worries, but if it didn't, it's a good idea to address how to do that, and that the example below is ofBall.cpp.]**


	#include "ofBall.h"
	
	ofBall::ofBall(){
		x = ofRandom(0, ofGetWidth());      // give some random positioning
		y = ofRandom(0, ofGetHeight());
		
		speedX = ofRandom(-1, 1);           // and random speed and direction
		speedY = ofRandom(-1, 1);
		
		dim = 20;
		
		color.set(ofRandom(255),ofRandom(255),ofRandom(255)); // one way of defining digital color is by adddressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
	}
	
	
	void ofBall::update(){
		if(x < 0 ){
			x = 0;
			speedX *= -1;
		} else if(x > ofGetWidth()){
			x = ofGetWidth();
			speedX *= -1;
		}
		
		if(y < 0 ){
			y = 0;
			speedY *= -1;
		} else if(y > ofGetHeight()){
			y = ofGetHeight();
			speedY *= -1;
		} 
		
		x+=speedX;
		y+=speedY;
	}

	void ofBall::draw(){
		ofSetColor(color);
		ofCircle(x, y, dim);
	} 
**[KL: Explain exactly why we are creating this class outside of ofApp. This and the explanation below seem kind of rushed and OOP can benefit by using some real life analogies to demonstrate class relationships.]**

##• 4 - make an Object from your Class 
Now that we've created a class let's make the real object! In your testApp.h (header file) we'll have to declare a new object and get some free memory for it. But first we need to include (or give the instructions to do so) your ofBall class in our program. To do this we need to write:

	#include "ofBall.h"

on the top of your testApp.h file. Then we can finally declare an instance of the class i our progam:

	ofBall myBall;


Now let's get that ball bouncing on screen! Go to your project testApp.cpp (implementation) file. Now that we've created the object, we just need to draw it and update its values by calling its methods. In the update() function, add:

	myBall.update();  // calling the object's update method


and in the draw() function lets add:

	myBall.draw();  // call the draw method to draw the object


Compile and run! By now you must be seeing a bouncing ball on the screen! Great!


##• 5 - make Objects from your Class
By now, you're probably asking yourself why you went to so much trouble to create a bouncing ball. You could have done this (and probably have) without using classes. In fact one of the advantages of using classes is to be able to create multiple individual objects with the same characteristics. So, let's do that now! Go back to your ofApp.h file and create a couple of new objects:

	ofBall myBall1;
	ofBall myBall2;
	ofBall myBall3;


In the implementation file (ofApp.cpp), call the corresponding methods for each of the objects

in the ofApp's update() function:

	myBall1.update();
	myBall2.update();
	myBall3.update();


and also in the draw() function:

	myBall1.draw();
	myBall2.draw();
	myBall3.draw();



##• 5.1- make more Objects from your Class
We've just created 3 objects but what if we wanted to created 10, 100 or maybe 1000's of them?! Hardcoding one by one would be a painful and long process that can be easily solved by automating the object creation and function calls. Just by using a couple for loops we'll make this process simpler and cleaner. Instead of declaring a list of objects one by one we'll create an array of objects of type 'ofBall'. We'll also introduce another new element: a constant. Constants are defined after the #includes as #define CONSTANT_NAME value. This is a way of defining a constant value that won't ever change in the program:

**[KL: The pseudo code-like explanation above is an effective approach. This is a good method to use before writing out the ofBall class above, too. Also, I've been taking out words like "just" before steps and simplifying verb tenses for clarity. I'd keep that in mind as you continue writing this chapter. The more concise, the better.]** 
**[KL: Restate which file this is happening in.]**
in the testApp class header file, where you define the balls objects also define the constant that we'll use for the number of objects:

	#define NBALLS 5


we'll now use the CONSTANT value to define the size of our array of objects:


	ofBall myBall[NBALLS];


back to our implementation file we'll just need to create an array of objects and call their methods through 'for' loops.
in the update() function:

	for(int i=0; i<NBALLS; i++){
		myBall[i].update();
	}


in the draw() function:

	for(int i=0; i<NBALLS; i++){
		myBall[i].draw();
	}



##• 6 - make even more Objects from your Class: properties and constructors

As we've seen, each of the objects has a set of properties defined by its variables (position, speed, direction, and dimension). Another advantage of object oriented programming is that the objects created can have different values for each of its properties. For us to have better control of each object, we can have a constructor that defines these characteristics and lets us access them. In the ofBall definitions file (*.h) we can change the constructor to include some of the object's properties (let's say position and dimension):

	ofBall(float x, float y, int dim);


Since we've changed the constructor, we'll need to update the ofBall implementation (*.cpp) file to reflect these.

	ofBall::ofBall(float _x, float _y, int _dim){
		x = _x;
		y = _y;
		dim = _dim;
		
		speedX = ofRandom(-1, 1);
		speedY = ofRandom(-1, 1);
	}

**[KL: Give an image of the entire .cpp file and not just the part we changed because you can't tell how this fits in to the original .cpp file.]**
By implementing these changes we'll also need to create space in memory for these objects. We'll do this by creating a pointer (a reference in memory) for each object. Back to the ofApp.h (definitions) file we'll declare a new object like this:


	ofBall *myBall;  


The star(*) means it will be created in a reserved part of memory just for it.

**[KL: specify why we'd make it into a pointer vs not a pointer]**

Now in the TestApp.cpp file we will need to create the object in the setup and we'll call the object's methods on the draw() and update() functions in a different way than before. In setup()

				// x-position,        y-position,           size
	myBall = new ofBall(ofRandom(300,400), ofRandom(200,300), ofRandom(10,40));


As you see it is now possible to directly control the objects properties on its creation. and now we'll just need to update and draw it.

	myBall->update();

	
	myBall->draw();

**[KL: We've changed myBall.update() to myBall->update(). That's kind of a big deal and warrants explanation concerning pointers.]**



##• 6.1 - make even more Objects from your Class
The final part of our OOP tutorial **[KL: I simplified two statements into one for concision.]** will demonstrate an automation process to create objects from our previously built class. We'll be creating **[KL: "We'll create" works better than "we'll be creating." This is an example of verb tenses I've been changing. It's shorter and clearer.]**  objects through arrays as we did in part 2.1 with some minor changes:

	ofBall** myBall;   // an array of pointers of type ofBall
	int nBalls;        //variable for the number of balls 


When creating an array of objects, instead of creating one pointer, we'll create an array of pointers. That's why we have two 'stars' and not one in the declarations(*.h) file. We have created a pointer to an array of pointers. Let's see how we'll create and call these objects in the implementation (*.cpp) file:

	nBalls = 5; // the number of ball objects we want to create
	
	myBall = new ofBall*[nBalls]; // an array of pointers for the objects
	
	for (int i = 0; i < nBalls; i++){
		float x = 20+(100*i); // using the value of the counter variable(i) to differentiate them
		float y = 20+(100*i);
		int dim = 10+(i*10);
			
		myBall[i] = new ofBall(x,y,dim);  // create each object from the array
	}


similarly when we want to draw and update the objects we've created we'll need 'for' loops to run through the array.


	for (int i = 0; i < nBalls; i++){
		myBall[i]->update();
	}



	for (int i = 0; i < nBalls; i++){
		myBall[i]->draw();
	}

**[KL: Great tutorial so far. The organization works well. I'm eager to see the rest. The main thing so far would be focusing on concision in your writing.]**

##• 7 - make and delete as you wish  - vectors
Quick example showing how to create dynamically objects, push them to a vector and delete them.
Basic example : 
- when mouse drag create objects, when objects leave the screen delete them.

##• 8 - quick intro to polymorphism
Quick intro to polymorphism by example.
Show how the same class base can be made flexible to create variety of objects based on the same principles of behaviors.
Example - particles behave the same way but different drawing methods (e.g. triangle and square) 
