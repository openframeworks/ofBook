/* Have three particles connected by two virtual springs.
   Move them with the mouse cursor and reset the system by
   pressing the space bar. */
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
	
    for (int i = 0; i < 4; i++){
        particle myParticle;
	myParticle.setInitialCondition(ofRandom(500,550),ofRandom(500,550),0,0);
	particles.push_back(myParticle);
    }

    for (int i = 0; i < (particles.size()-1); i++){
        spring mySpring;
	mySpring.distance = 10;
	mySpring.springiness = 0.1f;
	mySpring.particleA = & (particles[i]);
	mySpring.particleB = & (particles[(i+1)%particles.size()]);
	springs.push_back(mySpring);
    }
    //particles[particles.size()-1].bFixed = true;	
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
        //particles[i].addForce(0,0.1);
    }

    for (int i = 0; i < springs.size(); i++){
        springs[i].update();
    }

    for (int i = 0; i < particles.size(); i++){
        particles[i].addDampingForce();
	particles[i].update();
    }

    trail.push_back(particles[3].pos);
    if (trail.size() > 150){
        trail.erase(trail.begin());	
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

    ofNoFill();
    ofBeginShape();
    for (int i = 0; i < trail.size(); i++){
        ofVertex(trail[i].x, trail[i].y);
    }
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ 
    switch (key){
    case ' ':
        // reposition everything: 
        for (int i = 0; i < particles.size(); i++){
	    particles[i].setInitialCondition(
					     ofRandom(0,ofGetWidth()),
					     ofRandom(0,ofGetHeight()),
					     0,0);
	}
	break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    particles[0].pos.set(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    particles[0].bFixed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(){
    particles[0].bFixed = false;
}
