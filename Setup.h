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
//template system for weapons
struct weaponTemp { 
	string type;
	vector <string> dialogue;
	vector <int> baseDamage;
	vector<string> attackNames;
};
//build weapon from template with vals
Weapon createWeapon(const weaponTemp& temp, const string& weaponName, const vector<int>& damages);

class Setup {
public:

	//items and shop
	unordered_map<int, Item> itemDatabase; //all items in the game
	unordered_map<int, int> shopInventory; 

	//player instance
	player mainPlayer;

	//templates for weapons
	weaponTemp swordTemp;
	weaponTemp bowTemp;
	weaponTemp lastingEffectTemp;
	weaponTemp featherPenTemp;
	weaponTemp dragonToothTemp;
	weaponTemp bottleLightTemp;
	weaponTemp basicStaffTemp;

	//map ids for weapons
	unordered_map<int, weaponTemp> itemTemplates;
	unordered_map<int, vector<int>> weaponDamage;

	//flags for amulets
	bool amuletFromBeggarReceived = false;
	bool amuletAvailableInShop2 = true;
	bool amuletFromShop2Taken = false;
	int shardsCollected = 0;

	void initializeItems(); //set up all items
	void lootDrops();       //handle loot drop
	Setup();
};