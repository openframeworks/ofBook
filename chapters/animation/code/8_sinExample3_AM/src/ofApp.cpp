#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(0,0,0);
	ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::draw(){
	float modulator = ofMap(sin(ofGetElapsedTimef()*10), -1, 1, 0, 1);
	float xpos		= ofMap(sin(ofGetElapsedTimef()*3.7) * modulator, -1, 1, 0, ofGetWidth());
	
	ofSetColor(255,255,255);
	ofRect(xpos, 100, 20,20);
}
