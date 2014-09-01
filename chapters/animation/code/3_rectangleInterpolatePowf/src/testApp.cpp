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
	myRectangle.posb.x = 400;
	myRectangle.posb.y = 50;
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0;							// a variable we can alter...
} 

//--------------------------------------------------------------
void testApp::update(){
	
	pct += 0.01f;							// increase by a certain amount
	if (pct > 1) pct = 0;					// just between 0 and 1 (0% and 100%)
	myRectangle.interpolateByPct(pct);		// go between pta and ptb
	
}

//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
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
