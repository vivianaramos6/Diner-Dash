#include "EntityManager.h"

void EntityManager::tick(){
    for(unsigned int i=0; i<entities.size(); i++){
        entities[i]->tick();
    }
    if(firstClient != nullptr){
        firstClient->tick();
    }
    removeLeavingClients();
}

void EntityManager::removeClients(bool onlyLeavingClients) {
    // Remove all clients that are leaving
    Client* tempClient = firstClient;
    Client* prevClient = nullptr;
    
    while(tempClient != nullptr){
        // will remove client if it is either leaving or if onlyLeavingClients is false
        // this means that when onlyLeavingClients is false, all clients will be removed
        if(tempClient->isLeaving || !onlyLeavingClients){
            // Checking if client left with a patience of 0 to increment clientsLeft
            if(tempClient->getPatience() == 0) clientLeft();

            if(prevClient == nullptr){
                firstClient = tempClient->nextClient;
                delete tempClient;
                tempClient = firstClient;
            }else{
                prevClient->nextClient = tempClient->nextClient;
                delete tempClient;
                tempClient = prevClient->nextClient;
            }
        }else{
            prevClient = tempClient;
            tempClient = tempClient->nextClient;
        }
    }
}

void EntityManager::removeLeavingClients(){
    // the true parameter makes it so that it only removes the clients that are leaving
    removeClients(true);
}

void EntityManager::resetClients(){
    removeClients();
    clientsThatLeft = 0;
}

void EntityManager::resetStoves() {
    // Iterating through all entities
    for(Entity *entity : entities) {

        // Casting entity into stove counter to checkk if it is a stove
        StoveCounter *stove = dynamic_cast<StoveCounter*>(entity);
        if(stove != nullptr) stove->reset();
    }
}

void EntityManager::render(){
    for(unsigned int i=0; i<entities.size(); i++){
        entities[i]->render();
    }
    if(firstClient != nullptr){
        firstClient->render();
    }
}

void EntityManager::addEntity(Entity *e){
    entities.push_back(e);
}

void EntityManager::addClient(Client* c){
    if(firstClient == nullptr){
        firstClient = c;
    }else{
        Client* tempClient = firstClient;
        tempClient->setY(tempClient->getY()+72);
        while(tempClient->nextClient!=nullptr){
            tempClient = tempClient->nextClient;
            tempClient->setY(tempClient->getY()+72);

        }
        tempClient->nextClient = c;
    }
}