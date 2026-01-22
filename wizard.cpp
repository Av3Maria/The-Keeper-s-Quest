#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "wizard.h"
using namespace std;

int wizard::getAssignedNum() {
	return assignedNum;
}

wizard::wizard() :enemy(100, 18, 10) {}

string wizard::getName() {
	return "Wizard";
}

void wizard::flee() {
	cout << endl << "The Wizard is in retreat, screaming something about revenge as he leaves." << endl;
}

void wizard::die() {
	cout << endl << "As you throw your last hit, the Wizard, having no time to defend, takes the blow at full. He perishes, fading into a black mist." << endl;
}