#include "Setup.h"

void Setup::initializeItems() {
	//ID, name, price/value, equippable
	
	// Initialize the item database with some items

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

//health potions
	itemDatabase[14] = { 14, "Small Health Potion", 20, POTION, false }; 
	itemDatabase[15] = { 15, "Large Health Potion", 60, POTION, false };
	itemDatabase[16] = { 16, "Undying Health Potion", 200, POTION, false }; //very rare find?

//magic amulets
	itemDatabase[17] = { 17, "Amulet of Defense", 150, MAGIC_ITEM, true }; 
	itemDatabase[18] = { 18, "Amulet of Strength", 150, MAGIC_ITEM, true };
	itemDatabase[19] = { 19, "Amulet of Poison", 200, MAGIC_ITEM, true }; //drop somehow
	itemDatabase[20] = { 20, "Amulet of Fire", 200, MAGIC_ITEM, true }; //drop somehow
	itemDatabase[21] = { 21, "Amulet of Enduring", 500, MAGIC_ITEM, true }; // very rare drop (massive boost to health)


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
	//shopInventory[17] = 1; //amulet of defense
	//shopInventory[18] = 10; //amulet of strength


	mainPlayer.setGold(500);
}

