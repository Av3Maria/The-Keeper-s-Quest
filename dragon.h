#pragma once
#ifndef dragon_h
#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
using namespace std;



class dragon : public enemy {
protected:
	string name;
	int assignedNum = 2;
	bool isBoss;
public:
	int getAssignedNum();
	string getAmuletMessage() const override;
	//constructor, initializes health, strength, defense----------
	dragon(bool bossMode = false);
	//function that returns enemy name---------
	string getName() override;
	enemy* clone() const override;
};

#endif