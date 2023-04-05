#include "GameData.h"

void GameData::addGameStats(Stats stats) {
    allStats.push_back(stats);

    // Updating game data
    totalBurgersServed += stats.burgersServed;
    gamesPlayed++;
    if(stats.won) { gamesWon++; }
    else { gamesLost++; }
}