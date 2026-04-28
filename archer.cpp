#include <iostream>
#include <string>
#include "character.h"
#include "enemy.h"
#include "archer.h"
using namespace std;

int archer::getAssignedNum() {
    return assignedNum;
}
string archer::getAmuletMessage() const {
    return "";
}
// Constructor: initializes health, strength, defense
archer::archer() : enemy(90, 15, 10) {
    attacks = {
        { "Personal Hit", 9, { "As an arrow flies straight toward you, the Archer says, 'This one is just for you!'" } },
        { "Rapid fire", 12, { "The Archer seems upset as he shoots arrow after arrow barreling toward you. Some miss, but quite a few hit their intended target." } },
        { "Straight Shot", 10, { "The Archer lifts his bow and shoots an arrow directly at where you are standing. Anyone else might move in time, but you react too slowly and are hit. How disappointing." } },
        { "Stray Arrow", 8, { "As weak as the Archer may be, you are still struck by one of his stray arrows, boosting his already inflated ego." } }
    };

    runLines = {
        "The Archer is fleeing, too scared to continue the fight. You have won this battle.",
        "The Archer slowly backs away, looking at you with fear in his eyes. He screams, 'I am feeling nice, so I will leave you alive this once,' as he turns and runs—but you know with one more hit, he would have been dead.",
        "Just as you were about to finish the battle, the Archer throws something to the ground. Smoke fills your vision, and you hear footsteps dissipating. When the smoke clears, the Archer is nowhere to be found.",
        "Realizing the odds of victory are decreasing, the Archer decides he is not cut out for this battle and runs away. Were they always this weak? No matter—you still win."
    };

    healLines = {
        "You see the Archer reach into his pouch and take out a vial with green liquid swirling inside. He quickly drinks it, healing the wounds covering his body.",
        "The Archer fires a multitude of arrows as a distraction while taking the time to heal the damage you have done so far.",
        "The Archer glances at something nearby, picks up a bundle of berries, and swallows a few, healing wounds you hoped would have done more damage.",
        "The Archer says, 'You're the weakest person I have ever fought,' then downs a healing potion to close some of the cuts on his body."
    };

    dieLines = {
        "The Archer has succumbed to his fate. Congratulations, Player, you won this battle.",
        "You deal the final blow. With his last breath, the Archer tries to fire one final arrow, but it misses by a long shot.",
        "The Archer tries to flee, but just as he is about to escape into the woods, you land one last hit. He collapses with a thud, and you are victorious.",
        "After your last strike, the Archer falls to the ground. With his final breath, he calls this fight the most unfair battle he has ever been part of."
    };
}
//function that returns enemy name---------
string archer::getName() {
    return "Archer";
}
enemy* archer::clone() const {
    return new archer(*this);
}