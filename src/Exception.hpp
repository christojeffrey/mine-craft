#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <iostream>
using namespace std;

class BaseException { // abstract base class
public:
  
    virtual void printMessage() = 0;
};



/* for craftTable */
class craftTableIsNotEmptyException : public BaseException { // happened when the craft table at c_id is not empty when it supposed to be empty
    public:
        void printMessage();
};

class craftTableIsEmptyException : public BaseException { // happened when the craft table at c_id is empty when it supposed to not be empty
    public:
        void printMessage();
};
class craftTableDoesntMatchRecipeException : public BaseException { 
    // happened when trying to craft on craft table but doesnt match any recipe
    public:
        void printMessage();
};

class CIDNotValidException : public BaseException { 
    // happened when trying to craft on craft table but doesnt match any recipe
    public:
        void printMessage();
};

/* for inventory */
class inventoryIsFullException : public BaseException { // happened when the inventory is full
    public:
        void printMessage();
};
class inventoryIdIsEmptyException : public BaseException{
    // happened when the inventory on I_id is empty, when it's supposed to not be empty
    public:
        void printMessage();
};
class inventoryIdIsNotEmptyException : public BaseException{
    // happened when the inventory on I_id is not empty, when it's supposed to be empty
    public:
        void printMessage();
};
class inventoryIdIsInsufficientException : public BaseException{
    // happened when the inventory on I_id is insufficient
    public:
        void printMessage();
};

class inventoryIdIsNotToolException : public BaseException{
    // happened when inventory on I_id is not a tool when it is supposed to be tool
    public:
        void printMessage();
};

class inventoryItemNameIsNotFoundException : public BaseException{
    // happened when inventory on I_id is not a tool when it is supposed to be tool
    public:
        void printMessage();
};

class inventoryAddedPartialButFull : public BaseException{
    // happened when adding a new item and already added partially, but not all
    public:
        void printMessage();
};

class quantityExceedingLimitException : public BaseException{
    // happened when give command gives quantity that exceeds the limit 64
    public:
        void printMessage();
};

//untuk inventory
class wrongTypeException : public BaseException{
    //happen when you expet tool but get nontool, or when you expect nontool but get tool
    public:
        void printMessage();
};

class oneOfTheItemNeededDoesntExistException : public BaseException{
    //happen when move, and either idxsource or idxdest doesnt exist
    public:
        void printMessage();
};

class itemDoesntHaveTheSameNameException : public BaseException{
    //happen when you want to move to an existing inventory place, but item from source don't have the same name with item from destination
    public:
        void printMessage();
};

class negativeValueGivenException : public BaseException{
    //hapen when you expect non negative value, but given negative value
    public:
        void printMessage();
};

class invalidCommandToItemException : public BaseException{
    //happen when invalid command given to item. for example nontool.getDurability()
    public:
        void printMessage();
};

class itemQuantityIsNotSufficientException : public BaseException{
    //happen when you try to substract item(either tool or nontool) quantity, but the quantity existed is not sufficient
    public:
        void printMessage();
};

#endif
