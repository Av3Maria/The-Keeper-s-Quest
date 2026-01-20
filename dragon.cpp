#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "dragon.h"
using namespace std;

int dragon::getAssignedNum() {
	return assignedNum;
}

dragon::dragon():enemy(50,25,10){}

string dragon::getName() {
	return "Dragon";
}