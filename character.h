#pragma once
#ifndef character_h
#include <iostream>
#include <string>
using namespace std;


class character {
protected:
	//start as 50
	int health;
	int defense;
	int strength;
	string name;
public:

	character(const string& n = " ", int h = 50, int stg = 25, int def = 25);
	virtual ~character() = default;

	bool isAlive() const;

	virtual string getName();

	int getHealth();

	int getDefense();

	int getStrength();

	virtual void loseHealth(int amtHealth);

	virtual void gainHealth(int amtHealth);
};







#endif