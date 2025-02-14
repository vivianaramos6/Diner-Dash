#include "State.h"
#include "Restaurant.h"

class GameState: public State{
    public: 
        GameState(GameData *gameData, vector<Achivement> *achivements_p);
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		bool mousePressed(int x, int y, int button);
		void keyReleased(int key);
		void startTimer();
	
	private:
		vector<Achivement> *achivements_p;
		int clientsLeavingToLoose = 10;
		ofSoundPlayer gameOverSound;
		ofSoundPlayer gameWonSound;
		int moneyGoal = 100;
		Stats stats;

		Restaurant *restaurant;
};