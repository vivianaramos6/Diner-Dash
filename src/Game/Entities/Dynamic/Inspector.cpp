#include "Inspector.h"

Inspector::Inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger, int *money_p, ofSoundPlayer *leavingSound)
: Client(x, y, width, height, sprite, burger, leavingSound), money_p(money_p) {}

void Inspector::tick(){
    Client::tick();

    if(isLeaving)
        *money_p /= (*money_p < 0? 0.5 : 2);
}