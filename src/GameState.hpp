#include "Item.hpp"
#include "Inventory.hpp"
#include "Craft.hpp"
#include <string>

class GameState{
    private:
        Item * legalItem;
        Craft * legalRecipe;
        Inventory inventory;
        Craft craft;
    public:
        GameState();
        void SHOW();
        void GIVE(string item_name, int qty);
        void DISCARD(string I_id, int qty);
        void MOVE(string I_id, int N, vector<string> C_id); //dari inventory ke craft
        void MOVE(string C_id, string I_id); //dari craft ke inventory
        void USE(string I_id);
        void CRAFT();
        void EXPORT(string namaFile);

}




// MOVE I0 1 I1