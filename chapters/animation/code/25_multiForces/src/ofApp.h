#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "particle.h"
#include "spring.h"

class ofApp : public ofSimpleApp{
    public:
        void setup();
        void update();
        void draw();
        void keyPressed(int key);
        void mouseDragged(int x, int y, int button);

        // let's make a vector of them
        vector <particle> particles;
        vector <spring> springs;
};

#endif	
