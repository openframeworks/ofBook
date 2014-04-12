#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
                        // x-position,        y-position,           size
    myBall = new ofBall(ofRandom(300,400), ofRandom(200,300), ofRandom(10,40));

}

//--------------------------------------------------------------
void testApp::update(){
        myBall->update();
}

//--------------------------------------------------------------
void testApp::draw(){
    myBall->draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}