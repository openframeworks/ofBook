/* Fire a single (random) particle by clicking on the screen. */
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);	
	ofBackground(255, 255, 255);
	p.setInitialCondition(300,300,ofRandom(-1,1), ofRandom(-1,1));
}

//--------------------------------------------------------------
void ofApp::update(){
	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update

	p.resetForce();
	p.addForce(0, 0.1);
	p.addDampingForce();
	p.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0);
	p.draw();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	p.setInitialCondition(x,y,ofRandom(-10,10), ofRandom(-10,10));
}
