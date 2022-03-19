#include <iostream>
#include "Inventory.hpp"
#include "NonTool.hpp"
#include "Tool.hpp"

using namespace std;

int main(){
  Inventory i;
  NonTool nt1 = NonTool("NonTool1", "NonTool", 5);
  NonTool nt2 = NonTool("NonTool2", "NonTool", 3);
  NonTool nt3 = NonTool("NonTool1", "NonTool", 3);
  i.add(&nt1);
  i.add(&nt2);
  i.add(&nt3);
  i.printInfo();
  cout << "Setelah disubstract\n";
  i.printInfo();
  cout << "SAAT MOVE I1 KE I2\n";
  i.move("I0", "I2");
  i.printInfo();
}

// 18 MAR 2022 TESTING NONTOOL
// ADD SUDAH AMAN
// PRINT AMAN
// MOVE AMAN
// SUBSTRACT AMAN