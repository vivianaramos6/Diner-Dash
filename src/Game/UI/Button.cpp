#include "Button.h"
#include "GameFont.h"

Button::Button(int xPos, int yPos, int width, int height, 
string buttonText, int fontSize, ofColor txtColor, ofColor bgColor)
:
xPos(xPos), yPos(yPos), width(width), height(height), 
buttonText(buttonText), fontSize(fontSize), txtColor(txtColor), bgColor(bgColor) 
{ gameFont = GameFont(fontSize); }

void Button::reset(){
    pressedCounter = -1;
    pressed = false;
}
void Button::tick(){
    pressedCounter--;
    if(pressedCounter == 0){
        pressed = false;
        pressedCounter = -1;
    }

}

bool Button::mousePressed(int x, int y){
    if(xPos + width >= x && x >= xPos &&  yPos + height >= y && y >= yPos){
        pressed = true;
        pressedCounter = 10;
        return true;
    }
    return false;
}

void Button::render() {
    // Border
    // Changing the color of the border slightly
    ofSetColor(bgColor - ofColor(40, 40, 40));
    ofDrawRectRounded(xPos - 5, yPos - 5, width + 10, height + 10, 5);

    // Padding
    ofSetColor(bgColor);
    ofDrawRectRounded(xPos, yPos, width, height, 5);

    // text
    ofSetColor(txtColor);
    gameFont.draw(buttonText, xPos+width/2 - (buttonText.length() * fontSize * 0.65), yPos+height/2 + fontSize * 0.65);
}

bool Button::wasPressed(){
    return pressed;
}