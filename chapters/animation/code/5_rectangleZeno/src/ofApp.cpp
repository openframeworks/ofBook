#include "ofApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	ofSetVerticalSync(true);

	// set background: 
	ofEnableAlphaBlending();
	ofBackground(30,30,30);

	// set the position of the rectangle:
	myRectangle.pos.x = 100;
	myRectangle.pos.y = 50;
}

//--------------------------------------------------------------
void ofApp::update(){
	myRectangle.zenoToPoint(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::draw(){
	myRectangle.draw();
}
