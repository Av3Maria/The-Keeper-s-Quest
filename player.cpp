#include "Setup.h"
#include <iostream>
#include <string>
#include "character.h"
#include "player.h"
using namespace std;

//default constructor
player::player() : character("Player", 100, 10, 10) {
    name = "Player";
    classType = "None";
    equippedIndex = -1;
}

// Initializes player's health, strength, and defense
player::player(string charName, string charType) : character(charName, 100, 18, 10) {

    name = charName;
    classType = charType;
    equippedIndex = -1;

    if (charType == "Warrior") { //high defense
        health = 100;
        strength = 18;
        defense = 30;

		inventory[1] = 1; //wooden sword
    }
    else if (charType == "Rogue") { //high health
        health = 120;
        strength = 15;
        defense = 10;

		inventory[4] = 1; //basic dagger
    }
	else if (charType == "Hunter") { //high strength
        health = 90;
        strength = 25;
        defense = 8;

		inventory[7] = 1; //wooden bow
    }
    else if (charType == "Sorcerer") { //high strength
        health = 80;
        strength = 30;
        defense = 5;

		inventory[10] = 1; //basic staff
	}

	inventory[14] = 2; //small health potion
    setGold(500);

    attacks = {
        { "Sword Strike", 12, { "You attack the enemy with great force, your blade striking its body." } },
        { "Double Slash", 20, { "With surprising agility, you strike the enemy with your blade. Landing a hit on its side, you quickly follow up with another as it is distracted." } },
        { "Piercing Shot", 13, { "Choosing to attack with your bow, you draw the string close to your ear, aim carefully, and release an arrow that hits directly in the target's chest." } },
        { "Glancing Arrow", 12, { "With your bow, you hit the enemy's limb. With a cry, it is left hobbling and disoriented." } }
    };

    runLines = {
        "Low on items or afraid to die? Whatever the reason, you choose to flee, leaving the enemy far behind as you run.",
        "Your attacks aren’t doing as much damage as hoped, so before you get hurt further, you turn and run away, stumbling over debris from the fight as you go.",
        "Panic sets in as you realize this battle is not in your favor. Limbs trembling, you scramble away as fast as your legs can carry you, the sound of the creature fading as you escape.",
        "Exhausted, you can no longer fight. You make the decision to retreat, looks like the enemy will win this one."
    };

    healingOptions = {//{"name", type, cooldown time, turns left, base healing, health points per turn, how long it lasts}
         { 14, "Small Potion", Potion, 2, 0, 0, 4, 3, 2, {"Tired from the attacks thrown at you, you reach into your pouch and take out a red potion, hoping it will give you the energy to keep going."}},
         { 15, "Large Potion", Potion, 3, 0, 0, 6, 3, 1, {"You drink a healing potion, and your body slowly begins to recover, stitching wounds and easing pain."}}

    };

    dieLines = {
        "Oh no! You have been defeated. Slightly disappointing—I thought you were better than this.",
        "You feel the damage catching up to you all at once, causing you to collapse. With no energy left, your eyes close. You lose this fight.",
        "As the enemy towers over you, your vision blurs. You face death one last time. You lose, player—do better next time.",
        "You are struck down by the enemy's last attack. Helpless, you watch them walk away without remorse."
    };
    
    //probably have to change this part
    Weapon WoodenSword;
    WoodenSword.name = "Wooden Sword";
    WoodenSword.currentAttacks = {
        { "Sword Strike", 12, { "You attack the enemy with great force, your blade striking its body." } },
        { "Double Slash", 20, { "With surprising agility, you strike the enemy with your blade. Landing a hit on its side, you quickly follow up with another as it is distracted." } }
    };
    Weapon WoodenBow;
    WoodenBow.name = "Wooden Bow";
    WoodenBow.currentAttacks = {
        { "Piercing Shot", 13, { "Choosing to attack with your bow, you draw the string close to your ear, aim carefully, and release an arrow that hits directly in the target's chest." } },
        { "Glancing Arrow", 12, { "With your bow, you hit the enemy's limb. With a cry, it is left hobbling and disoriented." } }
    };
    inventoryW.push_back(WoodenSword);
    inventoryW.push_back(WoodenBow);
    equippedIndex = 0;
    
}

void player::showInventory() {
    cout << endl << "Inventory Options: " << endl;
    for (int i = 0; i < inventoryW.size(); i++) {
        cout << i + 1 << ". " << inventoryW[i].name;
        if (i == equippedIndex) {
            cout << " is equipped";
        }
        cout << endl;
    }
}

void player::setGold(int amt) {
    ownedGold = amt;
}
int player::getOwnedGold() const {
    return ownedGold;
}
void player::modifyGold(int amount) {
    ownedGold += amount;
    if (ownedGold < 0) {
        ownedGold = 0;
    }
}
/*
void player::addToInventory(Setup& setup, int itemID) {
    inventory[itemID]++;

    const Item& item = setup.itemDatabase[itemID];

	cout << endl << "You added: " << item.name << " to your inventory." << endl;
}*/
void player::equipWeapon(int inventoryIndex) {

	if (inventoryW.empty()) {
        cout << "\nYou have no weapons to equip." << endl;
        return;
    }

    if (inventoryIndex < 0 || inventoryIndex >= inventoryW.size()) {
        cout << "\nSorry, you can't choose that." << endl;
        return;
    }

    cout << "\nUnequipping " << inventoryW[equippedIndex].name << endl;
    equippedIndex = inventoryIndex; // set new equipped weapon
    cout << "\nEquipped Weapon: " << inventoryW[equippedIndex].name << endl;
}

vector<attackMoves>& player::getcurrentAttacks() {
    static vector<attackMoves> empty;
    if (!inventoryW.empty()) {
        Weapon& currentWeapon = inventoryW[equippedIndex];
        return currentWeapon.currentAttacks;
    }else {
        return empty;
    }
}

//funciton to get players name----------
string player::getName() {
    return name;
}
void player::setName(string newName) {
    name = newName;
}
string player::getClassType() const {
    return classType;
}
void player::setClassType(string newClassType) {
    classType = newClassType;
}

void player::useHealingOption(int index) {
    if (index < 0 || index >= healingOptions.size()) return;
    HealOption& potion = healingOptions[index];
    // Apply healing
    gainHealth(potion.baseHeal);
    if (potion.healAmountPerTurn > 0)
        slowTurnEffect_Logic(potion.name, potion.healAmountPerTurn, potion.durationTime);

    cout << "You used " << potion.name << "! Your health goes up to " << getHealth() << ".\n";

    // Set cooldown AFTER using
    potion.turnRemaining = potion.optionCooldown;
}

vector<HealOption>& player::getHealingOptions() {
    return healingOptions;
}

void player::updateHealingCooldown() {
    for (HealOption& heal : healingOptions) {
        if (heal.turnRemaining > 0) {
            heal.turnRemaining -= 1;
        }
    }
}

void player::showHeallingOpt() {
    cout << "Inventory Options: " << endl;
    for (int i = 0; i < healingOptions.size(); i++) {
        cout << i + 1 << ". " << healingOptions[i].name;
        if (healingOptions[i].turnRemaining > 0) {
            cout << " has" << healingOptions[i].turnRemaining << " turns remaining.";
        }
        cout << endl;
    }
    cout << endl;
}

void player::syncWeapons(player& plyr, Setup& setup) {
    plyr.inventoryW.clear();
	//plyr.equippedIndex = -1;

    if (!plyr.inventoryW.empty()) {
        plyr.equippedIndex = 0;
    }

    // populate inventoryW from inventory
    for (const auto& pair : plyr.inventory) {
        int itemID = pair.first;
        const Item& item = setup.itemDatabase[itemID];

        if (item.type == WEAPON) {
            Weapon w;
            w.name = item.name;

            const weaponTemp& temp = setup.itemTemplates[itemID];
            for (int i = 0; i < temp.attackNames.size(); i++) {
                attackMoves a;
                a.name = temp.attackNames[i];
                a.damagedone = temp.baseDamage[i];
                a.dialogue = { temp.dialogue[i] };
                w.currentAttacks.push_back(a);
            }

            plyr.inventoryW.push_back(w);

            if (!plyr.inventoryW.empty()) {
                plyr.equippedIndex = 0; // auto-equip first weapon
            }
            else {
                plyr.equippedIndex = -1;
            }
        }
    }
}

HealOption& player::getPotionFromItemID(int itemID) {
    for (HealOption& heal : healingOptions) {
        if (heal.itemID == itemID) {  // we need to add `itemID` field to HealOption
            return heal;
        }
    }
    throw std::runtime_error("Potion not found for itemID!");
}

void player::syncPotion(player& plyr, Setup& setup, int itemID) {
    if (plyr.inventory[itemID] <= 0) {
        cout << "You don't have that potion!\n";
        return;
    }
    for (int i = 0; i < plyr.getHealingOptions().size(); i++) {
        if (plyr.getHealingOptions()[i].itemID == itemID) {

            plyr.useHealingOption(i);

            // remove from inventory
            plyr.inventory[itemID]--;
            if (plyr.inventory[itemID] == 0)
                plyr.inventory.erase(itemID);

            return;
        }
    }
    cout << "Potion not found.\n";
}