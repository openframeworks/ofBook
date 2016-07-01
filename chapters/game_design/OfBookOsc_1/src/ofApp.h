#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Enemy.h"
#include "LevelController.h"
#include "Bullet.h"
#include "Life.h"
#include "LiveTesting.h"

#include "ofxOsc.h"



class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    float max_enemy_amplitude;
    float max_enemy_shoot_interval;
    
    int score;
    
    string game_state;
    
    Player player_1;
    
    LevelController level_controller;
    
    vector<Bullet> bullets;
    vector<Enemy> enemies;
    vector<Life> bonuses;
    
    ofImage enemy_image;
    ofImage player_image;
    ofImage enemy_bullet_image;
    ofImage player_bullet_image;
    ofImage start_screen;
    ofImage end_screen;
    ofImage life_image;

    LiveTesting liveTest;
    
    void update_bullets();
    void update_bonuses();
    void check_bullet_collisions();
    void draw_lives();
    void draw_score();
    
    ofTrueTypeFont score_font;
    bool testing;
   
    
};
