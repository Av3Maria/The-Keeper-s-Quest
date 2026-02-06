#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "dragon.h"
using namespace std;

int dragon::getAssignedNum() {
	return assignedNum;
}
//constructor, initializes health, strength, defense----------
dragon::dragon():enemy(120,25,10){
	attackLines = {
		{
		" ",
		10,
		{
		"You would think it'd be easy to dodge an attack from a creature who's moves are so obvious, but being as slow as you are the tail of the Dragon still makes contact. You are knocked back, disoriented from the attack"
		}
		};
		{
		" ",
		12,
		{
		"The Dragon looks enraged, its moves getting more eratic as the fight goes on. Instead of charging at you, it takes in a deep breath, sucking in as much air as it can. Simaltaniuosly its stomach begins to emit a soft glow, brightening as the seconds tic by. Then, all at once the Dragon stops and unleashes an enormous blast of fire from its mouth. You try to run out of its way but there was too much, surrounding you on all sides you are burned with the hot flames"
		}
		};
		{
		" ",
		15,
		{
		"Faster than you had inticipated the Dragon darts towards you, wings flapping vigorously. It manages to pin you to the ground, tearing at your armor. Before being crushed by the wieght of the creature, you are able to maneuver from out of its grasp  "
		}
		};
		{
		" ",
		10,
		{
		"The Dragon throws its sharp claws out towards you, managing to snag onto your clothing. You are both wounded by this attack and thrown to the side "
		}
		};
	};
	runLines = {
		"The Dragaon runs away screaming 'This is not over yet. I WILL RETURN TO RAIN FIRE UPON YOU."
		"Realization dawns the Dragons face as it begins to understand its impending doom. The screech it lets out next is deafening, causing you to close your eyes and grip onto your head to try and block out some of its noise. As you were distracted the Dragon makes its get away, leaving you behind as well as a trail of blood"
		"The Dragon is extremely mad at the fact that you are winning this battle, but fear also resides within it. Instead of staying to find out more of what you could do with your weapon, the Dragon decides to leave, flying away with a powerful gust of wind hitting you on its way out"
		"The Dragon srambles away, frantically trying to leave the battle field as it understands that staying any longer would result in its defeat"
	};
	healLines = {
		"The new wounds that had just been dealt to the Dragon's body begin to close, new scales growing overtop of the missing ones"
		"After your attack the Dragon takes in a deep breath. Wounds that had once lined its body begin to glow and heal over, giving it more enrgy you wish it did not have" 
		"You did quite a lot of damage on the beast, and it seems to notice this as well as it begins to heal itself"
		"Exhausted, you watch as the Dragon regenerates scales over the damage that you had just dealt. "
	};
	dieLines = {
		"With one last screech the Dragon tries to knock you back away from its collapsed body, but you stand strong. With your weapon you are able to finally take down the beast once and for all"
		"Being how the Dragon is one of the loudest creatures you have encountered, it is almost surreal with how quiet it has become. In the distance the Dragon lays lifeless, almost like it is asleep. As you approach you can sense that you have won this battle"
		"Your weapon is able to make contact with the Dragon as it is within the air, bringing its descent to a halt. Its wings stop moving as it takes in the full impact, and the Dragon falls back to the ground with an earth-shaking thud"
		"With the last hit of your weapon the Dragon goes down. As you walk away with triumph the Dragon's body begins to light up, catching aflame. As it burns into ash the only thing you can think is how fitting, a dramatic creature getting a dramatic end"
	};
}
//function that returns enemy name---------
string dragon::getName() {
	return "Dragon";
}
//function when enemy runs in battle, output specific line--------
//void dragon::flee() {
	//runDialogue();
//}
//function when enemy dies in battle, output specific line--------
//void dragon::die() {
//	cout << endl << "The Dragon has been defeated. Congratulations on your win!" << endl;
//}

/*void attackDialogue() {
	cout <<endl<< "You would think it'd be easy to dodge an attack from a creature who's moves are so obvious, but being as slow as you are the tail of the Dragon still makes contact. You are knocked back, disoriented from the attack" << endl;
	cout <<endl<< "The Dragon looks enraged, its moves getting more eratic as the fight goes on. Instead of charging at you, it takes in a deep breath, sucking in as much air as it can. Simaltaniuosly its stomach begins to emit a soft glow, brightening as the seconds tic by. Then, all at once the Dragon stops and unleashes a enormous blast of fire from its mouth. You try to run out of its way but there was too much, surrounding you on all sides you are burned with the hot flames" << endl;
	cout <<endl<< "Faster than you had inticipated the Dragon darts towards you, wings flapping vigorously. It manages to pin you to the ground, tearing at your armor. Before being crushed by the wieght of the creature, you are able to maneuver from out of its grasp  " << endl;
	cout <<endl<< "The Dragon throws its sharp claws out towards you, managing to snag onto your clothing. You are both wounded by this attack and thrown to the side " << endl;
}

void runDialogue() {
	cout << endl << "The Dragaon runs away screaming 'This is not over yet. I WILL RETURN TO RAIN FIRE UPON YOU.'" << endl;
	cout <<endl<< "Realization dawns the Dragons face as it begins to understand its impending doom. The screech it lets out next is deafening, causing you to close your eyes and grip onto your head to try and block out some of its noise. As you were distracted the Dragon makes its get away, leaving you behind as well as a trail of blood" << endl;
	cout <<endl<< "The Dragon is extremely mad at the fact that you are winning this battle, but fear also resides within it. Instead of staying to find out more of what you could do with your weapon, the Dragon decides to leave, flying away with a powerful gust of wind hitting you on its way out" << endl;
	cout <<endl<< "The Dragon srambles away, frantically trying to leave the battle field as it understands that staying any longer would result in its defeat" << endl;
}

void dieDialogue(){
	cout <<endl<< "With one last screech the Dragon tries to knock you back away from its collapsed body, but you stand strong. With your weapon you are able to finally take down the beast once and for all" << endl;
	cout <<endl<< "Being how the Dragon is one of the loudest creatures you have encountered, it is almost surreal with how quiet it has become. In the distance the Dragon lays lifeless, almost like it is asleep. As you approach you can sense that you have won this battle" << endl;
	cout <<endl<< "Your weapon is able to make contact with the Dragon as it is within the air, bringing its descent to a halt. Its wings stop moving as it takes in the full impact, and the Dragon falls back to the ground with an earth-shaking thud" << endl;
	cout <<endl<< "With the last hit of your weapon the Dragon goes down. As you walk away with triumph the Dragon's body begins to light up, catching aflame. As it burns into ash the only thing you can think is how fitting, a dramatic creature getting a dramatic end" << endl;
}

void healDialogue() {
	cout <<endl<< "The new wounds that had just been dealt to the Dragon's body begin to close, new scales growing overtop of the missing ones" << endl;
	cout <<endl<< "After your attack the Dragon takes in a deep breath. Wounds that had once lined its body begin to glow and heal over, giving it more enrgy you wish it did not have" << endl;
	cout <<endl<< "You did quite a lot of damage on the beast, and it seems to notice this as well as it begins to heal itself" << endl;
	cout <<endl<< "Exhausted, you watch as the Dragon regenerates scales over the damage that you had just dealt. " << endl;
}*/