#include "StatsState.h"

StatsState::StatsState(GameData *gameData) : State(gameData), header("Stats") {
	// Menu button
	string menuTxt = "Menu";
	menuButton = new Button(15, 15, 100, 50, menuTxt, 12, 255, ofColor::grey);
	
	header.setButton(menuButton);
}

void StatsState::tick() {
	menuButton->tick();
	if(menuButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}

void StatsState::renderAllTimeStats() {
	gameFont14px.draw("All Time Stats", 20, 150);
	gameFont10px.draw("Games played:" + to_string(gameData->getGamesPlayed()), 20, 185);
	gameFont10px.draw("Games won:" + to_string(gameData->getGamesWon()), 20, 210);
	gameFont10px.draw("Games lost:" + to_string(gameData->getGamesLost()), 20, 235);
	gameFont10px.draw("Burger served:" + to_string(gameData->getBurgersServed()), 20, 260);
	gameFont10px.draw("Money made: $" + to_string(gameData->getTotalMoney()), 20, 285);
	gameFont10px.draw("Time played: " + Stats::getTimePlayed(gameData->getTimePlayed()), 20, 310);
}

void StatsState::render() {
	ofSetBackgroundColor(100);
	header.render();
	renderAllTimeStats();
}

void StatsState::keyPressed(int key){
	
}

void StatsState::mousePressed(int x, int y, int button){
	menuButton->mousePressed(x, y);
}

void StatsState::reset(){
	setFinished(false);
	setNextState("");
	menuButton->reset();
}