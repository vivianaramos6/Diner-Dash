// Each instance of Stats represent the stats for only one game/round once finished

struct Stats {
    bool won;
    int money;
    int ingredientsUsed;
    int clientsThatLeft;
    int elapsedTime;
    int burgersServed;
    int burgersWasted;
    int undos;
};