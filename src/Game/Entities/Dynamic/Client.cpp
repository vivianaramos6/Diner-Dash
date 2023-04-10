#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger, ofSoundPlayer *leavingSound) 
: Entity(x, y, width, height, sprite), burger(burger), leavingSound(leavingSound) { }

Client::~Client(){
    delete burger;
}

void Client::render(){
    burger->render();

    // Setting making the color of the client redder as they loose patience
    int patienceToColor = 255 / 2000. * patience;
    ofSetColor(255,patienceToColor,patienceToColor);

    sprite.draw(x, y, width, height);

    ofSetColor(255);

    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience <= 0){
        if(leavingSound != nullptr) leavingSound->play();
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
    // Client leaves and burger is disposed of when the burger served equals the client's
    if(burger->equals(this->burger)) {
        isLeaving = true;
        burger->clear();
        return this->burger->getprice();
    }

    // Checking if there is more clients and running serve on them
    if(nextClient != nullptr)
        return nextClient->serve(burger);

    // adding $0 and disposing burger when no burger is served
    burger->clear();
    return 0;
}