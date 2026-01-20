#pragma once
#ifndef wizard_h
#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
using namespace std;

class wizard : public enemy {
protected:
	string name = "Wizard";
	int assignedNum = 4;
public:
	int getAssignedNum();

 	void flee();

/*
name: isAttacked
parameters: none
return void
subtracts number from the health, defense and strength
*/
	void isAttacked();

	~wizard();
};


#endif

