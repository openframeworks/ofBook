#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "rectangle.h"
class ofApp:public ofSimpleApp{

    public:
        void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);

	rectangle myRectangle;
	float pct;
};

#endif
