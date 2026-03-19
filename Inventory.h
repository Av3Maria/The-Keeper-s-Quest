#pragma once
#include "Setup.h"
#include <iostream>
#include <string>
#include <unordered_map>

class Setup;

void addToInventory(Setup& setup, int itemID);
void removeFromInventory(Setup& setup, int itemID);
void printInventoryMenu(Setup& setup);
void equipItem(Setup& setup, int itemID);
void manageInventory(Setup& setup);

void refreshInv();