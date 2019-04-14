#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "particle.h"
#include "spring.h"

class ofApp : public ofBaseApp{
    using ofBaseApp::mouseReleased;
    public:

        void setup();
        void update();
        void draw();

        void keyPressed  (int key);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased();

        vector <particle> particles;
        vector <spring> springs;
};

#endif	
