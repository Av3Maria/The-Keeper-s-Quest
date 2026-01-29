#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "archer.h"
using namespace std;

int archer::getAssignedNum() {
	return assignedNum;
}
//constructor, initializes health, strength, defense----------
archer::archer() :enemy(90, 15, 10) {}
//function that returns enemy name---------
string archer::getName() {
	return "Archer";
}
//function when enemy runs in battle, output specific line--------
void archer::flee() {
}
//function when enemy dies in battle, output specific line--------
void archer::die() {
	cout << endl << "The Archer has succumbed to his fate. Congratulations Player, seems you won this battle" << endl;
}

/*string attackDialogue() {
	cout << endl << "As an arrow flies straight for you, the Archer says 'This one is just for you'" << endl;
	cout << endl << "The Archer seems upset as he shoots arrow after arrow, and all of them come barreling towards you. Some miss but quite a few hit their intended target" << endl;
	cout << endl << "The Archer lifts up his bow, shooting an arrow right at where you are standing. For anyone else, they would move out of the way in time, but for some reason you react too slow and are hit. How disapointing" << endl;
	cout << endl << "As weak as the Archer may be, you still are hit by one of his stray arrows. Boosting his already inflated ego" << endl;
	return 0;
}

string runDialogue() {
	cout << endl << "The Archer is fleeing, too scared to keep the fight going. You have won this battle" << endl;
	cout << endl << "The Archer slowly backs away, looking at you with fear in his eyes. He screams 'I am leaving you alive this once' as he turns and runs away, but you know with one more hit he owuld have been gone" << endl;
	cout << endl << "" << endl;
	cout << endl << "" << endl;
	return 0;
}

string healDialogue() {
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	return 0;*/
//}