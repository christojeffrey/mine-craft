#include "NonTool.hpp"
#include <string>
#include <iostream>

using namespace std;


NonTool::NonTool(int ID, string name, string nonToolClass, int quantity):Item(ID,name,false){
    this->nonToolClass=nonToolClass;
    this->quantity=quantity;
}

int NonTool::getQuantity() const{
    return this->quantity;
}

void NonTool::setQuantity(int pengganti){
    this->quantity=pengganti;
}


void NonTool::printInfo()const{
    Item::printInfo();
    cout << "Quantity\t: "<< this->quantity << endl;
}

bool NonTool::operator==(NonTool& n){
    return this->getQuantity()==n.getQuantity();
}

int NonTool::use(){
    throw "NonTool Item Tidak Bisa Digunakan";
}

int NonTool::substract(int qty){
    if(qty > this->quantity){
        throw "Sisa Item NonTool Tidak Cukup";
    }else{
        this->quantity -= qty;
        return this->quantity;
    }
}