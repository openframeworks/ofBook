#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
}
