#include "BallRed.h"

void BallRed::draw(){
    
    ofSetColor(ofColor::red);
    ofDrawCircle(x, y, dim);

}
