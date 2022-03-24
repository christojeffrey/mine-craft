#ifndef _INVENTORY_HPP
#define _INVENTORY_HPP
#include "Item.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
#include "Exception.hpp"
#include <string>
#include <map>
using namespace std;

#define MAX_INVEN 27

class Inventory{
    private:
        // pake map buat nyatet semua inventory
        map<string, Item*> inven;
    public:
        Inventory();
        ~Inventory();
        void move(string idx1, string idx2);
        void add(Item* item_name);
        void add(Item* item_name,string dest);
        void substract(string I_id, int qty);
        void use(string I_id);
        void printInfo();
        Item * getItem(string I_id);
};

#endif