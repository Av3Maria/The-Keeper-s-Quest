#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "character.h"
#include "Setup.h"
using namespace std;

class Setup;

struct Weapon {
	string name;
	vector<attackMoves> currentAttacks;
};

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
	
	int ownedGold = 0;
	vector<HealOption> healingOptions;
public:
	unordered_map<int, int> inventory;

	vector<Weapon> inventoryW;
	//Weapon* equippedWeapon = nullptr;
	int equippedIndex = 0;

	//constructor for player class------
	player();
	//function to get player name------
	string getName() override;
	vector<HealOption>& getHealingOptions();
	vector<attackMoves>& getcurrentAttacks();
	void showInventory();
	void useHealingOption(int index);
	void updateHealingCooldown();
	void syncWeapons(player& plyr, Setup& setup);
	void syncPotion(player& plyr, Setup& setup, int itemID);
	HealOption& getPotionFromItemID(int itemID);
	void equipWeapon(int inventoryIndex);
	void showHeallingOpt();

	int getOwnedGold() const;
	void setGold(int amt);
	void modifyGold(int amount);
	
	

};
