#ifndef _TOOL_HPP_
#define _TOOL_HPP_

#include "Item.hpp"

class Tool: public Item{
    private:
        int durability;
    public:
        Tool(int ID, string name,int durability);
        
        int getDurability()const;
        void setDurability(int pengganti);

        void printInfo()const;
        int use();
        int substract(int qty);

};
#endif