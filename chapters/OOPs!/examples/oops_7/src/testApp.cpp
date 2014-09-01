#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){

    redBall.update();
    greenBall.update();
    blueBall.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    redBall.draw();
    greenBall.draw();
    blueBall.draw();
    

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