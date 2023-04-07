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
	Button *nextButton;
	Button *previousButton;
	GameFont gameFont10px;
	GameFont gameFont14px = GameFont(14);

	// Pages is the number of pages of stats. each page can hold up to 4 stats entries.
	// So the number of pages is : ⌊number_of_entries / 4⌋ (the ceiling of # of entries / 4)
	int pages = 0;
	int currentPage = 0;
	int numberOfStats = 0;

	void renderPageInstruction();
	void renderAllTimeStats();
	void renderStatsInPage();

	public:
		StatsState(GameData *gameData);
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void reset();
};
