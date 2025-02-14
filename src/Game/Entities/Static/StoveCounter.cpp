#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item* rawItem, Item* cookedItem, ofImage sprite, ofImage activeSprite, ofSoundPlayer *sound, ofSoundPlayer *interactSound) 
: BaseCounter(x, y, width, height, rawItem, sprite, sound), 
cookedItem(cookedItem), rawItem(rawItem), sprite(sprite), activeSprite(activeSprite), interactSound(interactSound) {}

Item* StoveCounter::getItem() {
    // When isCooked == false, it returns a nullptr, causing the player to call the interact method
    if(!isCooked) return nullptr;

    // When finished cooking, it returns the item and resets the counter
    reset();
    playSound();
    return cookedItem;
}

// Called when there is no cooked burger and the player clicks e
void StoveCounter::interact() {
    if(isCooking) return;
    isCooking = true;
    setSprite(activeSprite);
    playInteractSound();
}

void StoveCounter::playInteractSound() {
    if(interactSound != nullptr) interactSound->play();
}

void StoveCounter::tick() {
    ticks++;
    // Increasing cooking progress every certian amount of ticks
    if(isCooking && ticks % ticksToCook == 0)
        cookingProgress++;

    if(isCooking && cookingProgress == 100) {
        setItem(cookedItem);
        setSprite(sprite);
        isCooking = false;
        isCooked = true;
    }
}

void StoveCounter::render() {
    Entity::render();

    // Drawing progress bar while cooking
    
    // Background
    ofSetColor(100);
    ofDrawRectRounded(x, y + height - progressBarH * 2, width, progressBarH, 1);

    // Progress
    ofSetColor(isCooked? completeColor : progressingColor);
    ofDrawRectRounded(x, y + height - progressBarH * 2, width / 100.0 * cookingProgress, progressBarH, 1);
}

void StoveCounter::reset() {
    cookingProgress = 0;
    setItem(rawItem);
    setSprite(sprite);
    isCooking = false;
    isCooked = false;
}