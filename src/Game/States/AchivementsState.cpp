#include "AchivementsState.h"

AchivementsState::AchivementsState(GameData *gameData) : State(gameData), header("Achivements") {
	// Menu button
	string menuTxt = "Menu";
	menuButton = new Button(15, 15, 100, 50, menuTxt, 12, 255, ofColor::grey);
	
	header.setButton(menuButton);

	// Generating achivements
	ofImage *acImg1 = new ofImage("images/achivements/bl.png");
	ofImage *acImg2 = new ofImage("images/achivements/nrfe.png");
	ofImage *acImg3 = new ofImage("images/achivements/ftw.png");
	ofImage *acImg4 = new ofImage("images/achivements/asf.png");

	achivements.push_back(Achivement("Beginner's Luck", acImg1, "Win your first game." ));
	achivements.push_back(Achivement("No Room for Error", acImg2, "Win a game with 0 undos and 0 wasted burgers." ));
	achivements.push_back(Achivement("Full-Time Worker", acImg3, "Play the game for 8 minutes" ));
	achivements.push_back(Achivement("All Star Chef", acImg4, "Serve 30 burgers." ));
}

void AchivementsState::tick() {
	menuButton->tick();
	if(menuButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}
void AchivementsState::render() {
	ofSetBackgroundColor(100);
	header.render();

	for(int i = 0; i < achivements.size(); i++) {
		Achivement achivement = achivements[i];
		achivement.getIcon()->draw(100, 100 * i + 200, 50, 50);
	}

}

void AchivementsState::keyPressed(int key){
	
}

bool AchivementsState::mousePressed(int x, int y, int button){
	return menuButton->mousePressed(x, y);
}

void AchivementsState::reset(){
	setFinished(false);
	setNextState("");
	menuButton->reset();
}