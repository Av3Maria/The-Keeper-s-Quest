#pragma once
#ifndef Inventory_h
#include <iostream>
#include <string>
using namespace std;

void manageInventory();

class inventoryItem {
public:

	//void manageInventory();
	int printInventory();
	void addToInventory();
	void removeFromInventory();
	void equipItem(int userInput);
	void refreshInv();

};

#endif