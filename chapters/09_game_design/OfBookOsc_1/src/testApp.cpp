#include "testApp.h"



//-------------------------------------------------------------
void testApp::setup(){
  
    game_state = "start";
    
    max_enemy_amplitude = 3.0;
    max_enemy_shoot_interval = 1.5;
    
    enemy_image.loadImage("enemy0.png");
    player_image.loadImage("player.png");
    life_image.loadImage("life_image.png");
    enemy_bullet_image.loadImage("enemy_bullet.png");
    player_bullet_image.loadImage("player_bullet.png");
    start_screen.loadImage("start_screen.png");
    end_screen.loadImage("end_screen.png");
    player_1.setup(&player_image);
    
    score_font.loadFont("Gota_Light.otf", 48);
    //simply change this boolean to turn testing on and off
    testing == false;
    if(testing == true){
        liveTest = LiveTesting();
    }
}


//--------------------------------------------------------------
void testApp::update(){
    //setting up the sprites 
//	sort( sprites.begin(), sprites.end(), sortVertically ); // sorts the sprites vertically so the ones that are lower are drawn later and there for in front of the ones that are higher up
  
    //cleans up sprites

    
    
    if (game_state == "start") {
        
        
        
    } else if (game_state == "game") {
        player_1.update();
        update_bullets();
        update_bonuses();
        
        for (int i = enemies.size()-1; i >=0; i--) {
            enemies[i].update();
            if (enemies[i].time_to_shoot()) {
                Bullet b;
                b.setup(false, enemies[i].pos, enemies[i].speed, &enemy_bullet_image);
                bullets.push_back(b);
            }
            if(enemies[i].pos.y> ofGetHeight() +50)
            {
                enemies.erase(enemies.begin()+i);
                              
            }
        }
        
        if (level_controller.should_spawn() == true) {
            Enemy e;
            e.setup(max_enemy_amplitude, max_enemy_shoot_interval, &enemy_image);
            enemies.push_back(e);
        }
        
        liveTest.update();
        if(liveTest.triggerBonus)
        {
            Life l;
            l.setup(&life_image);
            bonuses.push_back(l);
        }
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){

    if (game_state == "start") {
        start_screen.draw(0,0);
    } else if (game_state == "game") {
        ofBackground(0,0,0);
        player_1.draw();
        draw_lives();

        
        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].draw();
        }
        
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].draw();
        }
        
        for (int i = 0; i < bonuses.size(); i++) {
            bonuses[i].draw();
        }
        
        draw_score();
    } else if (game_state == "end") {
        end_screen.draw(0,0);
        draw_score();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (game_state == "game") {
        if (key == OF_KEY_LEFT) {
            player_1.is_left_pressed = true;
        }
        
        if (key == OF_KEY_RIGHT) {
            player_1.is_right_pressed = true;
        }
        
        if (key == OF_KEY_UP) {
            player_1.is_up_pressed = true;
        }
        
        if (key == OF_KEY_DOWN) {
            player_1.is_down_pressed = true;
        }
        
        if (key == ' ') {
            Bullet b;
            b.setup(true, player_1.pos, player_1.speed, &player_bullet_image);
            bullets.push_back(b);
        }
        
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    if (game_state == "start") {
        game_state = "game";
        level_controller.setup(ofGetElapsedTimeMillis());
    } else if (game_state == "game") {
        if (key == OF_KEY_LEFT) {
            player_1.is_left_pressed = false;
        }
        
        if (key == OF_KEY_RIGHT) {
            player_1.is_right_pressed = false;
        }
        
        if (key == OF_KEY_UP) {
            player_1.is_up_pressed = false;
        }
        
        if (key == OF_KEY_DOWN) {
            player_1.is_down_pressed = false;
        }
        
        // CONTROLLING GAME ASPECTS
        if (key == '1') {
            max_enemy_amplitude -= .5;
        }
        
        if (key == '2') {
            max_enemy_amplitude += .5;
        }
        
        if (key == '3') {
            level_controller.interval_time += 50;
        }
        
        if (key == '4') {
            level_controller.interval_time -= 50;
        }
        
        if (key == '5') {
            if (max_enemy_shoot_interval > 0) {
                max_enemy_shoot_interval -= .1;
            }
        }
        
        if (key == '6') {
            max_enemy_shoot_interval += .1;
        }
        
        if (key == '7') {
            Life l;
            l.setup(&life_image);
            bonuses.push_back(l);
        }
        
    }
}


//--------------------------------------------------------------
void testApp::update_bullets() {
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i].update();
    }
    
    check_bullet_collisions();
    
}
//--------------------------------------------------------------
void testApp::update_bonuses() {
    for (int i = bonuses.size()-1; i > 0; i--) {
        bonuses[i].update();
        if (ofDist(player_1.pos.x, player_1.pos.y, bonuses[i].pos.x, bonuses[i].pos.y) < (player_1.width + bonuses[i].width)/2) {
            player_1.lives++;
            bonuses.erase(bonuses.begin() + i);
        }
        
        if (bonuses[i].pos.y + bonuses[i].width/2 > ofGetHeight()) {
            bonuses.erase(bonuses.begin() + i);
        }
    }
}

//--------------------------------------------------------------
void testApp::check_bullet_collisions() {
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets[i].from_player) {
            for (int e = enemies.size()-1; e >= 0; e--) {
                if (ofDist(bullets[i].pos.x, bullets[i].pos.y, enemies[e].pos.x, enemies[e].pos.y) < (enemies[e].width + bullets[i].width)/2) {
                    enemies.erase(enemies.begin()+e);
                    bullets.erase(bullets.begin()+i);
                    score+=10;
                }
            }
        } else {
            if (ofDist(bullets[i].pos.x, bullets[i].pos.y, player_1.pos.x, player_1.pos.y) < (bullets[i].width+player_1.width)/2) {
                bullets.erase(bullets.begin()+i);
                player_1.lives--;
                
                if (player_1.lives <= 0) {
                    game_state = "end";
                }
            }
        }
    }
    
}
//--------------------------------------------------------------
void testApp::draw_lives() {
    for (int i = 0; i < player_1.lives; i++) {
        player_image.draw(ofGetWidth() - (i * player_image.width) - 100, 30);
    }
    
}
//--------------------------------------------------------------
void testApp::draw_score() {
    if (game_state == "game") {
        score_font.drawString(ofToString(score), 30, 72);
    } else if (game_state == "end") {
        float w = score_font.stringWidth(ofToString(score));
        score_font.drawString(ofToString(score), ofGetWidth()/2 - w/2, ofGetHeight()/2 + 100);
    }
}
//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}