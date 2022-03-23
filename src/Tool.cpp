#include "Tool.hpp"
#include <string>
#include <iostream>

using namespace std;

Tool::Tool(int ID, string name, int durability) : Item(ID,name,true){
    this->durability=durability;
}

int Tool::getDurability()const{
    return this->durability;
}

void Tool::setDurability(int pengganti){
    this->durability=pengganti;
}

void Tool::printInfo()const{
    Item::printInfo();
    cout << "Durability\t: "<< this->durability <<endl;
}

int Tool::use(){
    //kalo di use, durability di kurangi sebanyak satu
    this->durability--;
    return this->durability;
}

int Tool::substract(int qty){
    //this actually did nothing to the item. return sisa itemnya
    if(qty!=1){
        throw "Tidak valid";
    }else{
        return 0;
    }
    return 0;
}
