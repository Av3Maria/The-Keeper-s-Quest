#include <iostream>
#include <string>
#include "character.h"
#include "player.h"
using namespace std;


//rewrite and fix
void player::setGold(int amt) {
	ownedGold = amt;
}
int player::getOwnedGold() const {
    return ownedGold;
}

void player::addToInventory(int itemID) {
    // For now, just print a message or add logic as needed
    // Example: Add a placeholder weapon with the itemID as its name
    Weapon newWeapon;
    newWeapon.name = "Item " + std::to_string(itemID);
    inventory.push_back(newWeapon);
}
void player::modifyGold(int amount) {
    ownedGold += amount;
    if (ownedGold < 0) {
        ownedGold = 0;
    }
}



// Initializes player's health, strength, and defense
player::player() : character("Player", 100, 18, 10) {

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
        "Exhausted, you can no longer fight. You make the decision to retreat—looks like the enemy will win this one."
    };

    healLines = {
        "Tired from the attacks thrown at you, you reach into your pouch and take out a red potion, hoping it will give you the energy to keep going.",
        "New wounds cover your body, but adrenaline kicks in, allowing you to ignore most of the damage.",
        "You drink a healing potion, and your body slowly begins to recover, stitching wounds and easing pain.",
        "Potions become your best friend. You take out a vial of red liquid, drink it, and watch as your cuts begin to close. A strange, almost magical sensation fills you."
    };

    dieLines = {
        "Oh no! You have been defeated. Slightly disappointing—I thought you were better than this.",
        "You feel the damage catching up to you all at once, causing you to collapse. With no energy left, your eyes close. You lose this fight.",
        "As the enemy towers over you, your vision blurs. You face death one last time. You lose, player—do better next time.",
        "You are struck down by the enemy's last attack. Helpless, you watch them walk away without remorse."
    };
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
    inventory.push_back(WoodenSword);
    inventory.push_back(WoodenBow);
    equippedWeapon = &inventory[0];
}

void player::showInventory() {
    cout << endl << "Inventory Options: " << endl;
    for (int i = 0; i < inventory.size(); i++) {
        cout << i + 1 << ". " << inventory[i].name;
        if (&inventory[i] == equippedWeapon) {
            cout << " is equipped";
        }
        cout << endl;
    }
}

void player::addToInventory(Setup& setup, int itemID) {
    inventory[itemID]++;

    const Item& item = setup.itemDatabase[itemID];

	cout << endl << "You added: " << item.name << " to your inventory." << endl;
    }
    else {
        cout << endl << "You chose to equip " << equippedWeapon->name << endl;
    }
}

vector<attackMoves>& player::getcurrentAttacks() {
    static vector<attackMoves> emptyAttacks;
    if (equippedWeapon) {
        return equippedWeapon->currentAttacks;
    }
    else {
        return emptyAttacks;
    }
}

//funciton to get players name----------
string player::getName() {
    return "player";
}