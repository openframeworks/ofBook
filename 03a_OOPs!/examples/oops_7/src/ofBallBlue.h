//
//  ofBallBlue.h
//  oops! - object oriented programming
//
//  Created by rux for ofBook
//
//

#pragma once				// another and more modern way to prevent the compiler from including thiis file more than once

#include "ofMain.h"
#include "ofBall.h"			// we need to include the 'mother' class, the compiler will include the mother/base class so we have access to all the methods inherited

class ofBallBlue : public ofBall { 	// we set the class to inherit from 'ofBall'
	
public:
	
    void draw(); 			// this is the only methid we actually want to be different from the 'mother class'
	
};
