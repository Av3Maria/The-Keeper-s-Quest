#pragma once
#ifndef player_h
#include <iostream>
#include <string>
#include "character.h"
using namespace std;

class player : public character {
protected:

public:

	player() : character() {}
	player(string& n, int h, int stg, int def);
	string getName() override;
};

#endif