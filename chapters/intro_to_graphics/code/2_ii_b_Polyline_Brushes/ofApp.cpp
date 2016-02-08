// =============================================================================
//
// Source code for section 2.ii.b. Polyline Brushes from the Introduction
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
    minDistance = 10.0;
    leftMouseButtonPressed = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (leftMouseButtonPressed) {
        ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
        if (lastPoint.distance(mousePos) >= minDistance) {
            // a.distance(b) calculates the Euclidean distance between point a and b.  It's
            // the straight line distance between the points.
            currentPolyline.curveTo(mousePos);  // Here we are using an ofVec2f with curveTo(...)
            lastPoint = mousePos;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);  // White color for saved polylines
    for (int i=0; i<polylines.size(); i++) {

        // Drawing the polyline
        ofPolyline polyline = polylines[i];
        polyline.draw();

        // Below are three different drawing methods: points, normals and tangents.
        // Use comments to select which one you'd like to run.  You can comment out the
        // original polyline drawing on line 57, if you like.

        // Drawing evenly spaced points along the polyline
//        vector<ofVec3f> vertices = polyline.getVertices();  // If you haven't seen a vector < >, before
//        for (int p=0; p<100; p+=10) {
//            ofVec3f point = polyline.getPointAtPercent(p/100.0);  // Returns a point at a percentage along the polyline
//            ofCircle(point, 5);
//        }

        // Drawing evenly spaced normals along the polyline
        //  Note: If you want to use the normals to add thickness to our polylines
        //  (creating "ribbons"), then edit the loop so that it moves by a smaller
        //  percentage each iteration
//        float numPoints = polyline.size();
//        float normalLength = 50;
//        for (int p=0; p<100; p+=10) {
//            ofVec3f point = polyline.getPointAtPercent(p/100.0);
//            float floatIndex = p/100.0 * (numPoints-1);
//            ofVec3f normal = polyline.getNormalAtIndexInterpolated(floatIndex) * normalLength;
//            ofLine(point-normal/2, point+normal/2);
//        }

        // Drawing evenly spaced tangents along the polyline
        //  Note: These are pretty exaggerated tangents, like Figure 16 (right)
        ofSetColor(255, 50);
        float numPoints = polyline.size();
        float tangentLength = 300;
        for (int p=0; p<500; p+=1) {
            ofVec3f point = polyline.getPointAtPercent(p/500.0);
            float floatIndex = p/500.0 * (numPoints-1);
            ofVec3f tangent = polyline.getTangentAtIndexInterpolated(floatIndex) * tangentLength;
            ofLine(point-tangent/2, point+tangent/2);
        }
    }

    ofSetColor(255,100,0);  // Orange color for active polyline
    currentPolyline.draw();
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
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = true;
        currentPolyline.curveTo(x, y);  // Remember that x and y are the location of the mouse
        currentPolyline.curveTo(x, y);  // Necessary duplicate for first control point
        lastPoint.set(x, y);  // Set the x and y of a ofVec2f in a single line
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = false;
        currentPolyline.curveTo(x, y);   // Necessary duplicate for last control point
        currentPolyline.simplify(0.75);
        polylines.push_back(currentPolyline);
        currentPolyline.clear();  // Erase the vertices, allows us to start a new brush stroke
    }
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
