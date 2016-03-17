#include "ofApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that:
	ofSetVerticalSync(true);

	// set background:
	ofBackground(30,30,30);

	// set the "a" and "b" positions of the rectangle...
	myRectangle.posa.x = 0;
	myRectangle.posa.y = 50;
	myRectangle.posb.x = 500;
	myRectangle.posb.y = 500;

	myRectangle.radiusa = 30;
	myRectangle.radiusb = 200;

	myRectangle.interpolateByPct(0);  // start at 0 pct
	pct = 0;			  // a variable we can alter...
}

//--------------------------------------------------------------
void ofApp::update(){
	pct = (float) mouseY / (float) ofGetHeight();
	//printf("%f \n", pct);
	myRectangle.interpolateByPct(pct);
}

//--------------------------------------------------------------
void ofApp::draw(){
	myRectangle.draw();

	ofSetColor(255,255,255);
	ofDrawBitmapString("mouse height controls interpolation (pct = " + ofToString(pct) + ")", 20, 20);
}
