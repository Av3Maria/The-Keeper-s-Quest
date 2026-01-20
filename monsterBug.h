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
	monsterBug();
	string getName() override;
};

#endif