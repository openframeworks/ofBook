#include "BallRed.h"

void BallRed::draw(){
    
    ofSetColor(ofColor::red);
    ofCircle(x, y, dim);

}