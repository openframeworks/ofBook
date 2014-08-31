#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0 ; i<myBall.size(); i++) {
        myBall[i]->update();
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

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    ofBall *temp;
    temp = new ofBall(x,y, ofRandom(10,40));
    myBall.push_back(temp);
    cout << myBall.size()<<endl;

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    for (int i =0; i < myBall.size(); i++) {
        float distance = ofDist(x,y, myBall[i]->x, myBall[i]->y);
        
        if (distance < myBall[i]->dim) {
            delete myBall[i];
            myBall.erase(myBall.begin()+i);
            cout << myBall.size()<<endl;
        }
    }
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