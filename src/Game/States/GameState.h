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
	
	private:
		int clientsLeavingToLoose = 10;
		int moneyGoal = 100;

		Restaurant *restaurant;
};