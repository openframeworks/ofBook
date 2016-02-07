#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
	//ofSetFrameRate(5);
	ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255,0,127);
	ofDrawCircle(ofNoise(ofGetElapsedTimef()) * ofGetWidth(),
				 ofNoise(ofGetElapsedTimef()+1000) * ofGetHeight(),
				 20);
}
