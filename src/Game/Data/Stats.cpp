#include "Stats.h"

Stats::Stats() {
    gameFont14px = GameFont(14);
}

void Stats::draw() {
    gameFont14px.draw("Stats", 10, 585);

    gameFont10px.draw("Money: " + to_string(money), 10, 620);
    gameFont10px.draw("Undos: " + to_string(undos), 10, 645);
    gameFont10px.draw("Elapsed time: " + to_string(elapsedTime), 10, 670);
    gameFont10px.draw("Burgers served: " + to_string(burgersServed), 10, 695);
    gameFont10px.draw("Burgers wasted: " + to_string(burgersWasted), 10, 720);
    gameFont10px.draw("Ingredients used: " + to_string(ingredientsUsed), 10, 745);
    gameFont10px.draw("Clients that left: " + to_string(clientsThatLeft), 10, 770);
}