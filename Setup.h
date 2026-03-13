#pragma once
#include <unordered_map>
#include <string>
#include "player.h"
using namespace std;

struct Item {
	int itemID;
	string name;
	int price;
	bool equippable;
};

class Setup {
public:

	unordered_map<int, Item> itemDatabase;
	unordered_map<int, int> shopInventory;
	player plyr;

	void initializeItems();
};

