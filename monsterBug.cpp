#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "monsterBug.h"
using namespace std;

int monsterBug::getAssignedNum() {
	return assignedNum;
}

monsterBug::monsterBug() :enemy(50, 25, 10) {}

string monsterBug::getName() {
	return "Monster Bug";
}