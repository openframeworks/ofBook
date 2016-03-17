#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){	
	ofBackground(0,0,0);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	particle myParticle;
	myParticle.setInitialCondition(400,400,0,0);
	particles.push_back(myParticle);

	myParticle.setInitialCondition(400,500,0,0);
	particles.push_back(myParticle);

	myParticle.setInitialCondition(500,500,0,0);
	particles.push_back(myParticle);

	myParticle.setInitialCondition(500,400,0,0);
	particles.push_back(myParticle);

	spring mySpring;

	for (int i = 0; i < particles.size(); i++){
		mySpring.distance		= 100;
		mySpring.springiness	= 0.2f;
		mySpring.particleA = & (particles[i]);
		mySpring.particleB = & (particles[(i+1) % particles.size()]);
		springs.push_back(mySpring);
	}

	mySpring.distance		= (particles[0].pos-particles[2].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[0]);
	mySpring.particleB = & (particles[2]);
	springs.push_back(mySpring);

	mySpring.distance		= (particles[1].pos-particles[3].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[1]);
	mySpring.particleB = & (particles[3]);
	springs.push_back(mySpring);
}

//--------------------------------------------------------------
void ofApp::update(){
	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	springs[0].distance = 100 + 50 * sin(ofGetElapsedTimef()*8);
	springs[2].distance = 100 + 50 * sin(ofGetElapsedTimef()*8 + PI);

	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		particles[i].addForce(0,0.1f);
		particles[i].addRepulsionForce(mouseX, mouseY, 300, 0.7f);
	}

	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}

	for (int i = 0; i < particles.size(); i++){
		particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);

	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}

	for (int i = 0; i < springs.size(); i++){
		springs[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ 
	switch (key){
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	particles[0].pos.set(mouseX, mouseY);
	/*particles.erase(particles.begin());
	particle myParticle;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);*/
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	particles[0].bFixed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(){
	particles[0].bFixed = false;
}
