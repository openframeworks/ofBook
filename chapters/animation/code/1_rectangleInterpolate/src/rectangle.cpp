#include "rectangle.h"
 
//------------------------------------------------------------------
	rectangle::rectangle() {
}

 
//------------------------------------------------------------------
	void
rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER);	// center around the position
	ofSetColor(198, 246, 55);
	ofRect(pos.x, pos.y, 20, 20);
}  

//------------------------------------------------------------------
	void
rectangle::interpolateByPct(float myPct) {
	pct = myPct;
	pos.x = (1 - pct) * posa.x + (pct) * posb.x;
	pos.y = (1 - pct) * posa.y + (pct) * posb.y;
	 
		// this is an alternative way to write above..
		// differe style, but the same mathematically.
		//pos.x = posa.x + (pct) * (posb.x-posa.x);
} 
