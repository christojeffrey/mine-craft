#include "Tool.hpp"
#include "Exception.hpp"
#include <string>
#include <iostream>

using namespace std;

Tool::Tool(int ID, string name, int durability) : Item(ID,name,true){
    this->durability=durability;
}

int Tool::getDurability()const{
    return this->durability;
}

void Tool::setDurability(int pengganti){
    this->durability=pengganti;
}

void Tool::printInfo()const{
    Item::printInfo();
    cout << this->durability;
}

int Tool::use(){
    //kalo di use, durability di kurangi sebanyak satu
    this->durability--;
    return this->durability;
}

int Tool::substract(int qty){
    //this actually did nothing to the item. return sisa itemnya
    if(qty!=1){
        throw new itemQuantityIsNotSufficientException();
    }else{
        return 0;
    }
    return 0;
}
// Item& Tool::operator=(const Item& i){
//     return *new Tool(i.getID(),i.getName(),i.getDurability());
// }
