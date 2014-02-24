#Ooops! = Object Oriented Programming + Classes#

##Contents
##• 1 - Overview
##• 2 - What is OOP
##• 3 - How to build your own Classes (simple Class)
##• 4 - make an Object from your Class 
##• 5 - make Objects from your Class
	##• 5.1- make more Objects from your Class
##• 6 - make even more Objects from your Class: properties and  constructor
	• 6.1 - make even more Objects from your Class
##• 7 - make and delete as you wish  - vectors
##• 8 - quick intro to polymorphism

##• 1 - Overview
This tutorial is an quick  and practical introduction to Object Oriented Programming in OpenFrameworks and a how-to guide to build and use your own classes.
By the end of this chapter you should understand how to create your own objects and have a lot of balls bouncing on your screen!

##• 2 - What is OOP
Object Oriented Programming is a programming paradigm based on the use of objects and their interactions. some definitions:
-a Class defines the characteristics of a thing - the object - and its behaviors; it defines not only its properties and attributes but also what it can do.
-an Object is an instance of a class.
-the Methods are the objects abilities and how we can call them.
A recurring analogy is to see a Class as a the cookie cutter and the cookies as the Objects. 
note: pls see chapter (Josh Nimoy's) for amore detailed explanation of Objected Oriented languages.

• 3 - How to build your own Classes (simple Class)
Classes and objects are similar to the concepts of movie clips and instances in Flash and are also a fundamental part of Java programming. If you have a background in Java and/or Processing this other tutorial will be useful.
This is how you declare a Class -> in the header file (*.h), otherwise known as the declarations file. In this case, the file name should be ofBall.h 


#ifndef _OF_BALL // if this class hasn't been defined, the program can define it
#define _OF_BALL // by using this if statement you prevent the class to be called more 
                 // than once which would confuse the compiler
 
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
 
        ofBall(); // constructor - used to initialize an object, if no properties are passed
                  //               the program sets them to the default value
 
    private: // place private functions or variables declarations here
 
}; // dont't forget the semicolon!!
 
#endif 


We have declared the Ball class header filer (the list of ingredients) and now lets get to the cooking part -> what do these ingredients do!
Please notice the '#include' tag, this is a way to tell the compiler which file to include for each implementation file. When the program is compiled these '#include' tags will be replaced by the original file they're referring to. The 'if statement' (#ifndef) is a way to prevent the repetition of header files which could easily occur. Here's an example of how easily this could happen due to the recursive structure of the program: Lets say we're building a Pool game, we'll have the ofApp class, dependent on this there will be the pool table class and also the pool stick class and as both of these will be needed for our balls collision detection function both will refer to the ball class individually. If we didn't use the '#ifndef' 'if' statement the compiler would try to compile the ball class repeatedly and would find some conflicts.

Here's how you can write the class *.cpp file, the implementation file:


#include "ofBall.h"
 
ofBall::ofBall()
{
    x = ofRandom(0, ofGetWidth());      // give some random positioning
    y = ofRandom(0, ofGetHeight());
 
    speedX = ofRandom(-1, 1);           // and random speed and direction
    speedY = ofRandom(-1, 1);
 
    dim = 20;
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
    // values for R, G, B
    ofSetColor(120,120,120);
    ofCircle(x, y, dim);
} 

• 4 - make an Object from your Class 
now that we've created a class let's make the real object! in your testapp.h (header file) we'll have to add declare a new object and get some free memory for it. this is how we do it:

ofBall myBall;

and finally let's get that ball bouncing on screen! go to your project testapp.cpp (implementation) file. now that we've created the object we just need to draw it and update its values by calling its methods. in the update() function add:


myBall.update();  // calling the object's update method

and in the draw() function lets add:


myBall.draw();  // call the draw method to draw the object

compile and run! by now you must be seeing a bouncing ball on the screen! great!


• 5 - make Objects from your Class
you're probably asking yourself now why did you have so much trouble just to create a bouncing ball. You could have done this (and you've probably done it!) without using classes. In fact one of the advantages of using classes is to be able to create multiple individual objects with the same characteristics. So, lets do that now! going back to your ofApp.h file we'll just need to create a couple of new objects:


ofBall myBall1;
ofBall myBall2;
ofBall myBall3;

And in the implementation file (*.cpp) just call the corresponding methods for each of the objects.
in the ofApp's update() function:



myBall1.update();
myBall2.update();
myBall3.update();


and also in the draw() function:


myBall1.draw();
myBall2.draw();
myBall3.draw();


• 5.1- make more Objects from your Class
We've just created 3 objects but what if we wanted to created 10, 100 or may be 1000's of them?! hardcoding one by one would be a painful and long process that can be easily solved by automating the object creation and function calls. Just by using a couple for loops we'll be making this process way simpler and cleaner. Instead of declaring a list of objects one by one we'll just create an array of objects of type 'ofBall'. We'll also introduce another new element: a constant. Constants are defined after the #includes as #define CONSTANT_NAME value. This is a way of defining a constant value that won't be ever changed in the program:


#define NBALLS 5

we'll now use the CONSTANT value to define the size of our array of objects:


ofBall myBall[NBALLS];

back to our implementation file we'll just need to create an array of objects and call their methods through 'for' loops.
in the update() function:


for(int i=0; i<NBALLS; i++)
{
  myBall[i].update();
}
in the draw() function:


for(int i=0; i<NBALLS; i++)
{
  myBall[i].draw();
}


• 6 - make even more Objects from your Class: properties and  constructor

As we've seen each of the objects has a set of properties defined by its variables (position, speed and direction and dimension). Another advantage of object oriented programming is that the objects created can have different values on each of its properties. For us to be able to have better control of each object we can have a constructor which defines these characteristics and lets us access them. In the ofBall definitions file (*.h) we can change the constructor to include some of the objects properties (lets say position and dimension):


ofBall(float x, float y, int dim);
As we've changed the constructor we'll need to update the ofBall implementation (*.cpp) file to reflect these.


ofBall::ofBall(float _x, float _y, int _dim)
{
    x = _x;
    y = _y;
    dim = _dim;
 
    speedX = ofRandom(-1, 1);
    speedY = ofRandom(-1, 1);
}


By implementing these changes we'll also need to create space in memory for these objects. We'll do this by creating a pointer (a reference in memory) for each object. Back to the ofApp.h (definitions) file we'll declare a new object like this:


ofBall *myBall;  

The star means it will be created in a reserved part of memory just for it.
Now in the TestApp.cpp file we will need to create the object in the setup and we'll call the objects methods on the draw() and update() functions in a different way than we've been doing before. in the setup() :



                        // x-position,        y-position,           size
myBall = new ofBall(ofRandom(300,400), ofRandom(200,300), ofRandom(10,40));


As you see it is now possible to directly control the objects properties on its creation. and now we'll just need to update and draw it.

myBall->update();
 
myBall->draw();



• 6.1 - make even more Objects from your Class
we're now at the last part of this how-to tutorial on classes and objects. this part will now demonstrate an automation process to create objects from our previously built class. We'll be creating objects through arrays as we did in part 2.1 with some minor changes:


ofBall** myBall;   // an array of pointers of type ofBall
int nBalls;        //variable for the number of balls 

As we're creating an array of objects, instead of creating one pointer only we'll also have to create an array of pointers. That's why we have two 'stars' and not one in the declarations(*.h) file. We have created a pointer to an array of pointers. Let's see how we'll create and call these objects in the implementation (*.cpp) file:


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



• 7 - make and delete as you wish  - vectors
Quick example showing how to create dynamically objects, push them to a vector and delete them.
Basic example : 
- when mouse drag create objects, when objects leave the screen delete them.

• 8 - quick intro to polymorphism
Quick intro to polymorphism by example.
Show how the same class base can be made flexible to create variety of objects based on the same principles of behaviors.
Example - particles behave the same way but different drawing methods (e.g. triangle and square) 