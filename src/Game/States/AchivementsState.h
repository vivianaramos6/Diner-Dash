#pragma once

#include "State.h"
#include "StateTitle.h"
#include "Button.h"
#include "GameFont.h"
#include "Achivement.h"

class AchivementsState : public State {
private:
	ofImage checkmark = ofImage("images/achivements/cm.png");
	vector<Achivement> achivements;
	GameFont gameFont14px = GameFont(14);
	GameFont gameFont10px;
	StateTitle header;
	Button *menuButton;

public:
	AchivementsState(GameData *gameData);
	vector<Achivement>* getAchivementsPointer() { return &achivements; }
	void tick();
	void render();
	void keyPressed(int key);
	bool mousePressed(int x, int y, int button);
	void reset();
};
