#pragma once

#include "State.h"
#include "StateTitle.h"
#include "Button.h"
#include "GameFont.h"

class AchivementsState : public State {
private:
	StateTitle header;
	Button *menuButton;

public:
	AchivementsState(GameData *gameData);
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
