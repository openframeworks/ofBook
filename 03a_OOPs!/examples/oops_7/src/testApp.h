#pragma once

#include "ofMain.h"
#include "ofBall.h"
#include "ofBallRed.h"
#include "ofBallGreen.h"
#include "ofBallBlue.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofBallRed redBall;
    ofBallGreen greenBall;
    ofBallBlue blueBall;
    
};
