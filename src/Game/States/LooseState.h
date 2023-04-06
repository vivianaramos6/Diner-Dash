#pragma once
#include "State.h"
#include "Button.h"


class LooseState : public State {
    private:
		Button *playAgainBtn;
		Button *goToMenuBtn;

    public: 
        LooseState(GameData *gameData);
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void reset();

		ofImage sadchef;
		ofImage gameover;
};