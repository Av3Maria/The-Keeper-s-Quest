#pragma once
#ifndef archer_h
#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
using namespace std;

class archer : public enemy {
protected:
	string name;
	int assignedNum = 1;
public:
	int getAssignedNum();
	archer();
	string getName() override;
	void flee() override;
	void die() override;
};




#endif