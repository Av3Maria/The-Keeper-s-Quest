#pragma once
#include "Setup.h"
#include <iostream>
#include <unordered_map>

class Setup;

void enterShop(Setup& setup);
void purchaseItem(Setup& setup, int itemID);
void sellItem(Setup& setup);
void displayShopMenu(Setup& setup);
void displayType(Setup& setup, ItemType type);

