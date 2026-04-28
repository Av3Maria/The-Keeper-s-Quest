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
	virtual string getAmuletMessage() const { return ""; };
	virtual int getAssignedNum();
	//function, allows classes that are of enemy class to set the strength, health, and defense---------
	enemy(int health, int strength, int defense);
	//delete the enemy object when called to--------
	virtual ~enemy() = default;
	//function to call name of enemy---------
	virtual string getName();
	virtual enemy* clone() const = 0;
};

#endif