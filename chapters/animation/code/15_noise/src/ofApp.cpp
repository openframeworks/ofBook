#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
	//ofSetFrameRate(5);
	ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255,0,127);
	ofDrawCircle(ofNoise(ofGetElapsedTimef()) * ofGetWidth(),
				 ofNoise(ofGetElapsedTimef()+1000) * ofGetHeight(),
				 20);
}
