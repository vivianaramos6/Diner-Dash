#include "WinState.h"

WinState::WinState(GameData *gameData) : State(gameData) {
    int centerX = ofGetViewportWidth() / 2;
    int btnW = 150;
    int btnH = 40;

    playAgainBtn = new Button(centerX + 125, ofGetViewportHeight() / 2 + 100, btnW, btnH, "Play Again", 10, ofColor(255), ofColor(0x15, 0x88, 255));
    goToMenuBtn = new Button(centerX - 275, ofGetViewportHeight() / 2 + 100, btnW, btnH, "Go to Menu", 10, ofColor(255), ofColor::orange);
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
	playAgainBtn->render();
	goToMenuBtn->render();

    ofSetColor(0);
    ofDrawBitmapString("YOU WON!", ofGetViewportWidth() / 2 - 44, ofGetViewportHeight() / 3);
    ofSetColor(255);

    // Showing stats
    Stats* stats_p = gameData->getLastStats();
    if(stats_p != nullptr) stats_p->draw();
}

void WinState::keyPressed(int key) {
	
}

bool WinState::mousePressed(int x, int y, int button) {
	return
    playAgainBtn->mousePressed(x, y) ||
    goToMenuBtn->mousePressed(x, y);
}

void WinState::reset() {
    setFinished(false);
    setNextState("");
    playAgainBtn->reset();
    goToMenuBtn->reset();
}