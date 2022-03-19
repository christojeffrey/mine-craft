#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <vector>
#include "Item.hpp"
#include "CraftTable.hpp"
using namespace std;

class Recipe {
    private:
        int row, col;
        vector<string>  recipe;
        Item* item;
        int quantityResult;
    public:
        Recipe(); // Ctor
        Recipe(int row, int col, vector<string> recipe, Item& item, int quantityResult);
        // Getter Setter
        ~Recipe();
        vector<string> getRecipe();
        int getRow();
        int getCol();
        int getQuantityResult();
        void setItemRecipe(Item& other);
        void setQuantityResult(int quantityResult);
};

#endif