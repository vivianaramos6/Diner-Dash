#include "Button.h"

class StateTitle {
    private:
        GameFont title;
        string titleTxt;
        Button *button;
    
    public:
        StateTitle(string titleTxt) 
        : title(GameFont(38)), titleTxt(titleTxt) {}
        void render();

        void setButton(Button *button) { this->button = button; }
};