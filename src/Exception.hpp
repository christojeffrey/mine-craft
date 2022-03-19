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
            cout << "craft table is not empty" << endl;
        }
};

class craftTableIsEmptyException : public BaseException { // happened when the craft table at c_id is empty when it supposed to not be empty
    public:
        void printMessage(){
            cout << "craft table is empty" << endl;
        }
};
class craftTableDoesntMatchRecipeException : public BaseException { 
    // happened when trying to craft on craft table but doesnt match any recipe
    public:
        void printMessage(){
            cout << "craft table does not match any recipe" << endl;
        }
};

class CIDNotValid : public BaseException { 
    // happened when trying to craft on craft table but doesnt match any recipe
    public:
        void printMessage(){
            cout << "C id is not a valid" << endl;
        }
};

/* for inventory */
class inventoryIsFullException : public BaseException { // happened when the inventory is full
    public:
        void printMessage(){
            cout << "inventory is full" << endl;
        }
};
class inventoryIdIsEmptyException : public BaseException{
    // happened when the inventory on I_id is empty
    public:
        void printMessage(){
            cout << "I id is empty" << endl;
        }
};
class inventoryIdIsInsufficientException : public BaseException{
    // happened when the inventory on I_id is insufficient
    public:
        void printMessage(){
            cout << "I id has insufficient quantity" << endl;
        }
};

class inventoryIdIsNotToolException : public BaseException{
    // happened when inventory on I_id is not a tool when it is supposed to be tool
    public:
        void printMessage(){
            cout << "I id give is not a tool. it's supposed to be a tool" << endl;
        }
};

class inventoryItemNameIsNotFoundException : public BaseException{
    // happened when inventory on I_id is not a tool when it is supposed to be tool
    public:
        void printMessage(){
            cout<< "Nama item tidak ditemukan" << endl;
        }
};

#endif
