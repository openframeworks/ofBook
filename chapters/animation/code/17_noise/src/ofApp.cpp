#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255,255,255);
  //ofSetFrameRate(5);
  ofSetVerticalSync(true);
  colorScheme.load("sunset.png");
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofEnableAlphaBlending();
  ofSetColor(255, 255, 255, 100);
  ofSeedRandom(0); // always pick the same random numbers.

  float currentTime = ofGetElapsedTimef();

  for (int i = 0; i < mouseX * 3; i++){
    float screenWidth = ofGetWidth();
    float screenHeight = ofGetHeight();

    float xNoise = ofNoise(currentTime * 0.2, i * 0.3);
    float yNoise = ofNoise(-currentTime * 0.2, i * 0.3);

    float x = xNoise * screenWidth;
    float y = yNoise * screenHeight;

    ofColor color = getColorForPixel(
      ofMap(x, 0, screenWidth, 0, colorScheme.getWidth()),
      ofMap(x, 0, screenHeight, 0, colorScheme.getHeight())
    );

    color.a = 85; // set some alpha.

    ofSetColor(color);
    ofDrawCircle(x, y, ofRandom(4, 40));
  }
}

//--------------------------------------------------------------
ofColor ofApp::getColorForPixel(int x, int y) {
  x = ofClamp(x, 0, colorScheme.getWidth() - 1);
  y = ofClamp(y, 0, colorScheme.getHeight() - 1);

  return colorScheme.getColor(x,y);
}
