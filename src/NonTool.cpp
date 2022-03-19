#include "NonTool.hpp"
#include "Tool.hpp"
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
    return 0;
}

int NonTool::substract(int qty){
    if(qty > this->quantity){
        throw "Sisa Item NonTool Tidak Cukup";
    }else{
        this->quantity -= qty;
        throw "NonTool gabisa di add";
    }
    return 0;
}

string NonTool::getNonToolClass()const{
    return this->nonToolClass;
    //   return this->quantity;
}

// }

// void NonTool::add(Tool * t){
    
// }

// void NonTool::add(NonTool *n ){
//     if(n->getQuantity()<=0){
//         throw "Nontool yang ditambahkan kosong";
//     }
//     this->quantity+=n->getQuantity();
// } 