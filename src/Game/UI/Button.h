#pragma once
#include "ofMain.h"

class Button {
    
    public:
        // Constructors
        Button()
        : Button(ofGetWidth()/2, ofGetHeight()/2, 64, 20, "", ofColor::black, ofColor(171, 202, 252)) {}

        Button(int x, int y, int w, int h, string s) 
        : Button(x, y, w, h, s, ofColor::black, ofColor(171, 202, 252)) {}

        Button(int x, int y, int w, int h, string s, ofColor txtColor)
        : Button(x, y, w, h, s, txtColor, ofColor(171, 202, 252)) {}

        Button(int x, int y, int w, int h, string s, ofColor txtColor, ofColor bgColor);

        void mousePressed(int x, int y);
        void tick();
        void render();
        bool wasPressed();
        void reset();

    private:
        int xPos, yPos, width, height;
        ofImage buttonImage;
        ofImage clickedButtonImage;
        bool pressed = false;
        int pressedCounter = -1;
        string buttonText;
        ofColor txtColor;
        ofColor bgColor;
};