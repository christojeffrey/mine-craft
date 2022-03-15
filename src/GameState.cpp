using namespace std;

#include "GameState.hpp"
#include "Craft.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

GameState::GameState(list<Item> _legalItem, list<Craft> _legalRecipe){
    this->legalItem = _legalItem;
    this->legalRecipe = _legalRecipe;
    this->craft = Craft(); //buat craft kosong
    this->inventory = Inventory(); //buat inventory kosong
}
void GameState::SHOW(){
    this->craft.print();
    this->inventory.print();
}
void GameState::GIVE(string item_name, int qty){
    try{
        this->inventory.add(item_name,qty);
    } catch(...){
        //kalau inventory penuh
    }
}
void GameState::DISCARD(string I_id, int qty){
    try{
        this->inventory.substract(I_id,qty);
    }catch(...){
        //kalau I_id tersebut kosong atau kurang
    }
}
void GameState::MOVE(string I_id, int N, vector<string> C_id){
    try{
        Item itemnyaapa=0;
        this->inventory.substract(I_id,N);
        try{
            for(iterasi vector c_id){
                this->craft.add(itemnyaapa,c_id);
            }
        }catch(...){
            //kalau di C_id sudah ada yg menempati
            this->inventory.add(itemnyaapa,N);
        }
    }catch(...){
        //kalau jumlah di inventory kurang
    }
}
void GameState::MOVE(string C_id, string I_id){
    try{
        Item itemnyaapa=0;
        this->craft.substract(C_id);
        this->inventory.add(itemnyaapa,I_id);
    }catch(...){
        //kalau di craft kosong atau inventory penuh
    }
}
void GameState::USE(string I_id){
    try{
        this->inventory.use(I_id); //sudah termasuk menghilangkan bila durability 0
    }catch(...){
        //kalau I_id bukan tool
    }
}
void GameState::CRAFT(){
    try{
        this->craft.make();
    }catch(...){
        //bila tidak sesuai dengan resep
    }
}
void GameState::EXPORT(string namaFile){

}