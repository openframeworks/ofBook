#include "ofApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that:
	ofSetVerticalSync(true);

	// set background: 
	ofBackground(30, 30, 30);

	// set the "a" and "b" positions of the rectangle...
	myRectangle.posa.x = 10;
	myRectangle.posa.y = 10;
	myRectangle.posb.x = 590;
	myRectangle.posb.y = 590;
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0;					// a variable we can alter...
}

//--------------------------------------------------------------
void ofApp::update(){
	// to see pct in the console
	//printf("%f \n", pct);

	pct += 0.01f;				// increase by a certain amount
	if(pct > 1) {
		pct = 0;				// just between 0 and 1 (0% and 100%)
	}
	myRectangle.interpolateByPct(pct);	// go between pta and ptb
}

//--------------------------------------------------------------
void ofApp::draw(){
	myRectangle.draw();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//myRectangle.posa.x = x;
	//myRectangle.posa.y = y;   
}
