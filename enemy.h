#pragma once
#ifndef enemy_h
#include <iostream>
#include <string>
#include "character.h"
using namespace std;

class enemy : public character {
protected :
	int assignedNum;
public:
	virtual int getAssignedNum();

	/*
name: displayStats
parameters: none
return none
displays the statistics for the enemy, currently only health
*/
void displayStats();

};





#endif
