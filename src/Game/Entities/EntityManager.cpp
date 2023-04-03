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

void EntityManager::removeLeavingClients(){

    // Remove all clients that are leaving
    Client* tempClient = firstClient;
    Client* prevClient = nullptr;
    
    while(tempClient != nullptr){
        if(tempClient->isLeaving){
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