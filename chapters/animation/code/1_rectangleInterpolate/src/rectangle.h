#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle{

    public:

	rectangle();
	void draw();
	void interpolateByPct(float myPct);

	ofPoint pos;
	ofPoint posa;
	ofPoint posb;
	// what pct are we between "a" and "b"
	float pct;
};

#endif // RECTANGLE_H
