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
	
	
	float modulator = ofMap( sin(ofGetElapsedTimef()*10), -1, 1, 0, 1);
	
	float xpos		= ofMap( sin(ofGetElapsedTimef()*3.7) * modulator, -1, 1, 0, ofGetWidth());
	
	
	ofSetColor(255,255,255);
	
	ofRect(xpos, 100, 20,20);
	
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

