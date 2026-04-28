#pragma once
#ifndef monsterBug_h
#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
using namespace std;

class monsterBug : public enemy {
protected:
	int assignedNum = 3;
	string name;
	bool isBoss;
public:
	int getAssignedNum();
	string getAmuletMessage() const override;
	//constructor, initializes health, strength, defense----------
	monsterBug(bool bossMode = false);
	//function that returns enemy name---------
	string getName() override;
	enemy* clone() const override;

};

#endif