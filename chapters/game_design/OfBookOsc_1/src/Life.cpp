#include "Life.h"

void Life::setup(ofImage * _img) {
    img = _img;
    width = img->getWidth();
    speed = 5;
    pos.x = ofRandom(ofGetWidth());
    pos.y = -img->getWidth()/2;
}

void Life::update() {
    pos.y += speed;
}

void Life::draw() {
    img->draw(pos.x - img->getWidth()/2, pos.y - img->getWidth()/2);
}