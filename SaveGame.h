#pragma once
#include "Setup.h"
#include <string>
#include <vector>

//header file for save/load game functions

void saveGame(Setup& s, string fileName);
void QuickSaveGame(Setup& s, string fileName);
void loadGame(Setup& s, string fileName);
string getFileName(string prompt);
vector<string> listSaveFiles();
string chooseSaveFile(Setup& s);
void startNewGame(Setup& s);