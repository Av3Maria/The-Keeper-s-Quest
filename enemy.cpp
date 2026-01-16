#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
using namespace std;

int enemy::getAssignedNum() {
	return assignedNum;

}

/*
name: heal
parameter: none
return void
heals the enemy a random amt btw 1 health and 3/4 of the heals remaining
*/
void enemy::heal() {
	int amtHealed;
	//converts type so the program is happy
	unsigned int newHeals = heals;

	//find a random number
	default_random_engine engine{ static_cast <unsigned int>(time(0)) };
	uniform_int_distribution<unsigned int> randomInt{ 1, newHeals };
	amtHealed = randomInt(engine);

	if (amtHealed == 0) {
		amtHealed = 1;
	}

	//add random number to health, and subtract from # of heals
	health = health + amtHealed;
	heals = heals - amtHealed;
}
