#include <bits/stdc++.h>
using namespace std;

class YourClass {
public:
  YourClass() {

  }
};

// class Item

// class Tool extends Item

// class NonTool extends Item

class MyClass {
public:
  map<string, YourClass*> myMap;
  map<string, YourClass> myMap;
  MyClass() {
    myMap["I0"] = NULL;
    myMap["I1"] = new YourClass();
  }
};

int main() {
  MyClass myClass;
  if (myClass.myMap.count("1")) { 
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }

  if (!myClass.myMap["I0"]) {
    cout << "I0 is empty" << endl;
  }
  return 0;
}