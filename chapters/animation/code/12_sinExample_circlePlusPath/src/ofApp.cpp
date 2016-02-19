#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(0,0,0);
	ofSetCircleResolution(100);
	radius = 50;
}

//--------------------------------------------------------------
void ofApp::update(){
	radius = radius + 0.1;
}

//--------------------------------------------------------------
void ofApp::draw(){

	float xorig = 500;
	float yorig = 300;
	float angle = ofGetElapsedTimef()*3.5;
	float x = xorig + radius * cos(angle);
	float y = yorig + radius * -sin(angle);
	
	ofPoint temp;
	temp.x = x;
	temp.y = y;
	points.push_back(temp);
	if (points.size() > 500){
		points.erase(points.begin());
	}
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(255,0,127);
	ofFill();
	ofDrawCircle(x,y,10);
	
	ofSetColor(255,255,255);
	
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i < points.size(); i++){
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape();
}
