#pragma once
#include "Stats.h"
#include "Achivement.h"
#include <vector>
#include <unordered_map>

using namespace std;

class GameData {
    private:
        vector<Stats> allStats;
        vector<Achivement*> achivements;
        int totalBurgersServed = 0;
        int gamesPlayed = 0;
        int gamesLost = 0;
        int gamesWon = 0;

    public:
    // Getters
        vector<Stats> getAllStats() { return allStats; }
        vector<Achivement*> getAchivements() { return achivements; }
        int getBurgersServed() { return totalBurgersServed; }
        int getGamesPlayed() { return gamesPlayed; }
        int getGamesLost() { return gamesLost; }
        int getGamesWon() { return gamesWon; }
        Stats* getLastStats();

    // Methods
        void addGameStats(Stats stats);
};