#pragma once
#include <iostream>
#include "talkingNPC.h"
#include "Setup.h"
#include "enemy.h"
#include "Shop.h"
#include <vector>
#include <string>
class Map;
using namespace std;

enum ShardType {
    COMBAT,
    DIALOGUE,
    SHOP_EVENT
};

class Tile {
public:
    //tile and data saved onto tile (shard and characters)
    Tile(Tile* right = nullptr, Tile* left = nullptr, Tile* up = nullptr, Tile* below = nullptr, string name = "", string description = "");
    Tile* right_tile;
    Tile* left_tile;
    Tile* up_tile;
    Tile* down_tile;
    string name;
    string description;

    vector<talkingNPC*> npcs;
    vector<enemy*> enemies;
    enemy* getRandomEnemy();
    void addNPC(talkingNPC* npc) {
        npcs.push_back(npc);
    }
    void addEnemy(enemy* enemyy) {
        enemies.push_back(enemyy);
    }
    int x = -1;
    int y = -1;

    ShardType shardType;
    bool hasShard = false;
    int shardID = -1;
    bool shardCollected = false;
    bool shardHintShown = false;

    void execLocation(Setup& setup, Map& map);
    bool allowRandomEncounters = true;
    bool hasBossBattleOption = true;
    bool hasBattleOption = true;
    bool hasFixedBoss = false;
    enemy* fixedEnemy = nullptr;

    bool hasShop = false;
    bool canBattle = true;
    bool isShop2 = false;
    bool isBridge = false;
};

class Map {
public:
    Map();
    //tracker for tile player has visited
    Tile* startTile;
    Tile* currentTile;
    Tile* previousTile;
    Tile* getTile(int x, int y);

    //assign characters to tile
    void assignCharacters();

    //run through game
    int returnToOverworld(Setup& setup);
    void enterShop(Setup& setup, Tile* tile);
    void tryBattle(Setup& setup, Tile* tile);

    //display map
    void displayMap();
    string formatTile(Tile* tile, int width);

private:
    //tiles for map
    Tile* woods1;
    Tile* woods2;
    Tile* woods3;
    Tile* woods4;
    Tile* woods5;
    Tile* woods6;
    Tile* woods7;
    Tile* woods8;

    Tile* dragonsDen;
    Tile* lake;
    Tile* bridge;
    Tile* castle;
    Tile* town;

    Tile* shop1;
    Tile* shop2;
    Tile* shop3;
};


