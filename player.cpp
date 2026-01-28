#include <iostream>
#include <string>
#include "character.h"
#include "player.h"
using namespace std;
//initializes players health, strength, and defense---------
player::player() :character("Player", 100, 18, 10) {}
//funciton to get players name----------
string player::getName() {
	return "player";
}
//function for when player dies, specific lines output---------
void player::die() {
	cout <<endl<< "Oh no, it appears that you have been taken out. I suppose that was slightly disaappointing..."<<
		"I thought you were better than this." << endl;
}
//function for when player flees, specific lines output-------------
void player::flee() {
	cout <<endl<< "Low on items? Scared to die? No matter the reason, you choose to flee the fight, "
		"leaving the enemy far behind as you run" << endl;
}