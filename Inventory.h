#pragma once
#include "Setup.h"

//header file for inventory functions
//add and remove items to players inventory
void addToInventory(Setup& setup, int itemID);
void removeFromInventory(Setup& setup, int itemID);
//display inventory with options for using and manage items
void printInventoryMenu(Setup& setup);
void equipItem(Setup& setup, int itemID);
void manageInventory(Setup& setup);

void refreshInv();