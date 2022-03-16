#include "Tool.hpp"
#include <string>
#include <iostream>

using namespace std;
Tool::Tool():Item(){
    this->durability=10;
    this->kind="Wood";
}

Tool::Tool(string name, string type, int durability, string kind):Item(name,type){
    this->durability=durability;
    this->kind=kind;
}

void Tool::printInfo(){
    Item::printInfo();
    cout << "Durability\t: "<< this->durability <<endl;
    cout << "Kind\t\t: "<< this->kind <<endl;
}