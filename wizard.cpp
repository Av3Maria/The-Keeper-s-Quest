#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "wizard.h"
using namespace std;

int wizard::getAssignedNum() {
    return assignedNum;
}
string wizard::getAmuletMessage() const {
    return " "; //--------------------------------------------------------------------------------------
}
// Constructor: initializes health, strength, defense
wizard::wizard(bool bossMode) : enemy(100, 18, 10), isBoss(bossMode) {

    if (isBoss) {
        health = 160;
        strength = 28;
        defense = 15;
    }
    attacks = {
        { "Cascading Fire", isBoss ? 18 : 12, { "The Wizard snaps their fingers, calling forth a spell that sends fire crawling up from the ground beneath you. The heat radiating from the flames burns through your clothing, leaving painful marks." } },
        { "WhirlWind", isBoss ? 14 : 8, { "You see the Wizard whispering a foreign chant. Fear grips you as you try to run, but you are caught. Frozen mid-stride, the Wizard blasts you with an enormous gust of wind, throwing you to the ground." } },
        { "Lightning Clash", isBoss ? 28 : 20, { "Thunder cracks above your fight. A blinding white light erupts from the clouds, temporarily stunning you. At this moment of weakness, the Wizard attacks, shooting smaller bolts of lightning at you, causing further damage." } },
        { "Sparking Cloud", isBoss ? 22 : 15, { "The air around you thickens, making it hard to breathe. Smoke fills your vision, and although you cannot see, the Wizard snaps his fingers, igniting the cloud in fire." } }
    };

    runLines = {
        "You have significantly weakened the Wizard. With one last hit, the fight should be over."
    };

    healLines = {
        "The battle has not lasted long, but you are already exhausted from the Wizard's attacks. As he heals his wounds, you are thankful for the brief break to catch your breath.",
        "A book appears before the Wizard. As he reads from it, smoke emits from his skin, knitting closed his wounds.",
        "After your strike lands, the Wizard takes out a green potion and drinks the slimy liquid, healing his injuries.",
        "Preparing for another attack, you watch as the Wizard begins to glow. Cuts and scratches knit back together, restoring his strength for the fight."
    };

    dieLines = {
        " "//--------------------------------------------------------------------------------------
    };
}
//function that returns enemy name---------
string wizard::getName() {
    return "Wizard";
}
enemy* wizard::clone() const {
    return new wizard(*this);
}
