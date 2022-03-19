#ifndef _ITEM_HPP_
#define _ITEM_HPP_
#include <string>
using namespace std;
class Item {
    private:
        int ID;
        string name;
        string type;
        bool isTool;
    public:
        Item();
        Item(int ID, string name, string type, bool isTool);
        string getName();
        void setName(string name);
        string getType();
        void setType(string type);
        int getID();
        bool getIsTool();
        virtual void printInfo()const;
        virtual int use() =0;
        virtual int substract(int qty)=0;
};


#endif