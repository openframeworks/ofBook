//
//  SpriteSingleton.cpp
//  OfBookOsc
//
//  Created by Phoenix Perry on 3/8/14.
//
//

#include "SpriteSingleton.h"
#include "ofxSpriteSheetRenderer.h"

bool SpriteSingleton::instanceFlag =false;
SpriteSingleton* SpriteSingleton::single = NULL;

SpriteSingleton* SpriteSingleton::getInstance()
{
    if(!instanceFlag)
    {
        single = new SpriteSingleton();
        instanceFlag = true;
        makeSprites(); 
        return single;
    }
    else
    {
        return single;
    }
    
}
void SpriteSingleton::makeSprites(){
   if(!instanceFlag)
   {
       //spriteRenderer = new ofxSpriteSheetRenderer(1, 10000, 0, 30); //declare a new renderer with 1 layer, 10000 tiles per layer, default layer of 0, tile size of 32
       //spriteRenderer->loadTexture("spriteSheet.pnd", 256, GL_NEAREST); // load the spriteSheetExample.png texture of size 256x256 into the sprite sheet. set it's scale mode to nearest since it's pixel art
   }
}
ofxSpriteSheetRenderer* SpriteSingleton::getSheet(){
    return spriteRenderer;

}

