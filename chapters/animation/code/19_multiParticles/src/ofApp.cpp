/* Have an explosion of particles by clicking on the screen. */
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){	

	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	for (int i = 0; i < 1000; i++){
		particle myParticle;
		float vx = ofRandom(-4,4);
		float vy = ofRandom(-4,4);
		myParticle.setInitialCondition(300,300,vx, vy);
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

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	for (int i = 0; i < particles.size(); i++){
		float vx = ofRandom(-4,4);
		float vy = ofRandom(-4,4);
		particles[i].setInitialCondition(mouseX,mouseY,vx, vy);	
	}
}
