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
#include "Map.h"
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

	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return true; // default = continue battle, NOT exit
	}

	return (choice == 1);
}

int enterBattle(Setup& setup, Map& map, enemy* Enemy, Tile* tile) {

	player& plyr = setup.mainPlayer;

	plyr.syncWeapons(plyr, setup);

	if (plyr.inventoryW.empty()) {
		cout << "Warning: player has no weapons!" << endl;
	}
	else if (plyr.equippedIndex >= plyr.inventoryW.size()) {
		plyr.equippedIndex = 0;
	}

	for (HealOption& heal : plyr.getHealingOptions()) {
		heal.turnRemaining = 0;
	}

	if (!HealthCheck(plyr)) {
		cout << "You decide to run from this fight." << endl;
		return 0;
	}

	system("cls");

	//enemy* Enemy = nullptr;

	// ================= ENEMY SELECTION =================
	if (Enemy == nullptr)
	{
		if (tile != nullptr && tile->hasFixedBoss && tile->fixedEnemy != nullptr)
		{
			Enemy = tile->fixedEnemy->clone();
			system("cls");
			bossIntro(*Enemy);

			cout << "\n(Press ENTER to continue...)";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
		}
		else
		{
			enemy* temp = map.currentTile->getRandomEnemy();

			if (!temp)
			{
				cout << "No enemies here.\n";
				return 0;
			}

			Enemy = temp->clone();
		}
	}

	// ================= BATTLE LOOP =================
	while (plyr.isAlive() && Enemy->isAlive())
	{
		print_stats(plyr, *Enemy);

		int choice = print_battlemenu(plyr);

		BattleResults result = battle_choices(setup, choice, plyr, *Enemy);

		if (!Enemy->isAlive())
		{
			Enemy->dieDialogue();

			// always drops
			setup.lootDrops();

			// boss reward only
			if (tile && tile->hasFixedBoss) {

				string msg = Enemy->getAmuletMessage();

				if (!msg.empty()) {
					cout << "\n" << msg << "\n";
				}

				if (tile->fixedEnemy->getName() == "Dragon")
					setup.mainPlayer.giveAmulet(20);

				else if (tile->fixedEnemy->getName() == "Wizard") {
					setup.mainPlayer.giveAmulet(21);
					wizardVictoryEnding(setup, map);
				}
				else if (tile->fixedEnemy->getName() == "Toad")
					setup.mainPlayer.giveAmulet(18);

				else if (tile->fixedEnemy->getName() == "MonsterBug")
					setup.mainPlayer.giveAmulet(19);
			}
			cout << "\n(Press ENTER to continue...)";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();

			break;
		}

		if (result == EndBattle) break;
		if (result == IgnoreAction) continue;

		int enemyResult = enemyAction(*Enemy, plyr);

		plyr.updateHealingCooldown();
		plyr.slowTurnEffect_Use();

		if (!enemyResult) {
			cout << "\nEnemy chooses to run!" << endl;
			break;
		}

		if (!plyr.isAlive()) {
			plyr.dieDialogue();
			cout << "\n(Press ENTER to continue...)";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			break;
		}
	}
	if (Enemy != nullptr && (tile == nullptr))
	{
		delete Enemy;
	}
	return 0;
}


/*//function that uses the random function to choose an enemy for battle-------------
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
}*/

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
				plyr.useHealingOption(healIndex, true);
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
			// FIRE AMULET (20)
			if (plyr.hasItem(20)) {
				cout << "Flames surge through your attack!\n";
				Enemy.loseHealth(5); // or scale if you want: plyr.getStrength()/4
			}

			// POISON AMULET (19)
			if (plyr.hasItem(19)) {
				cout << "A toxic burn spreads through the enemy!\n";
				Enemy.slowTurnEffect_Logic("Poison", 2, 3);
			}

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

void clearInput() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void bossIntro(enemy& Enemy) {
	string name = Enemy.getName();

	if (name == "Dragon")
	{
		cout << "You push forward into a rocky clearing near the base of the mountain." << endl;
		cout << "Loose gravel crunches beneath your feet as smoke rolls through the air." << endl;
		cout << "The heat grows stronger with every step, and the ground begins to tremble.\n" << endl;

		cout << "A deafening roar shakes the cliffs above you." << endl;
		cout << "From the flames, a massive Dragon rises and spreads its wings wide." << endl;
		cout << "Its burning eyes lock onto you as fire escapes from its jaws.\n" << endl;

		cout << "The Dragon slams its claws into the earth and lowers its head." << endl;
		cout << "You grip your weapon tightly and prepare for battle.\n" << endl;
	}
	else if (name == "Wizard")
	{
		cout << "You step into the ruined throne room at the top of the dark castle." << endl;
		cout << "Broken stone litters the floor, and torn banners hang from the walls." << endl;
		cout << "A cold wind slips through shattered windows as shadows twist around the room.\n" << endl;

		cout << "At the far end of the chamber, a figure slowly rises from the throne." << endl;
		cout << "The Wizard turns toward you, staff in hand, his cloak trailing black mist." << endl;
		cout << "His eyes glow with anger as he tightens his grip on the final amulet shard.\n" << endl;

		cout << "\"So... you have made it this far,\" he says." << endl;
		cout << "Dark magic gathers around him as he raises his staff." << endl;
		cout << "You take your stance as the final battle begins.\n" << endl;
	}
	else if (name == "MonsterBug")
	{
		cout << "You travel deeper into the forest, where the trees grow taller and the sunlight barely reaches the ground." << endl;
		cout << "The path becomes narrow and twisted, covered in roots and fallen branches." << endl;
		cout << "An uneasy silence settles around you as even the birds seem to have vanished.\n" << endl;

		cout << "Ahead, hidden between thick vines and stone, you notice the entrance to a dark cave." << endl;
		cout << "As you step closer, pairs of glowing eyes suddenly appear within the shadows." << endl;
		cout << "The ground begins to shake as scratching and skittering sounds echo from inside.\n" << endl;

		cout << "With a violent screech, the Monster Bug bursts from the cave entrance." << endl;
		cout << "Its massive body towers above you as venom drips from its jaws." << endl;
		cout << "Its many legs claw against the earth as it rushes forward.\n" << endl;

		cout << "You tighten your grip and prepare for battle.\n" << endl;
	}
	else if (name == "Toad")
	{
		cout << "You leave the safety of the town behind and begin your journey down an old dirt path." << endl;
		cout << "Rolling fields soon give way to damp ground and tall reeds swaying in the wind." << endl;
		cout << "Before long, you arrive at a quiet lake covered in lily pads stretching across the water.\n" << endl;

		cout << "Carefully, you step from pad to pad, making your way farther across the lake." << endl;
		cout << "With each step, the air grows heavier and the water darker." << endl;
		cout << "What began as a peaceful lake slowly turns into a murky swamp filled with fog and twisted trees.\n" << endl;

		cout << "The water around you begins to ripple." << endl;
		cout << "A giant Toad rises from the muck, mud sliding from its back as it stares you down." << endl;
		cout << "Its glowing eyes lock onto you as it lets out a deep, thunderous croak.\n" << endl;

		cout << "You brace yourself as the creature leaps forward.\n" << endl;
	}
	else
	{
		cout << "You step cautiously into the area ahead." << endl;
		cout << "A powerful presence suddenly blocks your path." << endl;
		cout << name << " appears before you." << endl;
		cout << "You prepare yourself for battle.\n" << endl;
	}
}

void wizardVictoryEnding(Setup& setup, Map& map)
{
	system("cls");
	cout << "The castle trembles around you as the final battle comes to an end." << endl;
	cout << "Cracked stone falls from the ceiling, and the once-grand halls echo with silence." << endl;
	cout << "Before you, the Wizard collapses to one knee, weakened and struggling to rise." << endl;
	cout << "Dark mist spills from his cloak as he grips the final amulet shard tightly in his hand.\n" << endl;

	cout << "\"No... this power is mine!\"" << endl;
	cout << "\"I searched for these pieces for years... I will not lose them to you!\"" << endl;
	cout << "He stumbles forward in anger, barely able to stand, yet refusing to surrender." << endl;
	cout << "With one final cry, he gathers the last of his strength and lunges at you.\n" << endl;

	cout << "You steady yourself and deliver the final strike." << endl;
	cout << "The Wizard freezes in place as the shadows around him begin to unravel." << endl;
	cout << "His body fades into a cloud of black mist, carried away by the cold air." << endl;
	cout << "Only the final amulet shard remains, clattering onto the stone floor.\n" << endl;

	cout << "You step forward and pick it up." << endl;
	cout << "The moment it touches the other shards in your pack, they begin to shake." << endl;
	cout << "One by one, the five pieces rise into the air and pull toward each other." << endl;
	cout << "A brilliant light fills the ruined chamber as the Sacred Amulet is restored.\n" << endl;

	cout << "With your quest complete, you begin the long journey home." << endl;
	cout << "Across forests, ruins, and broken roads, you retrace the path that led you here." << endl;
	cout << "The restored amulet glows warmly at your side as you carry hope back to the town.\n" << endl;

	cout << "When you arrive, the townsfolk rush toward you." << endl;
	cout << "\"Is that them?\"" << endl;
	cout << "\"Did they recover the shards?\"" << endl;
	cout << "\"Could it really be over?\"" << endl;
	cout << "Whispers spread through the crowd as the people gather around.\n" << endl;

	cout << "The townsfolk slowly part, and the village elder steps forward." << endl;
	cout << "His eyes are wide with anticipation as he stops before you." << endl;

	cout << "\"Tell me... did you defeat the Wizard?\"" << endl;
	cout << "\"Were you able to restore the amulet?\"" << endl;

	cout << "You nod and carefully raise the Sacred Amulet into the air." << endl;
	cout << "As the sunlight touches it, rays of brilliant color dance across the village." << endl;
	cout << "The crowd gasps in amazement.\n" << endl;

	cout << "\"You have done it...\"" << endl;
	cout << "\"With this, our town shall be protected once more.\"" << endl;
	cout << "\"You have given our people a future again.\"" << endl;
	cout << "\"Thank you for your bravery, " << setup.mainPlayer.getClassType() << ".\"" << endl;
	cout << "\"Your name will be remembered for generations to come.\"\n" << endl;

	cout << "\n(Press ENTER to continue...)";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	system("cls");
	string playerClass = setup.mainPlayer.getClassType();

	if (playerClass == "Warrior")
	{
		cout << "The townspeople spoke of the mighty Warrior whose courage shattered the Wizard's reign.\n";
		cout << "Your strength became their shield.\n\n";
	}
	else if (playerClass == "Rogue")
	{
		cout << "They told stories of the Rogue who moved through danger unseen and struck when hope was lost.\n";
		cout << "Your cunning saved them all.\n\n";
	}
	else if (playerClass == "Hunter")
	{
		cout << "They honored the Hunter whose precision never failed, even against impossible odds.\n";
		cout << "Your instincts guided the town back to safety.\n\n";
	}
	else if (playerClass == "Sorcerer")
	{
		cout << "They remembered the Sorcerer who turned ancient power against the darkness.\n";
		cout << "Your mastery of magic restored the light.\n\n";
	}

	cout << "\n(Press ENTER to continue...)";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	system("cls");

	//add "your journey is at an end... do you want to save and exit of continue exploring?"
	//if yes, save and exit, if not quickSave and return to game (still stay at castle, last location)
}
