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
	cout << endl << "ARCHER is fleeing. PLAYER has won this battle." << endl;
	~archer();
}

archer::~archer(){
	

}


