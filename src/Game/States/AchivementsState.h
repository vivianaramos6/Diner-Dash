#pragma once

#include "State.h"
#include "StateTitle.h"
#include "Button.h"
#include "GameFont.h"
#include "Achivement.h"

class AchivementsState : public State {
private:
	vector<Achivement> achivements;
	StateTitle header;
	Button *menuButton;

public:
	AchivementsState(GameData *gameData);
	void tick();
	void render();
	void keyPressed(int key);
	bool mousePressed(int x, int y, int button);
	void reset();
};
