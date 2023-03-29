//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        std::vector<ofImage> people;
        int money =0;
        int clientsThatLeft = 0;

    public:
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        Item* itemOptions[4];
        ofImage floor;
        ofImage chairsandtable;
        ofImage BlueArcade;
        ofImage RedArcade;
        ofImage pottedplant;
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        ofTrueTypeFont pressStart;
        




        // Getters and setters
        int getClientsThatLeft() { return clientsThatLeft; }
        void setClientsThatLeft(int left) { clientsThatLeft = left; }
        int getMoney() { return money; }
};
