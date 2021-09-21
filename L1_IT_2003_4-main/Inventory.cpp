#include "Inventory.h"

Inventory::Inventory(){
    this->space = 5;
    this->numOfItems = 0;
    this->itemArr = new Item*[space];

    for(size_t i=0 ; i <  this->numOfItems; i++){
        delete this->itemArr[i];
    }
    delete[] itemArr;
}

//Creating new arrays to store our gained items if we run out of space
//doubles up the space
void Inventory::expand() {
    this->space *=2;

    Item **tempArr = new Item*[space];

    for(size_t i=0 ; i <  this->numOfItems; i++){
        tempArr[i] = new Item(*this->itemArr[i]);
    }
    for(size_t i=0 ; i <  this->numOfItems; i++){
        delete this->itemArr[i];
    }
    delete[] this->itemArr;

    this->itemArr = tempArr;

    this->initialize(this->numOfItems);

}
//starting the array for inventory to appear
void Inventory::initialize(const int from) {
    for (size_t i = from; i < space; i++) {
        this->itemArr[i] = nullptr;
    }
}
//adds an item into our inventory
void Inventory::addItem(const Item &item) {
    if(this->numOfItems >= this->space){
        expand();
    }
    this->itemArr[this->numOfItems++] = new Item(item);
}
//function deleting items after death
void Inventory::deleteItem(int index) {

}
