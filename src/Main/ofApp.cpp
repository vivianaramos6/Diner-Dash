#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Java Game Box");
	// Game data and achivements
	gameData = new GameData();

	//States
	menuState = new MenuState(gameData);
	statsState = new StatsState(gameData);
	achivementsState = new AchivementsState(gameData);
	gameState = new GameState(gameData);
	winState = new WinState(gameData);
	looseState = new LooseState(gameData);
	// Initial State
	currentState = menuState;

	// Sound
	sound.load("galactic.mp3");
	sound.setLoop(true);
	sound.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu"){
				currentState = menuState;
			}else if(currentState->getNextState() == "Stats"){
				currentState = statsState;
			}else if(currentState->getNextState() == "Achivements"){
				currentState = achivementsState;
			}else if(currentState->getNextState() == "Game"){
				currentState = gameState;
				gameState->startTimer();
			}else if(currentState->getNextState() == "Loose"){
				currentState = looseState;
			}else if(currentState->getNextState() == "Win"){
				currentState = winState;
			}
			currentState->reset();
		}
	}
		
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr)
		currentState->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr)
		currentState->keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}
