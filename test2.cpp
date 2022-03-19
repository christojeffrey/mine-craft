#include <bits/stdc++.h>
using namespace std;

int main() {
  string input;

  getline(cin, input);
  cin.ignore();
  
  cout << input << endl;
  stringstream ss(input);
  string currentWord;
  int cnt = 0;
  while (ss >> currentWord) {
    if (currentWord[0] == 'C') {
      cout << cnt++ << " " << currentWord << endl;
    }
  }
  return 0;
}