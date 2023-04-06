#pragma once

#include "State.h"
#include "StateTitle.h"
#include "Button.h"
#include "GameFont.h"
#include "Stats.h"

class StatsState : public State {
private:
	StateTitle header;
	Button *menuButton;
	GameFont gameFont10px;
	GameFont gameFont14px = GameFont(14);

public:
	StatsState(GameData *gameData);
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	void renderAllTimeStats();
};
