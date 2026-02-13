#pragma once
#ifndef player_h
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
	//constructor for player class------
	player();
	//function to get player name------
	string getName() override;

	vector<attackMoves>& getcurrentAttacks();
	void equipWeapon(int index);
	void showInventory();

};

#endif