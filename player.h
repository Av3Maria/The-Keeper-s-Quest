#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "character.h"
#include "Setup.h"
using namespace std;

class Setup;

//weapons
struct Weapon {
	string name;
	vector<attackMoves> currentAttacks;
};
//healing topions
enum HealingOptionType {
	Potion,  //option 0
	Bandage, //option 1
	Spell    //option 2
};

struct HealOption {
	int itemID;
	string name;
	HealingOptionType type;
	int optionCooldown;
	int turnRemaining;
	int baseHeal;
	int healAmountPerTurn;
	int durationTime;
	int quantity;
	vector<string> dialogue;
};

enum InventorySlots {
	WeaponSlot,
	NumberofSlots
};

class player : public character {
protected:
	//player character, gold, potions
	string classType;
	int ownedGold = 0;
	vector<HealOption> healingOptions;
public:
	//inventory
	unordered_map<int, int> inventory;
	vector<Weapon> inventoryW;
	int equippedIndex = 0;

	//constructor for player class
	player();
	player(string charName, string charType);

	//function to get player name
	string getName() override;
	void setName(string newName);

	//get player type
	string getClassType() const;
	void setClassType(string newClassType);

	//healing functions
	vector<HealOption>& getHealingOptions();
	void useHealingOption(int index, bool inBattle);
	void updateHealingCooldown();
	void showHeallingOpt();
	int getMaxHealth() const;
	//attack function
	vector<attackMoves>& getcurrentAttacks();

	//item functions
	void showInventory();
	void syncWeapons(player& plyr, Setup& setup);
	void syncPotion(player& plyr, Setup& setup, int itemID);
	HealOption& getPotionFromItemID(int itemID);
	void equipWeapon(int inventoryIndex);
	bool hasItem(int id) const;
	int getStrength() const;
	int getDefense() const;

	//amulet functions
	void resetStatsAfterBattle();
	void giveAmulet(int id);

	//gold funcitons
	int getOwnedGold() const;
	void setGold(int amt);
	void modifyGold(int amount);

};

