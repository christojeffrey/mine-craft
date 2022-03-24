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

void testInventory(){
    Inventory inven;
    cout << "=======\n";
    cout << "Test inventory kosong\n";
    inven.printInfo();
    cout << "Inventory seharusnya kosong\n";

    cout << "=======\n";
    cout << "Test menambah item NonTool di inventory tanpa index\n";
    inven.add(new NonTool(10, "IRON_INGOT", "-", 10));
    inven.printInfo();
    cout << "Inventory seharusnya berisi 10 IRON_INGOT pada I0\n";

    cout << "=======\n";
    cout << "Test menambah item NonTool di inventory dengan index\n";
    inven.add(new NonTool(10, "IRON_INGOT", "-", 10), "I1");
    inven.printInfo();
    cout << "Inventory seharusnya berisi 10 IRON_INGOT pada I1\n";

    cout << "=======\n";
    cout << "Test menambah item NonTool di inventory yang otomatis menambah\n";
    inven.add(new NonTool(10, "IRON_INGOT", "-", 64));
    inven.printInfo();
    cout << "Inventory seharusnya berisi 64 IRON_INGOT pada I0 dan I1\n";

    cout << "=======\n";
    cout << "Test menambah item Tool di inventory tanpa index\n";
    inven.add(new Tool(18, "STONE_AXE", 10));
    inven.printInfo();
    cout << "Inventory seharusnya berisi STONE_AXE pada I2 dengan durability 10\n";

    cout << "=======\n";
    cout << "Test menambah item Tool di inventory dengan index\n";
    inven.add(new Tool(18, "STONE_AXE", 10), "I4");
    inven.printInfo();
    cout << "Inventory seharusnya berisi STONE_AXE pada I4 dengan durability 10\n";

    cout << "=======\n";
    cout << "Test memindah I0 ke I2\n";
    try{
        inven.move("I0", "I2");
        inven.printInfo();
    } catch (BaseException* e){
        e->printMessage();
    }
    cout << "Inventory seharusnya tidak berubah\n";

    cout << "=======\n";
    cout << "Test memindah I0 ke I3\n";
    inven.move("I0", "I3");
    inven.printInfo();
    cout << "Inventory pada I0 seharusnya kosong dan IRON_INGOT sebanyak 64 pindah ke I3\n";

    cout << "=======\n";
    cout << "Test substract I3 sebanyak 70\n";
    try {
        inven.substract("I3", 70);
        inven.printInfo();
    } catch (BaseException* e){
        e->printMessage();
    }
    cout << "Seharusnya muncul pesan error\n";

    cout << "=======\n";
    cout << "Test substract I3 sebanyak 10\n";
    inven.substract("I3", 10);
    inven.printInfo();
    cout << "Inventory pada I3 IRON_INGOT sebanyak 54\n";

    cout << "=======\n";
    cout << "Test menggunakan I3\n";
    try{
        inven.use("I3");
        inven.printInfo();
    } catch (BaseException* e){
        e->printMessage();
    }
    cout << "Seharusnya muncul error\n";

    cout << "=======\n";
    cout << "Test menggunakan I2\n";
    inven.use("I2");
    inven.printInfo();
    cout << "Inventory pada I2 seharusnya STONE_AXE dengan durability 9\n";

    cout << "=======\n";
    cout << "Test menggunakan I2 hingga habis\n";
    for(int i = 0; i < 9; i++){
        inven.use("I2");
    }
    inven.printInfo();
    cout << "Inventory pada I2 seharusnya hilang\n";

    cout << "=======\n";
    cout << "Test getItem pada I3\n";
    Item* item = inven.getItem("I3");
    item->printInfo();
    cout << "Seharusnya print IRON_INGOT sebanyak 54\n";
}

int main() {
    testCraftTable();
    cout << "==== TEST INVENTORY ====" << endl;
    testInventory();
}