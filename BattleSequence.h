#pragma once
//#include "Setup.h"
#include "player.h"
#include "enemy.h"

//class Setup;

enum BattleResults {
	continueTurn,
	IgnoreAction,
	EndBattle
};

int enterBattle(Setup& setup, enemy* customEnemy = nullptr);
int print_battlemenu(player& plyr);
BattleResults battle_choices(Setup& setup, int user_choice, player& plyr, enemy& Enemy);
int print_stats(player& p, enemy& e);
enemy* choose_enemy();
int enemyAction(enemy& enemy, player& plyr);
bool HealthCheck(player& plyr);