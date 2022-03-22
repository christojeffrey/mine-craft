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
    // for (int idx = 0; idx < B.size(); idx++) {
    //     cout <<  B[idx] << endl;
    // }
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
        throw new CIDNotValidException();
    }
};

void CraftTable::add(Item& item, string c_id) {
    cout << "Adding to " << c_id << "item named " << item.getName();
    // Add item to c_id slot, if not empty throw error
    if (isCIDValid(c_id)) {
        cout << "is slot empty "<<isSlotEmpty(c_id) << endl;
        if (isSlotEmpty(c_id)) {
            table[c_id] = &item;
            cout<<"isi table cid" << table[c_id]->getName() << endl;
        } else {
            if (table[c_id]->getName() == item.getName()) {
                table[c_id]->setQuantity(table[c_id]->getQuantity()+1); 
            } else {
                throw new craftTableIsNotEmptyException();
            }
            // TAnya kakaknya kalo move dari inven ke craftable dan ternyata di craftable udah ada, tapi beda nama, itu ganti item di craftablenya atau throw error
        }
    } else {
        cout << "THROW" << endl;
        throw new CIDNotValidException();
    }
}; 
void CraftTable::substract(string c_id, int N) {
    // Delete item from c_id slot to be empty, if empty throw error
    if (isCIDValid(c_id)) {
        if (!isSlotEmpty(c_id)) {
            table[c_id]->setQuantity(table[c_id]->getQuantity() - N);
            if (table[c_id]->getQuantity() == 0) {
                table[c_id] = NULL;
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
   for (int i = 0; i < MAX_CAP; i++) {
        string key = get_cid(i);
        if (table[key]) {
            if (i == 2 || i == 5) {
                cout << table[key]->getName() << endl;
            } else {
                cout << table[key]->getName() << " ";
            }
        } else {
            if (i == 2 || i == 5) {
                cout << "KOSONG" << endl;
            } else {
                cout << "KOSONG" << " ";
            }
        }
    }
    cout << endl;
}; 

Item* CraftTable::make(vector<Recipe*> recipe, list<Item*> legalItem) {
    /* Jika terdapat resep yang memenuhi, Item bahan akan hilang dan Item hasil akan muncul. Item akan otomatis ditambahkan ke inventory dengan
    algoritma yang sama dengan command GIVE. */
    if (!this->isTableEmpty()) {
        cout << "Masuk table not empty craftable make\n";
        if (!this->isAllTool()) {

            cout << "Masuk table not is All tool tp belom whichbuildable craftable make\n";
            bool reflected = false;
            int idx = whichBuildable(recipe, legalItem, reflected);
            cout << "masuk sini dapet indeks" << endl;
            if (idx != -1) {
                // If recipe matched with craft table
                Recipe* itemCrafted = recipe[idx];
                cout << "masuk sini dapet resep yang dibuat" << endl;
                int multiplicity = this->checkMultiple();
                cout << "masuk sini dapet multiple" << endl;
                afterCraft(multiplicity);
                cout << "masuk sini ngosongin table" << endl;

                if (itemCrafted->getItem()->getIsTool() == true) {
                    return new Tool(itemCrafted->getItem()->getID(), itemCrafted->getItem()->getName(), 10);
                } else {
                    return new NonTool(itemCrafted->getItem()->getID(), itemCrafted->getItem()->getName(), itemCrafted->getItem()->getNonToolClass(), itemCrafted->getQuantityResult()*multiplicity);
                }
                
            } else {
                // If recipe not matched with craft table, check craft table reflected by Y-axis
                reflected = true;
                idx = whichBuildable(recipe, legalItem, reflected);
                cout << "masuk sini dapet indeks cermin" << endl;
                if (idx != -1) {
                    int multiplicity = this->checkMultiple();
                    cout << "masuk sini dapet multiple cermin" << endl;
                    afterCraft(multiplicity);
                    cout << "masuk sini ngosngin table cermin" << endl;
                    Recipe* itemCrafted = recipe[idx];
                    if (itemCrafted->getItem()->getIsTool() == true) {
                        return new Tool(itemCrafted->getItem()->getID(), itemCrafted->getItem()->getName(), 10);
                    } else {
                        return new NonTool(itemCrafted->getItem()->getID(), itemCrafted->getItem()->getName(), itemCrafted->getItem()->getNonToolClass(), itemCrafted->getQuantityResult()*multiplicity);
                    }
                    cout << "masuk sini dapet resep yang dibuat cermin" << endl;
                } else {
                    // cannot build items in craft table
                    cout << "masuk throw ga ada resep" << endl;
                    throw new craftTableDoesntMatchRecipeException();
                }
            }

        } else {
            // If build Tool sum by durability
            cout << "Masuk nambah durability tool\n";
            Tool* sumTool = makeTool();
            Item* res = new Tool(sumTool->getID(), sumTool->getName(), sumTool->getDurability());
            return res;
        }
        
    } else {
        cout << "Masuk throw table empty craftable make\n";
        throw new craftTableIsEmptyException();
    }
};

void CraftTable::afterCraft(int multiplicity) {
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

int CraftTable::whichBuildable(vector<Recipe*> listRecipe, list<Item*> legalItem, bool reflected) {
    int res = -1;
    for (int i = 0; i < listRecipe.size(); i++) {
        int row = listRecipe[i]->getRow();
        int col = listRecipe[i]->getCol();
        cout << "masuk awal\n";
        cout << "RESEP YANG DIBUAT : " << listRecipe[i]->getItem()->getName();
        vector<string> recipe = listRecipe[i]->getRecipe();
        cout << "masuk abis dapet resep\n";
        vector<string> table;
        if (!reflected) {
            table = (this->convertVector());
            cout << "masuk abis dapet konversi vector\n";
        } else {
            cout << "Mau direflect di whichbuildable\n";
            table = reflectYTable(this->convertVector());
            cout << "Sudah direflect di whichbuildable\n";
        }
        // table get non tool class
        table = getTableToCheck(table, legalItem);
        table = trimKosong(table);
        cout << "isi table " << endl;
        // for (auto it = table.begin(); it != table.end(); it++){
        //     cout << (*it) << endl;
        // }
        cout << "masuk abis trim\n";
        // check recipe is subarray of a table array
        if (isSubArray(recipe, table, recipe.size(), table.size())) {
            cout << "masuk abis cek subarray\n";
            res = i;
            break;
        }

        if (listRecipe[i]->getItem()->getName() == "STICK") {
            throw new invalidCommandToItem();
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

// Attribute
bool CraftTable::isSlotEmpty(string c_id) {
    if (isCIDValid(c_id))
        return (!table[c_id]);
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

int CraftTable::checkMultiple() {
    int idx = 0;
    int multiplicity = 0;
    for (auto it = table.begin(); it != table.end(); ++it) {
        if (it->second) {
            if (it->second->getQuantity() != 1) {
                int quantityItem = it->second->getQuantity();
                if (idx == 0) {
                    multiplicity = quantityItem;
                } else {
                    if (multiplicity > quantityItem) {
                        multiplicity = quantityItem;
                    }
                }

            } else {
                return 1;
            }
        }
        ++idx;
    }
    return multiplicity;
};
vector<string> CraftTable::getTableToCheck(vector<string> table, list<Item*> legalItem){
    //iterate legal item, masing2 add ke hasil
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