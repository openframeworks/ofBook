#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0 ; i<myBall.size(); i++) {
        myBall[i]->update();
    
        float distance = ofDist( mouseX, mouseY, myBall[i]->x, myBall[i]->y); //calculate the distance from mouse coordinates
        
        if (distance > myBall[i]->dim *5) {                                  // use the distance as a condition to delete some balls
            delete myBall[i];
            myBall.erase( myBall.begin()+i );
            cout << myBall.size()<<endl;
        }
    
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0 ; i<myBall.size(); i++) {
        myBall[i]->draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    ofBall *temp;
    temp = new ofBall(x,y, ofRandom(10,40));
    myBall.push_back(temp);
    cout << myBall.size()<<endl;

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