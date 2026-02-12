#include <iostream>
#include <iomanip>
#include "BattleSequence.h"
#include "dragon.h"
#include "archer.h"
#include "character.h"
#include "enemy.h"
#include "monsterBug.h"
#include "player.h"
#include "wizard.h"
#include <random>
#include <vector>
using namespace std;

<<<<<<< HEAD

=======
>>>>>>> 0cebf16040bd6a3f1e3a92b49ea6cade5d131d4f
//This plays out the entire Battle Sequence and uses the functions above-------------
int enterBattle() {
	//create instance of player and enemy, where enemy is chosen at random
	player plyr;
	enemy* Enemy = choose_enemy();

	cout << endl << left << setw(50) << " " << "You encountered an Enemy!" << endl;
	//while loop that runs the game as long as both the enemy and the player are alive
	while (plyr.isAlive() && Enemy->isAlive()) {
		print_stats(plyr, *Enemy);//visual for the player to see the stats of them and the enemy
		int  choice = print_battlemenu(plyr);//print choices for the player to pick from, return choice
		bool continueFight = battle_choices(choice, plyr, *Enemy);//choice is taken into account for player

		if (!Enemy->isAlive()) {//if enemy dies end loop
			Enemy->dieDialogue();
		}
		if (!continueFight) {//if player runs, end loop
			break;
		}
		int enemyResult = enemyAction(*Enemy, plyr);// enemy chocie is chosen through probability
		if (!enemyResult) {//if enemy runs end loop
			cout << endl << "Enemy chooses to run!" << endl;
			break;
		}
		if (!plyr.isAlive()) {//if player dies end loop
			plyr.dieDialogue();
			break;
		}
	}
	delete Enemy;//delete enemy after battle ends
	return 0;
}

//function to randomize choices, in this case it is used to chose enemy for battle-------------
int randomNum(unsigned int lowbound, unsigned int ubound) {
	static default_random_engine engine{ static_cast <unsigned int>(time(nullptr)) };
	uniform_int_distribution<unsigned int> randomInt{ lowbound, ubound };
	return randomInt(engine);
}

//function that uses the random function to choose an enemy for battle-------------
enemy* choose_enemy() {
	int choose = randomNum(0, 3);
	switch (choose) {
	case 0:
		return new dragon();
		break;
	case 1:
		return new monsterBug();
		break;
	case 2:
		return new wizard();
		break;
	case 3:
		return new archer();
		break;
	}
	return nullptr;
}

//function to print menu for player choices-------------
int print_battlemenu() {
	cout << "\n\n\n What would you like to do?" << endl;
	cout << " \n\n 1. Attack" << endl;
	cout << " 2. Heal" << endl;
	cout << " 3. Run\n\n" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		cout << endl << "Choose which attack you would like to do: " << endl;
		for (int i = 0; i < plyr.attackMoves.size(); ++i) {
			cout << i + 1 << ". " < , plyr.attackMoves[i].name << endl;
		}
		int attackchoice;
		cin >> attackchoice;
		return 100 + (attackchoice - 1);
	}
	return choice;
}

//function to print out the stats of both the enemy and the player-------------
int print_stats(player& plyr, enemy& enmy) {
	cout << " ----------------------------------------" << endl;
	cout << "|                                        |" << endl;
	cout << left << setw(10) << "| Enemy:" << left << setw(12) << enmy.getName() << "HP: " << left << setw(14) << enmy.getHealth() << " | " << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << left << setw(14) << "| Player HP:" << left << setw(26) << plyr.getHealth() << " | " << endl;
	cout << "|                                        |" << endl;
	cout << left << setw(14) << "| Defense:" << left << setw(26) << plyr.getDefense() << " | " << endl;
	cout << "|                                        |" << endl;
	cout << left << setw(14) << "| Strength:" << left << setw(26) << plyr.getStrength() << " | " << endl;
	cout << "|________________________________________|" << endl;
	return 0;
}

//function to take the player choice and run through it / execute it-------------
bool battle_choices(int user_choice, player& plyr, enemy& Enemy) {
	int damage; 
	switch (user_choice) {
	case 1://player chooses to attack
		if (user_choice >= 100){
		system("cls");
		AttackMoves& chosenAttack = plyr.attackMoves[attackIndex];
		int dialogueIndex = randomNum(0, chosenAttack.dialogue.size() - 1);
		cout << endl << "You chose" << chosenAttack.name << " to attack the enemy with" << endl;
		damage = plyr.getStrength();//the damage the player does is reduced by half, and the enemy defense is then reduced by a third (ensures battle is not short)
		damage = Enemy.damageReduce(damage);
		Enemy.loseHealth(damage);
		cout << endl << "The " << Enemy.getName() << " only takes " << damage << " damage. There defense is now reduced to "<<Enemy.getDefense()<<"\n\n" << endl;
		]
		break;
	case 2://player chooses to heal
		system("cls");
		plyr.healDialogue();
		cout << "Your Chose to Heal, Health Goes Up By 10." << endl;
		plyr.gainHealth(15);//when healing, defense is reduced by 5 points
		break;
	case 3://player chooses to run
		system("cls");
		cout << "You Chose to Run!" << endl;
		plyr.runDialogue();
		return false;
		break;
	}
	return plyr.isAlive() && Enemy.isAlive();
}

//function for enemy actions-------------
int enemyAction(enemy& enemy, player& plyr) {
	int takesaction = 2;//automatically gets set to attack
	bool action = false;//makes sure that only one action is executed
	int choice = randomNum(1, 100);//run probability for each action
	if (!action && enemy.getHealth() < 25 && choice <=10) {//10% chance to run, only becomes an option once the enemy health is lower than 25
		enemy.runDialogue();
		takesaction = 1;
		action = true;
	}
	if (!action && choice <= 40) {//40% chance to heal
		enemy.healDialogue();
		cout << endl << cout << "The " << enemy.getName() << " heals itself by 10 points." << endl;
		enemy.gainHealth(10);//health goes up by ten, subject to change
		takesaction = 3;
		action = true;
	}
	if (!action) {//50% chance to attack
		attackMoves& movefrmenemy = enemy.randattackmove();
		enemy.attackDialogue(movefrmenemy.dialogue);
		//int enemyDamage = enemy.getStrength();//works same as player, defense is reduced by a third and damage done to player is reduced to half
		int enemyDamage = enemy.getStrength() + movefrmenemy.damagedone;
		enemyDamage = plyr.damageReduce(enemyDamage);
		plyr.loseHealth(enemyDamage);
		enemy.attackDialogue();
		cout << endl << "You take " << enemyDamage << " damage." << endl;
		takesaction = 2;
		action = true;
	}
	return takesaction;
}
