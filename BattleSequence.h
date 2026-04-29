#pragma once
#include "player.h"
#include "enemy.h"
#include "Map.h"

enum BattleResults {
	continueTurn,
	IgnoreAction,
	EndBattle
};

void clearInput();
void bossIntro(enemy& Enemy);
void wizardVictoryEnding(Setup& setup, Map& map);
int enterBattle(Setup& setup, Map& map, enemy* Enemy, Tile* tile = nullptr);
int print_battlemenu(player& plyr);
BattleResults battle_choices(Setup& setup, int user_choice, player& plyr, enemy& Enemy);
int print_stats(player& p, enemy& e);
int enemyAction(enemy& enemy, player& plyr);
bool HealthCheck(player& plyr);
