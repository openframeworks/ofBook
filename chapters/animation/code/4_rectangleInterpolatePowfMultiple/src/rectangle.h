#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle {

	public:
	
        rectangle();
	
		void draw();
		void interpolateByPct(float myPct);
		
		ofPoint		pos;
		ofPoint		posa;
		ofPoint		posb;
		float		pct;	// what pct are we between "a" and "b"
		float		shaper;
	
	

};

#endif // RECTANGLE_H
