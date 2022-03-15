using namespace std;

#include "Item.hpp"
#include "Inventory.hpp"
#include "Craft.hpp"
#include <string>
#include <vector>
#include <list>

class GameState{
    private:
        list<Item> legalItem;
        list<Craft> legalRecipe;
        Inventory inventory;
        Craft craft;
    public:
        GameState(list<Item> _legalItem, list<Craft> _legalRecipe);
        void SHOW();
        void GIVE(string item_name, int qty);
        void DISCARD(string I_id, int qty);
        void MOVE(string I_id, int N, vector<string> C_id); //dari inventory ke craft
        void MOVE(string C_id, string I_id); //dari craft ke inventory
        void USE(string I_id);
        void CRAFT();
        void EXPORT(string namaFile);

};
