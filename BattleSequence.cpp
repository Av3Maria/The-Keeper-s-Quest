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

		if (!Enemy->isAlive()) {
			Enemy->die();
		}
		if (!continueFight) {
			break;
		}
		int enemyResult = enemyAction(*Enemy, plyr);
		if (!enemyResult) {
			cout << "Enemy Chooses to run!" << endl;
			break;
		}
		if (!plyr.isAlive()) {
			plyr.die();
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
		damage = Enemy.damageReduce(damage);
		Enemy.loseHealth(damage);
		cout <<"The " << Enemy.getName() << " only takes " << damage << " damage. There defense is now reduced to "<<Enemy.getDefense()<<"\n\n" << endl;
		break;
	case 2:
		system("cls");
		cout << "Your Chose to Heal, Health Goes Up By 10." << endl;
		plyr.gainHealth(15);
		break;
	case 3:
		system("cls");
		cout << "You Chose to Run!" << endl;
		plyr.flee();
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
	cout << left << setw(14) << "| Strength:" << left << setw(26) << plyr.getStrength() << " | " << endl;
	cout << "|________________________________________|" << endl;
	return 0;
}

int randomNum(unsigned int lowbound, unsigned int ubound) {
	static default_random_engine engine{ static_cast <unsigned int>(time(nullptr)) };
	uniform_int_distribution<unsigned int> randomInt{ lowbound, ubound };
	return randomInt(engine);
}

int enemyAction(enemy& enemy, player& plyr) {
	int takesaction = 2;
	bool action = false;
	int choice = randomNum(1, 100);
	if (!action && enemy.getHealth() < 25 && choice <=10) {//run
		enemy.flee();
		takesaction = 1;
		action = true;
	}
	if (!action && choice <= 40) {//heal, later add function that goes along with items
		
		cout << "The " << enemy.getName() << " heals itself by 10 points." << endl;
		enemy.gainHealth(10);
		takesaction = 3;
		action = true;
	}
	if (!action) {//attack
		int enemyDamage = enemy.getStrength();
		enemyDamage = plyr.damageReduce(enemyDamage);
		plyr.loseHealth(enemyDamage);

		cout << "The " << enemy.getName() << " fights back, you take " << enemyDamage << " damage." << endl;
		takesaction = 2;
		action = true;
	}
	return takesaction;
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