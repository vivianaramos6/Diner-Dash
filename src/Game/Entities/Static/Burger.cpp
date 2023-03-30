//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"
#include <unordered_map>

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}
//removes last ingredient added to burger
void Burger::removelastingredient(){
    if(ingredients.size()<1) return;
    ingredients.pop_back();
   
    

}

int Burger::getprice(){
    int total=0;
     unordered_map<string, int> ingredientAmounts = getItemAmounts();
     for(auto x: ingredientAmounts){
        int price = (ingredientPrices.at(x.first))*(x.second);
       total+=price;

     }
     return total;

}

void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
      ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++;
    }
}

void Burger::clear(){
    ingredients.empty();
}

// This function returns a map of the items in a burger to their amount
unordered_map<string, int> Burger::getItemAmounts() {
    // Initializing map with default values 0
    unordered_map<string, int> ingredientAmounts = {{"cheese",0}, {"tomato",0}, {"lettuce",0}, {"patty",0}, {"topBun",0}, {"bottomBun",0}};

    for(Item *item : this->getIngredients()) {
        string name = item->name;
        ingredientAmounts[name] += 1;
    }

    return ingredientAmounts;
}

bool Burger::equals(Burger *burgerMade) {
    // Checking if top and buttom buns are placed correctly and that they have the same number of ingredients
    vector<Item *>burgerMadeItems = burgerMade->getIngredients();

    if(
        burgerMadeItems.size() != this->getIngredients().size() ||
        burgerMadeItems[0]->name != "bottomBun" || 
        burgerMadeItems[burgerMadeItems.size() - 1]->name != "topBun"
    )
        return false;

    // Mapping ingredients to their amounts
    unordered_map<string, int> targetIngredientAmounts = this->getItemAmounts();
    unordered_map<string, int> paramIngredientAmounts = burgerMade->getItemAmounts();
    
    // Comparing to see if amounts are equal, returning false if at least one isnt
    for(auto &x : targetIngredientAmounts) {
        if(x.second != paramIngredientAmounts.at(x.first))
            return false;
    }

    return true;
}