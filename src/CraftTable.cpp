#include <iostream>
#include "CraftTable.hpp"
#include "util.cpp"
using namespace std;

// Ctor
CraftTable::CraftTable() {
    for (int i = 0; i < MAX_CAP; i++) {
        string key = get_cid(i);
        table[key] = NULL;
    }
}; 
// CCtor
CraftTable::CraftTable(const CraftTable& other) {
    table = other.table;
};

// Overload
CraftTable& CraftTable::operator=(const CraftTable& other) {
    table = other.table;
    return *this;
};

// Getter Setter Push Pop
Item& CraftTable::getItemInCraftTable(string c_id) {
    if (isCIDValid(c_id))
        return *table[c_id];
    else {
        throw new CIDNotValid();
    }
};

void CraftTable::add(Item& item, string c_id) {
    // Add item to c_id slot, if not empty throw error
    if (isCIDValid(c_id)) {
        if (isSlotEmpty(c_id)) {
            table[c_id] = &item;
        } else {
            throw new craftTableIsNotEmptyException();
        }
    } else {
        throw new CIDNotValid();
    }
}; 
void CraftTable::substract(string c_id) {
    // Delete item from c_id slot to be empty, if empty throw error
    if (isCIDValid(c_id)) {
        if (!isSlotEmpty(c_id)) {
            table[c_id] = NULL;
        } else {
            throw new craftTableIsNotEmptyException();
        }
    } else {
        throw new CIDNotValid();
    }
}; 

// Method
void CraftTable::print() {
    // Print all the values of the Crafting Table
}; 


Item& CraftTable::make(vector<Recipe> recipe) {
    /* Jika terdapat resep yang memenuhi, Item bahan akan hilang dan Item hasil akan muncul. Item akan otomatis ditambahkan ke inventory dengan
    algoritma yang sama dengan command GIVE. */
    int idx = whichBuildable(recipe);
    if (idx != -1) {
        Recipe res = recipe[idx];
    } else {
        // cannot build items in craft table
        throw new craftTableDoesntMatchRecipeException();
    }
}; 

bool CraftTable::contain(Item& item) {
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->second == &item) return true;
    }
}

// Attribute
bool CraftTable::isSlotEmpty(string c_id) {
    if (isCIDValid(c_id))
        return (table[c_id]);
};

bool CraftTable::isTableEmpty() {
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->second) return false;
    }

    return true;
};

vector<string> CraftTable::convertVector() {
    vector<string> res;
    string val;
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->second) {
            val = it->second->getName();
        } else {
            val = "-";
        }
        res.push_back(val);
    }
}

int CraftTable::whichBuildable(vector<Recipe> listRecipe) {
    int res = -1;
    for (int i = 0; i < listRecipe.size(); i++) {
        int row = listRecipe[i].getRow();
        int col = listRecipe[i].getCol();
        vector<string> recipe = listRecipe[i].getRecipe();
        // int quantity = listRecipe[i].getQuantityResult();
        vector<string> table = (this->convertVector());
        table = trimKosong(table);

        // check recipe is subarray of a table array
        if (isSubArray(table, recipe, table.size(), recipe.size())) {
            res = i;
            break;
        }
    }
    return res;
};

vector<string> CraftTable::trimKosong(vector<string> table) {
    for (int i = 0; i < table.size(); i++) {
        if (table[i] == "-") {
            table.erase(table.begin()+i);
        } else {
            break;
        }
    }

    for (int i = table.size()-1; i>=0; i++) {
        if (table[i] == "-") {
            table.pop_back();
        } else {
            break;
        }
    }

    return table;
};
