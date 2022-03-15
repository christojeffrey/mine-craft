#ifndef CRAFT_H
#define CRAFT_H

#define MAX_CAP 9
#include <iostream>
#include <map>
#include "Item.hpp"
using namespace std;

class CraftTable {
    private:
        Item* tableTool;
        Item* tableNonTool;
    public:
        CraftTable(); // Ctor
        CraftTable(const CraftTable& CraftTable);// CCtor
        // Overload
        CraftTable& operator=(const CraftTable& craftTable);
        // Getter Setter
        Item getItemInCraftTable(string c_id);
        Item setItemInCraftTable(string c_id, Item other);
        // Method
        void print(); // Print all the values of the Crafting Table
        void add(Item item, string c_id); // Add item to c_id slot, if not empty throw error
        void substract(string c_id); // Delete item from c_id slot to be empty, if empty throw error
        Item make(); // return Item as a result of crafting
        // Attribute
        bool isSlotToolEmpty(string c_id);
        bool isSlotNonToolEmpty(string c_id);
        bool isTableEmpty(string c_id);
};

#endif