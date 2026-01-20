#pragma once
#ifndef enemy_h
#include <iostream>
#include <string>
#include "character.h"
using namespace std;

class enemy : public character {
protected:
	int assignedNum;
	string name;

public:
	virtual int getAssignedNum();
	enemy(int health, int strength, int defense);
	virtual ~enemy() = default;
	virtual string getName();
	//virtual  void heal(int heal);


};




#endif