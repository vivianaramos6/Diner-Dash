// Each instance of Stats represent the stats for only one game/round once finished
#pragma once
#include "ofMain.h"
#include "GameFont.h"
class Stats {
    private:
        // These two fonts are used in the draw method
        GameFont gameFont10px;
        GameFont gameFont14px;

        int startTime_ms;
        int endTime_ms;
        int elapsedTime_ms;

    public:
        bool won;
        int ingredientsUsed = 0;
        int clientsThatLeft = 0;
        int burgersServed = 0;
        int burgersWasted = 0;
        int money = 0;
        int undos = 0;
        void draw(); // Used in winstate and loosestate
        Stats();
        
        // Getters and Setters
        void endTime();
        void startTime();
        string getElapsedTime();
};