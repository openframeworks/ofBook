#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle{

    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;

        particle();

        void resetForce();
        void addForce(float x, float y);
        void addDampingForce();
        void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();

		float damping;
};

#endif // PARTICLE_H
