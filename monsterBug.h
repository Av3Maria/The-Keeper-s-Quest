#pragma once
#ifndef monsterBug_h
#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
using namespace std;

class monsterBug : public enemy {
protected:
	string name = "Monster Bug";
	int assignedNum = 3;
public:
	int getAssignedNum();

};

void flee();

/*
name: isAttacked
parameters: none
return void
subtracts number from the health, defense and strength
*/
void isAttacked();

~monsterBug();


#endif

