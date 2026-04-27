#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include "player.h"
using namespace std;

//header file for file connecting all game systems together

enum ItemType { //designates item types
	WEAPON,
	POTION,
	MAGIC_ITEM
};

struct Item { //item object with relevant data
	int itemID; //ID# of item, used for referencing in inventory and shop
	string name; //name of item
	int value; //gold value of item
	ItemType type; //type of item
	bool equippable; //if item can be equipped or not
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