#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){	
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    for (int i = 0; i < 100; i++){
        particle myParticle;
        float x = 500 + 100 * cos ( (i / 100.0) * TWO_PI);
        float y = 500 + 100 * sin ( (i / 100.0) * TWO_PI);
        myParticle.setInitialCondition(x,y ,0,0);
        particles.push_back(myParticle);
    }

    // change this to
    // for (int i = 0; i < 10; i++){
    // to see a chain
    for (int i = 0; i < particles.size(); i++){
        spring mySpring;
        mySpring.distance = 10;
        mySpring.springiness = 0.2f;
        mySpring.particleA = & (particles[i  ]);
        mySpring.particleB = & (particles[(i+1) % particles.size()]);
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
        particles[i].addRepulsionForce(mouseX, mouseY, 200, 0.3f);
	for (int j = 0; j < i; j++){
	    particles[i].addRepulsionForce(particles[j], 20, 0.3);
	}
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
