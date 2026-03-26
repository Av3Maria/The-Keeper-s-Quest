#include "Setup.h"
#include "Shop.h"
#include "player.h"
#include "Inventory.h"
#include "talkingNPC.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

ShopKeeper shopkeeperNPC;

//main function
void enterShop(Setup& setup) { 
	cout << "\nYou step into the shop where you recieve a friendly greeting." << endl;

	shopkeeperNPC.printLines(0, setup);
}

//function for main ship menu
int displayShopMenu(Setup& setup) {

	bool inShop = true;

	while (inShop) {

		cout << "\n\tYour Gold: " << setup.mainPlayer.getOwnedGold() << "\n\n";

		cout << "\n Shop Menu:\n" << endl;
		cout << " 1. Weapons" << endl;
		cout << " 2. Potions" << endl;
		cout << " 3. Magic Items" << endl; //change to knowledge/spells?
		cout << " 4. Sell Items" << endl;
		cout << " 5. Exit Shop\n" << endl;

		int shopInput;
		cin >> shopInput;

		switch (shopInput) {
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
		case 5:
			inShop = false;
			break;
		}
	}
	shopkeeperNPC.printLines(5, setup);
	return -1;
}

//function for secondary shop menu
void displayType(Setup& setup, ItemType type) {
	cout << "\n " << (type == WEAPON ? "Weapons" : type == POTION ? "Potions" : "Magic Items") << ": \n" << endl;

	for (const auto& pair : setup.shopInventory) {

			int itemID = pair.first;
			int quantity = pair.second;

			const Item& item = setup.itemDatabase[itemID];

			if (item.type == type) {
				cout << itemID << ". " << item.name << " - " << item.value << " gold" << " (in-stock: " << quantity << ")\n";
			}
	}

	cout << "0. Back\n\n";

	int userChoice;
	cin >> userChoice;

	if (userChoice != 0) {
		purchaseItem(setup, userChoice);
	}
	if (userChoice == 0) {
		shopkeeperNPC.printLines(2, setup);
	}
}

//function to buy items from shop
void purchaseItem(Setup& setup, int itemID) {
	//each item has to store a gold value
	//put all buying code in here so dSM is easier to read
	//work on later
	// Check if item exists in shop

	auto& shopInv = setup.shopInventory;
	auto& itemDB = setup.itemDatabase;
	player& mP = setup.mainPlayer;

	auto it = shopInv.find(itemID);

	if (it == shopInv.end()) {
		cout << "\nitem does not exist\n";
		return;
	}
	if (it->second <= 0) {
		cout << "\nItem is out of stock.\n";
		return;
	}

	const Item& item = itemDB[itemID];

	if (mP.getOwnedGold() < item.value) {
		cout << "\nYou don't have enough gold.\n";
		return;
	}

	mP.modifyGold(-item.value);

	addToInventory(setup, itemID);

	it->second--;

	cout << "\nYou bought: " << item.name << "!\n";
	cout << "\nGold remaining: " << mP.getOwnedGold() << "\n";

	shopkeeperNPC.printLines(4, setup);
}

//function to sell items from player's inventory
void sellItem(Setup& setup) {
	auto& pInv = setup.mainPlayer.inventory;
	auto& itemDB = setup.itemDatabase;
	player& mP = setup.mainPlayer;

	if (pInv.empty()) {
		cout << "\nLooks like you don't have anything to sell.\n";
		return;
	}

	cout << "\nYour Inventory:\n" << endl;

	for (const auto& pair : pInv) {

		int itemID = pair.first;
		int quantity = pair.second;

		const Item& item = itemDB[itemID]; 

		cout << itemID << ". " << item.name << " x" << quantity << "(sell value: " << item.value << " gold)\n";
		
	}

	cout << "0. Back\n";

	int userChoice;
	cin >> userChoice;

	if (userChoice == 0) {
		return;
	}

	auto it = pInv.find(userChoice);

	if (it == pInv.end()) {
		cout << "\n[item does not exist]\n";
		return;
	}

	const Item& item = itemDB[userChoice];

	it->second--;

	if (it->second <= 0) {
		pInv.erase(it);
	}

	setup.shopInventory[userChoice]++;

	cout << "\nYou sold: " << item.name << "!\n";

	mP.modifyGold(+item.value);
}