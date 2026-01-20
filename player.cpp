#include <iostream>
#include <string>
#include "character.h"
#include "player.h"
using namespace std;

player::player(string& n, int h, int stg, int def)
	:character("Player", 50, 25, 25){ }

string player::getName() {
	return "player";
}