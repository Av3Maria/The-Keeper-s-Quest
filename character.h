#pragma once
#ifndef character_h
#include <iostream>
#include <string>
using namespace std;


class character {
protected:
	//start as 50
	int health =50 ;
	int defense =50;
	int strength = 50;
	int heals = 50;

	string name;

public:

	string getName();

	int getHealth();

	int getDefense();

	int getStrength();

	int getHeals();

	virtual void loseHealth(int amtHealth);

	virtual void gainHealth(int amtHealth);
};








#endif
