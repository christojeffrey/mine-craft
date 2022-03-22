using namespace std;

#include "GameState.hpp"
#include "CraftTable.hpp"
#include "Inventory.hpp"
#include "Item.hpp"
#include "Exception.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

GameState::GameState(list<Item*> _legalItem, vector<Recipe*> _legalRecipe){
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
    int id;

    list<Item*>::iterator it;
    for (it = legalItem.begin(); it != legalItem.end(); it++){
        cout << "checking inside give" << endl;
        cout << (*it)->getName() << endl;
        if((*it)->getName()==item_name){
            found=true;
            type = (*it)->getNonToolClass();
            id = (*it)->getID();
            break;
        }
    }
    if(found){
        try{
            cout << "BERHASIL KETEMU" << endl;
            if (qty > 64) {
                qty = 64;
            } else if (qty < 0){
                cout << "QUANTITY JANGAN NEGATIF!!\n";
            } else {
                this->inventory.add(new NonTool(id,item_name,type,qty));
                this->inventory.printInfo();
            }
        } catch(BaseException *e){
            e->printMessage();
            //kalau inventory penuh
        }
    }else{
        throw new inventoryItemNameIsNotFoundException();
    }
    cout << "give done" << endl;
}
void GameState::DISCARD(string I_id, int qty){
    try{
        this->inventory.substract(I_id,qty);
    }catch(BaseException *e){
        e->printMessage();
        //kalau I_id tersebut kosong atau kurang
    }
}
void GameState::MOVE(string I_id, int N, vector<string> C_id){ //inven ke craft
    try{
        Item* itemnyaapa = this->inventory.getItem(I_id);
        Item* itemnyaapa_copy;
        if (itemnyaapa->getIsTool()){
            itemnyaapa_copy = new Tool(itemnyaapa->getID(), itemnyaapa->getName(), itemnyaapa->getDurability());
        } else {
            itemnyaapa_copy = new NonTool(itemnyaapa->getID(), itemnyaapa->getName(), itemnyaapa->getNonToolClass(), 1);
        }
        cout << "kirim ke "<<C_id.size()<<"  tempat di craft" << endl;
        try{
            for(vector<string>::iterator it=C_id.begin(); it!=C_id.end(); ++it){
                if (!isCIDValid(*it)) {
                    throw new CIDNotValidException();
                }
            }
            this->inventory.substract(I_id,N);
            for(vector<string>::iterator it=C_id.begin(); it!=C_id.end(); ++it){
                cout << "ngirim sebuah "<< (*itemnyaapa_copy).getName() << " ke "<< *it << endl;
                this->craftTable.add(*itemnyaapa_copy,*it);
            }
        }catch(BaseException *e){
            e->printMessage();
        }
    }catch(BaseException *e){
        e->printMessage();
        //kalau jumlah di inventory kurang
    }
}
void GameState::MOVE(string i_id1, string i_id2){ //inven ke inven
    try{
        Item* itemnyaapa = this->inventory.getItem(from);
        this->inventory.substract(from,itemnyaapa->getQuantity());
        this->inventory.add(itemnyaapa,to);
        itemnyaapa->printInfo();
    }catch(BaseException *e){
        e->printMessage();
        //kalau di craft kosong atau inventory penuh
    }

}

void GameState::MOVE(string c_id, int N, string i_id){
        try{
            Item& itemnyaapa = this->craftTable.getItemInCraftTable(from);
            this->craftTable.substract(from);
            this->inventory.add(&itemnyaapa,to);
            itemnyaapa.printInfo();
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
        Item* hasil = this->craftTable.make(this->legalRecipe, this->legalItem);
        this->inventory.add(hasil);
    }catch(BaseException *e){
        e->printMessage();
        //bila tidak sesuai dengan resep
    }
}
void GameState::EXPORT(string namaFile){
    ofstream result (namaFile);
    string idx;
    Item * item;
    for(int i=0;i<27;i++){
        idx = "I"+to_string(i);
        try{
            item = this->inventory.getItem(idx);
            if(item->getIsTool()){
                result << item->getID() << ":" << item->getDurability();
            }else{
                result << item->getID() << ":" << item->getQuantity();
            }
            result << endl;
        }catch(...){

        }
    }
}