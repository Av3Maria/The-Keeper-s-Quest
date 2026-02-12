#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <unordered_map>
using namespace std;

static unordered_map<int, inventoryItem> itemIndex; //unordered map to store all items in the game
static unordered_map<int, int> inventory; //unordered map to store the player's inventory
int equippedItemID = -1; //variable to store the itemID of the currently equipped item, -1 means no item is equipped

inventoryItem::inventoryItem() : itemID(0), itemName(""), equippable(false) {} 

//main function
void manageInventory() { 
	allItems(); //call all items

	//starting inventory
	addToInventory(1);
	addToInventory(2);
	addToInventory(3);

	printInventoryMenu(); //this is the main part of the inventory stuff
}
//function to add all items to the itemIndex unordered map
void allItems() {
	itemIndex.emplace(1, inventoryItem(1, "Basic Sword", true)); //format: inventoryItem(itemID, itemName, equippable)
	itemIndex.emplace(2, inventoryItem(2, "Basic Bow", true));
	itemIndex.emplace(3, inventoryItem(3, "Basic Health Potion", false));
	//add more
}
//prints inventory
void printInventoryMenu() { 
	bool isRunning = true;

	while (isRunning) {

		cout << "\n Your Inventory:\n" << endl;

		if (inventory.empty()) { //if inventory is empty, print this and refresh
			cout << "\n (your inventory is empty)" << endl;
			refreshInv();
			return;
		}

		vector<int> itemIDs; //stores what is actually in the player's inventory
		int index = 1;

		for (const auto& pair : inventory) { //for loop that prints the player's inventory
			
			const inventoryItem& item = itemIndex[pair.first];

			cout << " " << index << ". " << item.itemName << " x" << pair.second << endl;
			itemIDs.push_back(pair.first);
			index++;
		}

		cout << " 0. Exit Inventory";
		cout << "\n\n Select an item to manage: ";

		int userItemChoice;
		cin >> userItemChoice; //gets the user's choice for which item to manage
		
		if (userItemChoice < 0 || userItemChoice > itemIDs.size()) { //for values outside bounds
			cout << "\nInvalid item selection.\n";
			refreshInv();
			continue;
		}

		if (userItemChoice == 0) { //for when the user wants to exit the inventory
			isRunning = false;
			refreshInv();
			continue;
		}

		int selectedItemID = itemIDs[userItemChoice - 1]; //gets the itemID of the item the user selected
		const inventoryItem& selectedItem = itemIndex[selectedItemID]; //gets the inventoryItem object of the item the user selected

		cout << "\n" << selectedItem.itemName << "\n"; //prints the name of the item the user selected and a small menu afterwards
		cout << " 1. Equip Item" << endl;
		cout << " 2. Remove Item" << endl;
		cout << " 3. Back to Inventory" << endl;

		cout << "\n Select an action: ";

		int userAction;
		cin >> userAction; //gets the user's choice for what to do with the item they selected

		switch (userAction) { //switch to call the function corresponding to userAction
		case 1:
			equipItem(selectedItemID);
			refreshInv();
			break;
		case 2:
			removeFromInventory(selectedItemID);
			refreshInv();
			break;
		case 3:
			refreshInv();
			break;
		default:
			cout << "\n\t(not a valid option)" << endl;
			refreshInv();
		}
	}
}
//adds to inventory
void addToInventory(int itemID) {
	inventory[itemID]++;
}
//removes from inventory
void removeFromInventory(int itemID) {
	auto it = inventory.find(itemID); //finds the item in the inventory

	if (it != inventory.end()) { //if the item is found, decrease the quantity by 1
		it->second--;

		if (it->second <= 0) { //if the quantity is 0 or less, remove the item from the inventory
			inventory.erase(it);
		}
	}

	cout << "\n\tYou removed: " << itemIndex[itemID].itemName << endl;
}
//equips item
void equipItem(int itemID) {
	const inventoryItem& item = itemIndex[itemID]; //gets the inventoryItem object of the item the user selected

	if (item.equippable) { //if the item is equippable, equip it and set equippedItemID to the itemID of the item the user selected
		cout << "\n\tYou equipped: " << item.itemName << endl;
	}
	else {
		cout << "\n\t(this item cannot be equipped)" << endl;
	}

	//probably add more
}


void refreshInv() { //function to refresh the screen
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this codeline makes sure the refresh function waits for the user's enter before refreshing
	cout << "\n Press Enter to refresh: ";
	cin.get(); //reads the user's enter and then refreshes
	system("cls"); //clears the screen
}