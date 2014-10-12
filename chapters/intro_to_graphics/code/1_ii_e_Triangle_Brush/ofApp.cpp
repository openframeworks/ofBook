// =============================================================================
//
// Source code for section 1.ii.e. Fleeing Triangle Brush from the Introduction
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
	ofSetWindowShape(1024,768);

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

        // Code for the final version of the brush

        int numTriangles = 10;
        int minOffset = 5;
        int maxOffset = 70;
        int alpha = 150;

        for (int t=0; t<numTriangles; ++t) {
            float offsetDistance = ofRandom(minOffset, maxOffset);

            ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

            // Define a triangle at the origin (0,0) that points to the right
            ofVec2f p1(0, 6.25);
            ofVec2f p2(25, 0);
            ofVec2f p3(0, -6.25);

            float rotation = ofRandom(360); // The rotate function uses degrees!
            p1.rotate(rotation);
            p2.rotate(rotation);
            p3.rotate(rotation);

            ofVec2f triangleOffset(offsetDistance, 0.0);
            triangleOffset.rotate(rotation);

            p1 += mousePos + triangleOffset;
            p2 += mousePos + triangleOffset;
            p3 += mousePos + triangleOffset;

            ofColor aqua(0, 252, 255, alpha);
            ofColor purple(198, 0, 205, alpha);
            ofColor inbetween = aqua.getLerped(purple, ofRandom(1.0));
            ofSetColor(inbetween);

            ofTriangle(p1, p2, p3);
        }

        // Alternate code, for the rotating triangle brush discussed in the chapter:

//        ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
//
//        // Define a triangle at the origin (0,0) that points to the right
//        ofVec2f p1(0, 25.0);
//        ofVec2f p2(100, 0);
//        ofVec2f p3(0, -25.0);
//
//        // Rotate the triangle points around the origin
//        float rotation = ofRandom(360); // Uses degrees!
//        p1.rotate(rotation);
//        p2.rotate(rotation);
//        p3.rotate(rotation);
//
//        // Shift the triangle to the mouse position
//        p1 += mousePos;
//        p2 += mousePos;
//        p3 += mousePos;
//
//        ofSetColor(255, 50);
//        ofTriangle(p1, p2, p3);
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
