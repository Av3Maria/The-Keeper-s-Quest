#include <iostream>
#include <string>
#include <vector>
#include "character.h"
#include "enemy.h"
#include "monsterBug.h"
using namespace std;

int monsterBug::getAssignedNum() {
	return assignedNum;
}
//constructor, initializes health, strength, defense----------
monsterBug::monsterBug() :enemy(65, 12, 10) {
	attackLines = {
		{
		" ",
		10,
		{
		"The bug calls upon others like him. Spiders, ants, and other forest floor critters are surrounding you on all sides! The bugs attack, biting at your ankles, crawling up you leaving more damage in their wake."
		}
		};
		{
		" ",
		8,
		{
		"The bug, as small as it may be, still packs a lot of strength within its body. Without time to dodge you get hit by too many limbs to count"
		}
		};
		{
		" ",
		15,
		{
		"Enraged, the bug tries to take a bite out of your arm. Although it fails to rip anything off, you still are affected by the sting it leaves behind"
		}
		};
		{
		" ",
		10,
		{
		"The bug flies straight at you and grabs onto your arms. It brings you up into the air, achieving a good distance from where you just were. As it tries to fly even further up, you slip out of its grasp, hitting the ground hard"
		}
		};
	};
	runLines = {
		"The bug stops attacking, turning around scurrying away as fast as its tiny legs can go"
		"The bug scuttles away.You hear nothing from its motion and wonder how you shall detect its return"
		"Recognizing that this battle is futile, the bug backs up. It turns and flies away, leaving you far behind"
		"Just as you were about to go for the last hit, the bug in its panic digs down into the ground leaving you to stand there confused"
	};
	healLines = {
		"The bug decides to heal itself from the damage you have inflicted upon it. You watch in disgust as the gashes on the creature seem to itself back together"
		"You watch as the creature begins to convulse, limbs that had broken off begin to regenerate, scratches and cuts close"
		"The creature decides to heal, all the damage you had done thus far gets reduced to scars and newly reformed limbs"
		"The bug slowly backs away, trying to heal as much as it could muster in the little time you give it"
	};
	dieLines = {
		"The bug, as weak as it was, fought til its last breath. Although surprising, you still take this win. Congratulations." 
		"As you make contact with the shell of this vile creature, you hear a sickening crack. The bugs hard outside splits open, killing it in seconds. You win this battle, good job"
		"Just as the creature was about to flee, you hit it with the last of your strength. Cutting off any form of escape it had, as in the small wings attatched to its body, the bug finally perishes"
		"You hit the bug, sending it flying across the battle field. It hits the ground with a loud crunch, killing it upon impact. Seems you win this one"
	};

}
//function that returns enemy name---------
string monsterBug::getName() {
	return "Monster Bug";
}
//function when enemy runs in battle, output specific line--------
//void monsterBug::flee() {
//}
//function when enemy dies in battle, output specific line--------
//void monsterBug::die() {
//}

/*void attackDialogue() {
	//vector<string>dialogueLines;
	cout <<endl<<"The bug calls upon others like him. Spiders, ants, and other forest floor critters are surrounding you on all sides! The bugs attack, biting at your ankles, crawling up you leaving more damage in their wake." << endl;
	cout <<endl<<"The bug, as small as it may be, still packs a lot of strength within its body. Without time to dodge you get hit by too many limbs to count" << endl;
	cout <<endl<<"Enraged, the bug tries to take a bite out of your arm. Although it fails to rip anything off, you still are affected by the sting it leaves behind" << endl;
	cout <<endl<< "The bug flies straight at you and grabs onto your arms. It brings you up into the air, achieving a good distance from where you just were. As it tries to fly even further up, you slip out of its grasp, hitting the ground hard" << endl;
}

void runDialogue() {
	cout <<endl<<"The bug stops attacking, turning around scurrying away as fast as its tiny legs can go" << endl;
	cout <<endl<< "The bug scuttles away.You hear nothing from its motion and wonder how you shall detect its return" << endl;
	cout <<endl<< "Recognizing that this battle is futile, the bug backs up. It turns and flies away, leaving you far behind" << endl;
	cout <<endl<< "Just as you were about to go for the last hit, the bug in its panic digs down into the ground leaving you to stand there confused" << endl;
}

void dieDialogue(){
	cout <<endl<< "The bug, as weak as it was, fought til its last breath. Although "<<
		"surprising, you still take this win. Congratulations." << endl;
	cout <<endl<< "As you make contact with the shell of this vile creature, you hear a sickening crack. The bugs hard outside splits open, killing it in seconds. You win this battle, good job" << endl;
	cout <<endl<< "Just as the creature was about to flee, you hit it with the last of your strength. Cutting off any form of escape it had, as in the small wings attatched to its body, the bug finally perishes" << endl;
	cout <<endl<< "You hit the bug, sending it flying across the battle field. It hits the ground with a loud crunch, killing it upon impact. Seems you win this one" << endl;
}

void healDialogue() {
	cout <<endl<< "The bug decides to heal itself from the damage you have inflicted upon it. You watch in disgust as the gashes on the creature seem to itself back together" << endl;
	cout <<endl<< "You watch as the creature begins to convulse, limbs that had broken off begin to regenerate, scratches and cuts close" << endl;
	cout <<endl<< "The creature decides to heal, all the damage you had done thus far gets reduced to scars and newly reformed limbs" << endl;
	cout <<endl<< "The bug slowly backs away, trying to heal as much as it could muster in the little time you give it" << endl;
}*/
