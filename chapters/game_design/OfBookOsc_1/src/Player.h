//
//  Player.h
//  OfBookOsc
//
//  Created by Phoenix Perry on 3/3/14.
//
//

#pragma once
#include "ofMain.h"

class Player {
public:
    ofPoint pos;
    float width, height, speed;
    int lives;
    
    bool is_left_pressed, is_right_pressed, is_down_pressed, is_up_pressed;
    
    void setup(ofImage * _img);
    void update();
    void draw();
    void shoot();
    
    void calculate_movement();
    
    bool check_can_shoot();
    
    ofImage * img;
    
};
