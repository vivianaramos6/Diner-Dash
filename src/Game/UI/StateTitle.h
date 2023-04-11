#pragma once
#include "Button.h"
class StateTitle {
    private:
        GameFont title;
        string titleTxt;
        Button *button;
    
    public:
        StateTitle(string titleTxt) 
        : title(GameFont(36)), titleTxt(titleTxt) {}
        void render();

        void setButton(Button *button) { this->button = button; }
};