#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include <random>
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

	if (health == 0) {
	amtHealed = 0;
}

	//add random number to health, and subtract from # of heals
	health = health + amtHealed;
	heals = heals - amtHealed;
}

/*
name: displayStats
parameters: none
return none
displays the statistics for the enemy, currently only health
*/
void enemy::displayStats() {
	cout << endl << "STATISTICS FOR " << name << endl;
	cout << setw(10) << "Health" << setw(5) << health << endl;
}

/*
name: isAttacked
parameters: none
return void
subtracts number from the health, defense and strength
*/
void enemy::isAttacked(){
	cout << endl << "You have attacked the " << name << ".";

	//decrease health and check if dead before proceeding
	int healthLost;

	//finding random number to subtract health
	default_random_engine engine{ static_cast <unsigned int>(time(0)) };
	uniform_int_distribution<unsigned int> randomInt{ 1, health };
	healthLost = randomInt(engine);
	
	health = health - healthLost;
	if (health ==0){
		cout <<endl <<  "The " << name << " has been killed.";
	}

	//decrease defense stats
	int defenseLost;
	default_random_engine engine{ static_cast <unsigned int>(time(0)) };
	uniform_int_distribution<unsigned int> randomInt{ 1, defense };
	defenseLost = randomInt(engine);
	defense = defense - defenseLost;

	//decrease strength stats
	int strengthLost;
	default_random_engine engine{ static_cast <unsigned int>(time(0)) };
	uniform_int_distribution<unsigned int> randomInt{ 1, strength };
	strengthLost = randomInt(engine);
	strength = strength - strengthLost;
	
}




