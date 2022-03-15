#ifndef _NON_TOOL_HPP_
#define _NON_TOOL_HPP_

#include "Item.hpp"

class NonTool: public Item{
    private:
        int quantity;
        string kind;
    public:
        NonTool();
        NonTool(string name, string type,int quantity);
        void printInfo();
};


#endif