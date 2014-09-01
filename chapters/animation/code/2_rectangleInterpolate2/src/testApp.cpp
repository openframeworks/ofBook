#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
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
	
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0;							// a variable we can alter...
} 

//--------------------------------------------------------------
void testApp::update(){
	
	
	pct = (float) mouseY / (float) ofGetHeight();
	
	//printf("%f \n", pct);
	
	//pct = pct + 0.01;
	//	if (pct > 1){
	//		pct = 0;	
	//	}
	
	myRectangle.interpolateByPct(pct);
	
}

//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
	
	ofSetColor(255,255,255);
	ofDrawBitmapString("mouse height controls interpolation (pct = " + ofToString(pct) + ")", 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
	// set pct based on mouseY....
	//pct = (float)  y /  (float) ofGetHeight();
//	if (pct < 0) pct = 0;
//	if (pct > 1) pct = 1;
//	myRectangle.interpolateByPct(pct);		// go between pta and ptb
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
