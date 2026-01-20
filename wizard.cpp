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

/*
name: isAttacked
parameters: none
return void
subtracts number from the health, defense and strength
*/
void wizard::isAttacked(){
	cout << endl << "You have attacked the " << name << ".";
	int healthLost;
	
	default_random_engine engine{ static_cast <unsigned int>(time(0)) };
	uniform_int_distribution<unsigned int> randomInt{ 1, health };
	 healthLost = randomInt(engine);

	health = health - healthLost;

	if (health ==0){
		cout <<endl <<  "The " << name << " has been killed.";
		
	}
}
		


