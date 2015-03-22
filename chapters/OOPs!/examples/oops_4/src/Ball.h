//
//  ofBall.h
//  emptyExample
//
//  Created by rux on 3/31/14.
//
//

#ifndef _BALL // if this class hasn't been defined, the program can define it
#define _BALL // by using this if statement you prevent the class to be called more than once which would confuse the compiler
#include "ofMain.h"

class Ball {
    
    public: // place public functions or variables declarations here
        
        // methods, equivalent to specific functions of your class objects
        void setup(float _x, float _y, int _dim);   // setup method, used to define the initial state of the object: runs only once!
        void update();  // update method, used to refresh your objects properties: runs constantly
        void draw();    // draw method, this where you'll do the object's drawing: runs constantly
        
        // variables
        float x;      // position
        float y;
        float speedY; // speed and direction
        float speedX;
        int dim;      // size
        ofColor color; // color using ofColor type

    
        Ball(); // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    private: // place private functions or variables declarations here

}; // don't forget the semicolon!!
#endif