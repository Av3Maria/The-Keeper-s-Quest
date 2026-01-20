#pragma once
#ifndef dragon_h
#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
using namespace std;

class dragon : public enemy {
protected:
	string name = "dragon";
	int assignedNum = 2;
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

	~dragon();
};


#endif

