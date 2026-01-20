#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "wizard.h"
using namespace std;

int wizard::getAssignedNum() {
	return assignedNum;

}

void wizard::flee(){
	cout << endl << "WIZARD is in retreat.";
	cout << endl << "WIZARD shouts: I will have my revenge next time . . . . . . . ";
	~wizard();
}

void die(){
	cout << endl << "The WIZARD has died.";
	~wizard();
}

wizard::~wizard(){
	
}

	




