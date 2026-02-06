#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "wizard.h"
using namespace std;

int wizard::getAssignedNum() {
	return assignedNum;
}
//constructor, initializes health, strength, defense----------
wizard::wizard() :enemy(100, 18, 10) {
	attackLines = {
		{
		" ",
		10,
		{
		"The Wizard snaps their fingers, calling out a spell that has fire crawling up from the ground beneath you. The heat that radiates off of the flames burns through your clothing, leaving behind burns that you know are going to leave a mark"
		}
		};
		{
		" ",
		8,
		{
		"You see the Wizard wispering a foreign chant. Scared of what these words will bring you try and run but are caught. Frozen mid stride the Wizard blasts you with an enormous gust of wind, throwing you back onto the ground"
		}
		}
		{
		" ",
		20,
		{
		"You hear thunder crack right above where your fight is taking place. A blinding white light erupts from the clouds temperarily stunning you. At this moment of weakness the Wizard attacks, shooting smaller bolts of lightning at you causing more damage"
		}
		};
		{
		" ",
		15,
		{
		"The air around you turns thick, making it hard to breath! This smoke fills up your vision and although you are unable to see, the Wizard snaps his fingers lighting the cloud on fire."
			}
		};
	};
	runLines = {
		"The Wizard is in retreat, screaming something about revenge as he leaves."
		"The Wizard seems to be frozen in place, so you try and attack. As your weapon makes contact with this form, it disperses into thick black smoke. You look around for the real Wizard and are left with an empty battle field, he is no longer there"
		"With a panicked shout, the Wizard turns around and bolts away from you. As you begin to chase him, he takes out a bottle of a black substance with a sludge-like consistancy. he frantically drinks this vile liquid, and just before you know it, he disappears. Looks like you have won this battle"
		"You have significantly weakend the Wizard, and with one last hit this fight should finally be over. As if sensing your realizarion, the Wizard decides to run into the nearby woods and away from his impending death"
	};
	healLines = {
		"The battle has not lasted long but you are already exhausted from the Wizards attacks. As he heals his wounds you aret hankful for the small break you are given to catch your breath"
		"A book appears infront of the Wizard, and as he reads from its contents, smoke begins to emit from his skin, leaving behind healed wounds"
		"Just after your hit started to deal damage to the Wizards form, they take out a green potion and drink the disgusting slimy liquid, healing the wounds"
		"As you were preparing for another attack, the Wizard begins to glow, cuts and scratches knit back together, giving the Wizard back strength to keep the fight going"
	};
	dieLines = {
		"As you throw your last hit, the Wizard, having no time to defend, takes the blow at full. He perishes, fading into a black mist."
		"A sickening crack rings out as you throw a hit towards the Wizard, seems you have broken through his sheild. Before the Wizard can fully react you decide to end this here, killing the mage and taking the win" 
		"Just as you were about to give up on this everlasting battle, the Wizard collapses. You creep closer to the pool of robes on the soil and are met with...nothing. The Wizard is no longer there. You can only hope that he finally succumbed to death" 
		"With one last hit the Wizard finally collapses. He melts into the ground, leaving behind dying plants and newly formed weeds in his wake"
	};
}
//function that returns enemy name---------
string wizard::getName() {
	return "Wizard";
}
//function when enemy runs in battle, output specific line--------
//void wizard::flee() {
	//cout << endl << "The Wizard is in retreat, screaming something about revenge as he leaves." << endl;
//}
//function when enemy dies in battle, output specific line-------
//void wizard::die() {
	//cout << endl << "As you throw your last hit, the Wizard, having no time to defend, takes the blow at full. He perishes, fading into a black mist." << endl;
//}

/*void attackDialogue() {
	cout <<endl<< "The Wizard snaps their fingers, calling out a spell that has fire crawling up from the ground beneath you. The heat that radiates off of the flames burns through your clothing, leaving behind burns that you know are going to leave a mark" << endl;
	cout <<endl<< "You see the Wizard wispering a foreign chant. Scared of what these words will bring you try and run but are caught. Frozen mid stride the Wizard blasts you with an enormous gust of wind, throwing you back onto the ground" << endl;
	cout <<endl<< "You hear thunder crack right above where your fight is taking place. A blinding white light erupts from the clouds temperarily stunning you. At this moment of weakness the Wizard attacks, shooting smaller bolts of lightning at you causing more damage " << endl;
	cout <<endl<< "The air around you turns thick, making it hard to breath! This smoke fills up your vision and although you are unable to see, the Wizard takes snaps his fingers lighting the cloud on fire." << endl;
}

void runDialogue() {
	cout <<endl<< "The Wizard is in retreat, screaming something about revenge as he leaves." << endl;
	cout <<endl<< "The Wizard seems to be frozen in place, so you try and attack. As your weapon makes contact with this form, it disperses into thick black smoke. You look around for the real Wizard and are left with an empty battle field, he is no longer there" << endl;
	cout <<endl<< "With a panicked shout, the Wizard turns around and bolts away from you. As you begin to chase him, he takes out a bottle of a black substance with a sludge-like consistancy. he frantically drinks this vile liquid, and just before you know it, he disappears. Looks like you have won this battle" << endl;
	cout <<endl<< "You have significantly weakend the Wizard, and with one last hit this fight should finally be over. As if sensing your realizarion, the Wizard decides to run into the nearby woods and away from his impending death" << endl;
}

void dieDialogue(){
	cout <<endl<< "As you throw your last hit, the Wizard, having no time to defend, takes the blow at full. He perishes, fading into a black mist." << endl;
	cout <<endl<< "A sickening crack rings out as you throw a hit towards the Wizard, seems you have broken through his sheild. Before the Wizard can fully react you decide to end this here, killing the mage and taking the win" << endl;
	cout <<endl<< "Just as you were about to give up on this everlasting battle, the Wizard collapses. You creep closer to the pool of robes on the soil and are met with...nothing. The Wizard is no longer there. You can only hope that he finally succumbed to death" << endl;
	cout <<endl<< "With one last hit the Wizard finally collapses. He melts into the ground, leaving behind dying plants and newly formed weeds in his wake" << endl;
}

void healDialogue() {
	cout <<endl<< "The battle has not lasted long but you are already exhausted from the Wizards attacks. As he heals his wounds you aret hankful for the small break you are given to catch your breath" << endl;
	cout <<endl<< "A book appears infront of the Wizard, and as he reads from its contents, smoke begins to emit from his skin, leaving behind healed wounds" << endl;
	cout <<endl<< "Just after your hit started to deal damage to the Wizards form, they take out a green potion and drink the disgusting slimy liquid, healing the wounds" << endl;
	cout <<endl<< "As you were preparing for another attack, the Wizard begins to glow, cuts and scratches knit back together, giving the Wizard back strength to keep the fight going" << endl;
}*/
