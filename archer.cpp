#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "archer.h"
using namespace std;

int archer::getAssignedNum() {
	return assignedNum;

}

void archer::flee() {
	cout << endl << "The Archer has fled." << endl;

}
