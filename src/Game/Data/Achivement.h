#pragma once
#include <string>
#include "ofMain.h"
using namespace std;

class Achivement {
    private:

        // The parameter "callback" contains the logic that determines the progress of the achivement.
        // It is called whenever a game is finished
        function<void(Achivement *achivement, Stats &stats)> callback;

        // displayProgressDivisor is divided to both the goal and the progress when calling getProgression()
        // An example of when this is useful is when the progress is collected in millisecond but you want
        // to display it in seconds. In that case, the divisor should be set to 1000.
        int displayProgressDivisor = 1;

        // progress and goal are for achivements that can be worked up to progressively
        string name;
        ofImage *icon;
        string desc;
        int goal = 0;
        bool completed = false;
        int progress = 0;
    
    public:
        Achivement(
            string name, ofImage *icon, string desc, int goal, 
            function<void(Achivement *achivement, Stats &stats)> callback,
            int displayProgressDivisor = 1
        ) 
        : callback(callback), displayProgressDivisor(displayProgressDivisor), name(name), icon(icon), desc(desc), goal(goal) {}

        // Setters
        void complete() { completed = true; }
        void addToProgress(int n) {
            progress += n;
            if(progress >= goal) complete();
        }

        // Getters
        string getProgression() {
            return to_string(goal / displayProgressDivisor) + "/" + 
            to_string(progress / displayProgressDivisor);
        }
        string getName() { return name; }
        string getDesc() { return desc; }
        ofImage* getIcon() { return icon; }
        bool isComplete() { return completed; }
        int getProgress() { return progress; }
        int getGoal() { return goal; }

        // Methods
        void update(Stats &stats) { callback(this, stats); }
};