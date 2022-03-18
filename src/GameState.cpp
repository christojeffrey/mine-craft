using namespace std;

#include "GameState.hpp"
#include "CraftTable.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

GameState::GameState(list<Item> _legalItem, list<CraftTable> _legalRecipe){
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
        } catch(...){
            //kalau inventory penuh
        }
    }else{
        throw "Nama item tidak ditemukan";
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
                this->craftTable.add(itemnyaapa,c_id);
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
        this->craftTable.substract(C_id);
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
        this->craftTable.make();
    }catch(...){ 
        //bila tidak sesuai dengan resep
    }
}
void GameState::EXPORT(string namaFile){

}