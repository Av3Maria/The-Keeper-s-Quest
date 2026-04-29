#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "dragon.h"
using namespace std;

int dragon::getAssignedNum() {
    return assignedNum;
}
string dragon::getAmuletMessage() const {
    return "The Dragon's heart fades... you feel its fire transfer to you. You obtained the Amulet shard of fire.";
}
// Constructor: initializes health, strength, defense
dragon::dragon(bool bossMode) : enemy(120, 25, 10), isBoss(bossMode) {

    if (isBoss) {
        health = 180;
        strength = 35;
        defense = 15;
    }
    attacks = {
        { "Tail whip", isBoss ? 15 : 10, { "You would think it'd be easy to dodge an attack from a creature whose moves are so obvious, but being as slow as you are, the tail of the Dragon still makes contact. You are knocked back, disoriented from the attack." } },
        { "Fire Blast", isBoss ? 20 : 12, { "The Dragon looks enraged, its moves getting more erratic as the fight goes on. Instead of charging at you, it takes in a deep breath, sucking in as much air as it can. Simultaneously, its stomach begins to emit a soft glow, brightening as the seconds tick by. Then, all at once, the Dragon stops and unleashes an enormous blast of fire from its mouth. You try to run out of its way, but there is too much; surrounded on all sides, you are burned by the hot flames." } },
        { "Crushed Force", isBoss ? 22 : 15, { "Faster than you had anticipated, the Dragon darts towards you, wings flapping vigorously. It manages to pin you to the ground, tearing at your armor. Before being crushed by the weight of the creature, you maneuver out of its grasp." } },
        { "Claw Strike", isBoss ? 14 : 10, { "The Dragon throws its sharp claws towards you, managing to snag your clothing. You are both wounded by this attack and thrown to the side." } }
    };

    runLines = {
        "The Dragon runs away screaming, 'This is not over yet. I WILL RETURN TO RAIN FIRE UPON YOU.'",
        "Realization dawns on the Dragon's face as it begins to understand its impending doom. The screech it lets out next is deafening, causing you to close your eyes and grip your head to block out some of the noise. While distracted, the Dragon makes its getaway, leaving you behind along with a trail of blood.",
        "The Dragon is furious that you are winning this battle, but fear also grips it. Instead of staying to see what you could do with your weapon, it flies away, creating a powerful gust of wind as it leaves.",
        "The Dragon scrambles away, frantically trying to leave the battlefield, realizing that staying any longer would result in its defeat."
    };

    healLines = {
        "The new wounds on the Dragon's body begin to close, new scales growing over the missing ones.",
        "After your attack, the Dragon takes in a deep breath. Wounds that had once lined its body begin to glow and heal over, giving it more energy than you wish it had.",
        "You dealt quite a lot of damage, and the Dragon notices, beginning to heal itself.",
        "Exhausted, you watch as the Dragon regenerates scales over the damage you just inflicted."
    };

    dieLines = {
        "With one last screech, the Dragon tries to knock you back from its collapsed body, but you stand strong. With your weapon, you finally take down the beast once and for all.",
        "The Dragon, once one of the loudest creatures you've encountered, is now eerily silent. In the distance, it lays lifeless, almost like it is asleep. As you approach, you realize you have won this battle.",
        "Your weapon strikes the Dragon in mid air, halting its descent. Its wings stop moving as it takes the full impact, and the Dragon falls to the ground with an earth-shaking thud.",
        "With the final hit of your weapon, the Dragon goes down. As you walk away triumphantly, its body begins to catch fire and burn to ash. You think to yourself how fitting it is for such a dramatic creature to have such a dramatic end."
    };
}
//function that returns enemy name---------
string dragon::getName() {
	if (isBoss == true) {
		return "Ancient Dragon";
	}
    else {
        return "Dragon";
    }
}
enemy* dragon::clone() const {
    return new dragon(*this);
}