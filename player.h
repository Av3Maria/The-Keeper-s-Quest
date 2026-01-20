#pragma once
#ifndef player_h
#include <iostream>
#include <iomanip>
#include <string>
#include "character.h"
using namespace std;

class player : public character {
protected:

public:

  void die();

  void displayPlayerStats();

  ~player();


};


#endif


