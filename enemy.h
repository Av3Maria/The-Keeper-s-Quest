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

};




#endif