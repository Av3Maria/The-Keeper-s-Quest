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

struct weaponTemp {
	string type;
	vector <string> dialogue;
	vector <int> baseDamage;
	vector<string> attackNames;
};

Weapon createWeapon(const weaponTemp& temp, const string& weaponName, const vector<int>& damages);

class Setup {
public:

	unordered_map<int, Item> itemDatabase;
	unordered_map<int, int> shopInventory;
	player mainPlayer;
	weaponTemp swordTemp;
	weaponTemp bowTemp;
	weaponTemp lastingEffectTemp;
	unordered_map<int, weaponTemp> itemTemplates;
	unordered_map<int, vector<int>> weaponDamage;
	Setup();
	void initializeItems();
};