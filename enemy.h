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
name: heal
parameter: none
return void
heals the enemy a random amt btw 1 health and 3/4 of the heals remaining
*/
	virtual  void heal();

};





#endif
