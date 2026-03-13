#pragma once
#include "Setup.h"
#include <iostream>
#include <string>
#include <unordered_map>
/*
struct Item {
	int itemID;
	string name;
	int price;
	bool equippable;
};*/

/*
class inventoryItem {
public:

	int itemID;
	string itemName;
	bool equippable;

	inventoryItem();
	inventoryItem(int itemID, string itemName, bool equippable) : itemID(itemID), itemName(itemName), equippable(equippable) {}

};*/

//void allItems();
void printInventoryMenu();
void addToInventory(int itemID);
void removeFromInventory(int itemID);
void equipItem(int itemID);
void refreshInv();
void manageInventory(Setup& s);