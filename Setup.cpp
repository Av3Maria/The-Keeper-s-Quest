#include "Setup.h"

void Setup::initializeItems() {
	//change all this, this is tester code
	// Initialize the item database with some items
	itemDatabase[1] = { 1, "Sword", 50, true }; //ID, name, price, equippable
	itemDatabase[2] = { 2, "Shield", 100, true };
	itemDatabase[3] = { 3, "Health Potion", 20, false };
	itemDatabase[4] = { 4, "Mana Potion", 40, false };
	itemDatabase[5] = { 5, "Magic Wand", 200, true };
	itemDatabase[6] = { 6, "Enchanted Armor", 500, true };

	// Initialize the shop inventory with item IDs and their quantities
	shopInventory[1] = 10; // Sword
	shopInventory[2] = 5;  // Shield
	shopInventory[3] = 20; // Health Potion
	shopInventory[4] = 15; // Mana Potion
	shopInventory[5] = 2;  // Magic Wand
	shopInventory[6] = 1;  // Enchanted Armor

	plyr.setGold(500);
}

