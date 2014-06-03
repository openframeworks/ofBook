//
//  ofBallGreen.cpp
//  oops_7
//
//  Created by Rui Pereira on 4/9/14.
//
//

#include "ofBallGreen.h"

void ofBallGreen::draw(){
    ofSetColor(ofColor::green);
    ofCircle(x, y, dim);
}