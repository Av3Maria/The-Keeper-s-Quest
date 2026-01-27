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
public:
	int getAssignedNum();
	//constructor, initializes health, strength, defense----------
	dragon();
	//function that returns enemy name---------
	string getName() override;
	//function when enemy runs in battle, output specific line--------
	void flee() override;
	//function when enemy dies in battle, output specific line--------
	void die() override;
};

#endif