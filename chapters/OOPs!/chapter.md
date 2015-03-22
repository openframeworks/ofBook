#Ooops! = Object Oriented Programming + Classes#


##Overview
This tutorial is a quick and practical introduction to Object Oriented Programming in openFrameworks and a how-to guide to build and use your own classes.
By the end of this chapter you should understand how to create your own objects and have a lot of balls bouncing on your screen!

##What is OOP
Object Oriented Programming is a programming paradigm based on the use of objects and their interactions. Some terms and definitions used within OOP are listed below:

-A Class defines the characteristics of a thing - the object - and its behaviors; it defines not only its properties and attributes but also what it can do.

-An Object is an instance of a class.

-The Methods are the objects abilities and how we can call them.

A recurring analogy is to see a Class as a the cookie cutter and the cookies as the Objects. 

Note: please see chapter (Josh Nimoy's) for a more detailed explanation of Objected Oriented languages.

##How to build your own Classes (simple Class)
Classes and objects are similar to the concepts of movie clips and instances in Flash and are also a fundamental part of Java programming. 
Because cooking, like coding, is fun and we tend to experiment in the kitchen let's continue with the classic metaphor of a cookie cutter as a class and cookies as the objects.
Every class has two files: a header file, also known as a Declarations file with the termination '.h' and an implementation file, terminating in '.cpp'.
A very easy way of knowing what these two files do is to think of the header file (.h) as a recipe, a list of the main ingredients of your cookie. The implementation file (.cpp) is what we're going to do with them, how you mix and work them to be the perfect cookie!
So let's see how it works:

First of all let's create the two class files: 
If you're using Xcode as your IDE (it stands for: Integrated Development Environment), select the src folder and left Click (or CTRL + click), on the popup menu select 'New File' and you'll be taken to a new window menu, choose the appropriate platform you're developing for (OS X or iOS) and select C++ class and finally choose a name (we used 'Ball'). You'll automatically see the two files in your 'src' folder: Ball.h and Ball.cpp.
Now let's edit your class header (.h) file. Feel free to delete all its contents and let's start from scratch:
Declare a class in the header file (.h). In this case, the file name should be Ball.h. 
Follow the code below and type into your own Ball.h file, please note the comments I've included to guide you along.


```cpp
#ifndef _BALL // if this class hasn't been defined, the program can define it
#define _BALL // by using this if statement you prevent the class to be called more than once which would confuse the compiler
#include "ofMain.h" // we need to include this to have a reference to the OpenFrameworks framework
class Ball {
    
    public: // place public functions or variables declarations here
    
    // methods, equivalent to specific functions of your class objects
    void setup();	//setup method, use this to setup your object's initial state
    void update();  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing 
    
    // variables
    float x;      // position
    float y;
    float speedY; // speed and direction
    float speedX;
    int dim;      // size
    ofColor color; // color using ofColor type
    
    Ball(); // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    private: // place private functions or variables declarations here
}; // don't forget the semicolon!!
#endif 
```


We have declared the Ball class header file (the list of ingredients) and now lets get to the cooking part to see what these ingredients can do!
Please notice the '#include' tag, this is a way to tell the compiler about any files to include in the implementation file. When the program is compiled these '#include' tags will be replaced by the original file they're referring to. 
The 'if statement' (#ifndef) is a way to prevent the repetition of header files which could easily occur, by using this expression it helps the compiler to only include the file once and avoid repetition. Don't worry about this now, we'll talk about it later on!


Here's how you can write the class *.cpp file, the implementation file:

```cpp
#include "Ball.h"
Ball::Ball(){
}

Ball::setup(){
    x = ofRandom(0, ofGetWidth());      // give some random positioning
    y = ofRandom(0, ofGetHeight());
    
    speedX = ofRandom(-1, 1);           // and random speed and direction
    speedY = ofRandom(-1, 1);
    
    dim = 20;
    
    color.set(ofRandom(255),ofRandom(255),ofRandom(255)); // one way of defining digital color is by adddressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
}


void Ball::update(){
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

void Ball::draw(){
    ofSetColor(color);
    ofCircle(x, y, dim);
} 

```

Now, this is such a simple program that we could have written it inside our ofApp(.h and .cpp) files and it wouldn't be senseless to do if we didn't want to reuse this code. In there lies one of the advantages of Object Oriented Programming: reuse. Imagine we want to create thousands of these balls and how easily the code could get messy and extended, by creating our own class we can later re-create as many objects as need from it and just call the appropriate methods when needed keeping our code clean and efficient. In a more pragmatic example think of creating a class for each of your UI elements (button, slider, etc) and how easy it would be to then deploy them in your program but also to include and reuse them in future programs.

##Make an Object from your Class 
Now that we've created a class let's make the real object! In your ofApp.h (header file) we'll have to declare a new object and get some free memory for it. But first we need to include (or give the instructions to do so) your Ball class in our program. To do this we need to write:

```cpp
#include "Ball.h"
```

on the top of your ofApp.h file. Then we can finally declare an instance of the class in our program:

```cpp
Ball myBall;
```


Now let's get that ball bouncing on screen! Go to your project ofApp.cpp (implementation) file. Now that we've created the object, we just need to set it up and then update its values and draw it by calling its methods. 

In the setup() function, add the following code:

```cpp
myBall.setup();  // calling the object's setup method
```

In the update() function, add:

```cpp
myBall.update();  // calling the object's update method
```


and in the draw() function lets add:

```cpp
myBall.draw();  // call the draw method to draw the object
```


Compile and run! At this point you should be seeing a bouncing ball on the screen! Great!


##Make objects from your Class
By now, you're probably asking yourself why you went to so much trouble to create a bouncing ball. You could have done this (and probably have) without using classes. In fact one of the advantages of using classes is to be able to create multiple individual objects with the same characteristics. So, let's do that now! Go back to your ofApp.h file and create a couple of new objects:

```cpp
Ball myBall1;
Ball myBall2;
Ball myBall3;
```


In the implementation file (ofApp.cpp), call the corresponding methods for each of the objects

in the ofApp's setup() function:

```cpp
myBall1.setup();
myBall2.setup();
myBall3.setup();
```

in the ofApp's update() function:

```cpp
myBall1.update();
myBall2.update();
myBall3.update();
```


and also in the draw() function:

```cpp
myBall1.draw();
myBall2.draw();
myBall3.draw();
```



##Make more Objects from your Class
We've just created 3 objects but what if we wanted to created 10, 100 or maybe 1000's of them?! Hardcoding them one by one would be a long and painful process that could be easily solved by automating the object creation and function calls. Just by using a couple for loops we'll make this process simpler and cleaner. Instead of declaring a list of objects one by one we'll create an array of objects of type 'Ball'. We'll also introduce another new element: a constant. Constants are set after any #includes as #define CONSTANT_NAME value. This is a way of setting a value that won't ever change in the program:

**[KL: The pseudo code-like explanation above is an effective approach. This is a good method to use before writing out the Ball class above, too. Also, I've been taking out words like "just" before steps and simplifying verb tenses for clarity. I'd keep that in mind as you continue writing this chapter. The more concise, the better.]** 
**[KL: Restate which file this is happening in.]**
in the ofApp class header file, where you define the balls objects also define the constant that we'll use for the number of objects:

```cpp
#define NBALLS 5
```


we'll now use the CONSTANT value to define the size of our array of objects:


```cpp
Ball myBall[NBALLS];
```


back to our implementation file we'll just need to create an array of objects and call their methods through 'for' loops.
in the update() function:

```cpp
for(int i=0; i<NBALLS; i++){
    myBall[i].update();
}
```


in the draw() function:

```cpp
for(int i=0; i<NBALLS; i++){
    myBall[i].draw();
}
```



##Make even more Objects from your Class: properties and constructors

As we've seen, each of the objects has a set of properties defined by its variables (position, speed, direction, and dimension). Another advantage of object oriented programming is that the objects created can have different values for each of their properties. For us to have better control of each object, we can have a constructor that defines these characteristics and lets us access them. In the Ball definitions file (*.h) we can change the constructor to include some of the object's properties (let's say position and dimension):

```cpp
Ball(float x, float y, int dim);
```


Since we've changed the constructor, we'll need to update the Ball implementation (*.cpp) file to reflect these.

```cpp
Ball::Ball(float _x, float _y, int _dim){
    x = _x;
    y = _y;
    dim = _dim;
    
    speedX = ofRandom(-1, 1);
    speedY = ofRandom(-1, 1);
}
```

Your Ball.cpp file should look like this by now:

```cpp
#include "Ball.h"

Ball::Ball(float _x, float _y, int _dim){
        x = _x;
        y = _y;
        dim = _dim;
       
        speedX = ofRandom(-1, 1);
        speedY = ofRandom(-1, 1);
    
        color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    
}


void Ball::update(){
    
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

void Ball::draw(){
    ofSetColor(color);
    ofCircle(x, y, dim);
}
```

By implementing these changes we'll also need to create space in memory for these objects. We'll do this by creating a pointer (a reference in memory) for each object. Back to the ofApp.h (definitions) file we'll declare a new object like this:


```cpp
Ball *myBall;  
```


The star(*) means it will be created in a reserved part of memory just for it, we'll dynamically allocate this instance of the Ball class.

**[KL: specify why we'd make it into a pointer vs not a pointer]**

Now in the ofApp.cpp file we will need to create the object in the setup and we'll call the object's methods on the draw() and update() functions in a different way than before. Instead of using the (.) dot syntax like we have been doing so far, from now on we'll use the (->) arrow syntax. Also, we'll also be creating a new instance way more explicitly. So, in setup()

```cpp
            // x-position,        y-position,           size
myBall = new Ball(ofRandom(300,400), ofRandom(200,300), ofRandom(10,40));
```


As you see it is now possible to directly control the objects properties on its creation. and now we'll just need to update and draw it.

```cpp
myBall->update();


myBall->draw();
```

**[KL: We've changed myBall.update() to myBall->update(). That's kind of a big deal and warrants explanation concerning pointers.]**

**[JTN: no harm in explaining it twice, but i introduced it at the end of my unabridged chapter https://github.com/openframeworks/ofBook/blob/master/02_cplusplus_basics/unabridged.md#classes  ]**



##Make even more Objects from your Class
In this part of our OOPs! tutorial **[KL: I simplified two statements into one for concision.]** we'll demonstrate an automation process to create objects from our previously built class. We'll create more **[KL: "We'll create" works better than "we'll be creating." This is an example of verb tenses I've been changing. It's shorter and clearer.]**  objects by using arrays like we did in part 2.1 but this time we'll have to do some minor changes:

```cpp
Ball** myBall;   // an array of pointers of type Ball
int nBalls;        //variable for the number of balls 
```


When creating an array of objects, instead of creating one pointer, we'll create an array of pointers. That's why we have two 'stars' and not one in the declarations(\*.h) file. We have created a pointer to an array of pointers. Let's see how we'll create and call these objects in the implementation (\*.cpp) file:

```cpp
nBalls = 5; // the number of ball objects we want to create

myBall = new Ball*[nBalls]; // an array of pointers for the objects

for (int i = 0; i < nBalls; i++){
    float x = 20+(100*i); // using the value of the counter variable(i) to differentiate them
    float y = 20+(100*i);
    int dim = 10+(i*10);
        
    myBall[i] = new Ball(x,y,dim);  // create each object from the array
}
```


similarly when we want to draw and update the objects we've created we'll need 'for' loops to run through the array.


```cpp
for (int i = 0; i < nBalls; i++){
    myBall[i]->update();
}


for (int i = 0; i < nBalls; i++){
    myBall[i]->draw();
}
```

**[KL: Great tutorial so far. The organization works well. I'm eager to see the rest. The main thing so far would be focusing on concision in your writing.]**

##Make and delete as you wish - using vectors

In this part we'll look into more dynamic ways of creating and destroying objects from our class.
Vectors are special arrays that don't need a pre-fixed number of elements, that's their magic: vectors are elastic! 
Note: You'll be hearing about two different types of vectors throughout this book. Please don't confuse stl::vectors (the elastic arrays type we're talking about) with math vectors (forces).

Back to our beloved ofApp.h file, let's define a vector of Ball objects by typing:
	
```cpp
vector <Ball*> myBall;
```

In this expression we're creating a type (vector) of type (Ball pointers) and naming it myBall.
Now, let's head to our (.cpp) and start cooking!
Ignore the setup, update and draw methods for now, let's jump to

```cpp
void ofApp::mouseDragged(int x, int y, int button){
    
}
```

In this method we're listening to the dragging activity of your mouse or trackpad and we'll use this simplicity to create interaction! So let's just create some code to create Balls and add them to our program when we drag the mouse.

```cpp
void ofApp::mouseDragged(int x, int y, int button){
    Ball *tempBall;
        tempBall = new Ball(x,y, ofRandom(10,40));
        myBall.push_back(tempBall);
}
```

A few new things in our code, first we declare a temporary object pointer, we them create it and assign 'x' and 'y' mouse coordinates to it's constructor variables. We later use this temporary object as a shortcut to add Ball objects to our vector.
Back to our update and draw methods we can add the needed 'for loops' to iterate over the objects in the vector to update and draw them like we would do with arrays. This time though we didn't declare a variable that stores the maximum number of objects but instead we call a method of vectors that allows us to know their size. See code below for update:
	
```cpp
for (int i = 0 ; i<myBall.size(); i++) {
        myBall[i]->update();
    }
```

and for draw:

```cpp
for (int i = 0 ; i<myBall.size(); i++) {
    myBall[i]->draw();
}


```
<<<<<<< Updated upstream

Now let's also implement a way to delete them before we have way too many Balls:
On the ofApp::MousePressed call we will loop though our vector and check the distance between the coordinates of the mouse with the Ball position, if this distance is smaller than the Ball dimension then, we know that we're clicking inside it, we can delete it. Because we're using the vector.erase method we need to use an iterator ( myBall.begin() ), a shortcut that references to the first element of the vector as a starting point to access the vector element we really want to erase ( 'i' ).
=======
<<<<<<< HEAD
<<<<<<< HEAD
'''
On the ofApp::MousePressed() call we will loop though our vector and check the distance between the coordinates of the mouse with the Ball position, if this distance is smaller than the Ball dimension then, we know that we're clicking inside it, we can delete it. Because we're using the vector.erase method we need to use an iterator ( myBall.begin() ), a shortcut that references to the first element of the vector as a starting point to access the vector element we really want to erase ( 'i' ).
=======

Now let's also implement a way to delete them before we have way too many Balls:
On the ofApp::MousePressed call we will loop though our vector and check the distance between the coordinates of the mouse with the Ball position, if this distance is smaller than the Ball dimension then, we know that we're clicking inside it, we can delete it. Because we're using the vector.erase method we need to use an iterator ( myBall.begin() ), a shortcut that references to the first element of the vector as a starting point to access the vector element we really want to erase ( 'i' ).
>>>>>>> origin/master
=======

Now let's also implement a way to delete them before we have way too many Balls:
On the ofApp::MousePressed call we will loop though our vector and check the distance between the coordinates of the mouse with the Ball position, if this distance is smaller than the Ball dimension then, we know that we're clicking inside it, we can delete it. Because we're using the vector.erase method we need to use an iterator ( myBall.begin() ), a shortcut that references to the first element of the vector as a starting point to access the vector element we really want to erase ( 'i' ).
>>>>>>> origin/master
>>>>>>> Stashed changes

```cpp
for (int i =0; i < myBall.size(); i++) {
    float distance = ofDist(x,y, myBall[i]->x, myBall[i]->y); // a method OF give us to check the distance between two coordinates
    
    if (distance < myBall[i]->dim) {
        myBall.erase(myBall.begin()+i); // we need to use an iterator/ reference to the vector position we want to delete
    }
}
```

But because there's always a time you might just want to destroy them all, vectors also have a very handy method to help you: clear().
Feel free to experiemnt and try using it yourself!

```cpp
balls.clear();
```

To learn more about stl::vector check xxx chapter or this short online tutorial : http://www.openframeworks.cc/tutorials/c++%20concepts/001_stl_vectors_basic.html


##Quick intro to polymorphism (inheritance)
You're now discovering the power of OOP, making a class and creating as many objects from that in an instant, adding and deleting by your application needs. Now, for a second let's go back to our cooking metaphor (yummy!) and imagine that your cookies, even though sharing the same cookie cutter and dough, are using some different sprinkles on each to add some desired variation to our cookie jar selection!
This is also the power of OOP and inheritance: by allowing to use a base class and add some specific behaviors, overwriting some of the behaviors of a class, creating a subset of instances / objects with slightly different behaviors.
The great thing about this is it's reusability, we're using the 'mother' class as a starting point, using all its capabilities but we overwrite one of its methods to give it more flexibility.
Going back to the initial version of our Ball class (step 1) we'll build some 'daughter' classes based on its main characteristics (motion behaviors and shape) but we'll distinguish each inherited subClass by using a different color on its drawing method.
Your Ball header file should look like this:

```cpp
#ifndef _BALL // if this class hasn't been defined, the program can define it
#define _BALL // by using this if statement you prevent the class to be called more than once which would         confuse the compiler
#include "ofMain.h"


class Ball {
    
public: // place public functions or variables declarations here
        
void update();
void draw(); 

// variables
float x;      
float y;
float speedY; 
float speedX;
int dim;      

ofColor color;
    
Ball();

private: 

};
#endif
```

And let's make some slight changes on the implementation file:
lets change the minimum and maximum values of the random size to larger values and set the position to the center of the screen. Make it look like this: 

```cpp
#include "Ball.h"

Ball::Ball(){
    x = ofGetWidth()*.5;
    y = ofGetHeight()*.5;
    dim = ofRandom(200,250);
    
    speedX = ofRandom(-1, 1);
    speedY = ofRandom(-1, 1);
    
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}
```

We can leave the update() and draw() functions as they were.
Now, let's start making 'daughter' versions of this 'mother' class.
Create a new Class set of files and name them 'BallBlue'. Feel free to copy the code below and
it's '.h' should look like this:

```cpp
#pragma once                // another and more modern way to prevent the compiler from including this file more than once

#include "ofMain.h"
#include "Ball.h"            // we need to include the 'mother' class, the compiler will include the mother/base class so we have access to all the methods inherited

class BallBlue : public Ball {     // we set the class to inherit from 'Ball'

public: 

    void draw();             // this is the only methid we actually want to be different from the 'mother class'

};
```


On the '.cpp' file we'll need to then specify what we want the new 'draw()' method to do uniquely.

```cpp
#include "BallBlue.h"


void BallBlue::draw(){
    ofSetColor(ofColor::blue);    // this is a shortcut for full blue color ;)
    ofCircle(x, y, dim);    
}

```
Now, on your own, create two new classes: BallRed and BallGreen based on Ball class like BallBlue is.
Back to your ofApp.h, include the newly made classes and create one instance of each and in your ofApp.cpp file initialize them and call their update() and draw() methods. A quick trick! Right before you call the draw method, make this call:
	
```cpp
ofEnableBlendMode(OF_BLENDMODE_ADD);
```

This will make your application drawing methods have an Additive Blending Mode. For more on this check Chapter??.

Hope you enjoyed this short tutorial!
Have fun!


	
