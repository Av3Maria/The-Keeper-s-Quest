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
string monsterBug::getAmuletMessage() const {
    return "Bugs of different sizes and shapes come grab the body of the thing you just fought and drag its remains into the thick brush, leaving behind something green and shiny. As you grab onto it you feel a wave of nausea run over your body. You obtained the Amulet shard of poison. ";
}
// Constructor: initializes health, strength, defense
monsterBug::monsterBug(bool bossMode) : enemy(65, 12, 10), isBoss(bossMode) {

    if (isBoss) {
        health = 110;
        strength = 20;
        defense = 14;
    }
    attacks = {
        { "Swarm Bite", isBoss ? 15 : 10, { "The bug calls upon others like him. Spiders, ants, and other forest floor critters surround you on all sides! They attack, biting at your ankles and crawling up you, leaving more damage in their wake." } },
        { "Claw Strike", isBoss ? 12 : 8, { "The bug, as small as it may be, still packs a surprising amount of strength. Without time to dodge, you get hit by too many limbs to count." } },
        { "Venom Masticate", isBoss ? 22 : 15, { "Enraged, the bug tries to take a bite out of your arm. Although it fails to rip anything off, the sting it leaves behind still hurts." }, "Poision", -5, 3 },
        { "Flying Swipe", isBoss ? 14 : 10, { "The bug flies straight at you and grabs onto your arms, lifting you into the air. As it tries to fly even higher, you slip out of its grasp and hit the ground hard." } }
    };

    runLines = {
        "The bug stops attacking, turning around and scurrying away as fast as its tiny legs can go.",
        "The bug scuttles away. You hear nothing from its motion and wonder how you will detect its return.",
        "Recognizing that this battle is futile, the bug backs up, then flies away, leaving you far behind.",
        "Just as you were about to go for the last hit, the bug panics and digs into the ground, leaving you standing there confused."
    };

    healLines = {
        "The bug begins to heal itself from the damage you inflicted. You watch in disgust as its gashes close back together.",
        "You see the creature convulse as broken limbs regenerate and scratches and cuts close.",
        "The creature heals itself, reducing all the damage you had done so far to scars and newly reformed limbs.",
        "The bug slowly backs away, trying to heal as much as it can in the little time you give it."
    };

    dieLines = {
        "The bug, as weak as it was, fought to its last breath. Despite the struggle, you emerge victorious. Congratulations!",
        "As you strike the bug's shell, you hear a sickening crack. Its hard exterior splits open, killing it instantly. You win this battle.",
        "Just as the creature was about to flee, you deliver the final blow, cutting off any escape. With its small wings rendered useless, the bug finally perishes.",
        "You hit the bug, sending it flying across the battlefield. It crashes to the ground with a loud crunch, dying on impact. Victory is yours."
    };
}
//function that returns enemy name---------
string monsterBug::getName() {
    if (isBoss == true) {
        return "Giant Bug";
    }
    else {
        return "Monster Bug";
    }
}
enemy* monsterBug::clone() const {
    return new monsterBug(*this);
}