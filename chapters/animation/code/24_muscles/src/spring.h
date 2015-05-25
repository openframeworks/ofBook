#ifndef SPRING_H
#define SPRING_H

#include "ofMain.h"
#include "particle.h"

class spring {
	public:
		particle * particleA;
		particle * particleB;

		spring();
		
		float distance;
		float springiness;	 // this is the k, springiness constant
		void update();
		void draw();
};

#endif
