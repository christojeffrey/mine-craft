using namespace std;

#include "GameState.hpp"
#include "CraftTable.hpp"
#include "Inventory.hpp"
#include "Item.hpp"
#include "Exception.hpp"
GameState::GameState(list<Item> _legalItem, vector<Recipe> _legalRecipe){
    this->legalItem = _legalItem;
    this->legalRecipe = _legalRecipe;
    this->craftTable = CraftTable(); //buat craft kosong
    this->inventory = Inventory(); //buat inventory kosong
}
void GameState::SHOW(){
    this->craftTable.print();
    this->inventory.printInfo();
}
void GameState::GIVE(string item_name, int qty){
    bool found=false;
    string type;
    list<Item>::iterator it = this->legalItem.begin();
    while(it!=this->legalItem.end()){
        if(it->getName()==item_name){
            found=true;
            type = it->getType();
        }else{
            ++it;
        }
    }
    if(found){
        try{
            this->inventory.add(new NonTool(item_name,type,qty));
        } catch(BaseException *e){
            e->printMessage();
            //kalau inventory penuh
        }
    }else{
        throw new inventoryItemNameIsNotFoundException;
    }
}
void GameState::DISCARD(string I_id, int qty){
    try{
        this->inventory.substract(I_id,qty);
    }catch(BaseException *e){
        e->printMessage();
        //kalau I_id tersebut kosong atau kurang
    }
}
void GameState::MOVE(string I_id, int N, vector<string> C_id){
    try{
        Item* itemnyaapa = this->inventory.getItem(I_id);
        this->inventory.substract(I_id,N);
        try{
            itemnyaapa->substract(1);
            for(vector<string>::iterator it=C_id.begin(); it!=C_id.end(); ++it){
                this->craftTable.add(*itemnyaapa,*it);
            }
        }catch(BaseException *e){
            e->printMessage();
            //kalau di C_id sudah ada yg menempati

            this->inventory.add(itemnyaapa);
        }
    }catch(BaseException *e){
        e->printMessage();
        //kalau jumlah di inventory kurang
    }
}
void GameState::MOVE(string C_id, string I_id){
    try{
        Item* itemnyaapa = this->inventory.getItem(I_id);
        this->craftTable.substract(C_id);
        this->inventory.add(itemnyaapa,I_id);
    }catch(BaseException *e){
        e->printMessage();
        //kalau di craft kosong atau inventory penuh
    }
}
void GameState::USE(string I_id){
    try{
        this->inventory.use(I_id); //sudah termasuk menghilangkan bila durability 0
    }catch(BaseException *e){
        e->printMessage();
        //kalau I_id bukan tool
    }
}
void GameState::CRAFT(){
    try{
        this->craftTable.make(this->legalRecipe);
    }catch(BaseException *e){
        e->printMessage();
        //bila tidak sesuai dengan resep
    }
}
void GameState::EXPORT(string namaFile){

}