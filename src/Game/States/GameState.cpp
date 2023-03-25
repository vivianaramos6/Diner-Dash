#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick();

	// Checking if enought clients have left in order to trigger the loose state
	if(restaurant->getClientsThatLeft() >= clientsLeavingToLoose) {
		setFinished(true);
		setNextState("Loose");
	}

	// Checking if the player has reached the money goal to win
	if(restaurant->getMoney() >= moneyGoal) {
		setFinished(true);
		setNextState("Win");
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

void GameState::reset(){
	// Resetting restaurant
	delete this->restaurant;
	this->restaurant = new Restaurant();
	
	setFinished(false);
	setNextState("");
}