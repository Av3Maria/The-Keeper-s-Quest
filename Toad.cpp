#include <iostream>
#include <string>
#include "Toad.h"
using namespace std;

int toad::getAssignedNum() {
    return assignedNum;
}
string toad::getAmuletMessage() const {
    return "Looks like its large body had been sitting on something, a shiny lays in its wake. After slipping the shard into your pocket you feel a sense of power sink into your muscles. You receive and Amulet of Strength.";
}
toad::toad(bool bossMode) : enemy(70, 20, 8), isBoss(bossMode) {

    //Boss scaling
    if (isBoss) {
        health = 120;
        strength = 30;
        defense = 15;
    }

    attacks = {
        { "Tongue Lash", isBoss ? 16 : 10,
            { "The Toad lashes out violently with its tongue." } },

        { "Swamp Slam", isBoss ? 22 : 14,
            { "The ground shakes as the Toad crashes down." } },

        { "Poison Puff", isBoss ? 18 : 12,
            { "A massive toxic cloud erupts from its body." } },

        { "Croak Shock", isBoss ? 24 : 16,
            { "The air vibrates violently from its devastating croak." } }
    };

    runLines = {
        "The Toad escapes into the depths.",
        "It vanishes beneath the swamp.",
        "The water swallows it whole.",
        "It flees into the murky lake."
    };

    healLines = {
        "The swamp restores its power.",
        "It regains strength in the water.",
        "Mud and water heal its wounds.",
        "The environment sustains it."
    };

    dieLines = {
        "The Toad collapses into the swamp.",
        "It sinks beneath the water, defeated.",
        "The swamp goes still.",
        "Its body disappears below the surface."
    };
}

string toad::getName() {
    if (isBoss == true) {
		return "Giant Toad";
    }
    else {
        return "Toad";
    }
}

enemy* toad::clone() const {
    return new toad(*this);
}