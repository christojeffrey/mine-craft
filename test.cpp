#include "src/CraftTable.hpp"
#include "src/Item.hpp"
#include "src/Tool.hpp"
#include "src/NonTool.hpp"
#include "src/Recipe.hpp"
#include "src/GameState.hpp"
#include "src/Exception.hpp"
#include "src/Inventory.hpp"
#include <assert.h>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <sstream>
#include <map>

void testCraftTable() {
    CraftTable a;
    assert(a.isTableEmpty()); // test if craft table is empty
    assert(a.size() == 0); // test if craft table size is 0 because empty

    // assert(!a.isTableEmpty()); // should terminate
    a.print();
    Item* tool1 = new Tool(1, "WOODEN_SWORD", 10);
    Item* tool2 = new Tool(2, "WOODEN_AXE", 10);

    a.add(*tool1, "C0");
    a.add(*tool2, "C8");
    assert(a.isAllTool()); // test if craft table is all tool

    a.substract("C0", 1);
    assert(a.isSlotEmpty("C0")); // test if craft table slot is empty
    a.substract("C8", 1);
    assert(a.isSlotEmpty("C8")); // test if craft table slot is empty
    assert(a.isTableEmpty());
}    

void testGameState(){
    list<Item*> legalItem;
    legalItem.push_back(new Tool(1, "WOODEN_SWORD", 10));
    vector<Recipe*> legalRecipe;
    vector<string> s;
    s.push_back("BAHAN BAHAN");
    legalRecipe.push_back(new Recipe(1,2,s,new Tool(1, "WOODEN_SWORD", 10),1));
    GameState* gs = new GameState(legalItem,legalRecipe);
    gs->GIVE("WOODEN_SWORD",1);
    gs->SHOW();
    gs->DISCARD("I0",5);
    vector<string> p;
    p.push_back("C0");
    gs->MOVE("I0",1,p);
    gs->MOVE("C0",1,"I0");
    gs->MOVE("I0","I1");
    gs->USE("I1");
    gs->USE("I6");  
}

void testItem(){
    Tool *a = new Tool(1, "WOODEN_SWORD", 10);
    NonTool *b = new NonTool(2, "WOODEN_AXE", "AXE", 10);
    assert(a->getID() == 1);
    assert(a->getName() == "WOODEN_SWORD");
    assert(a->getIsTool() == true);
    assert(a->getNonToolClass() == "");
    assert(a->getQuantity() == 10);
    assert(b->getID() == 2);
    assert(b->getName() == "WOODEN_AXE");
    assert(b->getIsTool() == false);
    assert(b->getNonToolClass() == "AXE");
    assert(b->getQuantity() == 10);
}
int main() {
    testCraftTable();
    testGameState();
    testItem();
}