#include "ofBall.h"

ofBall::ofBall(){
    x = ofRandom(0, ofGetWidth());      // give some random positioning
    y = ofRandom(0, ofGetHeight());
    
    speedX = ofRandom(-5, 5);           // and random speed and direction
    speedY = ofRandom(-5, 5);
    
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
    // set Color based on values for Red, Green and Blue
    ofSetColor(120,120,120);
    ofCircle(x, y, dim);
}