#include "Shop.h"
#include "Setup.h"
#include "player.h"
#include "Inventory.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

static unordered_map<int, int> shopInventory;

//main function
void enterShop(Setup& s) { 
	displayShopMenu(s);

}

void displayShopMenu(Setup& s) {
	bool inShop = true;

	cout << "\n\tYou step into the shop.\n";

	while (inShop) {

		cout << "\tGold: " << s.plyr.getOwnedGold() << "\n\n";

		cout << "Available Items:\n";

		// Display items dynamically from shopStock
		for (const auto& pair : s.shopInventory) {

			int itemID = pair.first;
			int stock = pair.second;

			const Item& item = s.itemDatabase[itemID];

			cout << itemID << ". "
				<< item.name
				<< " - " << item.price << " gold"
				<< " (Stock: " << stock << ")\n";
		}

		cout << "0. Exit Shop\n";
		cout << "\nSelect an item to buy: ";

		int choice;
		cin >> choice;

		if (choice == 0) {
			inShop = false;
			cout << "\n\tYou leave the shop.\n";
			break;
		}

		purchaseItem(s, choice);
	}
	/*
	cout << "\n\t You step into the shop and walk up to the shopkeeper who says," << endl;
	cout << "\t\t'What would you like to buy?'" << endl;
	cout << "\nShop Menu:\n" << endl;
	cout << " 1. Weapons" << endl;
	cout << " 2. Potions" << endl;
	cout << " 3. Magic Items" << endl; //change to knowlegde/spells
	cout << " 4. Exit Shop" << endl;

	int shopInput;
	cin >> shopInput;

	int choice;
	switch (shopInput) {
	case 1:
		cout << "\n\t Weapons: \n" << endl;
		cout << "1 -50 gold" << endl;
		cout << "2 -100 gold" << endl;

		cout << "\n What would you like to buy? (type the number): ";
		cin >> choice;

		//purchaseItem(choice);

		if(ownedGold >= 50 && choice == 1) {
			//add item to inventory
			ownedGold -= 50;
			cout << "\n\t You bought the item and added it to your inventory." << endl;
			cout << "\n\t You have " << ownedGold << " gold left." << endl;
		}
		else if(ownedGold >= 100 && choice == 2) {
			//add item to inventory
			ownedGold -= 100;
			cout << "\n\t You bought the item and added it to your inventory." << endl;
			cout << "\n\t You have " << ownedGold << " gold left." << endl;
		}
		else {
			cout << "\n\t You don't have enough gold for that item." << endl;
		}
		break;
	case 2:
		cout << "\n\t Potions: \n" << endl;
		cout << "1 -20 gold" << endl;
		cout << "2 -40 gold" << endl;

		cout << "\n What would you like to buy? (type the number): ";
		cin >> choice;

		if(ownedGold >= 20 && choice == 1) {
			//add item to inventory
			ownedGold -= 20;
			cout << "\n\t You bought the item and added it to your inventory." << endl;
			cout << "\n\t You have " << ownedGold << " gold left." << endl;
		}
		else if(ownedGold >= 40 && choice == 2) {
			//add item to inventory
			ownedGold -= 40;
			cout << "\n\t You bought the item and added it to your inventory." << endl;
			cout << "\n\t You have " << ownedGold << " gold left." << endl;
		}
		else {
			cout << "\n\t You don't have enough gold for that item." << endl;
		}
		break;
	case 3:
		cout << "\n\t Magic Items: \n" << endl;
		cout << "1 -200 gold" << endl;
		cout << "2 -500 gold" << endl;

		cout << "\n What would you like to buy? (type the number): ";
		cin >> choice;

		if(ownedGold >= 200 && choice == 1) {
			//add item to inventory
			ownedGold -= 200;
			cout << "\n\t You bought the item and added it to your inventory." << endl;
			cout << "\n\t You have " << ownedGold << " gold left." << endl;
		}
		else if(ownedGold >= 500 && choice == 2) {
			//add item to inventory
			ownedGold -= 500;
			cout << "\n\t You bought the item and added it to your inventory." << endl;
			cout << "\n\t You have " << ownedGold << " gold left." << endl;
		}
		else {
			cout << "\n\t You don't have enough gold for that item." << endl;
		}
		break;
	case 4:
		cout << "\n\t You exit the shop and continue on your adventure." << endl;
		break;
	}*/
}

void purchaseItem(Setup& s, int itemID) {
	//each item has to store a gold value
	//put all buying code in here so dSM is easier to read
	//work on later
	// Check if item exists in shop
	auto stockIt = s.shopInventory.find(itemID);

	if (stockIt == s.shopInventory.end()) {
		cout << "\nInvalid item selection.\n";
		return;
	}

	if (stockIt->second <= 0) {
		cout << "\nItem is out of stock.\n";
		return;
	}

	const Item& item = s.itemDatabase[itemID];
	player& p = s.plyr;

	if (p.getOwnedGold() < item.price) {
		cout << "\nYou don't have enough gold.\n";
		return;
	}

	// Deduct gold
	p.modifyGold(-item.price);

	// Add to player inventory
	p.addToInventory(itemID);

	// Reduce shop stock
	stockIt->second--;

	cout << "\nYou bought: " << item.name << "!\n";
	cout << "Gold remaining: " << p.getOwnedGold() << "\n";
}


void sellItem(Setup& s) {
	//similar thing for purchasing but check the players inventory and add gold instead of subtracting it
}