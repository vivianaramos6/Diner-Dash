//
// Created by joshu on 11/3/2020.
//

#pragma once

#include "Item.h"
#include "Entity.h"

class BaseCounter: public Entity {
    private:
        Item *item;
        ofSoundPlayer *sound;

    public:
        BaseCounter(int x, int y, int width, int height, Item* item, ofImage sprite, ofSoundPlayer *sound = nullptr);
        virtual Item* getItem();
        void setItem(Item* item);
        virtual void interact();
        void showItem();
        void playSound();
        void setSprite(ofImage sprite);
};
