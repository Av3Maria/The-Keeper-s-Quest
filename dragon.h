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

	~dragon();
};


#endif


