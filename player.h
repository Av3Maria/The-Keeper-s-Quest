#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "character.h"
#include "Setup.h"
using namespace std;

class Setup;
class Setup;

struct Weapon {
	string name;
	vector<attackMoves> currentAttacks;
};


class player : public character {
protected:
	
	int ownedGold = 0;

public:
	unordered_map<int, int> inventory;

	vector<Weapon> inventoryW;
	Weapon* equippedWeapon = nullptr;
	//int equippedWeapon;

	//constructor for player class------
	player();
	//function to get player name------
	string getName() override;
	vector<attackMoves>& getcurrentAttacks();
	void showInventory();

	//void addToInventory(Setup& setup, int itemID);
	void equipWeapon(Setup& setup, int itemID);

	int getOwnedGold() const;
	void setGold(int amt);
	void modifyGold(int amount);
	
	

};
