#include "Player.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em, int *money_p, int *undos_p, int *ingredientsUsed_p) : Entity(x, y, width, height, sprite){

    vector<ofImage> chefAnimframes;
    ofImage temp;
    this->burger = new Burger(ofGetWidth()-110, 100, 100, 50);
    temp.cropFrom(sprite, 30,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 159,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 287, 3,67,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 31,129,66,120);
    chefAnimframes.push_back(temp);
    this->chefAnim = new Animation(50, chefAnimframes);
    this->entityManager = em;
    this->ingredientsUsed_p = ingredientsUsed_p;
    this->money_p = money_p;
    this->undos_p = undos_p;
    
}
void Player::tick(){
    chefAnim->tick();

    // Moving chef
    if(movingLeft && x > 0) x -= speed;
    if(movingRight && x + width<ofGetWidth()) x += speed;
}


void Player::render(){
    BaseCounter *ac = getActiveCounter();
    if (ac != nullptr) {
        ac->showItem();
    }
    ofSetColor(256, 256, 256);
    ofImage currentFrame = chefAnim->getCurrentFrame();
    if (facing == "left") {
        currentFrame.mirror(false, true);
    }
    currentFrame.draw(x, y, width, height);
    burger->render();
}



void Player::keyPressed(int key){
    if(key == 'e'){
        BaseCounter* ac = getActiveCounter();
        if(ac != nullptr){
            Item* item = ac->getItem();

            // calling interact method on the counter if it returns null item pointer
            if(item == nullptr) {
                ac->interact();
            }
            // Adding the item to the bruger if the pointer was not null
            else {
                burger->addIngredient(item);
                // Deduct $1 when selecting ingredient and incrementeing ingredients used by 1
                (*ingredientsUsed_p)++;
                (*money_p)--;
            }
        }
    }
    //undoes last ingredient added to burger
    if(key=='u'){
        // Tries to removw last ingredient, if there is an ingredient to remove, the $1 is returned
        // # of undos is incremented by 1 and # of ingredients used is decremented by 1
        if(burger->removelastingredient()) {
            (*ingredientsUsed_p)--;
            (*money_p)++;
            (*undos_p)++;
        }

    }
    //chef moves left
    if(key == OF_KEY_LEFT){
        facing="left";
        movingLeft = true;
    }

    //chef moves right
    else if(key == OF_KEY_RIGHT){
        facing = "right";
        movingRight = true;
    }     
}

void Player::keyReleased(int key) {
    //chef stop moving left
    if(key == OF_KEY_LEFT) movingLeft = false;
    //chef stop moving right
    else if(key == OF_KEY_RIGHT) movingRight = false;     
}

BaseCounter* Player::getActiveCounter(){
    for(Entity* e:entityManager->entities){
        BaseCounter* c = dynamic_cast<BaseCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }

void Player::reset() {
    movingRight = false;
    movingLeft = false;
    facing = "right";
    burger->clear();
    this->setX(0);
}