// =============================================================================
//
// Source code for section 1.ii.d. Star Line Brush from the Introduction
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
    ofSetFrameRate(60);
    isLeftMousePressed = false;
    ofSetBackgroundAuto(false);
    // We still want to draw on a black background, so we need to draw
    // the background before we do anything with the brush
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if (isLeftMousePressed) {
        int numLines = 30;
        int minRadius = 25;
        int maxRadius = 125;
        for (int i=0; i<numLines; i++) {
            float distance = ofRandom(minRadius, maxRadius);
            float angle = ofRandom(2.0*PI);
            float xOffset = cos(angle) * distance;
            float yOffset = sin(angle) * distance;
            float alpha = ofMap(distance, minRadius, maxRadius, 50, 0);  // Make shorter lines more opaque
            ofSetColor(255, alpha);
            ofSetLineWidth(ofRandom(1.0, 5.0));
            ofLine(mouseX, mouseY, mouseX+xOffset, mouseY+yOffset);
        }
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
    if (button == OF_MOUSE_BUTTON_LEFT) isLeftMousePressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (button == OF_MOUSE_BUTTON_LEFT) isLeftMousePressed = false;
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
