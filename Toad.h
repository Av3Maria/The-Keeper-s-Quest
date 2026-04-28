#pragma once
#ifndef toad_h
#define toad_h
#include <iostream>
#include <string>
#include "enemy.h"
using namespace std;

class toad : public enemy {
protected:
    int assignedNum = 5;
    bool isBoss;
public:
    int getAssignedNum();
    string getAmuletMessage() const override;
    toad(bool bossMode = false);
    string getName() override;
    enemy* clone() const override;
};

#endif

