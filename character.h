#pragma once
#ifndef character_h
#include <iostream>
#include <string>
#include <vector>
#include <random>
//#include "Setup.h"
using namespace std;

struct attackMoves {
	string name;
	int damagedone;
	vector<string> dialogue;
	string effectName = "";
	int effectAmount = 0;
	int effectDuration = 0;
};

struct slowTurnEffect {
	string name;
	int amountinTurn;
	int turnsRemain;
	bool active = true;
};

//function to randomize choices, in this case it is used to chose enemy for battle-------------
inline int randomNum(unsigned int lowbound, unsigned int ubound) {
	static default_random_engine engine{ static_cast <unsigned int>(time(nullptr)) };
	uniform_int_distribution<unsigned int> randomInt{ lowbound, ubound };
	return randomInt(engine);
}

class character {
protected:
	
	string name;
	vector<attackMoves> attacks;
	vector<slowTurnEffect> currentEffect;
public:
//start as 50
	int health;
	int defense;
	int strength;

	//constructor, initialize name, strength, health, and defense for each character------------
	character(const string& n = " ", int h = 50, int stg = 50, int def = 50);
	virtual ~character() = default;
	void slowTurnEffect_Logic(const string& name, int amount, int turns);
	void slowTurnEffect_Use();

	vector<attackMoves>& getAttacks();
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

	attackMoves& randattackmove();
	vector<string> attackLines;
	vector<string> healLines;
	vector<string> runLines;
	vector<string> dieLines;
	void randomLine(vector<string>& lines);
	virtual void attackDialogue(vector<string>& lines);
	virtual void runDialogue();
	virtual void healDialogue();
	virtual void dieDialogue();
};

#endif