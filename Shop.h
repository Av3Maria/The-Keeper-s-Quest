#pragma once
#include "Setup.h"

//header file for shop functions

void enterShop(Setup& setup);
void purchaseItem(Setup& setup, int itemID);
void sellItem(Setup& setup);
int displayShopMenu(Setup& setup);
void displayType(Setup& setup, ItemType type);
void refreshShop();