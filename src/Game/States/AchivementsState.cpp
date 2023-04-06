#include "AchivementsState.h"

AchivementsState::AchivementsState(GameData *gameData) : State(gameData), header("Achivements") {
	// Menu button
	string menuTxt = "Menu";
	menuButton = new Button(15, 15, 100, 50, menuTxt, 12, 255, ofColor::grey);
	
	header.setButton(menuButton);
}

void AchivementsState::tick() {
	menuButton->tick();
	if(menuButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}
void AchivementsState::render() {
	header.render();
}

void AchivementsState::keyPressed(int key){
	
}

void AchivementsState::mousePressed(int x, int y, int button){
	menuButton->mousePressed(x, y);
}

void AchivementsState::reset(){
	setFinished(false);
	setNextState("");
	menuButton->reset();
}