#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(0,0,0);
	ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void testApp::draw(){
    float sinOfTime = sin( ofGetElapsedTimef() );
    float xpos = ofMap(sinOfTime, -1, 1, 0, ofGetWidth());
	ofSetColor(255, 255, 255);
	ofCircle(xpos, 400, 10);
}
