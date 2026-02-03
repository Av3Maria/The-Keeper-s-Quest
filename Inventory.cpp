#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void manageInventory() {
	inventoryItem inv;

	int userInput = inv.printInventory();
	inv.equipItem(userInput);

	inv.refreshInv();

}

int inventoryItem::printInventory() { //COMPLETELY CHANGE THSI PART

	//using a list or hash table so change all this code
	vector<string> inventory = { "Basic Sword", "Basic Bow" };

	cout << "\n Your Inventory:\n" << endl;

	for (size_t i = 0; i < inventory.size(); ++i) {
		cout << " " << (i + 1) << ". " << inventory[i] << endl;
	}

	cout << "\n Equip Weapon: ";
	int userInput;
	cin >> userInput;

	return userInput;
}

void inventoryItem::addToInventory() {
	//add
}

void inventoryItem::removeFromInventory() {
	//add
}

void inventoryItem::equipItem(int userInput) {
	switch (userInput) {
	case 1:
		cout << "\n\tYou have equipped the Basic Sword!" << endl;
		break;
	case 2:
		cout << "\n\tYou have equipped the Basic Bow!" << endl;
		break;

	}
}

void inventoryItem::refreshInv() { //function to refresh the screen
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this codeline makes sure the refresh function waits for the user's enter before refreshing
	cout << "\n Press Enter to refresh: ";
	cin.get(); //reads the user's enter and then refreshes
	system("cls"); //clears the screen
}