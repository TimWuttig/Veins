//
// Copyright (C) 2006-2011 Christoph Sommer <christoph.sommer@uibk.ac.at>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "veins/modules/application/ieee80211p/SimpleWaveApp.h"

using Veins::AnnotationManagerAccess;

Define_Module(SimpleWaveApp);

void SimpleWaveApp::initialize(int stage) {
    BaseWaveApplLayer::initialize(stage);
    if (stage == 0) {
        mobi = dynamic_cast<LinearMobility*> (getParentModule()->getSubmodule("mobility"));
        ASSERT(mobi);
    }

    // set random offset to reduce collisions
    someOffset = dblrand() * 0.01;
}

//function will be called when beacon packet has been received
void SimpleWaveApp::onBSM(DemoSafetyMessage* bsm) {
    EV << bsm->getSenderID();
    EV << bsm->getRecipientAddress();
    EV << endl;

    int id = getParentModule()->getSubmodule("nic")->getId();
    int senderId = bsm->getSenderID();

    if(bsm->getRecipientAddress() == id){
        EV<< "Record delay" << endl;
        simtime_t delay = simTime() - bsm->getTimestamp();
        delayVector.record(delay);
    }else {
        if(bsm->getRecipientAddress() == -1){


           //send new message if senderId = 0
           if(senderId == 0){
               neighbourVector.record(neighbours.size());

               //check current neighbours
               simtime_t now = simTime();
               std::map<int, Neighbour>::iterator iterator;
               iterator = neighbours.begin();
               while(iterator != neighbours.end()){
                   if((now - iterator->second.last_recieve) > 5) {
                       iterator = neighbours.erase(iterator);
                   }else {
                       iterator++;
                   }
               }

               //send message with position
               EV << "sending message" << endl;
               DemoSafetyMessage* msg = new DemoSafetyMessage();
               prepareWSM(msg, beaconLengthBits, ChannelType::control, beaconPriority, -1, 2);
               msg->setSenderID(getParentModule()->getSubmodule("nic")->getId());
               msg->setSenderSpeed(curSpeed);
               msg->setSenderPos(curPosition);
               sendBSM(msg);
           }else{
               Neighbour n;
               n.last_recieve = simTime();
               n.position = bsm->getSenderPos();
               n.speed = bsm->getSenderSpeed();
               neighbours[bsm->getSenderID()] = n;


                //reply on message
                /*BaseFrame1609_4 *response = new BaseFrame1609_4();
                prepareWSM(response, bsm->getBitLength(), ChannelType::control, bsm->getUserPriority(), senderId, 2);
                response->setSenderID(id);
                sendWSM(response);*/
           }
        }
    }
    std::cerr << "Received Beacon" << std::endl;
}

//function will be called when data packet has been received
void SimpleWaveApp::onWSM(BaseFrame1609_4* wsm) {
    findHost()->getDisplayString().updateWith("r=16,green");
    EV<< "Record delay" << endl;
    simtime_t delay = simTime() - wsm->getTimestamp();
    delayVector.record(delay);
}

//function will be called when node has been moved. see parent class how to access a node's position
void SimpleWaveApp::handlePositionUpdate(cObject* obj) {
    BaseWaveApplLayer::handlePositionUpdate(obj);
}

void SimpleWaveApp::sendWSM(BaseFrame1609_4* wsm) {
    sendDelayedDown(wsm,someOffset);
}

void SimpleWaveApp::sendBSM(DemoSafetyMessage* bsm) {
    sendDelayedDown(bsm,someOffset);
}
