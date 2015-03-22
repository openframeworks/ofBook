#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    leftMouseButtonPressed = false;
    minDistance = 10.0;
    isSavingPDF = false;
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

    // If isSavingPDF is true (i.e. the s key has been pressed), then
    // anything in between ofBeginSaveScreenAsPDF(...) and ofEndSaveScreenAsPDF()
    // Note: anything after ofBeginSaveScreenAsPDF(...) has been called
    // is not drawn to the screen, it is instead rendered into a PDF file
    if (isSavingPDF) {
        ofBeginSaveScreenAsPDF("savedScreenshot_"+ofGetTimestampString()+".pdf");
    }

    ofBackground(0);
    ofSetColor(255);  // White color for saved polylines
    for (int i=0; i<polylines.size(); i++) {

        // Drawing the polyline
        ofPolyline polyline = polylines[i];
        //polyline.draw();

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

    // Finish saving the PDF and reset the isSavingPDF flag to false
    // Ending the PDF tells openFrameworks to resume drawing to the screen.
    if (isSavingPDF) {
        ofEndSaveScreenAsPDF();
        isSavingPDF = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        // isSavingPDF is a flag that lets us know whether or not save a PDF
        isSavingPDF = true;
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
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = true;
        currentPolyline.curveTo(x, y);  // Remember that x and y are the location of the mouse
        currentPolyline.curveTo(x, y);  // Necessary duplicate for first control point
        lastPoint.set(x, y);  // Set the x and y of a ofVec2f in a single line
    }

    // Erase the polylines if the right mouse button is pressed
    if (button == OF_MOUSE_BUTTON_RIGHT) {
        currentPolyline.clear();
        polylines.clear();
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
