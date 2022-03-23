#ifndef CRAFT_H
#define CRAFT_H

#define MAX_CAP 9
#include "Item.hpp"
#include "Recipe.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
#include "Exception.hpp"
#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

class CraftTable {
    private:
        map<string, Item*> table;
    public:
        CraftTable(); // Ctor
        CraftTable(const CraftTable& CraftTable);// CCtor
        // Overload
        CraftTable& operator=(const CraftTable& craftTable);
        // Getter Setter Push Pop
        Item& getItemInCraftTable(string c_id);
        void add(Item& item, string c_id); // Add item to c_id slot, if not empty throw error
        void substract(string c_id, int N); // Delete item from c_id slot to be empty, if empty throw error
        // Method
        void print(); // Print all the values of the Crafting Table
        vector<Item*> make(vector<Recipe*> recipe, list<Item*> legalItem); // return Item as a result of crafting
        Tool* makeTool();
        void afterCraft(int multiplicity);
        int whichBuildable(vector<Recipe*> listRecipe, list<Item*> legalItem);
        vector<string> getTableToCheck(vector<string> table, list<Item*> legalItem);
        int checkMultiple();
        vector<string> convertVector();
        // Attribute
        bool isSlotEmpty(string c_id);
        bool isTableEmpty();
        bool isAllTool();
};

bool isCIDValid(string c_id);
int get_idx(string c_id);
string get_cid(int idx);

#endif