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
    // Get index from key
    int res = c_id[1] - '0';
    return res;
};

bool isCIDValid(string c_id) {
    // Check if key is valid in capacity
    int idx = get_idx(c_id);
    return (idx >= 0 && idx < MAX_CAP);
};


bool isSubArray(vector<string> A, vector<string> B, int n, int m) {
    // to check if B is subarray of A
    int i = 0, j = 0;
    while (i < n && j < m) {
        cout << "table : " << B[j] << endl;
        cout << "recipe : " << A[i] << endl;
        if (A[i] == B[j]) {
            i++;
            j++;
            if (j == m)
                return true;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    return false;
}

vector<string> trimKosong(vector<string> table) {
    // To cut out the "-" (empty) part in table
    while (*(table.begin()) == "-") {
        table.erase(table.begin());
    }

    for (int i = table.size()-1; i>=0; i--) {
        if (table[i] == "-") {
            table.pop_back();
        } else {
            break;
        }
    }
    
    return table;
};

vector<string> reflectYTable(vector<string> table) {
    // reflect table by y-axis
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
    // Get item in craft table by key
    if (isCIDValid(c_id))
        return *table[c_id];
    else {
        throw new CIDNotValidException();
    }
};

void CraftTable::add(Item& item, string c_id) {
    // Add item to slot key
    cout << "Adding to " << c_id << "item named " << item.getName();
    // Add item to c_id slot, if not empty throw error
    if (isCIDValid(c_id)) {
        if (isSlotEmpty(c_id)) {
            table[c_id] = &item;
        } else {
            // if slot not empty then add by quantity
            if (table[c_id]->getName() == item.getName() || table[c_id]->getNonToolClass() == item.getNonToolClass()) {
                table[c_id]->setQuantity(table[c_id]->getQuantity()+1); 
            } else {
                throw new craftTableIsNotEmptyException();
            }
        }
    } else {
        throw new CIDNotValidException();
    }
}; 
void CraftTable::substract(string c_id, int N) {
    // Delete item from c_id slot to be empty, if empty throw error
    if (isCIDValid(c_id)) {
        if (!isSlotEmpty(c_id)) {
            int remain = table[c_id]->getQuantity() - N;
            if (remain < 0){
                throw new ItemQuantityIsNotSufficientException();
            } else if (remain == 0) {
                table[c_id]=NULL;
            } else {
                table[c_id]->setQuantity(table[c_id]->getQuantity() - N);
            }
        } else {
            throw new craftTableIsEmptyException();
        }
    } else {
        throw new CIDNotValidException();
    }
}; 

// Method
void CraftTable::print() {
    // Output information of craft table per slot
    for (int i = 0; i < MAX_CAP; i++) {
        string key = get_cid(i);
        if (table[key]) {
            if (i == 2 || i == 5) {
                cout << "[" << table[key]->getName() << "]" << endl;
            } else {
                cout << "[" << table[key]->getName() << "]" << " ";
            }
        } else {
            if (i == 2 || i == 5) {
                cout << "[KOSONG]" << endl;
            } else {
                cout << "[KOSONG]" << " ";
            }
        }
    }
    cout << endl;
}; 

vector<Item*> CraftTable::make(vector<Recipe*> recipe, list<Item*> legalItem) {
    /* Jika terdapat resep yang memenuhi, Item bahan akan hilang dan Item hasil akan muncul. Item akan otomatis ditambahkan ke inventory dengan
    algoritma yang sama dengan command GIVE. */
    if (!this->isTableEmpty()) {
        cout << "Masuk table not empty craftable make\n";
        if (!this->isAllTool()) {
            cout << "Masuk table not is All tool tp belom whichbuildable craftable make\n";
            int idx = whichBuildable(recipe, legalItem);
            cout << "masuk sini dapet indeks" << endl;
            if (idx != -1) {
                // If recipe matched with craft table
                Recipe* itemCrafted = recipe[idx];
                cout << "masuk sini dapet resep yang dibuat" << endl;
                int multiplicity = this->checkMultiple();
                cout << "kelipatan" << multiplicity << endl;
                afterCraft(multiplicity);
                cout << "masuk sini ngosongin table" << endl;

                if (itemCrafted->getItem()->getIsTool() == true) {
                    vector<Item*> res(multiplicity);
                    for (int i = 0; i < multiplicity; i++) {
                        res[i] = new Tool(itemCrafted->getItem()->getID(), itemCrafted->getItem()->getName(), 10);
                    }
                    return res;
                } else {
                    vector<Item*> res;
                    res.push_back(new NonTool(itemCrafted->getItem()->getID(), itemCrafted->getItem()->getName(), itemCrafted->getItem()->getNonToolClass(), itemCrafted->getQuantityResult()*multiplicity));
                    return res;
                }
                
            } else {
                // cannot build items in craft table
                cout << "masuk throw ga ada resep" << endl;
                throw new craftTableDoesntMatchRecipeException();
            }
        } else {
            if (this->size() > 2) throw new craftTableDoesntMatchRecipeException(); // THrow if there are tool more than 2
            // If build Tool sum by durability
            cout << "Masuk nambah durability tool\n";
            Tool* sumTool = makeTool();
            vector<Item*> res(1);
            res[0] = new Tool(sumTool->getID(), sumTool->getName(), sumTool->getDurability());
            return res;
        }
    } else {
        cout << "Masuk throw table empty craftable make\n";
        throw new craftTableIsEmptyException();
    }
};

void CraftTable::afterCraft(int multiplicity) {
    // For multiple crafting, empty if only items in crafttable are all used
    if (!this->isTableEmpty()) {
        for (auto it = table.begin(); it != table.end(); it++) {
            if (it->second) {
                int quantity = it->second->getQuantity();
                if (quantity == multiplicity) {
                    it->second = NULL;
                } else if (quantity > multiplicity) {
                    it->second->setQuantity(quantity - multiplicity);
                }
            }
        }
    } else {
        throw new craftTableIsEmptyException();
    }
};

Tool* CraftTable::makeTool() {
    // To make tool sum by durability, max durability is 10
    cout << "masuk makeTool" << endl;
    string name;
    int sum = 0, id = 0;
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->second) {
            id = it->second->getID();
            name = it->second->getName();
            sum += it->second->getDurability();

            it->second = NULL;
        }
    }
    sum = min(10, sum);
    return new Tool(id, name, sum);
};

int CraftTable::whichBuildable(vector<Recipe*> listRecipe, list<Item*> legalItem) {
    // Return an index where recipe is match in listRecipe
    int res = -1;
    for (int i = 0; i < listRecipe.size(); i++) {
        int row = listRecipe[i]->getRow();
        int col = listRecipe[i]->getCol();
        cout << "RESEP YANG DIBUAT : " << listRecipe[i]->getItem()->getName();
        // Get the recipe to be checked
        vector<string> recipe = listRecipe[i]->getRecipe();
        vector<string> table;
        vector<string> tableReflected;
        // Convert to vector
        table = (this->convertVector());
        cout << "masuk abis dapet konversi vector\n";
        // Get table by non tool class
        table = getTableToCheck(table, legalItem);
        table = trimKosong(table);
        cout << "masuk abis trim\n";
        // Check recipe is subarray of a table array
        if (isSubArray(recipe, table, recipe.size(), table.size())) {
            cout << "masuk abis cek subarray\n";
            res = i;
            break;
        } else {
            // If not matched, check the reflected table
            cout << "Mau direflect di whichbuildable karena di original ga match\n";
            tableReflected = reflectYTable(this->convertVector());
            tableReflected = getTableToCheck(tableReflected, legalItem);
            tableReflected = trimKosong(tableReflected);
            if (isSubArray(recipe, tableReflected, recipe.size(), tableReflected.size())) {
                cout << "masuk abis cek subarray reflected\n";
                res = i;
                break;
            }
        }
    }
    return res;
};

vector<string> CraftTable::convertVector() {
    // Convert map table member in CraftTable to vector of string by its name
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

// Attribute
bool CraftTable::isSlotEmpty(string c_id) {
    // To check if slot is empty by key
    if (isCIDValid(c_id))
        return (!table[c_id]);
    return false;
};

bool CraftTable::isTableEmpty() {
    // To check if craft table is empty
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->second) return false;
    }

    return true;
};

bool CraftTable::isAllTool() {
    // To check if there are only tool in crafttable, return true
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->second) {
            // if slot not empty
            if (!it->second->getIsTool()) {            
                return false;
            }
        }
    } 
    return true;
};

int CraftTable::size() {
    int cnt = 0;
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->second) {
            // if slot not empty
            cnt++;
        }
    }
    return cnt; 
};

int CraftTable::checkMultiple() {
    // To check how many can be built from items in craft table
    int idx = 0;
    int multiplicity = 0;
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->second) {
            int quantityItem = it->second->getQuantity();
            if (quantityItem != 1) {
                if (idx == 0) {
                    multiplicity = quantityItem;
                    idx++;
                } else {
                    multiplicity = min(multiplicity, quantityItem);
                }
            } else {
                return 1;
            }
        }
    }
    return multiplicity;
};
vector<string> CraftTable::getTableToCheck(vector<string> table, list<Item*> legalItem) {
    // Convert table to get its non tool class (PLANK, LOG, etc)
    // If non tool class is empty => use the name (DIAMOND)
    for (auto it = (table).begin(); it != (table).end(); it++) {
        string name = *it;
        if (name == "-") continue;
        for (auto it1 = legalItem.begin(); it1 != legalItem.end(); it1++) {
            if ((*it1)->getName() == name) {
                if ((*it1)->getNonToolClass() != "-" && (*it1)->getNonToolClass() != "LOG"){
                    *it = (*it1)->getNonToolClass();
                    cout << *it << endl;
                } else {
                    break;
                }
            }
        }
    }
    return table;
}