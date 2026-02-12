#pragma once
#ifndef Inventory_h
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class inventoryItem {
public:

	int itemID;
	string itemName;
	bool equippable;

	inventoryItem();
	inventoryItem(int itemID, string itemName, bool equippable) : itemID(itemID), itemName(itemName), equippable(equippable) {}

};

void allItems();
void printInventoryMenu();
void addToInventory(int itemID);
void removeFromInventory(int itemID);
void equipItem(int itemID);
void refreshInv();
void manageInventory();

#endif

