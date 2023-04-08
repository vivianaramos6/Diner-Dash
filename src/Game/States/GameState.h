#include "State.h"
#include "Restaurant.h"

class GameState: public State{
    public: 
        GameState(GameData *gameData);
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		void startTimer();
	
	private:
		int clientsLeavingToLoose = 10;
		int moneyGoal = 100;
		Stats stats;

		Restaurant *restaurant;
};