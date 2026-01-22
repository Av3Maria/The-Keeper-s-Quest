#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "archer.h"
using namespace std;

int archer::getAssignedNum() {
	return assignedNum;
}

archer::archer() :enemy(90, 15, 10) {}

string archer::getName() {
	return "Archer";
}

void archer::flee() {
	cout << endl << "The Archer is fleeing, too scared to keep the fight going. You have won this battle" << endl;
}

void archer::die() {
	cout << endl << "The Archer has succumbed to his fate. Congratulations Player, seems you won this battle." << endl;
}