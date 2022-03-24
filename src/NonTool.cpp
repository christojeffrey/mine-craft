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
    cout << this->quantity;
}

bool NonTool::operator==(NonTool& n){
    return this->getQuantity()==n.getQuantity();
}

int NonTool::use(){
    throw new invalidCommandToItemException();
    return 0;
}

int NonTool::substract(int qty){
    //memberikan return sisa quantity setelah dikurangi
    if(qty > this->quantity){
        throw new itemQuantityIsNotSufficientException();
    }else{
        this->quantity -= qty;
    }
    return this->quantity;
}

string NonTool::getNonToolClass()const{
    return this->nonToolClass;
    //   return this->quantity;
}

// Item& NonTool::operator=(const Item& i){
//     return *new NonTool(i.getID(),i.getName(),i.getNonToolClass(),i.getQuantity());
// }

