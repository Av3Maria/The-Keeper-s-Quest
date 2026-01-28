#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "monsterBug.h"
using namespace std;

int monsterBug::getAssignedNum() {
	return assignedNum;
}
//constructor, initializes health, strength, defense----------
monsterBug::monsterBug() :enemy(65, 12, 10) {}
//function that returns enemy name---------
string monsterBug::getName() {
	return "Monster Bug";
}
//function when enemy runs in battle, output specific line--------
void monsterBug::flee() {
	cout << endl << "The bug scuttles away.You hear nothing from its motion and wonder how" <<
		" you shall detect its return." << endl;
}
//function when enemy dies in battle, output specific line--------
void monsterBug::die() {
	cout << endl << "The bug, as weak as it was, fought til its last breath. Although "<<
		"surprising, you still take this win. Congratulations." << endl;
}