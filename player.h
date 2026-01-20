#pragma once
#ifndef player_h
#include <iostream>
#include <iomanip>
#include <string>
#include "character.h"
using namespace std;

class player : public character {
protected:
  string name = "Player";

public:

  void die();

  void displayPlayerStats();

  ~player();

  void flee();


};


#endif



