#include "MenuState.h"

MenuState::MenuState(GameData *gameData) : State(gameData), title(GameFont(titleSize)) {
	burgerbg.load("images/pixelburger.png");

	// Start button
	string startTxt = "Start";
	startButton = new Button(ofGetWidth()/2 - 150, 450, 300, 100, startTxt, 16, 255, ofColor::orange);

	// Stats button
	string statsTxt = "Stats";
	statsButton = new Button(ofGetWidth()/2 - 150, 575, 300, 80, statsTxt, 16, 255, ofColor(145));


	// Achivements button
	string achivementsTxt = "Achivements";
	achivementsButton = new Button(ofGetWidth()/2 - 150, 675 , 300, 80, achivementsTxt, 16, 255, ofColor(145));

}
void MenuState::tick() {
	startButton->tick();
	statsButton->tick();
	achivementsButton->tick();

	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}

	if(statsButton->wasPressed()){
		setNextState("Stats");
		setFinished(true);
	}

	if(achivementsButton->wasPressed()){
		setNextState("Achivements");
		setFinished(true);
	}
}
void MenuState::render() {
	ofSetColor(255);
	burgerbg.draw(0,0,850,850);
	
	startButton->render();
	statsButton->render();
	achivementsButton->render();

	// Game title
	string titleStr = "DINER DASH";
	string titleStrBottom = "ARCADE";

	title.draw(titleStr, ofGetViewportWidth() / 2 - titleStr.length() * titleSize * 0.65, ofGetViewportHeight() / 3);

	// "ARCADE" shadow
	ofSetColor(18, 25, 89);

	// drawing the shadow multiple times slightly below each other to mimic 3d effect
	for(int i = 0; i < 10; i++) {
		title.draw(titleStrBottom, ofGetViewportWidth() / 2 - titleStrBottom.length() * titleSize * 0.65, ofGetViewportHeight() / 3 + 65 + i);
	}

	// "ARCADE"
	ofSetColor(255, 0, 0);
	title.draw(titleStrBottom, ofGetViewportWidth() / 2 - titleStrBottom.length() * titleSize * 0.65, ofGetViewportHeight() / 3 + 65);


//game instructions
    ofSetColor(77, 78, 79, 95); 
	ofDrawRectRounded(10, 10, 300, 120, 10);

	ofSetColor(255);
	ofDrawBitmapString("Press 'e' to pickup ingredients",40,40);
	
	ofDrawBitmapString("Press 's' to serve clients",40,65);

	ofDrawBitmapString("Press '->' to move right",40,90);
	ofDrawBitmapString("Press '<-'to move left",40,110);

}

void MenuState::keyPressed(int key){
	
}

bool MenuState::mousePressed(int x, int y, int button){
	return
	startButton->mousePressed(x, y) ||
	statsButton->mousePressed(x, y) ||
	achivementsButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
	statsButton->reset();
	achivementsButton->reset();
}