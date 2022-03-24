#include "Recipe.hpp"
#include <iostream>

using namespace std;

Recipe::Recipe() {
    row = 0;
    col = 0;
    quantityResult = 0;
}; // Ctor
// Recipe::Recipe(int row, int col, vector<string> recipe, Item& item, int quantityResult) {
//     this->row = row;
//     this->col = col;
//     this->quantityResult = quantityResult;
//     this->recipe = recipe;
//     this->item = &item;
// };

Recipe::Recipe(int row, int col, vector<string> recipe, Item *item, int quantityResult) {
    this->row = row;
    this->col = col;
    this->quantityResult = quantityResult;
    this->recipe = recipe;
    this->item = item;
};

Recipe::Recipe(const Recipe& r) {
    this->row = r.row;
    this->col = r.col;
    this->quantityResult = r.quantityResult;
    this->recipe = r.recipe;
    this->item = r.item;
};

Recipe::~Recipe() {
    delete item;
}
// Getter Setter
vector<string> Recipe::getRecipe() {
    return recipe;
};

int Recipe::getRow() {
    return row;
};
int Recipe::getCol() {
    return col;
};

Item* Recipe::getItem() {
    return item;
};

int Recipe::getQuantityResult() {
    return quantityResult;
};
void Recipe::setItemRecipe(Item& other) {
    item = &other;
};
void Recipe::setQuantityResult(int quantityResult) {
    this->quantityResult = quantityResult;
};