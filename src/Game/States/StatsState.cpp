#include "StatsState.h"

StatsState::StatsState(GameData *gameData) : State(gameData), header("Stats") {
	// Buttons
	menuButton = new Button(15, 15, 100, 50, "Menu", 12, 255, ofColor::grey);

	previousButton = new Button(175, 330, 100, 40, "Previous", 8, 255, ofColor::orange);
	nextButton = new Button(300, 330, 100, 40, "Next", 8, 255, ofColor::orange);
	
	header.setButton(menuButton);
}

void StatsState::tick() {
	menuButton->tick();
	previousButton->tick();
	nextButton->tick();

	if(menuButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}

	if(previousButton->wasPressed()){
		previousButton->reset();
		currentPage--;

		// Going to last page when going before first page
		if(currentPage < 1) currentPage = pages;
	}

	if(nextButton->wasPressed()){
		nextButton->reset();
		currentPage++;

		// Starting back at 1st page when going past last page
		if(currentPage > pages) currentPage = 1;
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

void StatsState::renderPageInstruction() {
	gameFont10px.draw("Page " + to_string(currentPage) + "/" + to_string(pages), 20, 360);

	if(pages > 1) {
		previousButton->render();
		nextButton->render();
	}
}

void StatsState::renderStatsInPage() {
	// Checking if ther are any stats to render
	if(pages < 1) {
		gameFont14px.draw("No games have been played", ofGetViewportWidth() / 2.0 - 25 * 9.5, 520);
		return;
	}

	renderPageInstruction();

	// Iterating through the last 4 indeces of allStats
	int lastIndex = (gameData->getAllStats().size() - (currentPage - 1) * 4) - 1;
	int i = 0;

	for(int reverseIndex = lastIndex; reverseIndex >= 0 && reverseIndex >= lastIndex-3; reverseIndex--) {
		Stats entry = gameData->getAllStats()[reverseIndex];

		int width = 387;
		int height = 170;
		int padding = 15;

		int xPos = i % 2 == 0? padding : padding*2 + width;
		int yPos = i < 2? 387 : 387 + padding + height;

		// Green when game was won, red when game was lost
		ofColor winLoseColor = entry.won? ofColor::darkGreen : ofColor::darkRed;

		ofSetColor(winLoseColor);
		ofDrawRectRounded(xPos - 5, yPos - 5, width + 10, height + 10, 15);

		// Drawing box
		ofSetColor(ofColor::antiqueWhite);
		ofDrawRectRounded(xPos, yPos, width, height, 10);

		// Drawing the info
		ofSetColor(winLoseColor);
		gameFont10px.draw((string)"Game " + (entry.won? "won" : "lost"), xPos + 15, yPos + 20);

		int entryNumber = lastIndex - reverseIndex + 1;
		gameFont10px.draw(to_string(entryNumber), xPos + width - 20, yPos + 170);

		ofSetColor(0);
		gameFont10px.draw("Elapsed time: " + entry.getElapsedTimeStringShortened(), xPos + 15, yPos + 45);
		gameFont10px.draw("Clients that left: " + to_string(entry.clientsThatLeft), xPos + 15, yPos + 120);
		gameFont10px.draw("Burgers served: " + to_string(entry.burgersServed), xPos + 15, yPos + 70);
		gameFont10px.draw("Burgers wasted: " + to_string(entry.burgersWasted), xPos + 15, yPos + 95);
		gameFont10px.draw("Money earned: " + to_string(entry.money), xPos + 15, yPos + 145);
		gameFont10px.draw("Undos: " + to_string(entry.undos), xPos + 15, yPos + 170);

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
	previousButton->mousePressed(x, y);
	nextButton->mousePressed(x, y);
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