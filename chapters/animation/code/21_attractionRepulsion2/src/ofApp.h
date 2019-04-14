#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "particle.h"

class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();

		vector <particle> particles;
		int nPtsW;
		int nPtsH;
};

#endif
