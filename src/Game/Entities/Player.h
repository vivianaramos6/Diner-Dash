#pragma once
#include "Animation.h"
#include "Burger.h"
#include "EntityManager.h"
#include "BaseCounter.h"
class Player: public Entity{

    private:
        int speed = 5;
        int *ingredientsUsed_p;
        int *money_p;
        int *undos_p;
        ofSoundPlayer *incorrectSound_p;
        bool movingLeft = false;
        bool movingRight = false;
        string facing = "right";
        Animation *chefAnim;
        Burger *burger;
        EntityManager* entityManager;
    
    public:
        Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em, int *money_p, int *undos_p, int *ingredientsUsed_p, ofSoundPlayer *incorrectSound_p);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void mousePressed(int, int, int);
        void setFacing(string);
        void reset();
        BaseCounter* getActiveCounter();
        Burger* getBurger(){ return burger; }
       
};