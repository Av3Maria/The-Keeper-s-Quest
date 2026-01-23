#include "character.h"
#include <iostream>
#include <string>
using namespace std;

character::character(const string& n, int h, int stg, int def)
	:name(n), health(h), strength(stg), defense(def){ }

bool character::isAlive() const {
	return health > 0;
}

string character::getName() {
	return name;
}

int character::getHealth() {
	return health;
}

int character::getDefense() {
	return defense;
}

int character::getStrength() {
	return strength;
}

void character::loseHealth(int amtHealth) {
	health = health - amtHealth;
	if (health < 0)
		health = 0;
}

void character::gainHealth(int amtHealth) {
	health = health + amtHealth;
	if (health > 100)
		health = 100;
}

void character::defenseHealing(int healAmount) {
	if (healAmount <= 0 || defense <= 0) {
		return;
	}
	int heal = defense / 5;
	int defensehealth = min(heal, healAmount);
	defense = defense - defensehealth * 5;
	gainHealth(defensehealth);
}

int character::damageReduce(int damagedone) {
	if (damagedone <= 0 || defense <= 0) {
		return damagedone;
	}
	int defensereduced = damagedone / 2;
	int defensetaken = defensereduced / 3;
	defense = defense - defensetaken;
	if (defense < 0) {
		defense = 0;
	}
	return damagedone - defensereduced;
}

void character::flee() {

}

void character::die() {

}