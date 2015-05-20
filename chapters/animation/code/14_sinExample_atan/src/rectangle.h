#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle {

	public:

        rectangle();

		void	draw();
		void	xenoToPoint(float catchX, float catchY);

		ofPoint		pos;
		ofPoint		prevPos;
		float		angle;
		float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
};

#endif // RECTANGLE_H
