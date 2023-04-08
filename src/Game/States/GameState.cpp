#include "GameState.h"

GameState::GameState(GameData *gameData) : State(gameData) {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick();

	// Checking if enought clients have left in order to trigger the loose state
	if(restaurant->getClientsThatLeft() >= clientsLeavingToLoose) {
		stats.won = false;
		setFinished(true);
		setNextState("Loose");
	}

	// Checking if the player has reached the money goal to win
	if(restaurant->getMoney() >= moneyGoal) {
		stats.won = true;
		setFinished(true);
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
	}
}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::startTimer() {
	stats.startTime();
}

void GameState::reset(){
	// Resetting restaurant
	delete this->restaurant;
	this->restaurant = new Restaurant();
	
	setFinished(false);
	setNextState("");
}