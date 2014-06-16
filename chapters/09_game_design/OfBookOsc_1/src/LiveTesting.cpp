//
//  LiveTesting.cpp
//  OfBookOsc
//
//  Created by Phoenix Perry on 3/3/14.
//
//

#include "LiveTesting.h"

LiveTesting::LiveTesting(){
    sender.setup("192.168.0.11", 8000);
    //this is the ip address of your ipad/android and the port it should be
    //set to receive on
    
	receiver.setup(8001);
    //this is the port you're game will receive data on. For us this is the important one! Set your mobile device to send on this port.
    
    m.setAddress("/game");
    //this is OSC's URL like naming convention. You can use a root url address like structure and then everything under that address will be accessable by that message. It's very similar to a folder path on your hard drive. You can think of the game folder as your root directory and all the bits that are /game/someOtherName are inside of it.
}
void LiveTesting::setup()
{
    
}
void LiveTesting::update()
{
    while (receiver.hasWaitingMessages()) {
        
        //get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        //parse the message 
       
        ofxOscMessage sendBack;
               
        if(m.getAddress() == "/game/max_enemy_amplitude")
        {
            max_enemy_amplitude = m.getArgAsFloat(0);
            
            //these values send back to OSC to display the current settings for visual feedback
            sendBack.addFloatArg(max_enemy_amplitude);
            sendBack.setAddress("/updatedVals/max_enemy_amplitude");
            sender.sendMessage(sendBack);
            
            cout << max_enemy_amplitude << endl;
        }
        
        else if (m.getAddress() == "/game/interval_time")
        {
            interval_time = m.getArgAsInt32(0);
            
            //send visual feedback
            sendBack.addIntArg(interval_time);
            sendBack.setAddress("/updatedVals/interval");
            sender.sendMessage(sendBack);
        }
        else if (m.getAddress() == "/game/max_enemy_shoot_interval")
        {
            max_enemy_shoot_interval = m.getArgAsFloat(0);
            
            //send visual feedback
            sendBack.addFloatArg(max_enemy_shoot_interval);
            sendBack.setAddress("/updatedVals/max_enemy_shoot_interval");
            sender.sendMessage(sendBack);

        }
        else if (m.getAddress() == "/game/triggerBonus")
        {
            triggerBonus = m.getArgAsInt32(0);
            cout << triggerBonus << endl;
            //send visual feedback
            sendBack.addIntArg(triggerBonus);
            sendBack.setAddress("/updatedVals/triggerBouns");
            sender.sendMessage(sendBack);

            
        }
    }
    
}


