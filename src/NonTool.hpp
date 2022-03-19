#ifndef _NON_TOOL_HPP_
#define _NON_TOOL_HPP_

#include "Item.hpp"

class NonTool: public Item{
    private:
        int quantity;
        string nonToolClass;
    public:
        NonTool();
        NonTool(int ID,string name, string type, string NonToolClass,int quantity);
        int getQuantity();
        void setQuantity(int pengganti);
        int getDurability();
        void setDurability(int pengganti);
        void printInfo()const;
        bool operator==(NonTool& n);
        int use();
        int substract(int qty);
};


#endif