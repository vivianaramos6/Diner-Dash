#include "GameData.h"

void GameData::addGameStats(Stats stats) {
    allStats.push_back(stats);

    // Updating game data
    totalBurgersServed += stats.burgersServed;
    timePlayed += stats.getElapsedTimeMillisecs();
    totalMoney += stats.money;
    gamesPlayed++;
    if(stats.won) { gamesWon++; }
    else { gamesLost++; }
}

Stats* GameData::getLastStats() {
    if(allStats.size() == 0) return new Stats();
    return &allStats[allStats.size() - 1];
}