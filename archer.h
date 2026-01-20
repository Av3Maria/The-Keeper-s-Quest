#pragma once
#ifndef archer_h
#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
using namespace std;

class archer : public enemy {
protected:
	string name = "Archer";
	int assignedNum = 1;
public:
	int getAssignedNum();

	~archer();

	void flee();

	void attack();

};










#endif
