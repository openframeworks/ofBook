//
//  LevelController.h
//  OfBookOsc
//
//  Created by Phoenix Perry on 3/3/14.
//
//

#pragma once
#include "ofMain.h"

class LevelController {
public:
    float start_time;
    float interval_time;
    
    void setup(float e);
    void update();
    bool should_spawn();
    
};