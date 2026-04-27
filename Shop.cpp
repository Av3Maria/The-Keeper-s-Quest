#include "Setup.h"
#include "Shop.h"
#include "player.h"
#include "Inventory.h"
#include "talkingNPC.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

ShopKeeper shopkeeperNPC;

//main function
void enterShop(Setup& setup) { 
	shopkeeperNPC.printLines(0, setup); //all other functions controlled through the npc code
}

//function for main ship menu
int displayShopMenu(Setup& setup) {
	bool inShop = true;

	while (inShop) {

		cout << "\n\tYour Gold: " << setup.mainPlayer.getOwnedGold() << "\n\n"; //prints player's current gold

		cout << "\n Shop Menu:\n" << endl; //shop menu options
		cout << " 1. Weapons" << endl;
		cout << " 2. Potions" << endl;
		cout << " 3. Magic Items" << endl; 
		cout << " 4. Sell Items" << endl;
		cout << " 5. Exit Shop\n" << endl;

		int shopInput;
		cin >> shopInput; //gets user's choice for menu

		switch (shopInput) { //handles user input and prints submenu for each item type
		case 1:
			displayType(setup, WEAPON);
			break;
		case 2:
			displayType(setup, POTION);
			break;
		case 3:
			displayType(setup, MAGIC_ITEM);
			break;
		case 4:
			sellItem(setup);
			break;
		case 5: //leaves shop
			inShop = false;
			break;
		}
	}
	shopkeeperNPC.printLines(5, setup); //prints npc lines
	return -1;
}

//function for secondary shop menu
void displayType(Setup& setup, ItemType type) {
	refreshShop();

	cout << "\n\tYour Gold: " << setup.mainPlayer.getOwnedGold() << "\n\n"; //prints player's current gold

	cout << "\n " << (type == WEAPON ? "Weapons" : type == POTION ? "Potions" : "Magic Items") << ": \n" << endl; //prints item type header based on user choice

	for (const auto& pair : setup.shopInventory) { //prints out item types (but only corresponding item type)

			int itemID = pair.first;
			int quantity = pair.second;

			const Item& item = setup.itemDatabase[itemID];

			if (item.type == type) {
				cout << itemID << ". " << item.name << " - " << item.value << " gold" << " (in-stock: " << quantity << ")\n";
			}
	}

	cout << "0. Back\n\n";

	int userChoice;
	cin >> userChoice; //gets user choice for what item to buy

	if (userChoice != 0) { //buys item
		purchaseItem(setup, userChoice);
	}
	if (userChoice == 0) { //does not buy item
		shopkeeperNPC.printLines(2, setup);
	}
}

//function to buy items from shop
void purchaseItem(Setup& setup, int itemID) {
	//put all buying code in here so dSM is easier to read
	//work on later

	auto& shopInv = setup.shopInventory; //for easier access to shop inventory
	auto& itemDB = setup.itemDatabase; //for easier access to item database
	player& mP = setup.mainPlayer; //for easier access to player

	auto it = shopInv.find(itemID);

	if (it == shopInv.end()) { //checks to make sure item is in the shop
		cout << "\nitem does not exist\n";
		return;
	}
	if (it->second <= 0) { //checks to make sure item is in stock
		cout << "\nItem is out of stock.\n";
		return;
	}

	const Item& item = itemDB[itemID];

	if (mP.getOwnedGold() < item.value) { //if player doesn't have enough gold
		cout << "\nYou don't have enough gold.\n";
		return;
	}

	mP.modifyGold(-item.value); //decreases gold if item bought

	addToInventory(setup, itemID); //adds to player inventory

	it->second--; //decreases shop inventory

	cout << "\nYou bought: " << item.name << "!\n"; //tells player they bought item
	cout << "\nGold remaining: " << mP.getOwnedGold() << "\n"; //tells player their remaining gold

	this_thread::sleep_for(chrono::seconds(2)); //waits a bit so player can read confirmation

	shopkeeperNPC.printLines(4, setup); //prints npc lines
}

//function to sell items from player's inventory
void sellItem(Setup& setup) {
	refreshShop();

	auto& pInv = setup.mainPlayer.inventory; //for easier access to player inventory
	auto& itemDB = setup.itemDatabase; //for easier access to item database
	player& mP = setup.mainPlayer; //for easier access to player

	if (pInv.empty()) { //if player inventory is empty
		cout << "\nLooks like you don't have anything to sell.\n";
		return;
	}

	cout << "\nYour Inventory:\n" << endl; 

	for (const auto& pair : pInv) { //prints player inventory and corresponding sell values

		int itemID = pair.first;
		int quantity = pair.second;

		const Item& item = itemDB[itemID]; 

		cout << itemID << ". " << item.name << " x" << quantity << "(sell value: " << item.value << " gold)\n";
		
	}

	cout << "0. Back\n";

	int userChoice;
	cin >> userChoice; //gets user choice for what item to sell

	if (userChoice == 0) { //if player doesn't want to sell anything
		refreshShop();
		return;
	}

	auto it = pInv.find(userChoice); //finds item in player's inventory

	if (it == pInv.end()) { //if item doesn't exist in player's inventory
		cout << "\n[item does not exist]\n";
		return;
	}

	const Item& item = itemDB[userChoice]; //gets item information from item database

	it->second--; //decreases item quantity in player's inventory

	if (it->second <= 0) { //if quantity is 0 or less, remove item from player's inventory
		pInv.erase(it);
	}

	setup.shopInventory[userChoice]++; //increases shop inventory (adds sold item to shop inventory)

	cout << "\nYou sold: " << item.name << "!\n"; //tells player what they sold

	mP.modifyGold(+item.value); //increases player's gold based on sold item

	refreshShop();
}

void refreshShop() { //function to refresh the screen
	this_thread::sleep_for(chrono::milliseconds(500)); 
	system("cls");
}