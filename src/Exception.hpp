#ifndef __BASE_EXCEPTION_HPP__
#define __BASE_EXCEPTION_HPP__

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

class CIDNotValid : public BaseException { 
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
    // happened when the inventory on I_id is empty
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

#endif
