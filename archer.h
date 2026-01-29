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
	//constructor, initializes health, strength, defense----------
	archer();
	//function that returns enemy name---------
	string getName() override;
	//function when enemy runs in battle, output specific line--------
	void flee() override;
	//function when enemy dies in battle, output specific line--------
	void die() override;

	/*string attackDialogue() override;
	string runDialogue() override;
	string healDialogue() override;*/
};




#endif