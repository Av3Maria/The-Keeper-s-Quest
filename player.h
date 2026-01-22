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
	player( int h, int stg, int def);
	string getName() override;
	void flee() override;
	void die() override;
};

#endif