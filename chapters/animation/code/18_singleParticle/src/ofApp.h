#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "particle.h"

class ofApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();

		void mousePressed(int x, int y, int button);

		particle p;
};

#endif	
