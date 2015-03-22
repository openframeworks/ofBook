#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0); // let's make our background black
    
    int xCenter = ofGetWidth()*.5;
    int yCenter = ofGetHeight()*.5;
    int dim = ofRandom(200,250);
    redBall.setup(xCenter, yCenter, dim);
    greenBall.setup(xCenter, yCenter, dim);
    blueBall.setup(xCenter, yCenter, dim);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    redBall.update();
    greenBall.update();
    blueBall.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    redBall.draw();
    greenBall.draw();
    blueBall.draw();
    
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