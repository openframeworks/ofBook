//
//  ofBall.h
//  emptyExample
//
//  Created by rux on 3/31/14.
//
//

#ifndef _OF_BALL // if this class hasn't been defined, the program can define it
#define _OF_BALL // by using this if statement you prevent the class to be called more than once which would confuse the compiler
#include "ofMain.h"


class ofBall {
    
    public: // place public functions or variables declarations here
        
        // methods, equivalent to specific functions of your class objects
        void update();  // update method, used to refresh your objects properties
        void draw();    // draw method, this where you'll do the object's drawing
        
        // variables
        float x;      // position
        float y;
        float speedY; // speed and direction
        float speedX;
        int dim;      // size

        ofColor color;// color usinf ofColor type
    
        ofBall(float _x, float _y, int _dim); // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
   
private: // place private functions or variables declarations here

}; // don't forget the semicolon!!
#endif