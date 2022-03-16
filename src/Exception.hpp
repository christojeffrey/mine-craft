#ifndef __BASE_EXCEPTION_HPP__
#define __BASE_EXCEPTION_HPP__

#include <iostream>
using namespace std;

class BaseException { // abstract base class
public:
    // menuliskan pesan kesalahan ke stdout
    virtual void printMessage() = 0;
};

class ExampleException : public BaseException { 
    private:
        int contoh;
    public:
        ExampleException(int _contoh);
        void printMessage();
};

#endif
