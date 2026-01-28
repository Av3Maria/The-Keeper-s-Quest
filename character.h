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
	//constructor, initialize name, strength, health, and defense for each character------------
	character(const string& n = " ", int h = 50, int stg = 50, int def = 50);
	virtual ~character() = default;
	//function, once character is creasted automatically set to true------------
	bool isAlive() const;
	//function, return character name------------
	virtual string getName();
	//function, return character health------------
	int getHealth();
	//function, return character defense------------
	int getDefense();
	//function, return character strength------------
	int getStrength();
	//function, executes reduction of character health, sets lower bound for health------------
	virtual void loseHealth(int amtHealth);
	//function, executes addition of character health, set upper bound for health------------
	virtual void gainHealth(int amtHealth);
	//function, executes the reduciton of defense when healing is used------------
	virtual void defenseHealing(int healAmount);
	//function, executes the reduciton of damage and defense when attacking------------
	virtual int damageReduce(int damagedone);
	//function for character to flee------------
	virtual void flee();
	//function for character to run------------
	virtual void die();
};







#endif