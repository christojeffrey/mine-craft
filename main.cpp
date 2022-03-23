#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <sstream>
#include <map>
#include "src/Item.hpp"
#include "src/Tool.hpp"
#include "src/NonTool.hpp"
#include "src/Recipe.hpp"
#include "src/GameState.hpp"
using namespace std;

vector<string> getRecipeMatrix(vector<string> eachRecipe, int row, int col) {
  vector<string> res(9);
  int appendmanyRow = 3 - row;
  int idx = 0;
  for (int i = 0; i <= 3; i++) {
    if (i < col) {
      res[i] = eachRecipe[idx];
      idx++;
    } else {
      res[i] ="-";
    }
  }
  
  if (appendmanyRow == 1) {
    for (int i = 3; i <= 5; i++) {
      if (i < col + 3) {
        res[i] = eachRecipe[idx];
        idx++;
      } else {
        res[i] = "-";
      }
    }

    for (int i = 6; i <= 8; i++) {
      res[i] = "-";
    }
  } else if (appendmanyRow == 2) {
    for (int i = 3; i <= 8; i++) {
      res[i] = "-";
    }
  } else {
    for (int i = 3; i <= 5; i++) {
      if (i < col + 3) {
        res[i] = eachRecipe[idx];
        idx++;
      } else {
        res[i] = "-";
      }
    }

    for (int i = 6; i <= 8; i++) {
      if (i < col + 6) {
        res[i] = eachRecipe[idx];
        idx++;
      } else {
        res[i] = "-";
      }
    }
  }
  return res;
}



int main() {
  //add welcome message
  cout << "Welcome to the tall corn game!" << endl;


  // /* SETUP */
  cout << "Setting up..." << endl;
  cout << "Loading..." << endl;
  cout << "Please wait and sit tight..." << endl;
  string configPath = "./config";
  string itemConfigPath = configPath + "/item.txt";

  // CREATE LIST OF LEGAL ITEM
  list<Item*> legalItem;

  //buat ngebantu bikin recipe, aku butuh sebuah item, ketika diketahui nama item.
  map<string, Item*> ItemNameToItemObject; 
  map<string, bool> isItemATool;
   
  //read from config 
  ifstream itemConfigFile(itemConfigPath);
  for (string line; getline(itemConfigFile, line);) {
    //spliting line
    stringstream ss(line);
    string currentWord;
    int count = 0;
    string id;
    string name;
    string nonToolClass;
    string toolnontool;
    while (ss >> currentWord) {
      if (count == 0) {
        id = currentWord;
      }
      else if (count == 1) {
        name = currentWord;
      }
      else if (count == 2) {
        nonToolClass = currentWord;
      }
      else if (count == 3) {
        toolnontool = currentWord;
      }
      count++;
    }


    //add to legal list
    if (toolnontool == "TOOL") {
      //tambahkan tool ke legal item
      Tool* temp = new Tool(stoi(id) ,name, 10);
      legalItem.push_back(temp);

      //add to recipe helper
      ItemNameToItemObject.insert(pair<string,Item*> (name,temp));
      isItemATool.insert(pair<string,bool> (name, true));
    } else {
      //tambahakn nontool ke legal item
      NonTool* temp = new NonTool(stoi(id), name, nonToolClass,1); // quantity disini harusnya gaperna disentuh. aku kasih 1. kenapa gk dikasih 0 aja? takutnya nti bikin behaviour yg aneh
      legalItem.push_back(temp);
      ItemNameToItemObject.insert(pair<string,Item*> (name,temp));
      isItemATool.insert(pair<string,bool> (name, false));
    }
  }

  vector<Recipe*> legalRecipe;

  // read recipes
  for (const auto &entry :filesystem::directory_iterator(configPath + "/recipe")) {   
    // create list of legal recipe
    ifstream eachRecipeFile(entry.path());

    //changing text inside into one long string
    string currentRecipeString;
    for (string line; getline(eachRecipeFile, line);) {

      //each line inside a recipe
      currentRecipeString.append(line);
      currentRecipeString.append(" ");
    }
    //spliting long string into each variable needed to make a recipe
    string currentWordRecipe;
    int count = 0;
    int row = 0;
    int col = 0; 
    vector<string> eachRecipe;
    string itemName;
    int resultquantity = 0;

    stringstream ssrecipe(currentRecipeString);
    //assigning into the correct variable
    while (ssrecipe >> currentWordRecipe) {
      count++;
      if (count == 1) {
        row = stoi(currentWordRecipe);
      }
      else if (count == 2) { 
        col = stoi(currentWordRecipe);
      }
      else if (count > 2 && count <= ((row*col) + 2)) {
        //add to vector recipe
        eachRecipe.push_back(currentWordRecipe);
      }
      else if (count == ((row*col) + 3)) { 
        itemName = currentWordRecipe;
      }
      else if (count == ((row*col) + 4)) { 
        resultquantity = stoi(currentWordRecipe);
      }
    }

    vector<string> addToRecipe = getRecipeMatrix(eachRecipe, row, col);

    //creating Recipe Object
    if (isItemATool[itemName]) {
      int tempid = ItemNameToItemObject[itemName]->getID();
      string tempname = ItemNameToItemObject[itemName]->getName();
      int tempdurability = ItemNameToItemObject[itemName]->getDurability();
      Recipe *temp = new Recipe(row, col, addToRecipe, new Tool(tempid, tempname, tempdurability),resultquantity);
      legalRecipe.push_back(temp);
    } else {
      int tempid = ItemNameToItemObject[itemName]->getID();
      string tempname = ItemNameToItemObject[itemName]->getName();
      string nontoolClass = ItemNameToItemObject[itemName]->getNonToolClass();
      int quantity = ItemNameToItemObject[itemName]->getQuantity();
      Recipe *temp = new Recipe(row, col, addToRecipe, new NonTool(tempid, tempname, nontoolClass, quantity),resultquantity);
      legalRecipe.push_back(temp);
    }
  }
  /*SETUP DONE*/


  //creating gamestate
  GameState *GS = new GameState(legalItem, legalRecipe);
  cout << "Game is ready!" << endl;

  /* START */
  string command;
  command = "HELP";
  while (command != "EXIT") {
    cout << ">";
    cin >> command;
    if (command == "SHOW") {
      GS->SHOW();
    } 
    else if (command == "GIVE") {
      try {
        string itemName;
        int itemQty;
        cin >> itemName >> itemQty;
        GS->GIVE(itemName, itemQty);
      } catch(BaseException* e){
        e->printMessage();
      }
    }
    else if (command == "DISCARD"){
      string i_id;
      int itemQty;
      cin >> i_id >> itemQty;

      GS->DISCARD(i_id, itemQty);

    }
    else if (command == "MOVE") { //COMMAND MOVE
    try{
        string src;
        int N;
        string tempN;
        cin >> src >> tempN;

        N = stoi(tempN);
        
        if(src.substr(0,1) == "I"){
          vector<string> dest;
          string temp;
          for(int i = 0 ; i < N ; i++){
            cin >> temp;
            if(temp[0]=='C'){ 
              dest.push_back(temp);
            }else{
              break;
            }
          }
          if(temp[0]=='C'){
            GS->MOVE(src, N, dest);
          }else{
            GS->MOVE(src,temp);
          }
        }
        else{
          string dest;
          cin >> dest;
          GS->MOVE(src, N,dest);
        }
      }
      catch(exception &err){
        cout << "Conversion failure: "<< err.what() <<endl;
      }
    }
    else if (command == "USE") {
      string i_id;
      cin >> i_id;
      GS->USE(i_id);
    } 
    else if (command == "CRAFT") {
      cout << "CRAFT command is picked" << endl;
      GS->CRAFT();
    } 
    else if (command == "EXPORT") {
      string outputPath;
      cin >> outputPath;

      GS->EXPORT(outputPath);
    }

    else if (command == "HELP") {
      cout << "LIST OF AVAILABLE COMMAND" << endl;
      cout << "SHOW" << endl;
      cout << "GIVE <itemName> <itemQty>" << endl;
      cout << "DISCARD <InventoryIdx> <itemQty>" << endl;
      cout << "MOVE <InventoryIdx> <CraftCount> <CraftIdx>" << endl;
      cout << "MOVE <InventoryIdx> 1 <InventoryIdx>" << endl;
      cout << "MOVE <CraftIdx> 1 <InventoryIdx>" << endl;
      cout << "USE <InventoryIdx>" << endl;
      cout << "CRAFT" << endl;
      cout << "EXPORT <outputPath>" << endl;
      cout << "EXIT" << endl;


    }
    else if (command == "EXIT") {
      cout << "Do you want to export your state first? (y/n)" << endl;
      char yn;
      cin >> yn;
      if (yn == 'y') {
        //do export
        cout << "Please input the output path" << endl;
        string outputPath;
        cin >> outputPath;
        GS->EXPORT(outputPath);

      }
      else if (yn == 'n') {
        //say goodbye
        cout << "Goodbye!" << endl;
      }
      else {
        //print invalid input. we take it as a 'n', so bye bye
        cout << "Goodbye!" << endl;
      }
    }
    else {
      cout << "Invalid command. try \"HELP\" " << endl;
    }
    cout << "COMMAND DONE, NEXT COMMAND..." << endl;
  }
  
  // add closing screen?
  return 0;
}
