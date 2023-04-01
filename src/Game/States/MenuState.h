#pragma once

#include "State.h"
#include "GameFont.h"
#include "Button.h"

class MenuState : public State {
private:
	ofImage img1;
	Button *startButton;
	int titleSize = 24;
	GameFont title;

public:
	MenuState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	ofImage burgerbg;
	
};
