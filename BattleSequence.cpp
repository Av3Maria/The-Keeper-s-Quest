#include "Setup.h"
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
#include "Inventory.h"
using namespace std;

//Check Player health before battle-----------------------------------------------------------------
bool HealthCheck(player& plyr) {
	int healthcurr = plyr.getHealth();

	cout << "\nBefore entering battle it is best to see how you feel. This is your current health status: " << healthcurr << endl;
	if (healthcurr <= 50) {
		cout << "Since your health is low right now I suggest taking a minute to heal up just in case there is a really tough enemy up ahead." << endl;
		cout << endl;
	}
	else if (healthcurr < 100) {
		cout << "You have enough health to sway the battle. Although you are not at your best strength." << endl;
		cout << endl;
	}
	else {
		cout << "Your strength will be of no issue, but I cannot say the same for your decisions during battle." << endl;
		cout << endl;
	}
	cout << "Do you still wish to proceede with the way you are? You are allowed to avoid this battle. (Enter: 1 = Yes, 2 = No)" << endl;
	int choice;
	cin >> choice;
	return (choice == 1);
}

//This plays out the entire Battle Sequence and uses the functions above-------------
int enterBattle(Setup& setup, enemy* customEnemy) {
	//create instance of player and enemy, where enemy is chosen at random
	player& plyr = setup.mainPlayer;

	plyr.syncWeapons(plyr, setup);

	// Ensure player has a weapon equipped after syncing
	if (plyr.inventoryW.empty()) {
		cout << "Warning: player has no weapons!" << endl;
	}
	else if (plyr.equippedIndex >= plyr.inventoryW.size()) {
		plyr.equippedIndex = 0;
	}

	// Reset all potion cooldowns
	for (HealOption& heal : plyr.getHealingOptions()) {
		heal.turnRemaining = 0;
	}

	if (!HealthCheck(plyr)) {
		cout << "You decide to run from this fight." << endl;
		return 0;
	}
	system("cls");

	enemy* Enemy = choose_enemy();

	cout << endl << left << setw(50) << " " << "You encountered an Enemy!" << endl;
	//while loop that runs the game as long as both the enemy and the player are alive
	while (plyr.isAlive() && Enemy->isAlive()) {
		print_stats(plyr, *Enemy);//visual for the player to see the stats of them and the enemy
		int  choice = print_battlemenu(plyr);//print choices for the player to pick from, return choice
		
		BattleResults result = battle_choices(setup, choice, plyr, *Enemy);

		if (!Enemy->isAlive()) {//if enemy dies end loop
			Enemy->dieDialogue();
			break;
		}
		if (result == EndBattle) {
			break;
		}
		if (result == IgnoreAction) {
			continue;
		}
		int enemyResult = enemyAction(*Enemy, plyr);// enemy chocie is chosen through probability
		plyr.updateHealingCooldown();
		plyr.slowTurnEffect_Use();
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
int print_battlemenu(player& plyr) {
	cout << "\n\n\n What would you like to do?" << endl;
	cout << " \n\n 1. Attack" << endl;
	cout << " 2. Heal" << endl;
	cout << " 3. Run" << endl;
	cout << " 4. Inventory\n\n" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		cout << endl << "Choose which attack you would like to do: " << endl;
		vector<attackMoves>& attacks = plyr.getcurrentAttacks();
		for (int i = 0; i < attacks.size(); ++i) {
			cout << i + 1 << ". " << attacks[i].name << endl;
		}
		int attackchoice;
		cin >> attackchoice;
		return 100 + (attackchoice - 1);
	}
	if (choice == 2) {
		cout << endl << "Choose a healing option you would like to do: " << endl;
		vector<HealOption>& healing = plyr.getHealingOptions();
		vector<int> validIndices;
		for (int i = 0; i < healing.size(); i++) {
			int itemID = healing[i].itemID;

			if (plyr.inventory[itemID] <= 0) continue;

			validIndices.push_back(i);

			cout << validIndices.size() << ". " << healing[i].name;
			cout << " (x" << plyr.inventory[itemID] << ")";

			if (healing[i].turnRemaining > 0)
				cout << " - Cooldown: " << healing[i].turnRemaining;

			cout << endl;
		}
		int healthChoice;
		cin >> healthChoice;
		if (healthChoice > 0 && healthChoice <= validIndices.size()) {
			return 200 + validIndices[healthChoice - 1];
		}
		else {
			return -1;
		}
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
BattleResults battle_choices(Setup& setup, int user_choice, player& plyr, enemy& Enemy) {
	int damage;

	//player chooses to attack
	if (user_choice >= 200) {
		system("cls");
		int healIndex = user_choice - 200;
		vector<HealOption>& heals = plyr.getHealingOptions();

		// Check index validity
		if (healIndex >= 0 && healIndex < heals.size()) {
			HealOption& chosenPotion = heals[healIndex];

			if (plyr.inventory[chosenPotion.itemID] <= 0) {
				cout << "You have none left of " << chosenPotion.name << "!\n";
			}
			else {
				plyr.useHealingOption(healIndex);
				// Reduce inventory count
				plyr.inventory[chosenPotion.itemID]--;
				// remove if it hits 0
				if (plyr.inventory[chosenPotion.itemID] == 0) {
					plyr.inventory.erase(chosenPotion.itemID);
				}
			}
		}
		else {
			cout << "Invalid potion choice.\n";
		}
		return continueTurn;
	}
	if (user_choice >= 100) {
		system("cls");
		int attackIndex = user_choice - 100;
		vector<attackMoves>& playerAttacks = plyr.getAttacks();
		if (attackIndex >= 0 && attackIndex < playerAttacks.size()) {
			attackMoves& chosenAttack = playerAttacks[attackIndex];
			cout << endl << "You chose " << chosenAttack.name << " to attack the enemy with" << endl;
			int damage = plyr.getStrength() + chosenAttack.damagedone;
			damage = Enemy.damageReduce(damage);
			Enemy.loseHealth(damage);

			if (!chosenAttack.effectName.empty() && chosenAttack.effectAmount != 0 && chosenAttack.effectDuration > 0) {
				Enemy.slowTurnEffect_Logic(
					chosenAttack.effectName,
					chosenAttack.effectAmount,
					chosenAttack.effectDuration
				);
				cout << Enemy.getName() << " is now affected by " << chosenAttack.effectName << " for "
					<< chosenAttack.effectDuration << " turns!\n";
			}

			plyr.attackDialogue(chosenAttack.dialogue);
			cout << endl << "The " << Enemy.getName() << " only takes " << damage << " damage. There defense is now reduced to " << Enemy.getDefense() << "\n\n" << endl;
		}
		//return plyr.isAlive() && Enemy.isAlive();
		return continueTurn;
	}
	else {
		switch (user_choice) {
		case 3://player chooses to run
			system("cls");
			cout << "You Chose to Run!" << endl;
			plyr.runDialogue();
			//return false;
			return EndBattle;
			break;
		case 4:
			system("cls");
			cout << "\nYour current weapons: " << endl;
			for (int i = 0; i < plyr.inventoryW.size(); i++) {
				cout << i + 1 << ". " << plyr.inventoryW[i].name;
				if (i == plyr.equippedIndex) {   // <-- use index, not pointer
					cout << " Equipped";
				}
				cout << endl;
			}
			cout << "\nSelect a weapon to equip: ";
			int choice;
			cin >> choice;
			choice -= 1; // convert to 0-based index

			if (choice >= 0 && choice < plyr.inventoryW.size()) {
				int previousIndex = plyr.equippedIndex;  // save old weapon
				plyr.equippedIndex = choice;             // equip new weapon

				if (previousIndex >= 0 && previousIndex < plyr.inventoryW.size()) {
					cout << "\nUnequipping " << plyr.inventoryW[previousIndex].name << endl;
				}
				cout << "Equipped Weapon: " << plyr.inventoryW[plyr.equippedIndex].name << endl;
			}
			else {
				cout << "\nInvalid choice!\n";
			}
			return IgnoreAction;
			break;
		}
	}
	return continueTurn;
	// return plyr.isAlive() && Enemy.isAlive();
}

//function for enemy actions-------------
int enemyAction(enemy& enemy, player& plyr) {
	int takesaction = 2;//automatically gets set to attack
	bool action = false;//makes sure that only one action is executed
	int choice = randomNum(1, 100);//run probability for each action
	if (!action && enemy.getHealth() < 25 && choice <= 10) {//10% chance to run, only becomes an option once the enemy health is lower than 25
		enemy.runDialogue();
		takesaction = 1;
		action = true;
	}
	if (!action && choice <= 20) {//40% chance to heal
		enemy.healDialogue();
		cout << endl << "The " << enemy.getName() << " heals itself by 10 points." << endl;
		enemy.gainHealth(10);//health goes up by ten, subject to change
		takesaction = 3;
		action = true;
	}
	if (!action) {//70% chance to attack
		attackMoves& movefrmenemy = enemy.randattackmove();
		cout << endl << enemy.getName() << " uses " << movefrmenemy.name << endl;
		enemy.attackDialogue(movefrmenemy.dialogue);
		//int enemyDamage = enemy.getStrength();//works same as player, defense is reduced by a third and damage done to player is reduced to half
		int enemyDamage = enemy.getStrength() + movefrmenemy.damagedone;
		enemyDamage = plyr.damageReduce(enemyDamage);
		plyr.loseHealth(enemyDamage);
		cout << endl << "You take " << enemyDamage << " damage." << endl;
		if (movefrmenemy.effectDuration > 0) {
			plyr.slowTurnEffect_Logic(
				movefrmenemy.effectName,
				movefrmenemy.effectAmount,
				movefrmenemy.effectDuration
			);
		}
		takesaction = 2;
		action = true;
	}
	return takesaction;
}
