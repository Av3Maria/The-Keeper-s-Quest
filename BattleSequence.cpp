#include <iostream>
#include <iomanip>
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

//Battle Sequence: When player enters battle, they are unaware of who they are fighting until they enter the sequence. Each side gets stats of health, defense, and stanima. 
// (All starting at 50). There are four options of enemies to be picked, which will be random. 

int enterBattle();
int print_battlemenu();
bool battle_choices(int user_choice, player& plyr, enemy& Enemy);
int print_stats( player& p, enemy& e);
enemy* choose_enemy();
int enemyAction(enemy& enemy, player& plyr);


int main() {
	enterBattle();
}

int enterBattle() {

	player plyr;
	enemy* Enemy = choose_enemy();

	cout << left << setw(50) << " " << "You encountered an Enemy!" << endl;

	while (plyr.isAlive() && Enemy->isAlive()) {
		print_stats(plyr, *Enemy);
		int  choice = print_battlemenu();

		bool continueFight = battle_choices(choice, plyr, *Enemy);
		if (!continueFight) {
			cout << "The fight has ended.\n";
			break;
		}

		int enemyResult = enemyAction(*Enemy, plyr);

		if (enemyResult == 1) {
			cout << "Seems You Win This Battle!" << endl;
			break;
		}
		if (!plyr.isAlive()) {
			cout << "You Have Been Defeated, Maybe You Will Get Them Next Time." << endl;
			break;
		}
	}

	delete Enemy;
	return 0;
}

int print_battlemenu() { //function to print menu for battle sequence

	cout << "\n\n\n What would you like to do?" << endl;
	cout << " \n\n 1. Attack" << endl;
	cout << " 2. Heal" << endl;
	cout << " 3. Run\n\n" << endl;

	int choice;
	cin >> choice;

	return choice;
}

bool battle_choices(int user_choice, player& plyr, enemy& Enemy) {
	int damage; 
	switch (user_choice) {

	case 1:
		system("cls");
		cout << "You Chose to Attack the Enemy!\n\n" << endl;
		damage = plyr.getStrength();
		Enemy.loseHealth(damage);
		cout << "You hit the enemy!!" << "The " << Enemy.getName() << " takes " << damage << " damage.\n\n" << endl;
		break;
	case 2:
		system("cls");
		cout << "Your Chose to Heal, Health Goes Up By 10." << endl;
		plyr.gainHealth(10);
		break;
	case 3:
		system("cls");
		cout << "You Chose to Run!" << endl;
		return false;
		break;
	}
	return plyr.isAlive() && Enemy.isAlive();
}


int print_stats (player& plyr, enemy& enmy) {
	cout << " ----------------------------------------" << endl;
	cout << "|                                        |" << endl;
	cout << left << setw(10) << "| Enemy:" << left << setw(12) << enmy.getName() << "HP: " << left << setw(14) << enmy.getHealth() << " | " << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << left << setw(14) << "| Player HP:" << left << setw(26) << plyr.getHealth() << " | " << endl;
	cout << "|                                        |" << endl;
	cout << left << setw(14) << "| Defense:" << left << setw(26) << plyr.getDefense() << " | " << endl;
	cout << "|                                        |" << endl;
	cout << left << setw(14) << "| Stamina:" << left << setw(26) << plyr.getStrength() << " | " << endl;
	cout << "|________________________________________|" << endl;
	return 0;
}


int randomNum(unsigned int lowbound, unsigned int ubound) {

	static default_random_engine engine{ static_cast <unsigned int>(time(nullptr)) };
	uniform_int_distribution<unsigned int> randomInt{ lowbound, ubound };
	return randomInt(engine);
}


int enemyAction(enemy& enemy, player& plyr) {
	int choice = randomNum(1, 100);

	if (choice <= 10) {//run
		cout << "The " << enemy.getName() << " runs away from you, too scared to fight." << endl;
		return 1;
	}
	else if (choice <= 40) {//heal
		
		cout << "The " << enemy.getName() << " heals itslef by 10 points." << endl;
		enemy.gainHealth(10);
		return 3;
	}
	else {//attack
		int enemyDamage = enemy.getStrength();
		plyr.loseHealth(enemyDamage);

		cout << "The " << enemy.getName() << " fights back, you take " << enemyDamage << " damage!!!" << endl;
		return 2;
	}
	return 0;
}


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