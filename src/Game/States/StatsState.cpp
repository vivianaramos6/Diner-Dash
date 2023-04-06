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
void StatsState::render() {
	header.render();
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