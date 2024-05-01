#include <iostream>
#include <iomanip>
#include <limits>
#include "ShoppingCart.h"

using namespace std;

void PrintMenu() {
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   bool validOption = true;
    switch(option) {
        case 'a': {
            cout << "ADD ITEM TO CART" << endl;
            string itemName, itemDescription;
            int itemPrice, itemQuantity;
            cout << "Enter the item name:" << endl;
            getline(cin >> ws, itemName);
            cout << "Enter the item description:" << endl;
            getline(cin >> ws, itemDescription);
            cout << "Enter the item price:" << endl;
            cin >> itemPrice;
            cout << "Enter the item quantity:" << endl;
            cin >> itemQuantity;
            ItemToPurchase newItem;
            newItem.SetName(itemName);
            newItem.SetDescription(itemDescription);
            newItem.SetPrice(itemPrice);
            newItem.SetQuantity(itemQuantity);
            theCart.AddItem(newItem);
            break;
        }
        case 'd': {
            cout << "REMOVE ITEM FROM CART" << endl;
            string itemName;
            cout << "Enter name of item to remove:" << endl;
            getline(cin >> ws, itemName);
            theCart.RemoveItem(itemName);
            break;
        }
        case 'c': {
            cout << "CHANGE ITEM QUANTITY" << endl;
            string itemName;
            int newQuantity;
            cout << "Enter the item name:" << endl;
            getline(cin >> ws, itemName);
            cout << "Enter the new quantity:" << endl;
            cin >> newQuantity;
            ItemToPurchase newItem;
            newItem.SetName(itemName);
            newItem.SetQuantity(newQuantity);
            theCart.ModifyItem(newItem);
            break;
        }
        case 'i':
            theCart.PrintDescriptions();
            break;
        case 'o':
            theCart.PrintTotal();
            break;
        case 'q':
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid option, please try again." << endl;
            validOption = false;
    }
    if (!validOption) {
        cout << endl;
        PrintMenu();
    }
}

int main() {
    string customerName, currentDate;

    cout << "Enter customer's name:" << endl;
    getline(cin >> ws, customerName);
    cout << "Enter today's date:" << endl;
    getline(cin >> ws, currentDate);

    cout << endl;
    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl << endl;

    ShoppingCart cart(customerName, currentDate);

    char option;
    do {
        PrintMenu();
        cout << "Choose an option:" << endl;
        cin >> option;

        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        ExecuteMenu(option, cart);
        cout << endl;
    } while(option != 'q');

    return 0;
}

