//
// Created by 77082 on 19.09.2021.
//
#include "Item.h"

class Inventory {
private:    //here we will create a dynamic array so we have space to store our items
    int space;
    int numOfItems;
    Item **itemArr;
    void initialize(const int from);
    void expand();

public:
    Inventory();


    void addItem(const Item &item);
    void deleteItem(int index);
};

