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
	~monsterBug();
}

monsterBug::~monsterBug(){
	cout << endl <<  "The bug scuttles away. You hear nothing from its motion and wonder how to detect its return." ;
}
