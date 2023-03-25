#pragma once
#include "State.h"
#include "Button.h"


class LooseState : public State {
    private:
		Button *playAgainBtn;
		Button *goToMenuBtn;

    public: 
        LooseState();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void reset();
};