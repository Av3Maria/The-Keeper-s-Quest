#include <iostream>
#include <string>
#include "character.h"
using namespace std;

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
}

void character::gainHealth(int amtHealth) {
	health = health + amtHealth;
}