#pragma once
#include "Setup.h"
#include "Map.h"
#include <iostream>
#include <unordered_map>

//header file for shop functions

void purchaseItem(Setup& setup, int itemID);
void sellItem(Setup& setup);
int displayShopMenu(Setup& setup, ShopKeeper& npc, Map& map);
void displayType(Setup& setup, ItemType type);
void showInventoryPreview(Setup& setup);
