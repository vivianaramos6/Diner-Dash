#pragma once

#include "State.h"
#include "StateTitle.h"
#include "Button.h"
#include "GameFont.h"

class StatsState : public State {
private:
	StateTitle header;
	Button *menuButton = nullptr;

public:
	StatsState(GameData *gameData);
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
