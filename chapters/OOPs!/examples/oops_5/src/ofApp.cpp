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
  
    for (int i =0; i < myBall.size(); i++) {
        float distance = ofDist(x,y, myBall[i].x, myBall[i].y); // a method OF give us to check the distance between two coordinates
        
        if (distance < myBall[i].dim) {
            myBall.erase(myBall.begin()+i); // we need to use an iterator/ reference to the vector position we want to delete
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