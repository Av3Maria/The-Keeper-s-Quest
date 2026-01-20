#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "monsterBug.h"
using namespace std;

int monsterBug::getAssignedNum() {
	return assignedNum;

}

void monsterBug::flee(){
	cout << endl << "The bug scuttles away. You hear nothing from its motion and wonder how you shall detect its return.";
	~monsterBug();
}

monsterBug::~monsterBug(){
	
}

void monsterBug::die(){
	~monsterBug();
}

