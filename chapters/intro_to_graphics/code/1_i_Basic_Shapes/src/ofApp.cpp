// =============================================================================
//
// Source code for section 1.i. Basic Shapes from the Introduction to Graphics
// chapter of ofBook (https://github.com/openframeworks/ofBook).
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
    // This is enabled by default in recent version of openFrameworks
    ofEnableAntiAliasing();

    ofSetCircleResolution(50); // For smoother looking circles + ellipses
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0); // Clear the screen with a black color
    ofSetColor(255); // Set the drawing color to white

    ofFill(); // If we omit this and leave ofNoFill(), all the shapes will be outlines!
    ofSetLineWidth(2); // Line width is a default value of 1 if you don't modify it

    // Draw some shapes
    ofDrawRectangle(50, 50, 100, 100); // 100 wide x 100 high, top left corner at (50, 50)
    ofDrawCircle(250, 100, 50); // Radius of 50, centered at (250, 100)
    ofDrawEllipse(400, 100, 80, 100); // 80 wide x 100 high, centered at (400 100)
    ofDrawTriangle(500, 150, 550, 50, 600, 150); // Three corners: (500, 150), (550, 50), (600, 150)
    ofDrawLine(700, 50, 700, 150); // Line from (700, 50) to (700, 150)

    // If you are curious how to generate the series of lines shown in figure 2, you can use a for loop:
    //for (int i=0; i<11; i++) {
	//	ofDrawLine(650, 50+(i*10), 750, 75+(i*5));
	//}

    ofNoFill(); // If we omit this and leave ofFill(), all the shapes will be filled!
    ofSetLineWidth(4.5); // A higher value will render thicker lines
    // Note: Using ofSetLineWidth is tricky - it doesn't work with all graphics cards!

    // Draw some shapes (shifted down 150 pixels)
    ofDrawRectangle(50, 200, 100, 100);
    ofDrawCircle(250, 250, 50);
    ofDrawEllipse(400, 250, 80, 100);
    ofDrawTriangle(500, 300, 550, 200, 600, 300);
    ofDrawLine(700, 200, 700, 300);

    // Again, for generating the series of lines from figure 2:
    //for (int i=0; i<11; i++) {
	//	ofDrawLine(650, 200+(i*10), 750, 225+(i*5));
	//}
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
