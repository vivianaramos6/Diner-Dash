#pragma once
#include "State.h"
#include "Button.h"
#include"GameFont.h"

class WinState : public State {
    private:
		GameFont gameFont36px = GameFont(36);
		Button *playAgainBtn;
		Button *goToMenuBtn;

    public: 
        WinState(GameData *gameData);
		void tick();
		void render();
		void keyPressed(int key);
		bool mousePressed(int x, int y, int button);
		void reset();
};