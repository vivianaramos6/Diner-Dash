#pragma once
#include "ofMain.h"

class gameFont {
    private:
        ofTrueTypeFont pressStart;
        

    public:
        gameFont(int size = 10) {
            pressStart.load("fonts/pressStart.ttf", size);
        }

        void draw(string s, float x, float y) {
            pressStart.drawString(s ,x, y);
        }
};