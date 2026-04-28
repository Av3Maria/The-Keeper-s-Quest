#pragma once
#ifndef wizard_h
#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
using namespace std;

class wizard : public enemy {
protected:
	int assignedNum = 4;
	string name;
	bool isBoss;
public:
	int getAssignedNum();
	string getAmuletMessage() const override;
	//constructor, initializes health, strength, defense----------
	wizard(bool bossMode = false);
	//function that returns enemy name---------
	string getName() override;
	enemy* clone() const override;

};

#endif

