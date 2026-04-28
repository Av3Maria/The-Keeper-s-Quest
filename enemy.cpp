#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include <random>
using namespace std;

int enemy::getAssignedNum() {
	return assignedNum;
}
//function, constructor for enemy name, health, strength, and defense----------
enemy::enemy(int h, int stg, int def)
	: character("Enemy", h, stg, def) {
}
//function, returns enemy name---------
string enemy::getName() {
	return name;
}
