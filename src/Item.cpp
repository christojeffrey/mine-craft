#include "Item.hpp"
#include <string>
#include <iostream>
using namespace std;

Item::Item(int ID, string name, bool isTool) : ID(ID), name(name), isTool(isTool){
}

Item::~Item(){}

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
    cout << this->name << " ";

}

int Item::getQuantity()const{
    throw new invalidCommandToItemException();
}

void Item::setQuantity(int pengganti)
{
    throw new invalidCommandToItemException();

}

int Item::getDurability() const
{
    throw new invalidCommandToItemException();

}

void Item::setDurability(int pengganti)
{
    throw new invalidCommandToItemException();

}

string Item:: getNonToolClass() const {
    throw new invalidCommandToItemException();

}

string Item::getType(){
    throw new invalidCommandToItemException();

}

Item& Item::operator=(const Item& i){
    // this->isTool = i.isTool;
    return *new Item(i.getID(), i.getName(), i.getIsTool());
}

int Item::use(){
    return 1;
    }
int Item::substract(int qty){
    return 1;
}
