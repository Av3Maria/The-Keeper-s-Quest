#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "archer.h"
using namespace std;

int archer::getAssignedNum() {
	return assignedNum;
}
//constructor, initializes health, strength, defense----------
archer::archer() :enemy(90, 15, 10) {}
//function that returns enemy name---------
string archer::getName() {
	return "Archer";
}
//function when enemy runs in battle, output specific line--------
void archer::flee() {
	cout << endl << "The Archer is fleeing, too scared to keep the fight going. You have won this battle" << endl;
}
//function when enemy dies in battle, output specific line--------
void archer::die() {
	cout << endl << "The Archer has succumbed to his fate. Congratulations Player, seems you won this battle." << endl;
}