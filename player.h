#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "character.h"
using namespace std;


struct Weapon {
	string name;
	vector<attackMoves> currentAttacks;
};

class player : public character {
protected:
	vector<Weapon> inventory;
	Weapon* equippedWeapon = nullptr;

public:
	int ownedGold;
	void setGold(int amt);

	//constructor for player class------
	player();
	//function to get player name------
	string getName() override;

	vector<attackMoves>& getcurrentAttacks();
	void equipWeapon(int index);
	void showInventory();
	int getOwnedGold() const;

	void modifyGold(int amount);
	
	void addToInventory(int itemID);

};
