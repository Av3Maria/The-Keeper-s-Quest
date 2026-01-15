// BattleSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "dragon.h"
#include "archer.h"
#include "character.h"
#include "enemy.h"
#include "monsterBug.h"
#include "player.h"
#include "wizard.h";
#include <random>
using namespace std;

/*
name: randomNum
parameters: unsigned int lowbound, unsigned int ubound
return int
finds a random number between 1 and the given upper bound
*/
int randomNum(unsigned int lowbound, unsigned int ubound) {
    default_random_engine engine{ static_cast <unsigned int>(time(0)) };
    uniform_int_distribution<unsigned int> randomInt{ lowbound, ubound };
    return randomInt(engine);
}

void enterBattle() {
    int randomNumber = randomNum(1, 4);
    switch (randomNumber) {
    case 1:
        return;

    case 2:

        return;

    case 3:

        return;
    }

}


int main()
{
	monsterBug BUG;
	cout << BUG.getAssignedNum();
}

