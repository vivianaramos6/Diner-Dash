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
        int ingredientsUsed = 0;
        int burgersServed = 0;
        int burgersWasted = 0;
        int undos = 0;
        int money = 0;

        ofSoundPlayer stoveOnSound;
        ofSoundPlayer pickIngredientSound;
        ofSoundPlayer serveClientSound;
        ofSoundPlayer clientLeftSound;
        GameFont gameFont10px;

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
        ofImage moneysign;
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        




        // Getters and setters
        int getClientsThatLeft() { return entityManager->getClientsThatLeft(); }
        int getIngredientsUsed() { return ingredientsUsed; }
        int getBurgersServed() { return burgersServed; }
        int getBurgersWasted() { return burgersWasted; }
        int getUndos() { return undos; }
        int getMoney() { return money; }
};
