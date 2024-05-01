#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(const string& name, const string& description, int price, int quantity); 


    void SetName(const string& name);
    void SetPrice(int price);
    void SetQuantity(int quantity);
    void SetDescription(const string& description); 

    string GetName() const;
    int GetPrice() const;
    int GetQuantity() const;
    string GetDescription() const; 

private:
    string itemName;
    int itemPrice;
    int itemQuantity;
    string itemDescription; 
};    

#endif
