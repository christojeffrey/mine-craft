#include "Item.hpp"
#include <string>
#include <iostream>
using namespace std;

Item::Item(int ID, string name, bool isTool) : ID(ID), name(name), isTool(isTool){
}

string Item::getName()const{
    return this->name;
}

int Item::getID()const{
    return this->ID;
}

bool Item::getIsTool() const{
    return isTool;
}

void Item::printInfo()const{
    if(isTool){
        cout << "Item is Tool" << endl;
    }
    else{
        cout << "Item is Not a Tool" << endl;
    }

    cout << "ID\t\t: "<< this->ID <<endl;
    cout << "Name\t\t: "<< this->name <<endl;

    
