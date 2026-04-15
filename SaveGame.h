#pragma once
#include "Setup.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <filesystem>

namespace fs = std::filesystem;	

void saveGame(Setup& s, string fileName);
void loadGame(Setup& s, string fileName);
string getFileName(string prompt);
vector<string> listSaveFiles();
string chooseSaveFile();

