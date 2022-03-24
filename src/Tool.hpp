#ifndef _TOOL_HPP_
#define _TOOL_HPP_

#include "Item.hpp"

class Tool: public Item{
    private:
        int durability;
        //string kind; kind is not needed in tool. gangerti nyimpen value apaan
    public:
        // Tool(); once a tool is created, gaboleh polosan
        Tool(int ID, string name,int durability);
        
        int getDurability()const;
        void setDurability(int pengganti);

        void printInfo()const;
        int use();
        int substract(int qty);
        // int add(Item * t);
        // Item& operator=(const Item& i);

};
#endif