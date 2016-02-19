#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "particle.h"

class ofApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();

		// let's make a vector of them
		vector <particle> particles;
};

#endif
