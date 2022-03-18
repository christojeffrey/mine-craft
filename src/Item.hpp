#ifndef _ITEM_HPP_
#define _ITEM_HPP_
#include <string>
using namespace std;
class Item {
    private:
        int ID;
        string name;
        string type;
        static int countItem;
    public:
        Item();
        Item(string name, string type);
        string getName();
        void setName(string name);
        string getType();
        void setType(string type);
        int getID();
        virtual void printInfo()const;
        virtual int use() =0;
        virtual int substract(int qty)=0;
};


#endif