#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(255,255,255);
	//ofSetFrameRate(5);
	ofSetVerticalSync(true);
	
	colorScheme.loadImage("sunset.png");
}

//--------------------------------------------------------------
void testApp::update(){

	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofEnableAlphaBlending();
	ofSetColor(255,255,255, 100);
	//colorScheme.draw(0,0, ofGetWidth(), ofGetHeight());
	
	ofSeedRandom(0); // always pick the same random numbers.
	
	for (int i = 0; i < mouseX*3; i++){
		float x = ofNoise(ofGetElapsedTimef()*0.2, i*0.3)*ofGetWidth();
		float y = ofNoise(-ofGetElapsedTimef()*0.2, i*0.3)*ofGetHeight();
		
		ofColor col = getColorForPixel( ofMap(x,0,ofGetWidth(), 0, colorScheme.width),
									   ofMap(y,0,ofGetHeight(), 0, colorScheme.height));
			
		col.a = 85;	// set some alpha. 
		ofSetColor(col);
		ofCircle(x,y,ofRandom(4,40));
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}


ofColor testApp::getColorForPixel(int x, int y){

	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (x >= colorScheme.width) x = colorScheme.width-1;
	if (y >= colorScheme.height) y = colorScheme.height-1;
	
	return colorScheme.getColor(x,y);
}
