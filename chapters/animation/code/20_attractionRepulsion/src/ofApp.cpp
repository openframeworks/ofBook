/* Repell particles from current mouse position. */
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	for (int i = 0; i < 1000; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,1000),ofRandom(0,1000),0,0);
		// more interesting with diversity :)
		// uncomment this: 
		//myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
}

//--------------------------------------------------------------
void ofApp::update(){

    // on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update

	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		//particles[i].addAttractionForce(mouseX, mouseY, 1000, 0.1);
		//particles[i].addRepulsionForce(mouseX, mouseY, 60, 1);

		particles[i].addCounterClockwiseForce(mouseX, mouseY, 1000, 0.1);
		particles[i].addClockwiseForce(mouseX, mouseY, 200, 1);

		//particles[i].addForce(0,0.04);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0);

	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
}
