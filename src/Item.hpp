#ifndef _ITEM_HPP_
#define _ITEM_HPP_
#include <string>
using namespace std;
class Item {
    private:
        const int ID;
        const string name;

        //string type; type not needed. only non tool need type, and theres already an attribute to handle it

        const bool isTool; // true if item is tool. 
        
        //once an item is made, it should change it's status. so jadiin const semua aja
    public:
        // Item(); once an item is defined, harus udah ada data dalemnya. jadi gaboleh polosan gini
        Item(int ID, string name, bool isTool);

        //getter (no setter)
        int getID() const;

        string getName() const;
    
        bool getIsTool() const;

        //virtual
        virtual void printInfo() const;

        //pure virtual
        virtual int use() = 0;
        virtual int substract(int qty) = 0; 
        // kalo ini dibikin pure virual, artinya harus dibikinin sama tool. aneh kalo substact. kalo pun idenya 'ngeremove item dari inventory', yaitu di handle sama inventory. consider only making this on non tool.
        // oke gajadi, enaknya diinventory langsung manggil item substract, gk perlu peduliin dia itu tool atau nontool
};


#endif