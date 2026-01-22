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

	character(const string& n = " ", int h = 100, int stg = 20, int def = 25);
	virtual ~character() = default;

	bool isAlive() const;

	virtual string getName();

	int getHealth();

	int getDefense();

	int getStrength();

	virtual void loseHealth(int amtHealth);

	virtual void gainHealth(int amtHealth);

	virtual void defenseHealing(int healAmount);

	virtual int damageReduce(int damagedone);

	virtual void flee();

	virtual void die();
};







#endif