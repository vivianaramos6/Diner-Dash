#include "LooseState.h"

LooseState::LooseState() {
    int centerX = ofGetViewportWidth() / 2;
    int btnW = 150;
    int btnH = 40;

    playAgainBtn = new Button(centerX + 125, ofGetViewportHeight() / 2 + 100, btnW, btnH, "Play Again", 10, ofColor(255), ofColor(0x15, 0x88, 255));
    goToMenuBtn = new Button(centerX - 275, ofGetViewportHeight() / 2 + 100, btnW, btnH, "Go to Menu", 10, ofColor(255), ofColor::orange);
    sadchef.load("images/sad_chef.png");
    gameover.load("images/gameover.webp");
}
void LooseState::tick() {
    if(playAgainBtn->wasPressed()) {
        setNextState("Game");
        setFinished(true);
    }

    if(goToMenuBtn->wasPressed()) {
        setNextState("Menu");
        setFinished(true);
    }
}

void LooseState::render() {

	ofSetBackgroundColor(256);
    gameover.draw(0,0,850,850);
    sadchef.draw(ofGetWidth()/4-20, 200, 190,190);

	playAgainBtn->render();
	goToMenuBtn->render();
}

void LooseState::keyPressed(int key) {
	
}

void LooseState::mousePressed(int x, int y, int button) {
	playAgainBtn->mousePressed(x, y);
	goToMenuBtn->mousePressed(x, y);
}

void LooseState::reset() {
    setFinished(false);
    setNextState("");
    playAgainBtn->reset();
    goToMenuBtn->reset();
}