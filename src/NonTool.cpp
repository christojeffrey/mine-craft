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

void NonTool::printInfo(){
    Item::printInfo();
    cout << "Quantity\t: "<< this->quantity <<endl;
}