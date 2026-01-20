#pragma once
#ifndef wizard_h
#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
using namespace std;

class wizard : public enemy {
protected:
	int assignedNum = 4;
public:
	int getAssignedNum();
	wizard();
	string getName() override;
};

#endif
