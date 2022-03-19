#ifndef _TOOL_HPP_
#define _TOOL_HPP_

#include "Item.hpp"

class Tool: public Item{
    private:
        int durability;
        string kind;
    public:
        Tool();
        Tool(string name, string type,int durability);
        int getDurability()const;
        void setDurability(int pengganti);
        void printInfo()const;
        int use();
        int substract(int qty);
};


#endif