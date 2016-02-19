#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(0,0,0);
	ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::draw(){
    float sinOfTime = sin( ofGetElapsedTimef() );
    float xpos = ofMap(sinOfTime, -1, 1, 0, ofGetWidth());
	ofSetColor(255, 255, 255);
	ofDrawCircle(xpos, 400, 10);
}
