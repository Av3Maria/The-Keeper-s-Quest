#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "dragon.h"
using namespace std;

int dragon::getAssignedNum() {
	return assignedNum;
}

dragon::dragon():enemy(120,25,10){}

string dragon::getName() {
	return "Dragon";
}

void dragon::flee() {
	cout << endl << "This is not over yet. I WILL RETURN TO RAIN FIRE UPON YOU." << endl;
}

void dragon::die() {
	cout << endl << "The Dragon has been defeated. Congratulations on your win!" << endl;
}