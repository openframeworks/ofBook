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
	
	
	float sinOfTime				= sin( ofGetElapsedTimef() );
	float sinOfTimeMapped		= ofMap( sinOfTime, -1, 1, 0, 255);
	
	
	ofBackground(sinOfTimeMapped, sinOfTimeMapped, sinOfTimeMapped);

	
	float sinOfTime2			= sin( ofGetElapsedTimef() + PI);
	float sinOfTimeMapped2		= ofMap( sinOfTime2, -1, 1, 0, 255);
	
	ofSetColor(sinOfTimeMapped2, sinOfTimeMapped2, sinOfTimeMapped2);
	ofRect(100,100,ofGetWidth()-200, ofGetHeight()-200);
	
	

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

