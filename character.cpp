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
	if (health > 50)
		health = 50;
}
