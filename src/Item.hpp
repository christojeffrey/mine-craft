#ifndef _ITEM_HPP_
#define _ITEM_HPP_
#include <string>
using namespace std;
class Item {
    private:
        static int ID;
        string name;
        string type;
    public:
        Item();
        Item(string name, string type);
        string getName();
        string getType();
        int getID();
        virtual void printInfo();
};


#endif