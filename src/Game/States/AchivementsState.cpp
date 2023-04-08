#include "AchivementsState.h"

AchivementsState::AchivementsState(GameData *gameData) : State(gameData), header("Achivements") {
	menuButton = new Button(15, 15, 100, 50, "Menu", 12, 255, ofColor::grey);
	
	header.setButton(menuButton);

	// Loading the icons for all the achivements
	ofImage *acImg1 = new ofImage("images/achivements/bl.png");
	ofImage *acImg2 = new ofImage("images/achivements/nrfe.png");
	ofImage *acImg3 = new ofImage("images/achivements/ftw.png");
	ofImage *acImg4 = new ofImage("images/achivements/asf.png");

	// Generating all achivements, including a lambda function specifying
	// the logic to be used to track their progression based on the stats provided
	achivements.push_back(Achivement("Beginner's Luck", acImg1, "Win your first game.", 1, 
	[](Achivement *achivement, Stats &stats){
		if(stats.won) achivement->addToProgress(1);
	}));
	achivements.push_back(Achivement("All-Star Chef", acImg4, "Serve 30 burgers.", 30, 
	[](Achivement *achivement, Stats &stats){
		achivement->addToProgress(stats.burgersServed);
	}));
	achivements.push_back(Achivement("Full-Time Worker", acImg3, "Play the game for 8 minutes.", 480000, 
	[](Achivement *achivement, Stats &stats){
		achivement->addToProgress(stats.getElapsedTimeMillisecs());
	}, 60000));
	achivements.push_back(Achivement("No Room for Error", acImg2, "Win a game with no undos, no \nwasted burgers, and no \nclients that left.", 1, 
	[](Achivement *achivement, Stats &stats){
		if(stats.won && stats.undos == 0 && stats.burgersWasted == 0 && stats.clientsThatLeft == 0) achivement->addToProgress(1);
	}));
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

	// Iterating through all achivements and showing them
	for(int i = 0; i < achivements.size(); i++) {
		Achivement achivement = achivements[i];

		int width = 500;
		int height = 125;

		int xPos = ofGetViewportWidth() / 2 - width / 2;
		int yPos = 150 * i + 150;

		// Drawing box shadow
		ofSetColor(15);
		ofDrawRectRounded(xPos+5, yPos+8, width, height, 10);

		// Drawing box
		ofSetColor(ofColor::antiqueWhite);
		ofDrawRectRounded(xPos, yPos, width, height, 10);

		// Drawing icon
		achivement.getIcon()->draw(xPos + 10, yPos + 10, 50, 55);

		// Drawing achivement contents
		ofSetColor(0);
		gameFont14px.draw(achivement.getName(), xPos + 70, yPos + 35);
		gameFont10px.draw(achivement.getDesc(), xPos + 70, yPos + 65);
		
		// Drawing progress
		string progression = achivement.getProgression();
		gameFont10px.draw(progression, xPos + width - (progression.size() * 17), yPos + height - 5);

		// Drawing completion state
		if(achivement.isComplete()) {
			ofSetColor(255);
			checkmark.draw(xPos + width - 35, yPos - 17, 50, 50);
		}else {
			ofSetColor(ofColor::darkRed);
			gameFont10px.draw("Not yet completed", xPos + 70, yPos + height - 5);
		}
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