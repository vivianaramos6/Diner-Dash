#include "GameState.h"

GameState::GameState(GameData *gameData, vector<Achivement> *achivements_p) 
: State(gameData), achivements_p(achivements_p) {
    this->restaurant = new Restaurant();

	gameOverSound.load("sounds/game-over.mp3");
	gameWonSound.load("sounds/game-won.wav");
}
void GameState::tick() {
	restaurant->tick();

	// Checking if enought clients have left in order to trigger the loose state
	if(restaurant->getClientsThatLeft() >= clientsLeavingToLoose) {
		stats.won = false;
		setFinished(true);
		gameOverSound.play();
		setNextState("Loose");
	}

	// Checking if the player has reached the money goal to win
	if(restaurant->getMoney() >= moneyGoal) {
		stats.won = true;
		setFinished(true);
		gameWonSound.play();
		setNextState("Win");
	}

	// Adding game stats when game ends
	if(hasFinished()) {
		stats.money = restaurant->getMoney();
		stats.clientsThatLeft = restaurant->getClientsThatLeft();
		stats.ingredientsUsed = restaurant->getIngredientsUsed();
		stats.burgersServed = restaurant->getBurgersServed();
		stats.burgersWasted = restaurant->getBurgersWasted();
		stats.undos = restaurant->getUndos();
		stats.endTime();

		gameData->addGameStats(stats);

		// Iterating through all the achivements and providing them with the latest stats
		// in order to update their progression
		for(Achivement &achivement : *achivements_p) {
			achivement.update(stats);
		}
	}
}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

bool GameState::mousePressed(int x, int y, int button) {
	return false;
}

void GameState::keyReleased(int key){
	restaurant->keyReleased(key);
}

void GameState::startTimer() {
	stats.startTime();
}

void GameState::reset(){
	// Resetting restaurant
	this->restaurant->reset();
	
	setFinished(false);
	setNextState("");
}