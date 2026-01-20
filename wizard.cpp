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
	~wizard();
}

wizard::~wizard(){
	cout << endl << "I will have my revenge next time.............";
}
