#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include <random>
using namespace std;

int enemy::getAssignedNum() {
	return assignedNum;

}

enemy::enemy(int h, int stg, int def)
	: character("Enemy", h, stg, def){ }

string enemy::getName() {
	return name;
}

