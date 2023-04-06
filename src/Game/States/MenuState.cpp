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
	if(startButton->wasPressed()){
		setNextState("Game");
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
	title.draw(titleStr, ofGetViewportWidth() / 2 - titleStr.length() * titleSize * 0.65, ofGetViewportHeight() / 3);

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

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}