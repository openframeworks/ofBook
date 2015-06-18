#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0);
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255,0,127);

	ofBeginShape();
	for (int i = 0; i < 100; i++){
		//float add = ofNoise(sin((i/100.0)*TWO_PI), ofGetElapsedTimef());  // symetrical
		float add = ofNoise(i/7.0f, ofGetElapsedTimef() * 3 * (float)mouseX / (float)ofGetWidth());
		ofVertex( 500 + (200 + 100 * add) * cos((i/100.0)*TWO_PI), 
                  400 + (200 + 100 * add) * sin((i/100.0)*TWO_PI));
	}
	ofEndShape();
}

