#include "Entity.h"
#include "Burger.h"
class Client: public Entity{
    private:
        Burger* burger;
        ofSoundPlayer *leavingSound;
        int patience=1375;

    public:
        Client(int, int, int, int, ofImage, Burger*, ofSoundPlayer *leaveSound = nullptr);
        virtual ~Client();
        void tick();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;

        // Getters and setters
        int getPatience() { return patience; }
};