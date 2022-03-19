#ifndef _NON_TOOL_HPP_
#define _NON_TOOL_HPP_

#include "Item.hpp"

class NonTool: public Item{
    private:
        int quantity;
    public:
        NonTool();
        NonTool(string name, string type,int quantity);
        int getQuantity()const;
        void setQuantity(int pengganti);
        void printInfo()const;
        bool operator==(NonTool& n);
        int use();
        int substract(int qty);
};


#endif