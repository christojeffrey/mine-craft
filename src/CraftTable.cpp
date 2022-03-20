#include <iostream>
#include "CraftTable.hpp"

using namespace std;

string get_cid(int idx) {
    // Get c_id from a index
    char num = idx + '0';
    string res = "C";
    res.push_back(num);
    return res;
};

int get_idx(string c_id) {
    int res = c_id[1] - '0';
    return res;
};

bool isCIDValid(string c_id) {
    int idx = get_idx(c_id);
    return (idx >= 0 && idx < MAX_CAP);
};


bool isSubArray(vector<string> A, vector<string> B, int n, int m) {
    // to check if B is subarray of A
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) {
            i++;
            j++;
            if (j == m)
                return true;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    return false;
}

vector<string> trimKosong(vector<string> table) {
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

vector<string> reflectYTable(vector<string> table) {
    swap(table[0], table[2]);
    swap(table[3], table[5]);
    swap(table[6], table[8]);
    return table;
}


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
            throw new craftTableIsEmptyException();
        }
    } else {
        throw new CIDNotValid();
    }
}; 

// Method
void CraftTable::print() {
    // Print all the values of the Crafting Table
}; 


Item* CraftTable::make(vector<Recipe> recipe) {
    /* Jika terdapat resep yang memenuhi, Item bahan akan hilang dan Item hasil akan muncul. Item akan otomatis ditambahkan ke inventory dengan
    algoritma yang sama dengan command GIVE. */
    if (!isTableEmpty()) {
        if (!this->isAllTool()) {
            bool reflected = false;
            int idx = whichBuildable(recipe);
            if (idx != -1) {
                Recipe itemCrafted = recipe[idx];
                return new NonTool(itemCrafted.getItem()->getID(), itemCrafted.getItem()->getName(), itemCrafted.getItem()->getNonToolClass(), itemCrafted.getQuantityResult());
            } else {
                idx = whichBuildableReflected(recipe);
                if (idx != -1) {
                    reflected = true;
                    Recipe itemCrafted = recipe[idx];
                    return new NonTool(itemCrafted.getItem()->getID(), itemCrafted.getItem()->getName(), itemCrafted.getItem()->getNonToolClass(), itemCrafted.getQuantityResult());
                } else {
                    // cannot build items in craft table
                    throw new craftTableDoesntMatchRecipeException();
                }
            }
        } else {
            Tool* sumTool = makeTool();
            Item* res = new Tool(sumTool->getID(), sumTool->getName(), sumTool->getDurability());
            return res;
        }
    } else {
        throw new craftTableIsEmptyException;
    }
}; 

Tool* CraftTable::makeTool() {
    string name;
    int sum = 0, id = 0;
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->second) {
            id = it->second->getID();
            name = it->second->getName();
            sum += it->second->getDurability();
        }
    }
    sum = min(10, sum);
    return new Tool(id, name, sum);
};

int CraftTable::whichBuildable(vector<Recipe> listRecipe) {
    int res = -1;
    for (int i = 0; i < listRecipe.size(); i++) {
        int row = listRecipe[i].getRow();
        int col = listRecipe[i].getCol();
        vector<string> recipe = listRecipe[i].getRecipe();
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

int CraftTable::whichBuildableReflected(vector<Recipe> listRecipe) {
    int res = -1;
    for (int i = 0; i < listRecipe.size(); i++) {
        int row = listRecipe[i].getRow();
        int col = listRecipe[i].getCol();
        vector<string> recipe = listRecipe[i].getRecipe();
        vector<string> tableYReflected = reflectYTable(this->convertVector());
        tableYReflected = trimKosong(tableYReflected);
        // check recipe is subarray of a table array
        if (isSubArray(tableYReflected, recipe, tableYReflected.size(), recipe.size())) {
            res = i;
            break;
        }
    }
    return res;
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
    return res;
}

bool CraftTable::contain(Item& item) {
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->second == &item) return true;
    }
    return false;
}

// Attribute
bool CraftTable::isSlotEmpty(string c_id) {
    if (isCIDValid(c_id))
        return (table[c_id]);
    return false;
};

bool CraftTable::isTableEmpty() {
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->second) return false;
    }

    return true;
};

bool CraftTable::isAllTool() {
    int cnt = 2;
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->second) {
            // if slot not empty
            if (it->second->getIsTool() && cnt >= 0) {
                --cnt;
            } else {
                //if (!it->second->getIsTool() || cnt < 0)                
                return false;
            }
        }
    } 
    return true;
};

// int CraftTable::checkMultiple(Recipe recipe) {
//     int res = 0;
//     vector<string> recipeArray = trimKosong(recipe.getRecipe());
//     int idx = 0;
//     int tempMultiple = 0;
//     for (auto it = table.begin(); it != table.end(); ++it) {
//         if (it->second) {
//             if (it->second->getQuantity() != 1) {
//                 res = 1;
//                 int quantityItem = it->second->getQuantity();
//                 if (idx == 0) {
//                     tempMultiple = quantityItem;
//                 } else {
//                     if (tempMultiple != quantityItem) {
//                         tempMultiple = min(tempMultiple, quantityItem);
//                     }
//                 }

//             } else {
//                 return 1;
//             }
//         }
//         ++idx;
//     }

//     if (res == -1) {
//         for (auto it = table.begin(); it != table.end(); ++it) {
//         if (it->second) {
//             if (it->second->getQuantity() != 1) {
//                 res = 1;
//                 int quantityItem = it->second->getQuantity();
//                 if (idx == 0) {
//                     tempMultiple = quantityItem;
//                 } else {
//                     if (tempMultiple != quantityItem) {
//                         tempMultiple = min(tempMultiple, quantityItem);
//                     }
//                 }

//             } else {
//                 return 1;
//             }
//         }
//         ++idx;
//     }
//     }
// };


