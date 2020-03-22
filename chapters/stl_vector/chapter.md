# Introduction to vectors

*by Chris Sugrue*

A c++ vector is a type of container (like an array) that allows the storage of multiple elements (numbers, strings, objects etc.) in a format that can grow or shrink dynamically. Once a vector is created, new elements can be added, others erased and the entire vector can be sorted or shuffled. This tutorial is an overview of the basics of using vectors and is geared towards openFrameworks programmers that may be new or coming from other platforms and languages. It is not a comprehensive guide to all the functions of c++ vectors (additional resource links are provided below). 


Additional Resources:

<a href="http://www.cplusplus.com/reference/vector/vector/">C++ Vector Reference</a>

## Quick Review:

```cpp
vector<float> nums;  // create an empty vector of floats     
```


```cpp
nums.push_back(10.5); // add a float with value 10.5 to the end of vector
```

```cpp
cout << nums[0] << endl; // print out the value of element at position 0
```

```cpp
nums.erase( nums.begin() ); // erase the first element in the vector
```

```cpp
cout << nums.size() << endl; // print the number of elements in the vector

vector<float>:: iterator it = nums.begin(); // create an iterator for vector that points to first element
cout << *it << endl; // print out the value of the element pointed to by the iterator
```




## Declaring a vector

vector&#60; *type* &#62; *name*;

```cpp
vector<float> measures;       
vector<string> surnames;
vector<Particle> particles;
```


## Adding elements to a vector

### push_back
*push_back* adds a new element to the end of the vector. 
```cpp
vector<string> names; // declare an empty vector

names.push_back("jane"); // add an element
names.push_back("joe"); // add another - now has size of 2 with elements: "jane", "joe"
```


*push_back* is a very common way to add elements and is useful when adding elements one at a time or only a few (adding objects when an event occurs for example).

## resize
*resize* allocates memory for the desired number of elements in the vector and adjusts its size accordingly. 
```cpp
vector<int> nums; // declare the vector

nums.resize(100); // allocate space for 100 ints in vector

for(int i = 0; i < nums.size(); i++){
  nums[i] = i; // set value using index
}
```


When adding many elements at the same time, using *resize* may be faster than *push_back*. This is because when a new element is added to the end of a vector there might not be enough space in memory at the current location. In this case, the entire vector is moved meaning that it will be copied and new memory allocated in a different location. This can be slow and may occur multiple times when using push_back in a loop. When using *resize* the move would only need to be performed once.  

For more details on this refer to <a href="http://arturocastro.net/blog/2011/10/28/stl::vector/">Arturo Castro's tutorial</a> 


## assign
*assign* can be used to create a vector of a given size and populate it with uniform values, or to copy part of an existing vector. It reinitializes the vector deleting any previous elements. 

```cpp
vector<float> vals; // declare the vector
vals.assign(100,0.0f); // add 100 floats all with value of 0.0

vector<Particle> particles;
particles.assign(10,Particle());

vector<Particle> copyParticles;
copyParticles.assign( particles.begin(), particles.begin()+5 );
```


## Accessing elements of a vector

### operator []
Elements can be accessed using the [] operator with an index in the same style as c arrays. 
```cpp
cout << names[0] << end; // !if there is no element 0, you have a memory access error

for( int i = 0; i < names.size(); i++){
  cout << names[i] << endl;
}
```



### at()
Vectors have a function *at()* that will return the value in the same way as the [] operator, however it is slightly slower than []. *at()* checks if the index is in bounds and if not, throws an exception. This can make it useful for debugging, however for clarity and speed [] is usually preferred.

```cpp
cout << names.at(0) << endl;
```



## Erasing elements of a vector

### erase
An element can be removed from a vector using *erase*. This function takes in an iterator to the position in the vector not the index. The function *begin()* returns an iterator to the first element of the vector and can be added to to pass in subsequent positions. Note that erase does not check if the element exists or not, so be sure when erasing!
```cpp
particles.erase( particles.begin() ); // erase first element

particles.erase( particles.begin() + 3 ); // erase third element

particles.erase( particles.begin(), particles.begin()+2 ); // remove first 2 elements
```

### clear
*clear* removes all elements in the vector reducing its size to 0.
```cpp
particles.clear();
```
    

## Iterators
An iterator is a class of objects designed to help traverse through a sequence of elements (such as a vector). An iterator for a vector points to an individual element in the vector, and can be incremented to point to the next. As some vector functions take in or return iterators, it is useful to understand how they work. 

Declaring an iterator for a vector:

vector&#60; *type* &#62;::iterator it; // *it* is the name of the iterator but could be called anything we want
```cpp
vector<float>::iterator it = nums.begin();
vector<Particle>::iterator itp = partices.begin();
```

*begin()* returns an iterator to the first element of the vector and *end()* to one past the last element in the vector.

To access the value of an element using an iterator, we have to dereference it as if it was a pointer. The iterator is pointing to the element in the array, but we want the value of element it is pointing to instead. 
```cpp
vector<int> nums;
nums.push_back(10);
vector<int>::iterator it = nums.begin();
cout << *it << endl; // prints out 10

vector<Particle>::iterator itp = particles.begin(); // get iterator to first element
float xpos = (*itp).pos.x; // use dereference * to access the element value or properties
particle.erase(itp); // pass the iterator to a vector function such as erase 
```


Looping through the vector using iterators:
```cpp
 
vector<float>::iterator it = nums.begin();  // create an iterator that points to the first element

// loop through, increasing to next element until the end is reached

for(; it != nums.end(); ++it){ 
  cout << *it << end; // output value with dereference operator
}


for(vector<Particle>::iterator it = particles.begin(); it != particles.end(); ++it){ 
  cout << (*it).pos.x << end; 
}
```


Note that when using iterators we want to test that our iterator ( *it* in this case) is not equal to *end()* (it != particles.end()) rather than > test. *end()* signifies one element beyond the last. This is important because an iterator cannot be incremented beyond *end()* or bad things can happen.

In a while loop the structure would be:
```cpp
vector<Particle>::iterator it = particles.begin();

while( it != particles.end() ){
 cout << (*it).x << end; 
 ++it;
}
```


When erasing multiple elements with an iterator, it is important that the iterator gets a return value from the erased element so it does not become invalid.
```cpp
vector<float>::iterator it = nums.begin(); // iterator points to first element

for(; it != num.end();){
	if( *it > 5.2 ) it = nums.erase(it); // be sure to return the iterator when erasing so it is not invalidated
	else ++it;
}
```

With vectors there is no speed difference between iterators or array-style [] indexes.


### std::remove_if and ofRemove
*remove_if* checks conditions defined in a boolean function to determine if each element of the vector should be deleted or not. It moves any that return true to the end of the vector and then returns the iterator to the first element that should be removed. It does not remove anything, but can be used together with *erase* to actually delete the undesired elements. This is useful when all elements in the vector need to be checked to see if they should be deleted or not (for example if a particle has gone off screen or its life timer has reached zero and so on).

The first step is defining a function that returns a bool and takes in as a parameter a reference to an element of the type the vector contains.
```cpp
bool checkDead( Particle &p ){
	return p.isDead;
}
```
 
Then call *erase* with the iterator returned from *remove_if*:
```cpp
vector<Particle>::iterator it = particles.remove_if(particles.begin(),particles.end(),checkDead);
particles.erase( it, particles.end() );

// or all in one line
particles.erase( particles.remove_if(particles.begin(),particles.end(),checkDead), particles.end() );
```

OpenFrameworks has a function called *ofRemove* that performs similarly. Create the function and pass it with the vector to perform both the *remove_if* and *erase* at the same time.
```cpp
ofRemove(particles,checkDead); //particles is the vector, checkDead is the boolean function
```
 
Be careful that this format is not used with a vector of pointers to objects (see below).


## Sorting and shuffling a vector

c++ has a number of < algorithm > functions that work with vectors and iterators ( *remove_if* is one of these for example). Two very useful functions are *sort* and *random_shuffle*. In openFrameworks they are implemented as *ofSort* and *ofRandomize*.

*sort* works similarly to *remove_if* in that it can take in a vector and a boolean function that determines how the elements are sorted. The boolean function has two parameter that are elements of the type of vector, and returns true or false based on a comparison of the two.
```cpp
// compare for a vector of floats, sorting from lowest to highest
bool my_compare( float a, float b){
    return a < b;
}
```

The vector range and boolean function can then be passed to *sort*:
```cpp
    vector<float>vals;
    vals.push_back(3.0);
    vals.push_back(.1);
    vals.push_back(2.3); // vector now has: 3.0,.1,2.3
    
    std::sort( vals.begin(), vals.end(), my_compare); // after sorting: .1, 2.3, 3.0
```

*ofSort* with objects:
```cpp
    bool my_compare( Particle &a, Particle &b){
        return a.pos.x < b.pos.x;
    }
    
    ...
    vector<Particle> particles;
    particles.assign(10,Particle());
    
    ofSort(particles,my_compare); // with ofSort the entire vector is passed in rather than a range
```
    

*random_shuffle* and *ofRandomize* simply shuffle the elements of a vector into a random order.
```cpp
    std::random_shuffle(vals.begin(),vals.end());  // pass in range to be shuffled
     
    ofRandomize(vals); // pass in just the  vector (all will be shuffled)
```


More information on <a href="http://www.cplusplus.com/reference/algorithm/"> algorithm </a> functions:

## Vectors of objects

As indicated in the above examples, it is quite common to create vectors of objects. 
```cpp
    vector<Particle> particles;
```

In many situations this works great and is preferred. However, problems can sometimes arise if the class has member pointers and dynamically allocated memory but not a proper copy constructor. A vector of pointers to objects can be used, although shared pointers are probably best. Shared pointers would also be needed to use polymorphism / base classes.

More on <a href="http://www.learncpp.com/cpp-tutorial/912-shallow-vs-deep-copying/">vectors and copy constructors</a>.



<a name="vectorspointers"></a>
## Vectors of pointers to objects

When using a vector of pointers to objects, the syntax is similar:
```cpp
    vector<Particle *> particlePointers;
```

It is very important to remember that when erasing a pointer to an object in a vector it needs to be deleted as well as erased!! 
```cpp
    // delete and erase a single element with index
    delete particlePointers[1];
    particlePointers.erase( particlePointers.begin()+1 );

    // delete and erase with a loop
    vector<Particle>::iterator it = particlePointers.begin();
    for(; it != particlePointers.end();){
    	if( (*it)->isDead ){
    		delete *it;
     		it = particlePointers.erase(it);
    	}else
    		++it;
    }
```
 

Note that this means erase and remove_if demonstrated above will not be sufficient. If pointers are needed, it is worthwhile to consider using shared pointers instead.


<a name="optimizing"></a>
## Optimization with resize and reserve
See <a href="http://arturocastro.net/blog/2011/10/28/stl::vector/">Arturo Castro's article.</a>



<a name="of"></a>
## OpenFrameworks Example

ofApp.h
```cpp
    #pragma once

    #include "ofMain.h"

    // create the particle class in the header for brevity

    class Particle{
    public:
    Particle(){
    		pos.set( 0, 0, 0 );
    		vel.set( ofRandom(-5,5), ofRandom(-4,-8), 0);
    	}
	
    	void update(){
    		pos += vel;
    		vel.y += .1;
    	}
	
    	void draw(){
    		ofDrawEllipse(pos.x,pos.y,10,10);
    	}
	
    	ofPoint pos;
    	ofVec3f vel;
	
    };

    class ofApp : public ofBaseApp{
    public:
    	void setup();
    	void update();
        void draw();
	    
        void keyPressed(int key);
    	void keyReleased(int key);
    	void mouseMoved(int x, int y);
    	void mouseDragged(int x, int y, int button);
    	void mousePressed(int x, int y, int button);
    	void mouseReleased(int x, int y, int button);
    	void windowResized(int w, int h);
    	void dragEvent(ofDragInfo dragInfo);
    	void gotMessage(ofMessage msg);
	
    	// declare the vector of particles
    	vector<Particle> particles;
    };

```
    
    
ofApp.cpp
```cpp
    #include "ofApp.h"
    
    // write our boolean remove function
    bool shouldRemove(Particle &p){
    	if(p.pos.y > ofGetHeight() )return true;
    	else return false;
    }
    
    void ofApp::setup(){
    	ofSetFrameRate(60);
    }
    
    void ofApp::update(){
    	for(int i = 0; i < particles.size(); i++){
    		particles[i].update();
    	}
    	
    	ofRemove(particles,shouldRemove);
    }
    
    void ofApp::draw(){
    	
        ofTranslate( ofGetWidth()/2, ofGetHeight()/2);
        for(int i = 0; i < particles.size(); i++){
    		particles[i].draw();
    	}
    }
    
    void ofApp::keyPressed(int key){
    	particles.push_back( Particle() );
    }
```
    
    
    
ofApp.cpp using iterators
```cpp
    #include "ofApp.h"
    
    // write our boolean remove function
    bool shouldRemove(Particle &p){
    	if(p.pos.y > ofGetHeight() )return true;
    	else return false;
    }
    
    void ofApp::setup(){
    	ofSetFrameRate(60);
    }
    
    void ofApp::update(){
    	
    	for(vector<Particle>::iterator it = particles.begin(); it != particles.end(); it++){
    		(*it).update();
    	}
    	
    	ofRemove(particles,shouldRemove);
    }
    
    void ofApp::draw(){
    	
        ofTranslate( ofGetWidth()/2, ofGetHeight()/2);
        for(vector<Particle>::iterator it = particles.begin(); it != particles.end(); it++){
    		(*it).draw();
    	}
    }
    
    void ofApp::keyPressed(int key){
    	particles.push_back( Particle() );
    }
```

