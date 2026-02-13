#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "wizard.h"
using namespace std;

int wizard::getAssignedNum() {
    return assignedNum;
}
// Constructor: initializes health, strength, defense
wizard::wizard() : enemy(100, 18, 10) {
    attacks = {
        { "Cascading Fire", 12, { "The Wizard snaps their fingers, calling forth a spell that sends fire crawling up from the ground beneath you. The heat radiating from the flames burns through your clothing, leaving painful marks." } },
        { "WhirlWind", 8, { "You see the Wizard whispering a foreign chant. Fear grips you as you try to run, but you are caught. Frozen mid-stride, the Wizard blasts you with an enormous gust of wind, throwing you to the ground." } },
        { "Lightning Clash", 20, { "Thunder cracks above your fight. A blinding white light erupts from the clouds, temporarily stunning you. At this moment of weakness, the Wizard attacks, shooting smaller bolts of lightning at you, causing further damage." } },
        { "Sparking Cloud", 15, { "The air around you thickens, making it hard to breathe. Smoke fills your vision, and although you cannot see, the Wizard snaps his fingers, igniting the cloud in fire." } }
    };

    runLines = {
        "The Wizard retreats, screaming about revenge as he flees.",
        "The Wizard seems frozen in place, so you strike. As your weapon hits, his form disperses into thick black smoke. You search the battlefield, but the real Wizard is gone.",
        "With a panicked shout, the Wizard turns and bolts. He takes out a bottle of black, sludge-like liquid and drinks it frantically. In an instant, he vanishes. You have won this battle.",
        "You have significantly weakened the Wizard. With one last hit, the fight should be over. Sensing this, he flees into the nearby woods, escaping his impending death."
    };

    healLines = {
        "The battle has not lasted long, but you are already exhausted from the Wizard's attacks. As he heals his wounds, you are thankful for the brief break to catch your breath.",
        "A book appears before the Wizard. As he reads from it, smoke emits from his skin, knitting closed his wounds.",
        "After your strike lands, the Wizard takes out a green potion and drinks the slimy liquid, healing his injuries.",
        "Preparing for another attack, you watch as the Wizard begins to glow. Cuts and scratches knit back together, restoring his strength for the fight."
    };

    dieLines = {
        "You deliver your final hit. The Wizard, unable to defend himself, takes it fully and perishes, fading into black mist.",
        "A sickening crack rings out as your strike breaks through the Wizard's shield. Before he can react, you end it—killing the mage and claiming victory.",
        "Just as you were about to give up on this endless battle, the Wizard collapses. You creep closer to the pile of robes on the ground, but he is gone. You can only hope he has finally met his end.",
        "With one last strike, the Wizard collapses completely. He melts into the ground, leaving dying plants and newly formed weeds in his wake."
    };
}
//function that returns enemy name---------
string wizard::getName() {
    return "Wizard";
}

