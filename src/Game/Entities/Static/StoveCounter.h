#include "BaseCounter.h"

class StoveCounter: public BaseCounter {
    private:
        Item *cookedItem;
        Item *rawItem;
        // cookingProgress = 100 when it is done
        int cookingProgress = 0;
        int ticksToCook = 2;
        bool isCooking = false;
        // when isCooked == true, the item is set to cookedItem, otherwise it is set to rawItem
        bool isCooked = false;
        int progressBarH = 10;
        ofColor completeColor = ofColor(21, 136, 255);
        ofColor progressingColor = ofColor(255);
        ofImage activeSprite;
        ofImage sprite;
        ofSoundPlayer *interactSound;

    public:
        StoveCounter(int x, int y, int width, int height, Item* rawItem, Item* cookedItem, ofImage sprite, ofImage activeSprite, ofSoundPlayer *sound, ofSoundPlayer *interactSound);
        void playInteractSound();
        Item* getItem();
        void interact();
        void render();
        void reset();
        void tick();
};