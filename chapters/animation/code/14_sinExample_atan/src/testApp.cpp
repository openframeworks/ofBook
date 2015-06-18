#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
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
void testApp::update(){
	myRectangle.xenoToPoint(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
}
