#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();

		float position;
		ofImage colorScheme;
		ofColor getColorForPixel(int x, int y);
};
