#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "wizard.h"
using namespace std;

int wizard::getAssignedNum() {
	return assignedNum;
}
//constructor, initializes health, strength, defense----------
wizard::wizard() :enemy(100, 18, 10) {}
//function that returns enemy name---------
string wizard::getName() {
	return "Wizard";
}
//function when enemy runs in battle, output specific line--------
void wizard::flee() {
	cout << endl << "The Wizard is in retreat, screaming something about revenge as he leaves." << endl;
}
//function when enemy dies in battle, output specific line-------
void wizard::die() {
	cout << endl << "As you throw your last hit, the Wizard, having no time to defend, takes the blow at full. He perishes, fading into a black mist." << endl;
}