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
    throw "Salah tipe";
  } else if (this->inven.find(idxSrc) == this->inven.end() || this->inven.find(idxDest) == this->inven.end()) {
    throw "Salah satu item tidak ada";
  } else if (this->inven[idxSrc]->getName() != this->inven[idxDest]->getName()){
    throw "ITEM TIDAK SAMA!!";
  } 
  else {
    int sisaQty = 64 - this->inven[idxDest]->getQuantity();
    // Kalo qty src melebihi atau sama dengan sisaQty dest hingga max
    if (this->inven[idxSrc]->getQuantity() >= sisaQty) {
      this->inven[idxDest]->setQuantity(64);
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
  if (inven.size() == MAX_INVEN) {
    throw "Inventory penuh";
  } else {
    int i = 0;
    bool found = false;
    while (i < MAX_INVEN && !found){
      // cari indeks yang masi kosong
      string key = intToString(i);
      if (this->inven.find(key) == inven.end()){
        this->inven[key] = item;
        found = true;
      } else {
        i++;
      }
    }
  }
}

void Inventory::add(Item* item_name,string dest){
  if(this->inven.find(dest)== inven.end()){
    this->inven[dest]=item_name;
  }else{
    throw "Sudah ada yang menempati";
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
    throw "Tidak ada item di indeks tersebut";
  } else if (qty < 0) {
    throw "Quantity Negatif";
  } else{ // gamungkin quantity 0 soalnya klo 0 pasti udah gaada di map
    try{
      int sisa = this->inven[I_id]->substract(qty);
      if(sisa==0){
        this->inven.erase(I_id);
      }
    }catch(BaseException* e){
      e->printMessage();
      //kalau qty kurang atau
    }
  }
}

void Inventory::use(string I_id){
  if (this->inven.find(I_id) == this->inven.end()) {
    throw "Tidak ada item di indeks tersebut";
  } else {
    if (this->inven[I_id]->use() <= 0) {
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
