
#pragma once
#include "ofMain.h"

class Life {
public:
    ofPoint pos;
    float speed;
    float width;
    
    ofImage * img;
    
    void setup(ofImage * _img);
    void update();
    void draw();
    
};
