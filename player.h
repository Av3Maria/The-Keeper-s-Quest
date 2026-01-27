#pragma once
#ifndef player_h
#include <iostream>
#include <string>
#include "character.h"
using namespace std;

class player : public character {
protected:

public:
	//constructor for player class------
	player();
	//function to get player name------
	string getName() override;
	//function for flee-------
	void flee() override;
	//function for dieing-------
	void die() override;
};

#endif