#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
    
    nPtsW = 20;
    nPtsH = 20;
    
    for (int i = 0; i < nPtsW; i++){
        for (int j = 0; j < nPtsH; j++){
            
            float x = ofMap(i,0,nPtsW, 0,ofGetWidth());
            float y = ofMap(j,0,nPtsH, 0,ofGetHeight());
            particle myParticle;
            myParticle.setInitialCondition(x,y,0,0);
            // more interesting with diversity :)
            // uncomment this: 
            //myParticle.damping = ofRandom(0.01, 0.05);
            particles.push_back(myParticle);
        }    
    }
	
	
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
    int count = 0;
	
	for (int i = 0; i < nPtsW; i++){
        for (int j = 0; j < nPtsH; j++){

            
            float x = ofMap(i,0,nPtsW, 0,ofGetWidth());
            float y = ofMap(j,0,nPtsH, 0,ofGetHeight());    
                
            particles[count].resetForce();
            
            
            particles[count].addAttractionForce(x, y, 1000, 0.1);
//            // particles[i * nPtsH + j].addClockwiseForce(mouseX, mouseY, 100, 0.4);
            particles[count].addRepulsionForce(mouseX, mouseY, 500, 0.2);
//
            
            particles[count].addDampingForce();
            particles[count].update();
            
            count++;
            
        }
	}

}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(0x000000);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
