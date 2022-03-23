#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <iostream>
using namespace std;

class BaseException { // abstract base class
public:
    // menuliskan pesan kesalahan ke stdout
    virtual void printMessage() = 0;
};


class ExampleException : public BaseException { 
    private:
        int contoh;
    public:
        ExampleException(int _contoh);
        void printMessage();
};


/* for craftTable */
class craftTableIsNotEmptyException : public BaseException { // happened when the craft table at c_id is not empty when it supposed to be empty
    public:
        void printMessage(){
            cout << "Craft table is not empty!" << endl;
        }
};

class craftTableIsEmptyException : public BaseException { // happened when the craft table at c_id is empty when it supposed to not be empty
    public:
        void printMessage(){
            cout << "Craft table is empty!" << endl;
        }
};
class craftTableDoesntMatchRecipeException : public BaseException { 
    // happened when trying to craft on craft table but doesnt match any recipe
    public:
        void printMessage(){
            cout << "Craft table does not match any recipe!" << endl;
        }
};

class CIDNotValidException : public BaseException { 
    // happened when trying to craft on craft table but doesnt match any recipe
    public:
        void printMessage(){
            cout << "Index of Craft table given is not valid!" << endl;
        }
};

/* for inventory */
class inventoryIsFullException : public BaseException { // happened when the inventory is full
    public:
        void printMessage(){
            cout << "Inventory is full!" << endl;
        }
};
class inventoryIdIsEmptyException : public BaseException{
    // happened when the inventory on I_id is empty, when it's supposed to not be empty
    public:
        void printMessage(){
            cout << "Inventory in given index is empty!" << endl;
        }
};
class inventoryIdIsNotEmptyException : public BaseException{
    // happened when the inventory on I_id is not empty, when it's supposed to be empty
    public:
        void printMessage(){
            cout << "Inventory in given index is not empty!" << endl;
        }
};
class inventoryIdIsInsufficientException : public BaseException{
    // happened when the inventory on I_id is insufficient
    public:
        void printMessage(){
            cout << "Inventory in given index has insufficient quantity" << endl;
        }
};

class inventoryIdIsNotToolException : public BaseException{
    // happened when inventory on I_id is not a tool when it is supposed to be tool
    public:
        void printMessage(){
            cout << "Inventory in given index is not a tool. It's supposed to be a tool!" << endl;
        }
};

class inventoryItemNameIsNotFoundException : public BaseException{
    // happened when inventory on I_id is not a tool when it is supposed to be tool
    public:
        void printMessage(){
            cout<< "Item is not found in inventory!" << endl;
        }
};

class inventoryAddedPartialButFull : public BaseException{
    // happened when adding a new item and already added partially, but not all
    public:
        void printMessage(){
            cout << "Item has been added partially but not all because inventory is already full!\n";
        }
};

class quantityExceedingLimitException : public BaseException{
    // happened when give command gives quantity that exceeds the limit 64
    public:
        void printMessage(){
            cout << "New Item quantity must not exceed 64!\n";
        }
};

//untuk inventory
class wrongTypeException : public BaseException{
    //happen when you expet tool but get nontool, or when you expect nontool but get tool
    public:
        void printMessage(){
            cout << "Different type of item expected! (Tool or Non Tool)" << endl;
        }
};

class oneOfTheItemNeededDoesntExistException : public BaseException{
    //happen when move, and either idxsource or idxdest doesnt exist
    public:
        void printMessage(){
            cout << "One of the item in the argument given doesn't exist!" << endl;
        }
};

class itemDoesntHaveTheSameNameException : public BaseException{
    //happen when you want to move to an existing inventory place, but item from source don't have the same name with item from destination
    public:
        void printMessage(){
            cout << "Item from source is different with item from destination!" << endl;
        }
};

class negativeValueGivenException : public BaseException{
    //hapen when you expect non negative value, but given negative value
    public:
        void printMessage(){
            cout << "Negative value given when non negative value expected!" << endl;
        }
};

class invalidCommandToItem : public BaseException{
    //happen when invalid command given to item. for example nontool.getDurability()
    public:
        void printMessage(){
            cout << "Invalid command given to item!" << endl;
        }
};

class itemQuantityIsNotSufficientException : public BaseException{
    //happen when you try to substract item(either tool or nontool) quantity, but the quantity existed is not sufficient
    public:
        void printMessage(){
            cout << "Item quantity is not sufficient!"<< endl;
        }
};

#endif
