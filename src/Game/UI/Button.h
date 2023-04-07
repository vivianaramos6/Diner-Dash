#pragma once
#include "ofMain.h"
#include "GameFont.h"

class Button {
    
    public:
        // Constructors
        Button()
        : Button(ofGetWidth()/2, ofGetHeight()/2, 64, 20, "", 10, ofColor::black, ofColor(171, 202, 252)) {}

        Button(int x, int y, int w, int h, string s) 
        : Button(x, y, w, h, s, 10, ofColor::black, ofColor(171, 202, 252)) {}
        
        Button(int x, int y, int w, int h, string s, int fontSize) 
        : Button(x, y, w, h, s, fontSize, ofColor::black, ofColor(171, 202, 252)) {}

        Button(int x, int y, int w, int h, string s, int fontSize, ofColor txtColor)
        : Button(x, y, w, h, s, fontSize, txtColor, ofColor(171, 202, 252)) {}

        Button(int x, int y, int w, int h, string s, int fontSize, ofColor txtColor, ofColor bgColor);

        bool mousePressed(int x, int y);
        void tick();
        void render();
        bool wasPressed();
        void reset();

    private:
        int xPos, yPos, width, height, fontSize;
        ofImage buttonImage;
        ofImage clickedButtonImage;
        bool pressed = false;
        int pressedCounter = -1;
        string buttonText;
        GameFont gameFont;
        ofColor txtColor;
        ofColor bgColor;
};