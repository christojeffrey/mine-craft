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
    bool isTool;

    list<Item*>::iterator it;
    for (it = legalItem.begin(); it != legalItem.end(); it++){
        if((*it)->getName()==item_name){
            found=true;
            id = (*it)->getID();
            isTool = (*it)->getIsTool();
            if (!isTool){
                type = (*it)->getNonToolClass();
            }
            break;
        }
    }
    if (found) {
        try {
            // cek dulu dia tool atau bukan
            if(isTool){
                for (int i = 0; i < qty; i++){
                    this->inventory.add(new Tool(id, item_name, 10));
                }
            } else {
                if (qty > MAX_QUANTITY) {
                    while (qty > MAX_QUANTITY) {
                        this->inventory.add(new NonTool(id, item_name, type, MAX_QUANTITY));
                        qty -= MAX_QUANTITY;
                    }
                    this->inventory.add(new NonTool(id, item_name, type, qty));
                } else if (qty < 0){
                    throw new negativeValueGivenException();
                } else { 
                    this->inventory.add(new NonTool(id,item_name,type,qty));
                }
            }
        } catch(BaseException *e){
            //kalau inventory penuh
            e->printMessage();
        }
    }else{
        throw new inventoryItemNameIsNotFoundException();
    }
}
void GameState::DISCARD(string I_id, int qty){
    try{
        this->inventory.substract(I_id,qty);
    }catch(BaseException *e){
        //kalau I_id tersebut kosong atau kurang
        e->printMessage();
    }
}
void GameState::MOVE(string I_id, int N, vector<string> C_id){ //inven ke craft
    try{
        Item* itemnyaapa = this->inventory.getItem(I_id);
        Item* itemnyaapa_copy;
        
        try {
            for(vector<string>::iterator it=C_id.begin(); it!=C_id.end(); ++it){
                if (!isCIDValid(*it)) {
                    throw new CIDNotValidException();
                }
            }

            if(!itemnyaapa->getIsTool()){
                if(itemnyaapa->getQuantity()<N){
                    throw new itemQuantityIsNotSufficientException();
                }
            }else{
                if(N!=1){
                    throw new itemQuantityIsNotSufficientException();
                }
            }
            
            for(vector<string>::iterator it=C_id.begin(); it!=C_id.end(); ++it){
                try{
                    this->inventory.substract(I_id,1);
                    if (itemnyaapa->getIsTool()){
                        itemnyaapa_copy = new Tool(itemnyaapa->getID(), itemnyaapa->getName(), itemnyaapa->getDurability());
                    } else {
                        itemnyaapa_copy = new NonTool(itemnyaapa->getID(), itemnyaapa->getName(), itemnyaapa->getNonToolClass(), 1);
                    }
                    this->craftTable.add(*itemnyaapa_copy,*it);
                }catch(BaseException *e){
                    this->inventory.add(itemnyaapa_copy,I_id);
                    throw e;

                }
            }
        }catch(BaseException *e){
            throw e;
        }
    }catch(BaseException *e){
        //kalau jumlah di inventory kurang
        e->printMessage();
    }
}
void GameState::MOVE(string i_id1, string i_id2){ //inven ke inven
    try{
        this->inventory.move(i_id1,i_id2);
    }catch(BaseException *e){
        //kalau di craft kosong atau inventory penuh
        e->printMessage();
    }
}

void GameState::MOVE(string c_id, int N, string i_id){
        try{
            Item& itemnyaapa = this->craftTable.getItemInCraftTable(c_id);
            Item* copy;
            if(itemnyaapa.getIsTool()){
                copy = new Tool(itemnyaapa.getID(),itemnyaapa.getName(),itemnyaapa.getDurability());
            }else{
                copy = new NonTool(itemnyaapa.getID(),itemnyaapa.getName(), itemnyaapa.getNonToolClass(), N);
            }
            this->craftTable.substract(c_id,N);
            this->inventory.add(copy,i_id);
            itemnyaapa.printInfo();
        }catch(BaseException *e){
            //kalau di craft kosong atau inventory penuh
            e->printMessage();
        }
}
void GameState::USE(string I_id){
    try{
        this->inventory.use(I_id); //sudah termasuk menghilangkan bila durability 0
    }catch(BaseException *e){
        //kalau I_id bukan tool
        e->printMessage();
    }
}
void GameState::CRAFT(){
    try{
        vector<Item*> hasil = this->craftTable.make(this->legalRecipe, this->legalItem);
        for (int i = 0; i < hasil.size(); i++) {
            this->inventory.add(hasil[i]);
        }
    }catch(BaseException *e){
        //bila tidak sesuai dengan resep
        e->printMessage();
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
            result << "0:0" <<endl;
        }
    }
    result.close();
}