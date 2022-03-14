#include<string>
#include<string.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void simple_tokenizer(string s){
    stringstream ss(s);
    string word;
    while (ss >> word) {
        cout << word << endl;
    }
}

int main(){
    cout << "testing" << endl;
    string command;
    cin >> command;
    cout << "ini command " << command << endl;
    // string katasatu = strtok(command, " ");
    // cout << "ini kata satu " << katasatu<< endl;
    simple_tokenizer(command);
}