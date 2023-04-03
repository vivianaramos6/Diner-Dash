#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, 
Item* rawItem, Item* cookedItem, ofImage sprite) 
: BaseCounter(x, y, width, height, rawItem, sprite) {
    this->cookedItem = cookedItem;
    this->rawItem = rawItem;
}

Item* StoveCounter::getItem() {
    // When isCooked == false, it returns a nullptr, causing the player to call the interact method
    if(!isCooked) return nullptr;

    // When finished cooking, it returns the item and resets the counter
    reset();
    return cookedItem;
}

// Called when there is no cooked burger and the player clicks e
void StoveCounter::interact() {
    isCooking = true;
}

void StoveCounter::tick() {
    ticks++;
    // Increasing cooking progress every certian amount of ticks
    if(isCooking && ticks % 2 == 0) {
        cookingProgress++;
    }

    if(cookingProgress == 100) {
        setItem(cookedItem);
        isCooking = false;
        isCooked = true;
    }
}

void StoveCounter::reset() {
    cookingProgress = 0;
    setItem(rawItem);
    isCooking = false;
    isCooked = false;
}