#include "Setup.h"
#include "player.h"
#include "character.h"

//function to initialize all items in the game
void Setup::initializeItems() {
	//ID, name, price/value, type, equippable

	//WEAPON:

//swords
	itemDatabase[1] = { 1, "Wooden Sword", 50, WEAPON, true }; 
	itemDatabase[2] = { 2, "Iron Sword", 100, WEAPON, true };
	itemDatabase[3] = { 3, "Unbreakable Sword", 300, WEAPON, true }; //drop somehow
//daggers
	itemDatabase[4] = { 4, "Basic Dagger", 30, WEAPON, true }; 
	itemDatabase[5] = { 5, "Poison Dagger", 130, WEAPON, true };
	itemDatabase[6] = { 6, "Fire Dagger", 130, WEAPON, true };
//bows
	itemDatabase[7] = { 7, "Wooden Bow", 40, WEAPON, true }; 
	itemDatabase[8] = { 8, "Hunter Bow", 90, WEAPON, true };
	itemDatabase[9] = { 9, "Elven Bow", 300, WEAPON, true }; //drop somehow
//staffs (magic)
	itemDatabase[10] = { 10, "Basic Staff", 30, WEAPON, true }; 
	itemDatabase[11] = { 11, "Poison Staff", 150, WEAPON, true }; //wizard drop?
	itemDatabase[12] = { 12, "Fire Staff", 150, WEAPON, true }; //wizard drop?
	itemDatabase[13] = { 13, "Lightning Staff", 300, WEAPON, true }; //very rare wizard drop?

	//POTION:

//health potions
	itemDatabase[14] = { 14, "Small Health Potion", 20, POTION, false }; 
	itemDatabase[15] = { 15, "Large Health Potion", 60, POTION, false };
	itemDatabase[16] = { 16, "Undying Health Potion", 200, POTION, false }; //very rare find?

	//MAGIC_ITEM:

//magic amulets
	itemDatabase[17] = { 17, "Amulet of Defense", 150, MAGIC_ITEM, true }; 
	itemDatabase[18] = { 18, "Amulet of Strength", 150, MAGIC_ITEM, true };
	itemDatabase[19] = { 19, "Amulet of Poison", 200, MAGIC_ITEM, true }; //drop somehow
	itemDatabase[20] = { 20, "Amulet of Fire", 200, MAGIC_ITEM, true }; //drop somehow
	itemDatabase[21] = { 21, "Amulet of Enduring", 500, MAGIC_ITEM, true }; // very rare drop (massive boost to health)
//random magic items
	itemDatabase[22] = { 22, "Feather Pen", 10, MAGIC_ITEM, false };
	itemDatabase[23] = { 23, "Dragon Tooth", 100, MAGIC_ITEM, false };
	itemDatabase[24] = { 24, "Bottle of Light", 50, MAGIC_ITEM, false };


	// Initialize the shop inventory with item IDs and their quantities

	shopInventory[1] = 10; //wooden sword
	shopInventory[2] = 5;  //iron sword
	shopInventory[4] = 8; //basic dagger
	shopInventory[5] = 4; //poison dagger
	shopInventory[6] = 4; //fire dagger
	shopInventory[7] = 10; //wooden bow
	shopInventory[8] = 5; //hunter bow
	shopInventory[10] = 15; //basic staff
	shopInventory[14] = 20; //small health potion
	shopInventory[15] = 10; //large health potion
	shopInventory[22] = 10; //feather pen
	shopInventory[23] = 2; //dragon tooth
	shopInventory[24] = 5; //bottle of light

	//shopInventory[17] = 1; //amulet of defense
	//shopInventory[18] = 10; //amulet of strength
}

Weapon createWeapon(const weaponTemp& temp, const string& weaponName, const vector<int>& damages) {
	Weapon w;
	w.name = weaponName;
	for (int i = 0; i < temp.attackNames.size(); i++) {
		attackMoves a;
		a.name = temp.attackNames[i];
		a.damagedone = damages[i];    // damage specific to this weapon
		a.dialogue = temp.dialogue;   // shared dialogue for weapon type
		w.currentAttacks.push_back(a);
	}
	return w;
}

Setup::Setup() {
	// sword template
	swordTemp = {
		"Sword",
		{"You attack the enemy with great force, your blade striking its body.",
		 "With surprising agility, you strike the enemy with your blade. Landing a hit on its side, you quickly follow up with another as it is distracted."},
		{0, 0}, // placeholder, actual damage per weapon in weaponDamage
		{"Sword Strike", "Double Slash"}
	};

	// bow template
	bowTemp = {
		"Bow",
		{"Choosing to attack with your bow, you draw the string close to your ear, aim carefully, and release an arrow that hits directly in the target's chest.",
		 "With your bow, you hit the enemy's limb. With a cry, it is left hobbling and disoriented."},
		{0, 0}, // placeholder
		{"Piercing Shot","Glancing Arrow"}
	};

	lastingEffectTemp = {
		"Lasting Damage",
		{"As your weapon hits the enemy, you see the effects instantly. Damage starts racking the monsters body, and you know it will last longer than the other cuts.",
		"Your weapon strikes the monster right in the chest. Thats going to hurt, hopefully for a few more turns."},
		{0,0},
		{"Splintering Strike", "Everlasting Fracture"}
	};

	// map itemIDs to templates
	itemTemplates = {
		{1, swordTemp}, {2, swordTemp}, {3, swordTemp}, {4, swordTemp}, {5, lastingEffectTemp}, {6, lastingEffectTemp}, {7, bowTemp}, {8, bowTemp}, {9, bowTemp}
	};

	// assign weapon-specific damage
	weaponDamage = {
		{1, {12, 20}}, // Wooden Sword
		{2, {15, 25}}, // Iron Sword
		{3, {25, 40}}, // Unbreakable Sword
		{4, {8, 12}},  // Basic Dagger
		{5, {10, 18}}, // Poison Dagger
		{6, {12, 22}}, // Fire Dagger
		{7, {13, 12}}, // Wooden Bow
		{8, {18, 15}}, // Hunter Bow
		{9, {25, 22}}  // Elven Bow
	};
}