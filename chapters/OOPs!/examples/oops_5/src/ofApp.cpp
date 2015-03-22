#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i <myBall.size(); i++) {
        myBall[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i <myBall.size(); i++) {
        myBall[i].draw();
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
    myBall.push_back(tempBall);						// add it to the vector
    
    cout << "there are " << myBall.size() << " balls on screen" <<endl; // use this to monitor the object creation :)
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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