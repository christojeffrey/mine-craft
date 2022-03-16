#include "NonTool.hpp"
#include <string>
#include <iostream>

using namespace std;
NonTool::NonTool():Item(){
    this->quantity=1;
}

NonTool::NonTool(string name, string type, int quantity):Item(name,type){
    this->quantity=quantity;
}

int NonTool::getQuantity()const{
    return this->quantity;
}

void NonTool::setQuantity(int pengganti){
    this->quantity=pengganti;
}

void NonTool::printInfo()const{
    cout<< "NonTool\t:"<<endl;
    Item::printInfo();
    cout << "Quantity\t: "<< this->quantity <<endl<<endl;
}

bool NonTool::operator==(NonTool& n){
    return this->getQuantity()==n.getQuantity();
}