#include "Exception.hpp"
#include <iostream>
using namespace std;



void craftTableIsNotEmptyException::printMessage(){
    cout << "Craft table is not empty!" << endl;
}

void craftTableIsEmptyException::printMessage(){
    cout << "Craft table is empty!" << endl;
}

void craftTableDoesntMatchRecipeException::printMessage(){
    cout << "Craft table does not match any recipe!" << endl;
}
void CIDNotValidException::printMessage(){
    cout << "Index of Craft table given is not valid!" << endl;
}

void inventoryIsFullException::printMessage(){
    cout << "Inventory is full!" << endl;
}

void inventoryIdIsEmptyException::printMessage(){
    cout << "Inventory in given index is empty!" << endl;
}

void inventoryIdIsNotEmptyException::printMessage(){
    cout << "Inventory in given index is not empty!" << endl;
}

void inventoryIdIsInsufficientException::printMessage(){
    cout << "Inventory in given index has insufficient quantity" << endl;
}

void inventoryIdIsNotToolException::printMessage(){
    cout << "Inventory in given index is not a tool. It's supposed to be a tool!" << endl;
}


void inventoryItemNameIsNotFoundException::printMessage(){
    cout << "Item is not found in inventory!" << endl;
}

void inventoryAddedPartialButFull::printMessage(){
    cout << "Item has been added partially but not all because inventory is already full!\n";
}

void quantityExceedingLimitException::printMessage(){
    cout << "New Item quantity must not exceed 64!" << endl;
}

void wrongTypeException::printMessage(){
    cout << "Different type of item expected! (Tool or Non Tool)" << endl;
}

void oneOfTheItemNeededDoesntExistException::printMessage(){
    cout << "One of the item in the argument given doesn't exist!" << endl;
}

void itemDoesntHaveTheSameNameException::printMessage(){
    cout << "Item from source is different with item from destination!" << endl;
}

void negativeValueGivenException::printMessage(){
    cout << "Negative value given when non negative value expected!" << endl;
}

void invalidCommandToItemException::printMessage(){
    cout << "Invalid command given to item!" << endl;
}

void itemQuantityIsNotSufficientException::printMessage(){
    cout << "Item quantity is not sufficient!" << endl;
}