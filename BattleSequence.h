#pragma once

#include "player.h"
#include "enemy.h"

int enterBattle();
int print_battlemenu(player& plyr);
bool battle_choices(int user_choice, player& plyr, enemy& Enemy);
int print_stats(player& p, enemy& e);
enemy* choose_enemy();
int enemyAction(enemy& enemy, player& plyr);
