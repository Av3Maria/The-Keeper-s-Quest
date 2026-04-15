#pragma once
#include "Setup.h"
#include <string>
#include <vector>

void saveGame(Setup& s, string fileName);
void loadGame(Setup& s, string fileName);
string getFileName(string prompt);
vector<string> listSaveFiles();
string chooseSaveFile();
