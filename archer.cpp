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
archer::archer() :enemy(90, 15, 10) {
	attackLines = {
		{
		" ",
		9,
		{
		"As an arrow flies straight for you, the Archer says 'This one is just for you'"
		}
		};
		{
		" ",
		12,
		{
		"The Archer seems upset as he shoots arrow after arrow, and all of them come barreling towards you. Some miss but quite a few hit their intended target"
		}
		};
		{
		" ",
		10,
		{
		"The Archer lifts up his bow, shooting an arrow right at where you are standing. For anyone else, they would move out of the way in time, but for some reason you react too slow and are hit. How disappointing"
		}
		};
		{
		" ",
		8,
		{
		"As weak as the Archer may be, you still are hit by one of his stray arrows. Boosting his already inflated ego"
		}
		};
	};
	runLines = {
		"The Archer is fleeing, too scared to keep the fight going. You have won this battle"
		"The Archer slowly backs away, looking at you with fear in his eyes. He screams 'I am feeling nice so I will leave you alive this once' as he turns and runs away, but you know with one more hit he would have been dead"
		"Just as you were about to finish this battle, the Archer throws something on the ground. Jusr as you were about to question him your vision starts to fill with smoke. You hear footsteps dissipating away from you, and once the smoke clears, the Archer is no where to be found"
		"Realizing the odds of vicotry slowly decreasing, the Archer decides that he is not cut out for this Battle and runs away. Were they always this weak? No matter you still win this fight"
	
	};
	healLines = {
		"You see the Archer reach into their pouch taking out a vial with a green liquid sloshing arounf inside. They quickly down the substance, healing the wounds that littered their body"
		"The Archer fires a multitude of arrows at you as a distraction as he takes the time it gives him to heal the damage you have done thus far " 
		"The Archer seems to glance at something next to him. Running to the side you see him pick up a bundle of berries and swallow a few, healing wounds that you were hoping would have done more damage"
		"As the Archer says 'You're the weakest person I have ever fought,' they down a healing potion to sew up some of the cuts on their body "
	};
	dieLines = {
		"The Archer has succumbed to his fate. Congratulations Player, seems you won this battle"
		"You deal the final blow, and with the last of their breath, the Archer tries to fire one last arrow...and it misses by a long shot. "
		"The Archer sees what you are trying to do and tries to flee. Just as he was about to make it into the woods, you are able to make one last hit. He goes down with a thud, making you the winner of this battle"
		"After your last hit the Archer falls to the ground, and with his final breath he calls this fight the most unfair battle he has ever been apart of"
	
	};
}
//function that returns enemy name---------
string archer::getName() {
	return "Archer";
}
//function when enemy runs in battle, output specific line--------
//void archer::flee() {
}
//function when enemy dies in battle, output specific line--------
//void archer::die() {
	//cout << endl << "The Archer has succumbed to his fate. Congratulations Player, seems you won this battle" << endl;
//}

/*void attackDialogue() {
	cout << endl << "As an arrow flies straight for you, the Archer says 'This one is just for you'" << endl;
	cout << endl << "The Archer seems upset as he shoots arrow after arrow, and all of them come barreling towards you. Some miss but quite a few hit their intended target" << endl;
	cout << endl << "The Archer lifts up his bow, shooting an arrow right at where you are standing. For anyone else, they would move out of the way in time, but for some reason you react too slow and are hit. How disapointing" << endl;
	cout << endl << "As weak as the Archer may be, you still are hit by one of his stray arrows. Boosting his already inflated ego" << endl;
}

void runDialogue() {
	cout << endl << "The Archer is fleeing, too scared to keep the fight going. You have won this battle" << endl;
	cout << endl << "The Archer slowly backs away, looking at you with fear in his eyes. He screams 'I am feeling nice so I will leave you alive this once' as he turns and runs away, but you know with one more hit he would have been dead" << endl;
	cout << endl << "Just as you were about to finish this battle, the Archer throws something on the ground. Jusr as you were about to question him your vision starts to fill with smoke. You hear footsteps dissipating away from you, and once the smoke clears, the Archer is no where to be found" << endl;
	cout << endl << "Realizing the odds of vicotry slowly decreasing, the Archer decides that he is not cut out for this Battle and runs away. Were they always this weak? No matter you still win this fight" << endl;
}

void dieDialogue(){
	cout <<endl<< "The Archer has succumbed to his fate. Congratulations Player, seems you won this battle" << endl;
	cout <<endl<< "You deal the final blow, and with the last of their breath, the Archer tries to fire one last arrow...and it misses by a long shot. " << endl;
	cout <<endl<< "The Archer sees what you are trying to do and tries to flee. Just as he was about to make it into the woods, you are able to make one last hit. He goes down with a thud, making you the winner of this battle" << endl;
	cout <<endl<< "After your last hit the Archer falls to the ground, and with his final breath he calls this fight the most unfair battle he has ever been apart of" << endl;
}

void healDialogue() {
	cout << "You see the Archer reach into their pouch taking out a vial with a green liquid sloshing arounf inside. They quickly down the substance, healing the wounds that littered their body" << endl;
	cout << "The Archer fires a multitude of arrows at you as a distraction as he takes the time it gives him to heal the damage you have done thus far " << endl;
	cout << "The Archer seems to glance at something next to him. Running to the side you see him pick up a bundle of berries and swallow a few, healing wounds that you were hoping would have done more damage" << endl;
	cout << "As the Archer says 'You're the weakest person I have ever fought,' they down a healing potion to sew up some of the cuts on their body " << endl;*/
//}