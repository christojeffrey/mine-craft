#include "Inventory.hpp"
#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk mengubah int menjadi string
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

Inventory::Inventory() {
}

Inventory::~Inventory(){
}

// Belom cek apakah namanya sama (done)
void Inventory::move(string idxSrc, string idxDest){
  if (this->inven[idxDest]->getIsTool() || this->inven[idxSrc]->getIsTool()) {
    // throw exception
    throw new wrongTypeException();
  } else if (this->inven.find(idxSrc) == this->inven.end() || this->inven.find(idxDest) == this->inven.end()) {
    throw new oneOfTheItemNeededDoesntExistException();
  } else if (this->inven[idxSrc]->getName() != this->inven[idxDest]->getName()){
    throw new itemDoesntHaveTheSameNameException();
  } 
  else {
    int sisaQty = MAX_QUANTITY - this->inven[idxDest]->getQuantity();
    // Kalo qty src melebihi atau sama dengan sisaQty dest hingga max
    if (this->inven[idxSrc]->getQuantity() >= sisaQty) {
      this->inven[idxDest]->setQuantity(MAX_QUANTITY);
      this->inven[idxSrc]->setQuantity(this->inven[idxDest]->getQuantity() + this->inven[idxSrc]->getQuantity() - sisaQty);
      // hapus item jika jumlahnya jadi 0
      if (this->inven[idxSrc]->getQuantity() == 0) {
        this->inven.erase(idxSrc);
      }
    } else { // klo qty dari item di src engga memenuhi qty dari idx dest, idx dest lgsg tambahin, idx src lgsg hapus
      this->inven[idxDest]->setQuantity(this->inven[idxDest]->getQuantity() + this->inven[idxSrc]->getQuantity());
      this->inven.erase(idxSrc);
    }
  }
}

void Inventory::add(Item* item){ //kalo item banyak, kalo sudah ada gimana ?
  // Iterate item yang sudah ada dulu cari yang sama
  // Cek apakah dia nontool, kalau tool sudah pasti tambah baru
  bool alreadyAdded = false;
  bool alreadyAddedPartially = false;
  if (!item->getIsTool()){
    if (!inven.size() == 0){ // iterasi cuma kalo inventory size tidak 0
      map<string, Item*>::iterator it;
      int i = 0;
      for (it = inven.begin(); it != inven.end(); it++){
        // Cek apakah namanya sama dengan item yang akan ditambah
        if (item->getName() == it->second->getName()){
          // cek quantity item + qty this masih di batas atau tidak
          if (item->getQuantity() + it->second->getQuantity() <= MAX_QUANTITY){
            it->second->setQuantity(item->getQuantity() + it->second->getQuantity());
            item->setQuantity(0);
            alreadyAdded = true;
          } else { // kita add partial
            int sisaQty = MAX_QUANTITY - it->second->getQuantity(); // Simpan sisa sebelum penuh
            // Pasti yg ditambah lgsg set 64
            it->second->setQuantity(MAX_QUANTITY);
            //kurangi qty item yg akan ditambah
            item->setQuantity(item->getQuantity() - sisaQty);
            alreadyAddedPartially = true;
          }
        }
      }
    }
    // Cek apakah sudah ditambah
    if (!alreadyAdded && inven.size() == MAX_INVEN){
      // Jika sudah add sebagian
      if (alreadyAddedPartially){
        throw new inventoryAddedPartialButFull();
      } else { // Jika belum add sama sekali
        throw new inventoryIsFullException();
      }
    } else if (!alreadyAdded && !inven.size() < MAX_INVEN) { // Kalau belum ditambah dan inven tidak full
      // Cari tempat yang kosong
      int i = 0;
      bool found = false;
      while (i < MAX_INVEN && !found){
        string key = intToString(i);
        if (inven.find(key) == inven.end()){
          inven[key] = item;
          found = true;
        } else {
          i++;
        }
      }
    }
  } else { // klo dia tool langsung cari tempat kosong
    if (inven.size() == MAX_INVEN){
      throw new inventoryIsFullException();
    } else {
      // Cari tempat yang kosong
      int i = 0;
      bool found = false;
      while (i < MAX_INVEN && !found){
        string key = intToString(i);
        if (inven.find(key) == inven.end()){
          inven[key] = item;
          found = true;
        } else {
          i++;
        }
      }
    }
  }
}

void Inventory::add(Item* item_name,string dest){
  if(this->inven.find(dest) == inven.end()){
    // if item is not in inventory
    this->inven[dest]=item_name;
  } else {
    if (item_name->getName() == this->inven[dest]->getName() && !item_name->getIsTool()) {
      this->inven[dest]->setQuantity(this->inven[dest]->getQuantity() + item_name->getQuantity());
    } else {
      throw new itemDoesntHaveTheSameNameException();
    }
    
  }
}

void Inventory::printInfo(){
  // for (map<string, Item*>::iterator it = this->inven.begin(); it != this->inven.end(); ++it){
  for (int i = 0; i < MAX_INVEN; i++){
    string key = intToString(i);
    cout << key << ": [";
    if (this->inven.find(key) != this->inven.end()){
      inven[key]->printInfo();
    } else {
      cout << "KOSONG";
    }
    cout << "]\n";
  }
}

void Inventory::substract(string I_id, int qty){
  cout <<"inventory substract"<< I_id << " " << qty << endl;
  if (this->inven.find(I_id) == this->inven.end()) {
    throw new inventoryIdIsEmptyException();
  } else if (qty < 0) {
    throw new negativeValueGivenException();
  } else{ // gamungkin quantity 0 soalnya klo 0 pasti udah gaada di map
    try{
      int sisa = this->inven[I_id]->substract(qty);
      if(sisa==0){
        this->inven.erase(I_id);
      }
    }catch(BaseException* e){
      throw e;
      //kalau qty kurang atau
    }
  }
}

void Inventory::use(string I_id){
  if (this->inven.find(I_id) == this->inven.end()) {
    throw new inventoryIdIsEmptyException();
  } else {
    this->inven[I_id]->use();
    if (this->inven[I_id]->getDurability() <= 0) {
      this->inven.erase(I_id);
    }
  }
}
 
Item * Inventory::getItem(string I_id){
  if (this->inven.find(I_id) == this->inven.end()){
    throw new inventoryItemNameIsNotFoundException();
  } else {
    return this->inven[I_id];
  }
} 

// // driver
// int main(){
//   Inventory i;
//   return 0;
// }
