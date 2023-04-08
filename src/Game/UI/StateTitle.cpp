#include "StateTitle.h"

void StateTitle::render() {
// Box shadow
    ofSetColor(ofColor::darkorange);
    ofDrawRectangle(0, 75, ofGetViewportWidth(), 7);

    // background box
    ofSetColor(ofColor::orange);
    ofDrawRectangle(0, 0, ofGetViewportWidth(), 75);
    ofSetColor(255);

    // text
    title.draw(titleTxt, ofGetViewportWidth() / 2 - titleTxt.length() * 38 * 0.65, 65);

    if(button != nullptr) button->render();
}