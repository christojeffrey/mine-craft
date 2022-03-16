#include "Tool.hpp"
#include <string>
#include <iostream>

using namespace std;
Tool::Tool():Item(){
    this->durability=10;
}

Tool::Tool(string name, string type, int durability):Item(name,type){
    this->durability=durability;
}

int Tool::getDurability(){
    return this->durability;
}

void Tool::printInfo(){
    Item::printInfo();
    cout << "Durability\t: "<< this->durability <<endl;
    cout << "Kind\t\t: "<< this->kind <<endl;
}