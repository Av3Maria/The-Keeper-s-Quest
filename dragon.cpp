#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "dragon.h"
using namespace std;

int dragon::getAssignedNum() {
	return assignedNum;
}
//constructor, initializes health, strength, defense----------
dragon::dragon():enemy(120,25,10){}
//function that returns enemy name---------
string dragon::getName() {
	return "Dragon";
}
//function when enemy runs in battle, output specific line--------
void dragon::flee() {
	cout << endl << "This is not over yet. I WILL RETURN TO RAIN FIRE UPON YOU." << endl;
}
//function when enemy dies in battle, output specific line--------
void dragon::die() {
	cout << endl << "The Dragon has been defeated. Congratulations on your win!" << endl;
}