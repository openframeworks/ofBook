#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i=0; i <groupOfBalls.size(); i++) {
        groupOfBalls[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i=0; i <groupOfBalls.size(); i++) {
        groupOfBalls[i].draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    Ball tempBall;									// create the ball object
    tempBall.setup(x,y, ofRandom(10,40));			// setup its initial state
    groupOfBalls.push_back(tempBall);						// add it to the vector

    cout << "there are " << groupOfBalls.size() << " balls on screen" <<endl; // use this to monitor the object creation :)
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    for (int i =0; i < groupOfBalls.size(); i++) {
        float distance = ofDist(x,y, groupOfBalls[i].x, groupOfBalls[i].y); // a method OF give us to check the distance between two coordinates

        if (distance < groupOfBalls[i].dim) {
            groupOfBalls.erase(groupOfBalls.begin()+i); // we need to use an iterator/ reference to the vector position we want to delete
        }
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
