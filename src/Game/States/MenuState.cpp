#include "MenuState.h"

MenuState::MenuState() : title(GameFont(titleSize)) {
	string btnTxt = "Start";
	startButton = new Button(ofGetWidth()/2 - btnTxt.length()*16, ofGetHeight()/1.5 - btnTxt.length()*11, 200, 100, "Start", 16, 255, ofColor::orange);
	burgerbg.load("images/pixelburger.png");
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