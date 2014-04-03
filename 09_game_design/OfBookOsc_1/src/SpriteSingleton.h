//
//  SpriteSingleton.h
//  OfBookOsc
//
//  Created by Phoenix Perry on 3/8/14.
//
//

#ifndef __OfBookOsc__SpriteSingleton__
#define __OfBookOsc__SpriteSingleton__

#include <iostream>
#include <vector>
#include "ofMain.h"
#include "ofxSpriteSheetRenderer.h"


class SpriteSingleton{
private:
    static SpriteSingleton* getInstance();
        static void makeSprites();
public:
    ofxSpriteSheetRenderer *spriteRenderer;	// our spriteRenderer

    static bool instanceFlag;
    static SpriteSingleton *single;
    ofxSpriteSheetRenderer* getSheet();
    
    SpriteSingleton(){}
    
    ~SpriteSingleton(){
        instanceFlag = false;
        delete spriteRenderer;
    }
};
#endif /* defined(__OfBookOsc__SpriteSingleton__) */
