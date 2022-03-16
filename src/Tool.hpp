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
        int getDurability();
        void printInfo();


};


#endif