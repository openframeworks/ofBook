
#include "Enemy.h"


void Enemy::setup(float m_e_a, float m_e_s_i, ofImage * enemy_image) {
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    img = enemy_image;
    width = img->getWidth();
    
    speed = ofRandom(2, 7);
    
    amplitude = ofRandom(m_e_a);
    
    shoot_interval = ofRandom(0.5, m_e_s_i);
    
    start_shoot = ofGetElapsedTimef();
    
}

void Enemy::update() {
    pos.y += speed;
    pos.x += amplitude * sin(ofGetElapsedTimef());
    
}

void Enemy::draw() {
    img->draw(pos.x - width/2, pos.y - width/2);
    
}

bool Enemy::time_to_shoot() {
    if (ofGetElapsedTimef() - start_shoot > shoot_interval) {
        start_shoot = ofGetElapsedTimef();
        return true;
    }
    return false;

}
