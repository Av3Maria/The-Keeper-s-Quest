#include "Setup.h"
#include "Inventory.h"
#include "player.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <unordered_map>
using namespace std;

//main function
void manageInventory(Setup& setup) { 

	printInventoryMenu(setup); //call inventory menu
}

//prints inventory
void printInventoryMenu(Setup& setup) {
	bool isRunning = true;

	while (isRunning) {

		auto& inv = setup.mainPlayer.inventory;

		if (inv.empty()) {
			cout << "\n (your inventory is empty)" << endl;
			refreshInv();
			return;
		}

		vector<int> itemIDs; //stores what is actually in the player's inventory
		int index = 1;

		cout << "\n Your Inventory:\n" << endl;
	
		for (const auto& pair : inv) {

			const Item& item = setup.itemDatabase[pair.first];

			cout << " " << index << ". " << item.name << " x" << pair.second << endl;

			itemIDs.push_back(pair.first);
			index++;
		}

		cout << " 0. Exit Inventory";
		cout << "\n\n Select an item to manage: ";

		int userItemChoice;
		cin >> userItemChoice; //gets the user's choice for which item to manage
		
		if (userItemChoice == 0) { //for when the user wants to exit the inventory
			isRunning = false;
			refreshInv();
			continue;
		}
		if (userItemChoice < 0 || userItemChoice > itemIDs.size()) { //for values outside bounds
			cout << "\nInvalid item selection.\n";
			refreshInv();
			continue;
		}

		int selectedItemID = itemIDs[userItemChoice - 1]; //gets the itemID of the item the user selected
		//const Item& selectedItem = itemDatabase[selectedItemID]; //gets the inventoryItem object of the item the user selected

		//cout << "\n" << selectedItem.name << "\n"; //prints the name of the item the user selected and a small menu afterwards
		cout << " 1. Equip Item" << endl;
		cout << " 2. Remove Item" << endl;
		cout << " 3. Back to Inventory" << endl;

		cout << "\n Select an action: ";

		int userAction;
		cin >> userAction; //gets the user's choice for what to do with the item they selected

		switch (userAction) { //switch to call the function corresponding to userAction
		case 1:
			equipItem(setup, selectedItemID);
			//refreshInv();
			break;
		case 2:
			removeFromInventory(setup, selectedItemID);
			//refreshInv();
			break;
		case 3:
			//refreshInv();
			break;
		default:
			cout << "\n\t(not a valid option)" << endl;
			refreshInv();
		}
	}
}

//adds to inventory
void addToInventory(Setup& setup, int itemID) {
	setup.mainPlayer.inventory[itemID]++;
}

//removes from inventory
void removeFromInventory(Setup& setup, int itemID) {
	auto& inv = setup.mainPlayer.inventory; //finds the item in the inventory
	auto it = inv.find(itemID);

	if (it != inv.end()) { //if the item is found, decrease the quantity by 1
		it->second--;

		if (it->second <= 0) { //if the quantity is 0 or less, remove the item from the inventory
			inv.erase(it);
		}
	}

	cout << "\n\tYou removed: " << setup.itemDatabase[itemID].name << endl;
}


//equips item
void equipItem(Setup& setup, int itemID) {
	player& mP = setup.mainPlayer;
	const Item& item = setup.itemDatabase[itemID];

	if (!item.equippable) {
		cout << "\n\tthis item cannot be equipped\n";
		return;
	}
	if (item.type == WEAPON) {
		//mP.equipWeapon(setup, itemID);
		cout << "\n\tYou equipped: " << item.name << endl;
	}
	else if (item.type == MAGIC_ITEM) {
		if (itemID == 17) { //amulet of defense
			mP.defense += 20;
			cout << "\n\tYou equipped: " << item.name << endl;
		}
		else if (itemID == 18) { //amulet of strength
			mP.strength += 20;
			cout << "\n\tYou equipped: " << item.name << endl;
		}
		else if (itemID == 19) { //amulet of poison
			mP.strength += 10;
			mP.defense -= 10;
			cout << "\n\tYou equipped: " << item.name << endl;
		}
		else if (itemID == 20) { //amulet of fire
			mP.strength += 10;
			mP.defense -= 10;
			cout << "\n\tYou equipped: " << item.name << endl;
		}
		else if (itemID == 21) { //amulet of enduring
			mP.health += 50;
			cout << "\n\tYou equipped: " << item.name << endl;
		}
	}
}

void refreshInv() { //function to refresh the screen
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this codeline makes sure the refresh function waits for the user's enter before refreshing
	cout << "\n Press Enter to refresh: ";
	cin.get(); //reads the user's enter and then refreshes
	system("cls"); //clears the screen
}