#include "Player.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em, int *money_p) : Entity(x, y, width, height, sprite){

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
    this->money_p = money_p;
    
}
void Player::tick(){
    chefAnim->tick();
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
            if(item != nullptr){
                burger->addIngredient(item);
                

                // Deduct $1 when selecting ingredient
                (*money_p)--;
            }
        }
    }
    //undoes last ingredient added to burger
    if(key=='u'){
        burger->removelastingredient();
        }
        //chef moves left
        if(key == OF_KEY_LEFT){
            facing="left";
            if(x>0){
        x-=speed+20;}}
        //chef moves right
        else if(key == OF_KEY_RIGHT){
        facing = "right";
        if(x+width<ofGetWidth()){
        x+=speed+20;
    }}
        
    

    
        

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

void Player::keyReleased(int key) {
}
void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }