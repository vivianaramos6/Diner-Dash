#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 100, 100, "Start",255,95);
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