#include "NonTool.hpp"
#include <string>
#include <iostream>

using namespace std;
NonTool::NonTool():Item(){
    this->quantity=1;
}

NonTool::NonTool(int ID, string name, string type, string nonToolClass, int quantity):Item(ID,name,type,false){
    this->nonToolClass=nonToolClass;
    this->quantity=quantity;
}

int NonTool::getQuantity(){
    return this->quantity;
}

void NonTool::setQuantity(int pengganti){
    this->quantity=pengganti;
}

void NonTool::setDurability(int pengganti){
    
}

int NonTool::getDurability(){
    return 999;
} 

void NonTool::printInfo()const{
    cout<< "NonTool\t:"<<endl;
    Item::printInfo();
    cout << "Quantity\t: "<< this->quantity <<endl<<endl;
}

bool NonTool::operator==(NonTool& n){
    return this->getQuantity()==n.getQuantity();
}

int NonTool::use(){
    throw "Tidak Bisa Digunakan";
}

int NonTool::substract(int qty){
    if(qty>this->quantity){
        throw "Sisa item tidak cukup";
    }else{
        this->quantity-=qty;
        return this->quantity;
    }
}