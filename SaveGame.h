#pragma once
#include "Setup.h"
#include "Map.h"
#include <string>
#include <vector>

//header file for save/load game functions

inline bool gameRunning = true; //for the menu loop, set to false when user wants to quit the game
inline string currentSaveFile = ""; //to keep track of current save file
inline bool finalBossDefeated = false;

void saveGame(Setup& s, Map& map, string fileName);
void QuickSaveGame(Setup& s, Map& map, string fileName);
void loadGame(Setup& s, Map& map, string fileName);
string getFileName(string prompt);
vector<string> listSaveFiles();
string chooseSaveFile(Setup& s);
void startNewGame(Setup& s);
int quitGame(Setup& s, Map& map);