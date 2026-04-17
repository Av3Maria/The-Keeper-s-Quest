#include "Setup.h"
#include "player.h"
#include "SaveGame.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <istream>
#include <string>
using namespace std;

namespace fs = std::filesystem;

void saveGame(Setup& s, string fileName) {
	bool fileExists = fs::exists(fileName);

	if (fileExists) {
		char userChoice;
		cout << "\n\tA save file with this name already exists. Do you want to overwrite it? (y/n): ";
		cin >> userChoice;
		if (userChoice != 'y' && userChoice != 'Y') {
			cout << "\n\t[save cancelled]" << endl;
			return;
		}
	}

	ofstream file(fileName);

	if (!file) {
		cout << "\n\t[error saving game]" << endl;
		return;
	}

	file << s.mainPlayer.getName() << endl;
	file << s.mainPlayer.getClassType() << endl;
	
	file << s.mainPlayer.getHealth() << endl;
	file << s.mainPlayer.getDefense() << endl;
	file << s.mainPlayer.getStrength() << endl;

	file << s.mainPlayer.getOwnedGold() << endl;

	file << s.mainPlayer.inventory.size() << endl;
	for (const auto& pair : s.mainPlayer.inventory) {
		file << pair.first << " " << pair.second << endl;
	}

	//add location save

	file.close();
	cout << "\n\t[game saved as " << fileName << "]" << endl;
	return;
}

void loadGame(Setup& s, string fileName) {
	ifstream file(fileName);

	if (!file) {
		cout << "\n\t[no file found]" << endl;
		return;
	}

	string name;
	file >> name;
	s.mainPlayer.setName(name);

	string classType;
	file >> classType;
	s.mainPlayer.setClassType(classType);

	file >> s.mainPlayer.health;
	file >> s.mainPlayer.defense;
	file >> s.mainPlayer.strength;

	int gold;
	file >> gold;
	s.mainPlayer.setGold(gold);

	size_t inventorySize;
	file >> inventorySize;
	s.mainPlayer.inventory.clear();
	for (size_t i = 0; i < inventorySize; ++i) {
		int itemID;
		int itemQuantity;
		file >> itemID >> itemQuantity;
		s.mainPlayer.inventory[itemID] = itemQuantity;
	}

	//add location load

	file.close();

	s.mainPlayer.syncWeapons(s.mainPlayer, s);

	cout << "\n\t[game loaded from " << fileName << "]" << endl;
	
	//cout << "debug: " << s.mainPlayer.getName() << ", " << s.mainPlayer.getClassType() << ", " << s.mainPlayer.getHealth() << ", " << s.mainPlayer.getDefense() << ", " << s.mainPlayer.getStrength() << ", " << s.mainPlayer.getOwnedGold() << s.mainPlayer.inventory.size() << endl;
	return;
}

string getFileName(string prompt) {
	string fileName;
	cout << prompt;
	getline(cin >> ws, fileName);
	fileName += ".sf";
	return fileName;
}

vector<string> listSaveFiles() {
	vector<string> saveFiles;

	for (const auto& entry : fs::directory_iterator(".")) {
		string name = entry.path().filename().string();

		if (entry.path().extension() == ".sf") {
			saveFiles.push_back(name);
		}
	}
	return saveFiles;
}

string chooseSaveFile(Setup& s) {
	vector<string> saveFiles = listSaveFiles();

	if (saveFiles.empty()) {
		cout << "\n\t[no save files found]" << endl;
		startNewGame(s);
		return "";
	}

	cout << "\n\tSelect a save file to load:" << endl;
	for (int i = 0; i < saveFiles.size(); i++) {
		cout << "\t" << (i + 1) << ". " << saveFiles[i] << endl;
	}

	int userFile;
	cout << "\n\tEnter the number of the file you want: ";
	cin >> userFile;

	if (userFile < 1 || userFile > saveFiles.size()) {
		cout << "\n\t[invalid choice]" << endl;
		return "";
	}

	return saveFiles[userFile - 1];
}

void startNewGame(Setup& s) {
	cout << "\n\t Starting New Game..." << endl;

	string playerName;
	cout << "\n\t Enter your name! : ";
	getline(cin >> ws, playerName);

	int classChoice;
	cout << "Choose your class: ";
	cout << "\n1.Warrior (high defense)";
	cout << "\n2.Rogue (high health)";
	cout << "\n3.Hunter (high strength)";
	cout << "\n4.Sorcerer (high strength)" << endl;
	cin >> classChoice;

	string classType;
	switch (classChoice) {
	case 1:
		classType = "Warrior";
		break;
	case 2:
		classType = "Rogue";
		break;
	case 3:
		classType = "Hunter";
		break;
	case 4:
		classType = "Sorcerer";
		break;
	default:
		cout << "\n\t Invalid Class Choice" << endl;
		cout << "\n\t Defaulting to Warrior class..." << endl;
		classType = "Warrior";
		break;
	}
	player customPlayer(playerName, classType);
	s.mainPlayer = customPlayer;
}
