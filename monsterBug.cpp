#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "monsterBug.h"
using namespace std;

int monsterBug::getAssignedNum() {
	return assignedNum;
}

monsterBug::monsterBug() :enemy(65, 12, 10) {}

string monsterBug::getName() {
	return "Monster Bug";
}

void monsterBug::flee() {
	cout << endl << "The bug scuttles away.You hear nothing from its motion and wonder how" <<
		" you shall detect its return." << endl;
}

void monsterBug::die() {
	cout << endl << "The bug, as weak as it was, fought til its last breath. Although "<<
		"surprising, you still take this win. Congratulations." << endl;
}