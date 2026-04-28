#include "Setup.h"
#include <iostream>
#include <string>
#include "character.h"
#include "player.h"
using namespace std;

//default constructor
player::player()
    : character("Player", 100, 10, 10) {

    name = "Player";
    classType = "None";
    equippedIndex = 0;
    setGold(0);

    inventory[14] = 2;
}
// Initializes player's health, strength, and defense
player::player(string charName, string charType)
    : character(charName, 100, 0, 0) {

    name = charName;
    classType = charType;
    equippedIndex = 0;

    // ===== CLASS SETUP =====
    if (charType == "Warrior") {
        health = 100;
        strength = 18;
        defense = 30;
        inventory[1] = 1;
    }
    else if (charType == "Rogue") {
        health = 120;
        strength = 15;
        defense = 10;
        inventory[4] = 1;
    }
    else if (charType == "Hunter") {
        health = 90;
        strength = 25;
        defense = 8;
        inventory[7] = 1;
    }
    else if (charType == "Sorcerer") {
        health = 80;
        strength = 30;
        defense = 5;
        inventory[10] = 1;
    }

    inventory[14] = 2;
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
        "Oh no! You have been defeated. Slightly disappointing I thought you were better than this.",
        "You feel the damage catching up to you all at once, causing you to collapse. With no energy left, your eyes close. You lose this fight.",
        "As the enemy towers over you, your vision blurs. You face death one last time. You lose, player do better next time.",
        "You are struck down by the enemy's last attack. Helpless, you watch them walk away without remorse."
    };

    //probably have to change this part
    /*Weapon WoodenSword;
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
    equippedIndex = 0;*/

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
    }
    else {
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

void player::useHealingOption(int index, bool inBattle) {
    if (index < 0 || index >= healingOptions.size()) return;

    HealOption& potion = healingOptions[index];

    // ALWAYS apply instant healing
    gainHealth(potion.baseHeal);

    cout << "You used " << potion.name
        << "! You restored " << potion.baseHeal
        << " HP. Current HP: " << getHealth() << ".\n";

    // ONLY apply slow/over-time effect in battle
    if (inBattle && potion.healAmountPerTurn > 0) {
        slowTurnEffect_Logic(
            potion.name,
            potion.healAmountPerTurn,
            potion.durationTime
        );
    }

    // cooldown always applies
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
    // save what was equipped BEFORE clearing
    string previouslyEquippedName = "";
    if (plyr.equippedIndex >= 0 && plyr.equippedIndex < plyr.inventoryW.size()) {
        previouslyEquippedName = plyr.inventoryW[plyr.equippedIndex].name;
    }

    plyr.inventoryW.clear();

    for (const auto& pair : plyr.inventory) {

        int itemID = pair.first;
        const Item& item = setup.itemDatabase[itemID];

        if (item.type != WEAPON) continue;

        Weapon w;
        w.name = item.name;

        const weaponTemp& temp = setup.itemTemplates[itemID];
        vector<int> dmg = setup.weaponDamage[itemID];

        for (int i = 0; i < temp.attackNames.size(); i++) {
            attackMoves a;
            a.name = temp.attackNames[i];

            if (i < dmg.size())
                a.damagedone = dmg[i];
            else
                a.damagedone = 0;

            a.dialogue = { temp.dialogue[i] };
            w.currentAttacks.push_back(a);
        }

        plyr.inventoryW.push_back(w);
    }

    // restore equipped weapon if possible
    plyr.equippedIndex = -1;

    for (int i = 0; i < plyr.inventoryW.size(); i++) {
        if (plyr.inventoryW[i].name == previouslyEquippedName) {
            plyr.equippedIndex = i;
            break;
        }
    }

    // fallback if weapon no longer exists
    if (plyr.equippedIndex == -1 && !plyr.inventoryW.empty()) {
        plyr.equippedIndex = 0;
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

            plyr.useHealingOption(i, false);

            // remove from inventory
            plyr.inventory[itemID]--;
            if (plyr.inventory[itemID] == 0)
                plyr.inventory.erase(itemID);

            return;
        }
    }
    cout << "Potion not found.\n";
}

void player::giveAmulet(int id)
{
    if (id < 17 || id > 21)
        return;

    inventory[id] = 1; // mark as owned

    cout << "You obtained an AMULET!\n";

    if (id == 19)
        cout << "A poisonous energy lingers around you...\n";

    if (id == 20)
        cout << "You feel heat building in your hands...\n";
}

bool player::hasItem(int id) const
{
    auto it = inventory.find(id);
    return it != inventory.end() && it->second > 0;
}
int player::getStrength() const
{
    int bonus = 0;

    if (hasItem(18)) // Amulet of Strength
        bonus += 10;

    return strength + bonus;
}
int player::getDefense() const
{
    int bonus = 0;

    if (hasItem(17)) // Amulet of Defense
        bonus += 10;

    return defense + bonus;
}