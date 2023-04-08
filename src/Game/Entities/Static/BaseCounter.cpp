//
// Created by joshu on 11/3/2020.
//

#include "BaseCounter.h"

BaseCounter::BaseCounter(int x, int y, int width, int height,Item* item, ofImage sprite, ofSoundPlayer *sound)
 : Entity(x, y, width, height, sprite), item(item), sound(sound) { }

Item* BaseCounter::getItem(){
    playSound();
    return item;
}

void BaseCounter::playSound() {
    if(sound != nullptr) sound->play();
}

void BaseCounter::interact() { }

void BaseCounter::setItem(Item* item){
    this->item = item;
}

void BaseCounter::showItem(){
    if (item != nullptr){
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}

void BaseCounter::setSprite(ofImage sprite) {
    Entity::setSprite(sprite);
}
