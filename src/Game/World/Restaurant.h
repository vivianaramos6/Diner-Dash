//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "StoveCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"
#include "GameFont.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        std::vector<ofImage> people;
        int clientsThatLeft = 0;
        int ingredientsUsed = 0;
        int burgersServed = 0;
        int burgersWasted = 0;
        int undos = 0;
        int money = 0;

    public:
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* rawBurger;
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
        GameFont gameFont10px;
        




        // Getters and setters
        void setClientsThatLeft(int left) { clientsThatLeft = left; }

        int getClientsThatLeft() { return clientsThatLeft; }
        int getIngredientsUsed() { return ingredientsUsed; }
        int getBurgersServed() { return burgersServed; }
        int getBurgersWasted() { return burgersWasted; }
        int getUndos() { return undos; }
        int getMoney() { return money; }
};
