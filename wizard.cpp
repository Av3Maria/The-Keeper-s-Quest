#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "wizard.h"
using namespace std;

int wizard::getAssignedNum() {
	return assignedNum;
}

wizard::wizard() :enemy(50, 25, 10) {}

string wizard::getName() {
	return "Wizard";
}