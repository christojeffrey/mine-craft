#ifndef _ITEM_HPP_
#define _ITEM_HPP_
#include <string>
#include "Exception.hpp"

#define MAX_QUANTITY 64

using namespace std;
class Item {
    private:
        //once an item is made, it should change it's status. so jadiin const semua aja
        const int ID;
        const string name;
        const bool isTool; // true if item is tool. 
        
    public:
        Item(int ID, string name, bool isTool);
        ~Item();

        Item& operator=(const Item&);
        //getter (no setter)
        int getID() const;

        string getName() const;
    
        bool getIsTool() const;

        //virtual 
        //ditambahkan untuk memaksimalkan abstraksi
        virtual void printInfo() const;
        virtual int getQuantity() const;
        virtual void setQuantity(int pengganti);
        virtual int getDurability() const;
        virtual void setDurability(int pengganti);
        virtual string getNonToolClass() const;
        virtual string getType();
        //pure virtual
        virtual int use() = 0;
        virtual int substract(int qty) = 0;
};

#endif