#pragma once
#include <unordered_map>
#include <string>
#include "player.h"
using namespace std;

enum ItemType {
	WEAPON,
	POTION,
	MAGIC_ITEM
};

struct Item {
	int itemID;
	string name;
	int value;
	ItemType type;
	bool equippable;
};

class Setup {
public:

	unordered_map<int, Item> itemDatabase;
	unordered_map<int, int> shopInventory;
	player mainPlayer;

	void initializeItems();
};