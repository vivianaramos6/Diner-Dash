#include "StatsState.h"

StatsState::StatsState(GameData *gameData) : State(gameData), header("Stats") {
	// Menu button
	string menuTxt = "Menu";
	menuButton = new Button(15, 15, 100, 50, menuTxt, 12, 255, ofColor::grey);
	
	header.setButton(menuButton);
}

void StatsState::tick() {
	menuButton->tick();
	if(menuButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}

void StatsState::renderAllTimeStats() {
	gameFont14px.draw("All Time Stats", 20, 150);
	gameFont10px.draw("Games played:" + to_string(gameData->getGamesPlayed()), 20, 185);
	gameFont10px.draw("Games won:" + to_string(gameData->getGamesWon()), 20, 210);
	gameFont10px.draw("Games lost:" + to_string(gameData->getGamesLost()), 20, 235);
	gameFont10px.draw("Burger served:" + to_string(gameData->getBurgersServed()), 20, 260);
	gameFont10px.draw("Money made: $" + to_string(gameData->getTotalMoney()), 20, 285);
	gameFont10px.draw("Time played: " + Stats::getTimePlayed(gameData->getTimePlayed()), 20, 310);
}

void StatsState::renderStatsInPage() {
	// Checking if ther are any stats to render
	if(pages < 1) {
		gameFont14px.draw("No games have been played", ofGetViewportWidth() / 2.0 - 25 * 9.5, 520);
		return;
	}

	// Getting first iterator of the current page
	int beginAt = (currentPage - 1) * 4;
	auto iterator = gameData->getAllStats().rbegin() + beginAt;

	// Entries in page is always 4 unless you are in the last page,
	// in which case the number of entries here is: (total_entries % 4)
	// When (total_entries % 4) == 0, it means that the last page is full, therefore
	// The number of entries is set to 4.
	int entriesInPage = pages > currentPage? 4 : numberOfStats % 4;
	if(entriesInPage == 0) entriesInPage = 4;

	int i = 0;

	// Iterating through the stats of the current page stats
	for(auto it = iterator; it != iterator + entriesInPage; it++) {
		int width = 387;
		int height = 170;
		int padding = 15;

		int xPos = i % 2 == 0? padding : padding*2 + width;
		int yPos = i < 2? 387 : 387 + padding + height;

		ofSetColor(ofColor::antiqueWhite);
		ofDrawRectRounded(xPos, yPos, width, height, 10);

		i++;
	}
}

void StatsState::render() {
	ofSetBackgroundColor(100);
	header.render();
	renderAllTimeStats();
	renderStatsInPage();
}

void StatsState::keyPressed(int key){
	
}

void StatsState::mousePressed(int x, int y, int button){
	menuButton->mousePressed(x, y);
}

void StatsState::reset(){
	setFinished(false);
	setNextState("");
	menuButton->reset();

	// Setting up stats pages
	numberOfStats = gameData->getAllStats().size();
	pages = ceil(numberOfStats / 4.0);
	currentPage = pages > 0? 1 : 0;
}