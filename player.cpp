#include <iostream>
#include <string>
#include "character.h"
#include "player.h"
using namespace std;
//initializes players health, strength, and defense---------
player::player() :character("Player", 100, 18, 10) {
	attackLines = {
		{
		" ",
		12,
		{
		"You attack the enemy with great force, your blade making contact with its body."
		}
		};
		{
		" ",
		20,
		{
		"With agility that one would never know you had, you strike the enemy with your blade. Once in the side, and you were able to get another hit in as it was distracted"
		}
		};
		{
		" ",
		13,
		{
		"Choosing to attack with your bow, you draw the string close to your ear, aiming and releasing an arrow that hits directly into the targets chest"
		}
		};
		{
		" ",
		12,
		{
		"With your bow you hit the enemy in the enemy's limb, with a cry they are left hobbling and disoriented"
		}
		};
	};
	runLines = {
		"Low on items? Scared to die? No matter the reason you chose to flee the fight, leaving the enemy far behind as you run"
		"Seems your attacks are not doing as much damage as you had hoped, so before you get hurt any further, you turn and run away, stumbling over debree from the fight as you go"
		"As panic sets in, you realize that this is a battle that you will not be able to turn in your favor. Limbs trembling you turn and scramble away as fast as your legs can take you, the sound of the creature can be heard quieting as you leave"
		"Exhausted, you will no longer be able to participate in this fight, so you make the decision to leave. Looks like the enemy will win this one"
	};
	healLines = {
		"Tired from the attacks that have been thrown at you, reachinf into your puch you take out a red potion in hopes it will give you energy to keep going"
		"New wounds litter your body, but adrenaline kicks in, allowing you to ignore the most of the damage"
		"Taking out a potion and downing the liquid within it your body begins the painstakingly slow recovery of healing your wounds"
		"Potions are about to be your next best friend. You take out a wile containing a red liquid, and after drinking from the glass your cuts begin to heal over. What a weird sensation of skin growing back in mere seconds"
	};
	dieLines = {
		"Oh no, it appears that you have been taken out. I suppose that was... slightly disaappointing. I thought you were better than this."
		"You feel tired...the damage is starting to catch up to you all at once causing you to collapse to the ground. Without any energy left your eyes begin to close. looks like you lose this fight"
		"As the enemy towers over you, your vision starts to blur. You are it one last time, death comes quickly after. You lose player, do better next time"
		"You are rendered dead after the enemies last attack. They weakened you to mere helplessness, while they walk away with no remorse. "
	};
}
//funciton to get players name----------
string player::getName() {
	return "player";
}
//function for when player dies, specific lines output---------
//void player::die() {

//}
//function for when player flees, specific lines output-------------
//void player::flee() {

//}

/*void attackDialogue() {
	cout <<endl<< "" << endl;
	cout <<endl<< "" << endl;
	cout <<endl<< "" << endl;
	cout <<endl<< "" << endl;
}

void runDialogue() {
	cout <<endl<< "Low on items? Scared to die? No matter the reason you chose to flee the fight, "
	"leaving the enemy far behind as you run" << endl;
	cout <<endl<< "" << endl;
	cout <<endl<< "" << endl;
	cout <<endl<< "" << endl;
}

void dieDialogue(){
	cout <<endl<< "Oh no, it appears that you have been taken out. I suppose that was... slightly disaappointing. "<<
		"I thought you were better than this." << endl;
	cout <<endl<< "" << endl;
	cout <<endl<< "" << endl;
	cout <<endl<< "" << endl;
}

void healDialogue() {
	cout <<endl<< "" << endl;
	cout <<endl<< "" << endl;
	cout <<endl<< "" << endl;
	cout <<endl<< "" << endl;/
//}
