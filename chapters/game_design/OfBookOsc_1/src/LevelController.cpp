#include "LevelController.h"

void LevelController::setup(float s) {
    start_time = s;
    interval_time = 500;
}

void LevelController::update() {
    
}

bool LevelController::should_spawn() {
    if (ofGetElapsedTimeMillis() - start_time > interval_time) {
        start_time = ofGetElapsedTimeMillis();
        return true;
    }
    return false;
}

