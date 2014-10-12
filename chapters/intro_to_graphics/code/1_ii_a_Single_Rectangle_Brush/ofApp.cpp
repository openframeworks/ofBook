// =============================================================================
//
// Source code for section 1.ii.a. Single Rectangle Brush from the Introduction
// to Graphics chapter of ofBook (https://github.com/openframeworks/ofBook).
//
// Copyright (c) 2014 Michael Hadley, mikewesthad.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false); // Stop the background from being redrawn each frame

    // We still want to draw on a black background, so we need to draw
    // the background before we do anything with the brush
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // If the left mouse button is pressed...
    if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
        // Randomness!
        float randomColor = ofRandom(50, 255);
        ofSetColor(randomColor); // Exclude dark grayscale values (0 - 50) that won't show on black background

        ofSetRectMode(OF_RECTMODE_CENTER); // Draw rect by specifying the center
        ofRect(ofGetMouseX(), ofGetMouseY(), 50, 50); // Draw a 50 x 50 rect centered over the mouse
    }

    // If the right mouse button is pressed...
    if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {
        ofBackground(0);  // Erase the screen with a black background
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // From section 1.ii.f, allowing you to save a screenshot by pressing the 's' key:
    if (key == 's') {
        // HACK: only needed on windows, when using ofSetAutoBackground(false)
        glReadBuffer(GL_FRONT);

        // We use the timestamp here so that you can save multiple images without
        // overriding previous screenshots (i.e. each file has a unique name)
        ofSaveScreen("savedScreenshot_"+ofGetTimestampString()+".png");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
