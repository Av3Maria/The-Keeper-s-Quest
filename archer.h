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

public:

/*
destructor
*/
	~archer();

/*
name: flee
parameters: none
return void
calls the destructor and says the archer has fled
*/
	void flee();

/*
name: isAttacked
parameters: none
return void
subtracts number from the health, defense and strength
*/
	void isAttacked();

};










#endif

