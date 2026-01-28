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
public:
	int getAssignedNum();
	//constructor, initializes health, strength, defense----------
	monsterBug();
	//function that returns enemy name---------
	string getName() override;
	//function when enemy runs in battle, output specific line--------
	void flee() override;
	//function when enemy dies in battle, output specific line--------
	void die() override;
};

#endif