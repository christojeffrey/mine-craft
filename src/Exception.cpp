#include "Exception.hpp"
#include<iostream>
using namespace std;
ExampleException::ExampleException(int _contoh){
    this->contoh = _contoh;
}
void ExampleException::printMessage(){
    cout << "ini contoh exception dengan parameter, yaitu" << this->contoh << endl;
}


//sementara sisanya aku gabung dulu di hpp. repot kalo 2 file