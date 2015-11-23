#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void draw();

		float position;
		ofImage colorScheme;
		ofColor getColorForPixel(int x, int y);
};
