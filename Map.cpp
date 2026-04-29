#include "Map.h"
#pragma once
#include "inventory.h"
#include "Shop.h"
#include "dragon.h"
#include "Toad.h"
#include "monsterBug.h"
#include "archer.h"
#include "talkingNPC.h"
#include "BattleSequence.h"
#include "wizard.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//pointers for each tile
void connect(Tile* t, Tile* up, Tile* down, Tile* left, Tile* right) {
    t->up_tile = up;
    t->down_tile = down;
    t->left_tile = left;
    t->right_tile = right;
}
//tile data
Tile::Tile(Tile* right, Tile* left, Tile* up, Tile* down,
    string name, string description)
{
    this->right_tile = right;
    this->left_tile = left;
    this->up_tile = up;
    this->down_tile = down;

    this->name = name;
    this->description = description;

    this->shardType = COMBAT;
    this->hasShard = false;
    this->shardID = -1;
    this->shardCollected = false;
    this->shardHintShown = false;

    this->allowRandomEncounters = true;
    this->hasFixedBoss = false;
    this->fixedEnemy = nullptr;

}
//map and each name,description, has shard
Map::Map() {
    //tiles and their names
    town = new Tile(nullptr, nullptr, nullptr, nullptr, "Town", "The starting point of your adventure.");
    lake = new Tile(nullptr, nullptr, nullptr, nullptr, "Lake", "A calm lake glistening in the sun.");
    woods1 = new Tile(nullptr, nullptr, nullptr, nullptr, "Woods", "A dark forest full of mysteries.");
    woods2 = new Tile(nullptr, nullptr, nullptr, nullptr, "Woods", "Thick trees surround you.");
    woods3 = new Tile(nullptr, nullptr, nullptr, nullptr, "Woods", "You hear distant howls here.");
    woods4 = new Tile(nullptr, nullptr, nullptr, nullptr, "Woods", "The path splits ahead.");
    woods5 = new Tile(nullptr, nullptr, nullptr, nullptr, "Woods", "You feel a chill in the air.");
    woods6 = new Tile(nullptr, nullptr, nullptr, nullptr, "Woods", "Thick trees surround you.");
    woods7 = new Tile(nullptr, nullptr, nullptr, nullptr, "Woods", "A dark forest full of mysteries.");
    woods8 = new Tile(nullptr, nullptr, nullptr, nullptr, "Woods", "You hear distant howls here.");
    dragonsDen = new Tile(nullptr, nullptr, nullptr, nullptr, "Dragon's Den", "A fierce dragon sleeps here.");
    bridge = new Tile(nullptr, nullptr, nullptr, nullptr, "Bridge", "A bridge connecting the two islands.");
    castle = new Tile(nullptr, nullptr, nullptr, nullptr, "Castle", "An imposing castle looms ahead.");
    shop1 = new Tile(nullptr, nullptr, nullptr, nullptr, "Shop", "A small merchant's shop.");
    shop2 = new Tile(nullptr, nullptr, nullptr, nullptr, "Shop", "Another shop with rare items.");
    shop3 = new Tile(nullptr, nullptr, nullptr, nullptr, "Shop", "Another shop. You were hoping to find one of these.");
    //where each tile leads
    connect(woods1, dragonsDen, lake, nullptr, woods3); // tile, up, down, left, right
    connect(woods2, woods3, nullptr, lake, bridge);
    connect(woods3, shop1, woods2, woods1, woods5);
    connect(woods4, nullptr, shop1, nullptr, nullptr);
    connect(woods5, woods6, bridge, woods3, shop2);
    connect(woods6, nullptr, woods5, shop1, nullptr);
    connect(woods7, bridge, nullptr, nullptr, shop3);
    connect(woods8, nullptr, nullptr, shop3, nullptr);
    connect(shop1, woods4, woods3, dragonsDen, woods6);
    connect(shop2, nullptr, nullptr, woods5, nullptr);
    connect(shop3, nullptr, castle, woods7, woods8);
    connect(dragonsDen, nullptr, woods1, nullptr, shop1);
    connect(lake, woods1, town, nullptr, woods2);
    connect(town, lake, nullptr, nullptr, nullptr);
    connect(bridge, woods5, woods7, woods2, nullptr);
    connect(castle, shop3, nullptr, nullptr, nullptr);
    startTile = town;
    currentTile = startTile;
    previousTile = nullptr;

    //check if tile has shop option
    town->hasShop = true;
    shop1->hasShop = true;
    shop2->hasShop = true;
    shop3->hasShop = true;
    //check if tile is bridge
    bridge->isBridge = true;
    //check if tile has an amulet shard
    town->shardType = DIALOGUE;
    town->hasShard = true;
    town->shardID = 1;
    shop2->shardType = SHOP_EVENT;
    shop2->hasShard = true;
    shop2->shardID = 2;
    woods3->shardType = COMBAT;
    woods3->hasShard = true;
    woods3->shardID = 3;
    dragonsDen->shardType = COMBAT;
    dragonsDen->shardID = 4;

    //for map placment, coordinates of each
    shop1->x = 1; shop1->y = 1;
    shop2->x = 3; shop2->y = 2;
    shop3->x = 3; shop3->y = 4;

    woods1->x = 0; woods1->y = 2;
    woods2->x = 1; woods2->y = 3;
    woods3->x = 1; woods3->y = 2;
    woods4->x = 1; woods4->y = 0;
    woods5->x = 2; woods5->y = 2;
    woods6->x = 2; woods6->y = 1;
    woods7->x = 2; woods7->y = 4;
    woods8->x = 4; woods8->y = 4;

    town->x = 0; town->y = 4;
    castle->x = 3; castle->y = 5;
    dragonsDen->x = 0; dragonsDen->y = 1;
    lake->x = 0; lake->y = 3;
    bridge->x = 2; bridge->y = 3;

}
//add npcs and enemies
void Map::assignCharacters() {
    ShopKeeper* shopKeeper = new ShopKeeper();
    Blacksmith* blacksmith = new Blacksmith();
    Banker* banker = new Banker();
    Beggar* beggar = new Beggar();
    Townsfolk* townsfolk = new Townsfolk();
    Knight* knight = new Knight();
    Farmer* farmer = new Farmer();

    town->addNPC(shopKeeper);
    town->addNPC(banker);
    town->addNPC(blacksmith);
    town->addNPC(beggar);
    town->addNPC(townsfolk);
    town->addNPC(knight);
    town->addNPC(farmer);

    woods1->addNPC(townsfolk);
    woods1->addNPC(knight);
    woods1->addNPC(farmer);

    woods2->addNPC(townsfolk);
    woods2->addNPC(knight);
    woods2->addNPC(farmer);

    woods3->addNPC(townsfolk);
    woods3->addNPC(knight);
    woods3->addNPC(farmer);

    woods4->addNPC(townsfolk);
    woods4->addNPC(knight);
    woods4->addNPC(farmer);

    woods5->addNPC(townsfolk);
    woods5->addNPC(knight);
    woods5->addNPC(farmer);

    woods6->addNPC(townsfolk);
    woods6->addNPC(knight);
    woods6->addNPC(farmer);

    woods7->addNPC(townsfolk);
    woods7->addNPC(knight);
    woods7->addNPC(farmer);

    woods8->addNPC(townsfolk);
    woods8->addNPC(knight);
    woods8->addNPC(farmer);

    shop1->addNPC(shopKeeper);
    shop1->addNPC(banker);

    shop2->addNPC(shopKeeper);
    shop2->addNPC(blacksmith);

    shop3->addNPC(shopKeeper);
    shop3->addNPC(beggar);

    lake->addNPC(townsfolk);
    lake->addNPC(knight);
    lake->addNPC(farmer);

    bridge->addNPC(townsfolk);
    bridge->addNPC(knight);
    bridge->addNPC(banker);

    shop2->isShop2 = true;

    woods1->addEnemy(new dragon(false));
    woods1->addEnemy(new monsterBug(false));
    woods1->addEnemy(new archer());

    woods2->addEnemy(new monsterBug(false));
    woods2->addEnemy(new archer());

    woods3->addEnemy(new monsterBug(false));
    woods3->addEnemy(new archer());
    woods3->addEnemy(new dragon(false));

    woods4->addEnemy(new monsterBug(false));
    woods4->addEnemy(new toad(false));

    woods5->addEnemy(new archer());
    woods5->addEnemy(new monsterBug(false));

    woods7->addEnemy(new archer());
    woods7->addEnemy(new monsterBug(false));

    woods8->addEnemy(new dragon(false));
    woods8->addEnemy(new archer());
    lake->addEnemy(new toad(false));

    //add boss enemies
    dragonsDen->hasFixedBoss = true;
    dragonsDen->fixedEnemy = new dragon(true);
    dragonsDen->hasBossBattleOption = false;

    castle->hasBossBattleOption = false;
    castle->hasFixedBoss = true;
    castle->fixedEnemy = new wizard(true);

    woods6->hasBossBattleOption = false;
    woods6->hasFixedBoss = true;
    woods6->fixedEnemy = new monsterBug(true);

    lake->hasBossBattleOption = false;
    lake->hasFixedBoss = true;
    lake->fixedEnemy = new toad(true);
}
//player moves
void Tile::execLocation(Setup& setup, Map& map) {

    if (isBridge) 
    {
        int amulets = 0;

        for (int id = 17; id <= 21; id++)
        {
            amulets += setup.mainPlayer.inventory[id];
        }

        if (amulets < 4)
        {
            cout << "\nYou step onto the bridge...\n";
            cout << "It groans under your weight.\n\n";

            cout << "A strange force warns you:\n";
            cout << "\"You do not yet possess all the amulets.\"\n";
            cout << "\"This path may not end well.\"\n\n";

            cout << "Do you want to continue?\n";
            cout << "1. Yes\n2. No\n";

            int choice;
            cin >> choice;

            if (choice != 1)
            {
                cout << "\nYou step back from the bridge.\n";

                if (map.previousTile != nullptr)
                    map.currentTile = map.previousTile;

                return;
            }
        }
    }

    if (hasFixedBoss && fixedEnemy != nullptr) {
        //warn player of boss battle
        cout << "\nYou feel a powerful presence here...\n";
        cout << "Do you want to proceed?\n";
        cout << "1. Yes\n";
        cout << "2. No (go back)\n";

        int choice;
        cin >> choice;

        if (choice == 2) {
            cout << "You decide to step away...\n";

            if (map.previousTile != nullptr)
                map.currentTile = map.previousTile;

            return;
        }

        cout << "\nThe battle begins!\n";

        enterBattle(setup, map, nullptr, this);

        return;
    }

    cout << "\nThe area seems calm... but danger could be nearby.\n";
}
//game logic
int Map::returnToOverworld(Setup& setup) {

    bool inWorld = true;

    while (inWorld) {

        system("cls");
        Tile* t = currentTile;

        cout << "---------------------\n";
        cout << "Location: " << t->name << endl;
        cout << t->description << endl;
        cout << "---------------------\n";

        int option = 1;

        cout << "\nWhat would you like to do?\n";
        //ask player and give menu that chnages based on what tile has
        cout << " " << option++ << ". Move\n";

        bool canTalk = !currentTile->npcs.empty();
        bool canShop = currentTile->hasShop;

        int talkOption = -1;
        int shopOption = -1;
        int inventoryOption = -1;
        int exitOption = -1;
        //if npcs exist
        if (canTalk) {
            talkOption = option;
            cout << " " << option++ << ". Talk\n";
        }
        //if shop exists
        if (canShop) {
            shopOption = option;
            cout << " " << option++ << ". Shop\n";
        }
        //access inventory
        inventoryOption = option;
        cout << " " << option++ << ". Inventory\n";
        //if battle is an option
        bool canBattle = currentTile->hasBattleOption;
        int battleOption = -1;
        if (canBattle) {
            battleOption = option;
            cout << " " << option++ << ". Battle\n";
        }
        //open map
        int mapOption = option;
        cout << " " << option++ << ". View Map\n";
        //exit game
        exitOption = option;
        cout << " " << option++ << ". Exit to Save Menu\n";

        int choice;
        cin >> choice;
        system("cls");

        if (choice == 1) {
            cout << "\nWhere do you want to go?\n";

            if (t->up_tile) cout << " 1. Up\n";
            if (t->down_tile) cout << " 2. Down\n";
            if (t->left_tile) cout << " 3. Left\n";
            if (t->right_tile) cout << " 4. Right\n";

            int move;
            cin >> move;
            system("cls");

            if (move == 1 && t->up_tile) {
                previousTile = currentTile;
                currentTile = t->up_tile;
            }
            else if (move == 2 && t->down_tile) {
                previousTile = currentTile;
                currentTile = t->down_tile;
            }
            else if (move == 3 && t->left_tile) {
                previousTile = currentTile;
                currentTile = t->left_tile;
            }
            else if (move == 4 && t->right_tile) {
                previousTile = currentTile;
                currentTile = t->right_tile;
            }

            currentTile->execLocation(setup, *this);
            tryBattle(setup, currentTile);

        }
        //npc tlaking
        else if (choice == talkOption) {

            Tile* t = currentTile;

            if (t->npcs.empty()) {
                cout << "\nThere is no one here.\n";
            }
            else {
                cout << "\nWho do you want to talk to?\n";

                for (int i = 0; i < t->npcs.size(); i++) {
                    cout << i + 1 << ". " << t->npcs[i]->getName() << endl;
                }

                int npcchoice;
                cin >> npcchoice;

                if (npcchoice > 0 && npcchoice <= t->npcs.size()) {
                    t->npcs[npcchoice - 1]->printLines(0, setup, *this);
                }
                else {
                    cout << "\nInvalid choice.\n";
                }
            }
        }
        //shop options
        else if (choice == shopOption) {
            if (currentTile->hasShop) {
                enterShop(setup, currentTile);
            }
            else {
                cout << "There is no shop here.\n";
            }

        }
        else if (choice == inventoryOption) {
            manageInventory(setup);

        }
        else if (choice == battleOption) {
            enterBattle(setup, *this, nullptr);
        }
        else if (choice == mapOption) {
            displayMap();
        }
        else if (choice == exitOption) {
            inWorld = false;
        }

    }

    return 0;
}
//when player chooses to enter shop
void Map::enterShop(Setup& setup, Tile* tile)
{
    if (tile->name != "Shop" && tile->name != "Town") {
        cout << "There is no shop here.\n";
        return;
    }

    if (tile == shop2)
    {
        if (!setup.amuletFromBeggarReceived)
        {
            cout << "\nShopkeeper: I heard you refused the beggar...\n";
            cout << "You can still buy the amulet here.\n";

            if (setup.amuletAvailableInShop2)
            {
                setup.shopInventory[17] = 1;
            }
        }
    }
    ShopKeeper* sk = nullptr;

    for (auto* npc : tile->npcs) {
        sk = dynamic_cast<ShopKeeper*>(npc);
        if (sk) break;
    }

    if (sk) {
        displayShopMenu(setup, *sk, *this);
    }
}
//random enemies can appear
enemy* Tile::getRandomEnemy()
{
    if (enemies.empty()) return nullptr;

    enemy* chosen = nullptr;

    while (chosen == nullptr)
    {
        int index = rand() % enemies.size();

        if (enemies[index]->getName() != "Knight")
            chosen = enemies[index];
    }

    return chosen;
}
//if battle is chosen/radom enemy
void Map::tryBattle(Setup& setup, Tile* tile)
{
    if (!tile->allowRandomEncounters) return;

    int chance = rand() % 100;

    if (chance < 20)
    {
        cout << "\nA wild enemy appears!\n";
        enterBattle(setup, *this, nullptr, tile);
    }
}
//get tile for map
Tile* Map::getTile(int x, int y) {
    vector<Tile*> all = {
        town, lake, woods1, woods2, woods3, woods4,
        woods6, woods5, woods7, woods8,
        shop1, shop2, shop3,
        bridge, castle, dragonsDen
    };
    for (auto* t : all)
    {
        if (t->x == x && t->y == y)
        {
            return t;
        }
    }
    return startTile;
}
//display map
string Map::formatTile(Tile* tile, int width)
{
    string tileName;

    if (tile == nullptr)
    {
        tileName = ""; 
    }
    else
    {
        tileName = tile->name;

        if (tile == currentTile)
            tileName = "***" + tileName + "***";
    }


    while (tileName.length() < width)
        tileName += " ";

    return tileName;
}

void Map::displayMap()
{
    system("cls");

    const int W = 16;

    cout << "\n=========== WORLD MAP ===========\n\n";

    const int ROWS = 6;
    const int COLS = 5;

    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            Tile* found = nullptr;

            vector<Tile*> all = {
                town, lake, woods1, woods2, woods3, woods4,
                woods6, woods5, woods7, woods8,
                shop1, shop2, shop3,
                bridge, castle, dragonsDen
            };

            for (auto* t : all)
            {
                if (t->x == x && t->y == y)
                {
                    found = t;
                    break;
                }
            }

            cout << "[" << formatTile(found, W) << "]";
        }

        cout << "\n\n";
    }

    cout << "\n=================================\n";
    cout << "\nPress Enter...\n";
    cin.ignore();
    cin.get();
}

