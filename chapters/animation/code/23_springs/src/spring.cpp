#include "spring.h"

//---------------------------------------------------------------------
spring::spring(){
    particleA = NULL;
    particleB = NULL;
}

//---------------------------------------------------------------------
void spring::update(){
    if ((particleA == NULL) || (particleB == NULL)){
        return;
    }

    ofVec2f pta = particleA->pos;
    ofVec2f ptb = particleB->pos;

    float theirDistance = (pta - ptb).length();
    float springForce = (springiness * (distance - theirDistance));
    ofVec2f frcToAdd = (pta-ptb).normalized() * springForce;

    particleA->addForce(frcToAdd.x, frcToAdd.y);
    particleB->addForce(-frcToAdd.x, -frcToAdd.y);
}


//---------------------------------------------------------------------
void spring::draw(){
    if ((particleA == NULL) || (particleB == NULL)){
        return;
    }

    ofLine(particleA->pos.x, particleA->pos.y, particleB->pos.x, particleB->pos.y);
}
