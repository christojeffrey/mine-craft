#include "NonTool.hpp"
#include <string>
#include <iostream>

using namespace std;
NonTool::NonTool():Item(){
    this->quantity=1;
}

NonTool::NonTool(string name, string type, int quantity):Item(name,type){
    this->durability=durability;
    this->kind=kind;
}

void NonTool::printInfo(){
    Item::printInfo();
    cout << "Quantity\t\t: "<< this->durability <<endl;
}