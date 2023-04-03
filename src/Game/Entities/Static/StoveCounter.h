#include "BaseCounter.h"

class StoveCounter: public BaseCounter {
    private:
        Item *cookedItem;
        Item *rawItem;
        // cookingProgress = 100 when it is done
        int cookingProgress = 0;
        int ticksToCook = 1;
        bool isCooking = false;
        // when isCooked == true, the item is set to cookedItem, otherwise it is set to rawItem
        bool isCooked = false;

    public:
        StoveCounter(int x, int y, int width, int height, Item* rawItem, Item* cookedItem, ofImage sprite);
        Item* getItem();
        void interact();
        void reset();
        void tick();
};