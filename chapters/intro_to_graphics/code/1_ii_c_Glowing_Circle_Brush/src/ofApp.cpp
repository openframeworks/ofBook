// =============================================================================
//
// Source code for section 1.ii.c. Glowing Circle Brush from the Introduction
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
    ofSetFrameRate(60); // Limit the speed of our program to 60 frames per second

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
        int maxRadius = 100;  // Increase for a wider brush
        int radiusStepSize = 5;  // Decrease for more circles (i.e. a more opaque brush)
        int alpha = 3;  // Increase for a more opaque brush
        int maxOffsetDistance = 100;  // Increase for a larger spread of circles
        for (int radius=maxRadius; radius>0; radius-=radiusStepSize) {

            // Formula for converting from polar to Cartesian coordinates:
            //    x = cos(polar angle) * (polar distance)
            //    y = sin(polar angle) * (polar distance)
            // We need our angle to be in radians if we want to use sin() or cos()
            // so we can make use of an openFrameworks function to convert from degrees
            // to radians
            float angle = ofRandom(ofDegToRad(360.0));
            float distance = ofRandom(maxOffsetDistance);
            float xOffset = cos(angle) * distance;
            float yOffset = sin(angle) * distance;

            // Using the ofColor class, we will randomly select a color between orange and red
            ofColor myOrange(255, 132, 0, alpha);
            ofColor myRed(255, 6, 0, alpha);
            ofColor inBetween = myOrange.getLerped(myRed, ofRandom(1.0));
            ofSetColor(inBetween);

            ofDrawCircle(ofGetMouseX()+xOffset, ofGetMouseY()+yOffset, radius);
        }
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
