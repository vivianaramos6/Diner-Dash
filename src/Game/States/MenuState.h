#pragma once

#include "State.h"
#include "GameFont.h"
#include "Button.h"

class MenuState : public State {
private:
	ofImage img1;
	Button *startButton;
	Button *statsButton;
	Button *achivementsButton;
	int titleSize = 38;
	GameFont title;

public:
	MenuState(GameData *gameData);
	void tick();
	void render();
	void keyPressed(int key);
	bool mousePressed(int x, int y, int button);
	void reset();
	ofImage burgerbg;
	
};
