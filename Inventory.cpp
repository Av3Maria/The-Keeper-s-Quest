#include "Setup.h"
#include "Inventory.h"
#include "player.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

//main function
void manageInventory(Setup& setup) {
	refreshInv();
	printInventoryMenu(setup); //call inventory menu
}

//prints inventory
void printInventoryMenu(Setup& setup) {
	bool isRunning = true;
	//sync weapons in both inventories
	setup.mainPlayer.syncWeapons(setup.mainPlayer, setup);
	while (isRunning) {

		auto& inv = setup.mainPlayer.inventory;
		//if players inventory is empty
		if (inv.empty()) {
			cout << "\n (your inventory is empty)" << endl;
			refreshInv();
			return;
		}

		vector<int> itemIDs; //stores what is actually in the player's inventory
		int index = 1;
		refreshInv();
		player& p = setup.mainPlayer;

		//prints out the stats of the player
		cout << "=====================================\n";
		cout << "         PLAYER STATUS\n";
		cout << "=====================================\n";
		cout << "Name: " << p.getName() << endl;
		cout << "Class: " << p.getClassType() << endl;
		cout << "HP: " << p.getHealth() << endl;
		cout << "Strength: " << p.getStrength() << endl;
		cout << "Defense: " << p.getDefense() << endl;
		cout << "Gold: " << p.getOwnedGold() << endl;
		//equiped wepaon
		if (!p.inventoryW.empty() &&
			p.equippedIndex >= 0 &&
			p.equippedIndex < p.inventoryW.size())
		{
			cout << "Weapon: " << p.inventoryW[p.equippedIndex].name << endl;
		}
		else
		{
			cout << "Weapon: None" << endl;
		}
		cout << "=====================================\n";
		cout << "\n Your Inventory:\n" << endl;
		//inventory items
		for (const auto& pair : inv) {

			if (pair.second <= 0) continue;
			auto it = setup.itemDatabase.find(pair.first);
			
			if (it == setup.itemDatabase.end()) {
				cout << "\n\t[error: item not found in database]" << endl;
				continue;
			}

			const Item& item = it->second;
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
		refreshInv();
		cout << "\n" << setup.itemDatabase[selectedItemID].name << "\n"; //prints the name of the item the user selected and a small menu afterwards
		cout << " 1. Use Item" << endl;
		cout << " 2. Equip Item" << endl;
		cout << " 3. Remove Item" << endl;
		cout << " 4. Back to Inventory" << endl;

		cout << "\n Select an action: ";

		int userAction;
		cin >> userAction; //gets the user's choice for what to do with the item they selected

		switch (userAction) {
			//using item
		case 1:
		{
			player& p = setup.mainPlayer;

			auto it = p.inventory.find(selectedItemID);
			if (it == p.inventory.end() || it->second <= 0) {
				cout << "\nYou don't have that item!\n";
				break;
			}

			const Item& item = setup.itemDatabase[selectedItemID];

			if (item.type == POTION) {
				p.syncPotion(p, setup, selectedItemID);
			}
			else {
				cout << "\nThis item cannot be used.\n";
			}

			break;
		}
		//euiping item
		case 2: 
			equipItem(setup, selectedItemID);
			break;
		//removing item
		case 3:
			removeFromInventory(setup, selectedItemID);
			break;

		case 4:
			break;

		default:
			cout << "\n(not a valid option)\n";
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

		mP.syncWeapons(mP, setup);

		//euip weapon intialy
		for (int i = 0; i < mP.inventoryW.size(); i++) {
			if (mP.inventoryW[i].name == item.name) {
				mP.equipWeapon(i);
				break;
			}
		}
		cout << "\n\tYou equipped: " << item.name << endl;
		mP.syncWeapons(mP, setup);
	}
	else if (item.type == MAGIC_ITEM)
	{
		cout << "\nThe power of " << item.name
			<< " is already active while carried.\n";
	}
	
}

void refreshInv() { //function to refresh the screen
	this_thread::sleep_for(chrono::milliseconds(500));

	system("cls"); //clears the screen
}