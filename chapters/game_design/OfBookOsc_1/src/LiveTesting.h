

#pragma once
#include "ofxOsc.h"

class LiveTesting
{
public: 
    LiveTesting();
    
    void setup();
    void update();
    ofxOscSender sender;
    
    //you can set up a sender! We are going to use this to let us know what we our values are set to in our game as we change them, giving us the ability to reference them if they seem to be working and to save them into our game for later use.
    ofxOscReceiver receiver;
    //this is the magic! This is how your game gets incoming data
    ofxOscMessage m;
    //this is the osc message it gets.
    
    //these are the values we will be tweeking during testing
    float max_enemy_amplitude;
    int interval_time;
    float max_enemy_shoot_interval;
    bool triggerBonus; 
    
};
