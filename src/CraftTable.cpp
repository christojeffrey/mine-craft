#include <iostream>
#include "CraftTable.hpp"
using namespace std;

// Ctor
CraftTable::CraftTable() {
    tableTool = new Item[MAX_CAP];
    tableNonTool = new Item[MAX_CAP];
    for (int i = 0; i < MAX_CAP; i++) {
        this->tableTool[i] = Item();
        this->tableNonTool[i] = Item();
    }
}; 
// CCtor
CraftTable::CraftTable(const CraftTable& other) {
    tableTool = new Item[MAX_CAP];
    tableNonTool = new Item[MAX_CAP];
    for (int i = 0; i < MAX_CAP; i++) {
        this->tableTool[i] = other.tableTool[i];
        this->tableNonTool[i] = other.tableNonTool[i];
    }
};

// Overload
CraftTable& CraftTable::operator=(const CraftTable& other) {
    delete[] tableTool;
    delete[] tableNonTool;
    for (int i = 0; i < MAX_CAP; i++) {
        this->tableTool[i] = other.tableTool[i];
        this->tableNonTool[i] = other.tableNonTool[i];
    }
};

// Getter Setter
Item& CraftTable::getItemInCraftTable(string c_id) {
    // determine which is not empty

    int idx = (int)c_id[1];
    if (notempty) {
        return (tableTool[idx]);
    } else {
        return (tableNonTool[idx]);
    }
};

Item CraftTable::setItemInCraftTable(string c_id, Item item) {
    int idx = (int)c_id[1];
    if (getType(item) == "tool") {
        return tableTool[idx];        
    } else {
        return tableNonTool[idx];
    }
};


// Method
void CraftTable::print() {
    for (int i = 0; i < MAX_CAP; i++) {
        if (not null) {
            cout << tableTool[i] << " ";
        } else {
            cout << tableNonTool[i] << " ";
        }
        if (i==2 || i==5 || i==8) {
            cout << endl;
        }
    }
}; // Print all the values of the Crafting Table
void CraftTable::add(Item item, string c_id) {
    int idx = (int)c_id[1];
    if (getType(item) == "tool") {
        if (not empty) throw exception;
        tableTool[idx] = item;
    } else {
        if (not empty) throw exception;
        tableNonTool[idx] = item;
    }
}; // Add item to c_id slot, if not empty throw error
void CraftTable::substract(string c_id) {
    Item val;
    int idx = (int)c_id[1];
    if (not empty) throw exception;
    tableTool[idx] = NULL;
    tableNonTool[idx] = NULL;
}; // Delete item from c_id slot to be empty, if empty throw error
Item CraftTable::make() {

}; // return Item as a result of crafting


// Attribute
// bool CraftTable::isSlotToolEmpty(string c_id) {
//     int idx = (int)c_id[1];
//     return (this->tableTool[idx] == NULL);
// };

// bool CraftTable::isSlotNonToolEmpty(string c_id) {

// };

// bool CraftTable::isTableEmpty(string c_id) {

// };

