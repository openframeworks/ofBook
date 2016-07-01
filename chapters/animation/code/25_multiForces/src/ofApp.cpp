#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){	
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    for (int i = 0; i < 20; i++){
        particle myParticle;
	myParticle.setInitialCondition(ofRandom(500,550),ofRandom(500,550),0,0);
	particles.push_back(myParticle);
    }

    particles[0].bFixed = true;

    for (int i = 1; i < particles.size(); i++){
        spring mySpring;
	mySpring.distance = 100;
	mySpring.springiness = 0.2f;
	mySpring.particleA = & (particles[0  ]);
	mySpring.particleB = & (particles[i]);
	springs.push_back(mySpring);
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
    }

    for (int i = 0; i < particles.size(); i++){
        particles[i].addRepulsionForce(mouseX, mouseY, 200, 0.7f);
	for (int j = 0; j < i; j++){
            particles[i].addRepulsionForce(particles[j], 20, 0.03);
	}
    }

    for (int i = 0; i < springs.size(); i++){
        springs[i].update();
    }

    for (int i = 0; i < particles.size(); i++){
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
}
