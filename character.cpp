#include "character.h"
#include <iostream>
#include <string>
using namespace std;

//constructor, initialize name, strength, health, and defense for each character------------
character::character(const string& n, int h, int stg, int def)
	:name(n), health(h), strength(stg), defense(def) {
}

vector<attackMoves>& character::getAttacks() {
	return attacks;
}

//function, once character is creasted automatically set to true------------
bool character::isAlive() const {
	return health > 0;
}
//function, return character name------------
string character::getName() {
	return name;
}
//function, return character health------------
int character::getHealth() {
	return health;
}
//function, return character defense------------
int character::getDefense() {
	return defense;
}
//function, return character strength------------
int character::getStrength() {
	return strength;
}
//function, executes reduction of character health, sets lower bound for health------------
void character::loseHealth(int amtHealth) {
	health = health - amtHealth;
	if (health < 0)
		health = 0;
}
//function, executes addition of character health, set upper bound for health------------
void character::gainHealth(int amtHealth) {
	health = health + amtHealth;
	if (health > 100)
		health = 100;
}
//function, executes the reduciton of defense when healing is used------------
void character::defenseHealing(int healAmount) {
	if (healAmount <= 0 || defense <= 0) {
		return;
	}
	int heal = defense / 5;//only reduces by 5
	int defensehealth = min(heal, healAmount);
	defense = defense - defensehealth * 5;
	gainHealth(defensehealth);
}
//function, executes the reduciton of damage and defense when attacking------------ 
int character::damageReduce(int damagedone) {
	if (damagedone <= 0 || defense <= 0) {
		return damagedone;
	}
	int defensereduced = damagedone / 2;//damage reduced by half
	int defensetaken = defensereduced / 3;//defense reduced by third
	defense = defense - defensetaken;
	if (defense < 0) {
		defense = 0;
	}
	return damagedone - defensereduced;
}

void character::randomLine(vector<string>& lines) {
	if (lines.empty()) {
		return;
	}

	int index = randomNum(0, lines.size() - 1);
	cout << endl << lines[index] << endl;
}

attackMoves& character::randattackmove() {
	int index = randomNum(0, attacks.size() - 1);
	return attacks[index];
}

void character::attackDialogue(vector<string>& lines) {
	if (lines.empty()) {
		return;
	}
	int index = randomNum(0, lines.size() - 1);
	cout << endl << lines[index] << endl;
}

void character::runDialogue() {
	randomLine(runLines);
}

void character::healDialogue() {
	randomLine(healLines);
}

void character::dieDialogue() {
	randomLine(dieLines);
}