//
//  ofBallRed.cpp
//  oops_7
//
//  Created by Rui Pereira on 4/9/14.
//
//

#include "ofBallRed.h"

void ofBallRed::draw(){
    ofSetColor(ofColor::red);
    ofCircle(x, y, dim);
}