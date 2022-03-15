#include "Item.hpp"
#include <string>
#include <iostream>
using namespace std;
int Item::ID=0;

Item::Item(string name, string type){
    this->name=name;
    this->type=type;
    ID++;
}

string Item::getName(){
    return this->name;
}
string Item::getType(){
    return this->type;
}
int Item::getID(){
    return this->ID;
}

void Item::printInfo(){
    cout << "ID\t\t: "<< this->ID <<endl;
    cout << "Name\t\t: "<< this->name <<endl;
    cout << "type\t\t: "<< this->type <<endl;

}