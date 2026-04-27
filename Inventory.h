#pragma once
#include "Setup.h"

//header file for inventory functions

void addToInventory(Setup& setup, int itemID);
void removeFromInventory(Setup& setup, int itemID);
void printInventoryMenu(Setup& setup);
void equipItem(Setup& setup, int itemID);
void manageInventory(Setup& setup);
void refreshInv();