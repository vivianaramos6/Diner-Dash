//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"


Player *Restaurant::getPlayer() { return player; }
void Restaurant::setPlayer(Player *player) { this->player = player; }

Restaurant::Restaurant() {
    floor.load("images/arcade_floor3.png");
    
    entityManager = new EntityManager();
    //loading decoration
    moneysign.load("images/moneysign.png");
    leftsign.load("images/leftsign.png");
    chairsandtable.load("images/dinertables.png");
    BlueArcade.load("images/blue_arcade.png");
    RedArcade.load("images/red_arcade.png");
    greenArcade.load("images/greenarcade.png");
    pinkArcade.load("images/pinkarcade.png");
    yellowArcade.load("images/yellowarcade.png");

    bluepottedplant.load("images/bluepottedplant.png");


    // Loading sounds
    stoveOnSound.load("sounds/stove-on.mp3");
    pickIngredientSound.load("sounds/pick-ingredient.mp3");
    serveClientSound.load("sounds/serve-client.mp3");
    clientLeftSound.load("sounds/client-left.mp3");
    incorrectSound.load("sounds/incorrect-sound.wav");
   
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager, &money, &undos, &ingredientsUsed, &incorrectSound);    
    initItems();
    initCounters();
    initClients();
    generateClient();

}
void Restaurant::initItems(){
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, rawBurgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    rawBurgerImg.cropFrom(burgerSpriteSheet, 577, 11, 111, 57); // raw patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    rawBurger = new Item(rawBurgerImg, "rawPatty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");

    // Adding all itemOptions to a list (excluding bread)
    Item* newItemOptions[4] = { cheese, lettuce, tomato, burger };
    memcpy(itemOptions, newItemOptions, sizeof(itemOptions));

    // Sounds
}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, stoveCounterOnImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    stoveCounterOnImg.cropFrom(counterSheet, 224,140,32,43);//stoveTop turned on
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    emptyCounterImg.cropFrom(counterSheet,0,245,30,43);//Empty
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg, &pickIngredientSound));
    entityManager->addEntity(new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg, &pickIngredientSound));
    entityManager->addEntity(new StoveCounter(counterWidth*2,yOffset, counterWidth, 102, rawBurger, burger, stoveCounterImg, stoveCounterOnImg, &pickIngredientSound, &stoveOnSound));
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg, &pickIngredientSound));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, nullptr, emptyCounterImg, nullptr));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg, &pickIngredientSound));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg, &pickIngredientSound));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg, &pickIngredientSound));

}
void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
    temp.load("images/People/inspector.png");
    people.push_back(temp);
    temp.load("images/People/inspector.png");
    people.push_back(temp);
}
void Restaurant::tick() {
    ticks++;
    if(ticks % 275 == 0){
        generateClient();
        clientsGenerated++;

    }
    player->tick();
    entityManager->tick();
}


void Restaurant::generateClient(){
    Burger* b = new Burger(72, 100, 50, 25);
    b->addIngredient(botBread);

    // Deciding amount of ingredients
    int ingredientAmt = ofRandom(3);

    // Adding 4 random ingredients
    for(int i = 0; i <= ingredientAmt; i++) {
        int n = ofRandom(4);
        b->addIngredient(itemOptions[n]);
    }

    b->addIngredient(topBread);

    if(clientsGenerated % 10 == 0 && clientsGenerated > 0)
        entityManager->addClient(new Inspector(0, 50, 64, 72,people[8], b, &money, &clientLeftSound));
    else
        entityManager->addClient(new Client(0, 50, 64, 72,people[ofRandom(8)], b, &clientLeftSound));
}
void Restaurant::render() {
   
    floor.draw(0,0,ofGetWidth(),ofGetHeight());
    //drawing decorations
    chairsandtable.draw(ofGetWidth()/6, 330, 300,150);
    chairsandtable.draw(ofGetWidth()/6, 200, 300,150);
    chairsandtable.draw((ofGetWidth()/2)+30, 330, 300,150);
    chairsandtable.draw((ofGetWidth()/2)+30, 200, 300,150);
    BlueArcade.draw(ofGetWidth()-315,0,150,150);
    RedArcade.draw(ofGetWidth()-400,5,120,145);
    greenArcade.draw(ofGetWidth()-490,2,100,149);
    pinkArcade.draw(ofGetWidth()-585,2,100,149);
    bluepottedplant.draw(ofGetWidth()-100,ofGetHeight()-550,100,170);
    
    moneysign.draw(120,5,90,70);
    leftsign.draw(670, 5, 150, 70);

    ofSetColor(255, 0, 127);

    gameFont10px.draw(to_string(money),162,50);
    gameFont10px.draw(to_string(getClientsThatLeft()) + "/10",740,50);
    
    ofSetColor(256, 256, 256);
     
    
    player->render();
    entityManager->render();
    
}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        // Serve method returns the amount of money the bruger costs. returns 0 if no burger was served
        int moneyFromBurger = entityManager->firstClient->serve(player->getBurger());
        money += moneyFromBurger;

        // When money > 0, it means that the burger was served. otherwise it was thrown away
        if(moneyFromBurger > 0) {
            burgersServed++;
            serveClientSound.play();
        }
        else {
            incorrectSound.play();
            burgersWasted++;
        }
    }
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's'){
        serveClient();
    }
}

void Restaurant::keyReleased(int key) {
    player->keyReleased(key);
}

void Restaurant::reset() {
    ingredientsUsed = 0;
    burgersServed = 0;
    burgersWasted = 0;
    ticks = 0;
    undos = 0;
    money = 0;
    clientsGenerated=0;

    entityManager->resetClients();
    entityManager->resetStoves();
    player->reset();
}