#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		vector <ofPoint> points;
		float radius;
};

#endif
