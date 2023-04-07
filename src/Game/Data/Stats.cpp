#include "Stats.h"

Stats::Stats() {
    gameFont14px = GameFont(14);
}

string Stats::getTimePlayed(int milliseconds, bool shorten) {
    int totalSeconds = round(milliseconds / 1000.0);
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    if(shorten) {
        return to_string(minutes) + "m & " + to_string(seconds) + "s";
    }

    return to_string(minutes) + 
    (minutes == 1? " minute" : " minutes") + // uses "minute" insted of "minutes" if minutes == 1 
    " and " + to_string(seconds) + " seconds";
}

string Stats::getElapsedTimeString() {
    return getTimePlayed(elapsedTime_ms);
}

string Stats::getElapsedTimeStringShortened() {
    return getTimePlayed(elapsedTime_ms, true);
}

void Stats::startTime() {
    startTime_ms = ofGetElapsedTimeMillis();
}

void Stats::endTime() {
    endTime_ms = ofGetElapsedTimeMillis();
    elapsedTime_ms = endTime_ms - startTime_ms;
}

void Stats::draw() {
    gameFont14px.draw("Stats", 10, 585);

    gameFont10px.draw("Money: " + to_string(money), 10, 620);
    gameFont10px.draw("Undos: " + to_string(undos), 10, 645);
    gameFont10px.draw("Burgers served: " + to_string(burgersServed), 10, 670);
    gameFont10px.draw("Burgers wasted: " + to_string(burgersWasted), 10, 695);
    gameFont10px.draw("Ingredients used: " + to_string(ingredientsUsed), 10, 720);
    gameFont10px.draw("Clients that left: " + to_string(clientsThatLeft), 10, 745);
    gameFont10px.draw("Elapsed time: " + getElapsedTimeString(), 10, 770);
}