#include "Button.h"

Button::Button(int xPos, int yPos, int width, int height, 
string buttonText, ofColor txtColor, ofColor bgColor) {
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
    this->buttonText = buttonText;
    this->txtColor = txtColor;
    this->bgColor = bgColor;
}

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

void Button::mousePressed(int x, int y){
    if(xPos + width >= x && x >= xPos &&  yPos + height >= y && y >= yPos){
        pressed = true;
        pressedCounter = 10;
    }
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
    ofDrawBitmapString(buttonText, xPos+width/2 - (buttonText.length() * 4), yPos+height/2 + 4);
}

bool Button::wasPressed(){
    return pressed;
}