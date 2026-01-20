#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "dragon.h"
using namespace std;

int dragon::getAssignedNum() {
	return assignedNum;

}

void dragon::flee(){
	cout << endl << "This is not over yet. I WILL RETURN TO RAIN FIRE UPON YOU.";
	~dragon();
}

dragon::~dragon(){
	
}

void dragon::die(){
	cout << endl << "The DRAGON has died. Congragulations on its death!";
}

