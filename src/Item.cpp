#include "Item.hpp"
#include <string>
#include <iostream>
using namespace std;

Item::Item(int ID, string name, string type, bool isTool){
    this->ID=ID;
    this->name=name;
    this->type=type;
    this->isTool=false;
}

string Item::getName(){
    return this->name;
}

void Item::setName(string name){
    this->name=name;
}

void Item::setType(string type){
    this->type=type;
}

string Item::getType(){
    return this->type;
}
int Item::getID(){
    return this->ID;
}

void Item::printInfo()const{
    cout << "ID\t\t: "<< this->ID <<endl;
    cout << "Name\t\t: "<< this->name <<endl;
    cout << "type\t\t: "<< this->type <<endl;

}