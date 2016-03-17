#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){  
}


//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
	ofSetColor(198,246,55);
	ofCircle(pos.x, pos.y, radius);
}


//------------------------------------------------------------------
void rectangle::interpolateByPct(float myPct){
	pct = myPct;

	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	pos.y = (1-pct) * posa.y + (pct) * posb.y;

	radius = (1-pct) * radiusa + (pct) * radiusb;
}
