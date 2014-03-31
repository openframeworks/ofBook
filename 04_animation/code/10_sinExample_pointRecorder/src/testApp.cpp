#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	ofSetVerticalSync(true);
	
	ofBackground(255, 255, 255);
	
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	
	//for (int i = 0; i < points.size(); i++){
//		points[i].x += ofRandom(-1,1);
//		points[i].y += ofRandom(-1,1);
//	}
	

}

//--------------------------------------------------------------
void testApp::draw(){

	ofNoFill();
	ofSetColor(0, 0, 0);
	
	ofBeginShape();
	for (int i = 0; i < points.size(); i++){
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape();
	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

	ofPoint tempPt;
	tempPt.x = x;
	tempPt.y = y;
	points.push_back(tempPt);
	printf ("size of vector %i \n", points.size());
	
	
	if (points.size() > 50){
		points.erase(points.begin());
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

	points.clear();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

