#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);

}

//--------------------------------------------------------------
void testApp::update(){
	
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	
	for (int i = 0; i < 20; i++){
	
		float radius = 50 + i * 20;
		float angle = ofGetElapsedTimef() * (1 + i / 10.0);
		float x = xorig + radius * cos(angle);
		float y = yorig + radius * -sin(angle);
		
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofSetColor(255,255,255);
		ofRect(x,y,10,10);
	
	}	
		
	
	

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

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
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

