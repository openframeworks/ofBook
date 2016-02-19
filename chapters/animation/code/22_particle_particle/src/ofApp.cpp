/* Have randomly placed particles be attracted to the mouse cursor. (Toggleing not implemented yet.) */
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	for (int i = 0; i < 200; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}

	bRepel		= true;
	radius		= 40;
	strength	= 0.5f; 
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
	}

	for (int i = 0; i < particles.size(); i++){
		particles[i].addAttractionForce(mouseX, mouseY, 1000, 0.1);
		for (int j = 0; j < i; j++){
		    particles[i].addRepulsionForce(particles[j], 10, 0.4);
		    particles[i].addAttractionForce(particles[j], 500, 0.005);
		}
	}

	for (int i = 0; i < particles.size(); i++){
	    particles[i].addDampingForce();
	    particles[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	ofSetColor(0);
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}

	string reportString = "(space) = reset\n(a/s) strength = " + ofToString(strength) + 
	                      "\n(z/x) radius = " + ofToString(radius) + 
	                      "\n(r) toggle mode = " + (bRepel ? "repelling" : "attracting");

	ofSetColor(40,40,0);
	ofRect(10,10,300,80);
	ofSetColor(255,255,255);
	ofDrawBitmapString(reportString, 30, 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	switch (key){
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
		case 'a':
			strength += 0.02f;
			break;
		case 's':
			strength -= 0.02f;
			if (strength <= 0) strength = 0.02f;
			break;
		case 'z':
			radius += 5.0f;
			break;
		case 'x':
			radius -= 5.0f;
			if (radius <= 0) radius = 5.0f;
			break;
		case 'r':
			bRepel = !bRepel;
			break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	particles.erase(particles.begin());
	particle myParticle;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);
}
