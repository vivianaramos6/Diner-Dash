#pragma once
#include "Client.h"

class Inspector : public Client {
    private:
        int *money_p;

    public:
        Inspector(int x, int y , int width, int height, ofImage sprite, Burger* burger, int *money_p, ofSoundPlayer *leavingSound = nullptr);
        void tick();
        void serve();
};