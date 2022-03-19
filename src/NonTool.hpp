#ifndef _NON_TOOL_HPP_
#define _NON_TOOL_HPP_

#include<string>

#include "Item.hpp"

class NonTool: public Item{
    private:
        string nonToolClass; //for example, OAK_LOG has nonToolClass of LOG
        int quantity;
    public:
        // NonTool(); once a non tool is made, dia gaboleh polosan
        NonTool(int ID, string name, string NonToolClass, int quantity);
        ~NonTool(){};
        int getQuantity() const;
        void setQuantity(int pengganti);

        //kenapa ada durability disini?
        // int getDurability(); 
        // void setDurability(int pengganti);

        void printInfo()const;
        bool operator==(NonTool& n);
        int use();
        int substract(int qty);
        string getNonToolClass() const;
};


#endif