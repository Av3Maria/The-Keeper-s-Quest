#include <iostream>
#include <string>
#include "character.h"
#include "player.h"
using namespace std;

player::player(int h, int stg, int def)
	:character("Player", 100, 20, 25){ }

string player::getName() {
	return "player";
}

void player::die() {
	cout <<endl<< "Oh no, it appears that you have been taken out. I suppose that was slightly disaappointing..."<<
		"I thought you were better than this." << endl;
}

void player::flee() {
	cout <<endl<< "Low on items? Scared to die? No matter the reason, you choose to flee the fight, "
		"leaving the enemy far behind as you run" << endl;
}