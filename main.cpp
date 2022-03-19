#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <list>

#include "Item.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"

using namespace std;

int main() {
  //add welcome message
  
  /* SETUP */
  cout << "setting up..." << endl;
  string configPath = "./config";
  string itemConfigPath = configPath + "/item.txt";

  // CREATE LIST OF LEGAL ITEM
  list<Item> legalItem;
  //read from config 
  ifstream itemConfigFile(itemConfigPath);
  for (string line; getline(itemConfigFile, line);) {
    cout << line << endl;

    //spliting line
    stringstream ss(line);
    string currentWord;
    int count = 0;
    string id;
    string name;
    string type;
    string toolnontool;
    while(ss >> currentWord){
      if(count == 0){
        id = currentWord;
      }
      else if(count == 1){ //
        name = currentWord;
      }
      else if(count == 2){ //
        type = currentWord;
      }
      else if(count == 3){ //
        toolnontool = currentWord;
      }
      count++;
      //cout << count++ << ". " << currentWord << endl;
    }
    /* FOR DEBUGGING PURPOSE */
    cout << "\tid = " << id << endl;
    cout << "\tname = "<< name << endl;
    cout << "\ttype = "<< type << endl;
    cout << "\ttoolnontool = " << toolnontool << endl;
    /* FOR DEBUGGING PURPOSE */

  }

  // read recipes
  for (const auto &entry :filesystem::directory_iterator(configPath + "/recipe")) {
    cout << entry.path() << endl;
    // create list of legal recipe
  }


  // GameState GS = new GameState()
  cout << "game is ready!" << endl;
  // add more glorified welcome message
  /* START */
  string command;
  command = "HELP";
  while (command != "EXIT") {
    cout << "input your command!"<< endl;
    cout << ">";
    cin >> command;
    if(command == "SHOW"){ //COMMAND SHOW
      cout << "SHOW" << endl;
    } 
    else if (command == "GIVE") { //COMMAND GIVE
      string itemName;
      int itemQty;
      cin >> itemName >> itemQty;
      cout << "TODO" << endl;
    }
    else if (command == "DISCARD"){ //COMMAND DISCARD
      cout << "DISCARD" << endl;
    }
    else if (command == "MOVE") { //COMMAND MOVE
    }
    else if(command == "USE"){ //COMMAND USE
      cout << "USE " << endl;
    } 
    else if (command == "CRAFT") { //COMMAND CRAFT
      cout << "TODO" << endl;
      string slotSrc;
      int slotQty;
      string slotDest;
      // need to handle multiple destinations
      cin >> slotSrc >> slotQty >> slotDest;
      cout << "TODO" << endl;
    } 
    else if (command == "EXPORT") { //COMMAND EXPORT
      string outputPath;
      cin >> outputPath;
      ofstream outputFile(outputPath);

      // hardcode for first test case
      outputFile << "21:10" << endl;
      outputFile << "6:1" << endl;
      for (int i = 2; i < 27; i++) {
        outputFile << "0:0" << endl;
      }

      cout << "Exported" << endl;
      // todo
    }

    // COMMAND TAMBAHAN
    else if(command == "HELP"){
      cout << "this is your help lol" << endl;
    }
    else if(command == "EXIT"){
      cout << "do you want to export your state first? (y/n)" << endl;
      char yn;
      cin >> yn;
      if(yn == 'y'){
        //do export
      }
      else if(yn == 'n'){
        //say goodbye
      }
      else{
        //print invalid input. we take it as a 'n', so bye bye
      }
    }
    else {
      cout << "Invalid command. try \"HELP\" " << endl;
    }
  }

  // add closing screen?
  return 0;
}
