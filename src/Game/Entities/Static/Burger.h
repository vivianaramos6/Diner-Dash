//
// Created by joshu on 11/4/2020.
//
#pragma once

#include "Entity.h"
#include "Item.h"

class Burger {
  private:
    int x, y, width, height;
    vector<Item *> ingredients;

  public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    bool removelastingredient();
    void render();
    void clear();
    void setY(int y) {
        this->y = y;
    }

    unordered_map<string, int> getItemAmounts();
    unordered_map<string, int> ingredientPrices= {{"cheese",3}, {"tomato",2}, {"lettuce",2}, {"patty",4}, {"topBun",1}, {"bottomBun",1}};
    bool equals(Burger *burgerMade);

    // Getters and setters
    vector<Item *> getIngredients() { return ingredients; }
    int getprice();
};
