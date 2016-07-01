// =============================================================================
//
// Source code for section 3.i Translating Stick Family from the Introduction
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

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);

    // Set some colors for us to use.  They are slighty transparent,
    // so that we can see shapes even if they overlap
    ofColor blueColor(50, 187, 250, 200);
    ofColor purpleColor(231, 49, 247, 200);

    // Loop to draw a grid
    for (int rows=0; rows<4; rows++) {

        ofPushMatrix(); // Save the coordinate system before we shift it horizontally
            // It is often helpful to indent any code in-between push and pop matrix for readability

            // Loop and draw a row within the grid
            for (int cols=0; cols<7; cols++) {

                // Draw the stick figure family
                ofSetColor(blueColor);
                ofDrawCircle(30, 30, 30);
                ofDrawRectangle(5, 70, 50, 100);
                ofSetColor(blueColor);
                ofDrawCircle(95, 30, 30);
                ofDrawRectangle(70, 70, 50, 100);
                ofSetColor(purpleColor);
                ofDrawCircle(45, 90, 15);
                ofDrawRectangle(30, 110, 30, 60);
                ofSetColor(purpleColor);
                ofDrawCircle(80, 90, 15);
                ofDrawRectangle(65, 110, 30, 60);

                ofTranslate(150, 0); // Shift horizontally
            }

        ofPopMatrix(); // Return to the coordinate system before we shifted it horizontally
        ofTranslate(0, 200); // Shift vertically
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
