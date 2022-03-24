#ifndef _NON_TOOL_HPP_
#define _NON_TOOL_HPP_

#include<string>

#include "Item.hpp"

class NonTool: public Item{
    private:
        string nonToolClass; //for example, OAK_LOG has nonToolClass of LOG
        int quantity;
    public:
        NonTool(int ID, string name, string NonToolClass, int quantity);
        ~NonTool(){};
        int getQuantity() const;
        void setQuantity(int pengganti);

        void printInfo()const;
        bool operator==(NonTool& n);
        int use();
        int substract(int qty);
        string getNonToolClass() const;
};


#endif