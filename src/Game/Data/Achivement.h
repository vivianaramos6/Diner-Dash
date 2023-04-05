#pragma once
#include <string>
#include "ofMain.h"
using namespace std;

class Achivement {
    private:
        // progress and goal are for achivements that can be worked up to progressively
        // progressible indicates wether the achivement can be worked uo to progressively
        string name;
        ofImage icon;
        string desc;
        bool completed = false;
        int progress = 0;
        int goal = 0;
        bool progressible;
        bool seen = false; // When completed = true and seen = false, it notifies the player
    
    public:
        Achivement(string name, ofImage icon, string desc, bool progressible = false) 
        : name(name), icon(icon), desc(desc), progressible(progressible) {}

        // Setters
        void complete() { completed = true; }
        void see() { seen = true; }
        void addToProgress(int n) {
            progress += n;
            if(progress > goal) complete();
        }

        // Getters
        string getName() { return name; }
        ofImage getIcon() { return icon; }
        bool isComplete() { return completed; }
        int getProgress() { return progress; }
        int getGoal() { return goal; }
        bool isProgressible() { return progressible; }
};