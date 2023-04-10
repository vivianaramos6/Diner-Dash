
#pragma once
#include "Entity.h"
#include "Burger.h"
class Client: public Entity{
    protected:
        Burger* burger;
        ofSoundPlayer *leavingSound;
        int patience=1375;

    public:
        Client(int, int, int, int, ofImage, Burger*, ofSoundPlayer *leavingSound = nullptr);
        virtual ~Client();
        void tick();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;

        // Getters and setters
        int getPatience() { return patience; }
};