#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
    itemDescription = "none"; 
}
ItemToPurchase::ItemToPurchase(const string& name, const string& description, int price, int quantity) {
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
}

void ItemToPurchase::SetName(const string& name) {
    itemName = name;
}

void ItemToPurchase::SetPrice(int price) {
    itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

void ItemToPurchase::SetDescription(const string& description) {
    itemDescription = description;
}

string ItemToPurchase::GetName() const {
    return itemName;
}

int ItemToPurchase::GetPrice() const {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}

string ItemToPurchase::GetDescription() const {
    return itemDescription;
}
