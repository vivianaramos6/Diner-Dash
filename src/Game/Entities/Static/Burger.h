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
    void removelastingredient();
    void render();
    void clear();
    void setY(int y) {
        this->y = y;
    }

    unordered_map<string, int> getItemAmounts();
    bool equals(Burger *burgerMade);

    // Getters and setters
    vector<Item *> getIngredients() { return ingredients; }
};
