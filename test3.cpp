#include <iostream>
#include <map>
using namespace std;

string intToString(int angka){
  string key = "I";
  if (angka < 10) {
    char idx = angka + '0';
    key += idx;
  } else {
    // puluhan
    int i_div = angka / 10;
    char num1 = i_div + '0';
    // satuan
    int i_mod = angka % 10;
    char num2 = i_mod + '0';
    key += num1;
    key += num2;
  }
  return key;
}

class A {
  public:
    virtual void print(){
      cout << "Ini print kelas A dulu\n";
    }
    virtual int getNum() = 0;
};

class B: public A {
  private:
    int Num;
  public:
    B():Num(2){}
    void print(){
      A::print();
      cout << "Ini objek kelas B\n";
    }
    int getNum(){
      return this->Num;
    }
};
class C: public A {
  private:
    int Num;
  public:
    C():Num(3){}
    void print(){
      A::print();
      cout << "Ini objek kelas C\n";
    }
    int getNum(){
      return this->Num;
    }
};

int main(){
  map<int, A*> m;
  for (int i = 0; i < 27; i++){
    string key = intToString(i);
    cout << key << endl;
  }
  C c = C();
  m[0] = new B();
  m[1] = &c;
  m[0]->print();
  m[1]->print();
  cout << "Ini getNumnya B: " << m[0]->getNum() << endl;
  cout << "Ini getNumnya C: " << m[1]->getNum() << endl;
  return 0;
}