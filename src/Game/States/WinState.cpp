#include "WinState.h"

WinState::WinState() {
    int centerX = ofGetViewportWidth() / 2;
    int btnW = 100;
    int btnH = 40;

    playAgainBtn = new Button(centerX + 200, ofGetViewportHeight() / 2 + 100, btnW, btnH, "Play Again");
    goToMenuBtn = new Button(centerX - 200, ofGetViewportHeight() / 2 + 100, btnW, btnH, "Go to Menu");
}

void WinState::tick() {
    if(playAgainBtn->wasPressed()) {
        setNextState("Game");
        setFinished(true);
    }

    if(goToMenuBtn->wasPressed()) {
        setNextState("Menu");
        setFinished(true);
    }
}

void WinState::render() {
	ofSetBackgroundColor(59, 131, 247);
	playAgainBtn->render(ofColor::black);
	goToMenuBtn->render(ofColor::black);

    ofSetColor(0);
    ofDrawBitmapString("YOU WON!", ofGetViewportWidth() / 2 - 44, ofGetViewportHeight() / 3);
    ofSetColor(255);
}

void WinState::keyPressed(int key) {
	
}

void WinState::mousePressed(int x, int y, int button) {
	playAgainBtn->mousePressed(x, y);
	goToMenuBtn->mousePressed(x, y);
}

void WinState::reset() {
    setFinished(false);
    setNextState("");
    playAgainBtn->reset();
    goToMenuBtn->reset();
}