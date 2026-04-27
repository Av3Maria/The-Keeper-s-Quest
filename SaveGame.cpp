#include "Setup.h"
#include "player.h"
#include "SaveGame.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <istream>
#include <string>
#include <vector>
using namespace std;

namespace fs = std::filesystem; //for file handling

//main functions for saving and loading game, as well as helper functions to get file name and list save files in directory
void saveGame(Setup& s, string fileName) {

	bool fileExists = fs::exists(fileName); //checks if file already exists to prevent accidental overwriting of save files
	
	if (fileExists) { //if file already exists, ask user if they want to overwrite it
		cout << "\n\tA save file with this name already exists. Do you want to overwrite it? (y/n): ";

		char userChoice;
		cin >> userChoice; //gets user choice

		if (userChoice != 'y' && userChoice != 'Y') { //if user doesn't want to overwrite file, cancel save
			cout << "\n\t[save cancelled]" << endl;
			return;
		}
	}

	ofstream file(fileName); //opens file for writing

	if (!file) { //if file can't be opened, print error and return
		cout << "\n\t[error saving game]" << endl;
		return;
	}

	//gets all relevant player info and writes it to file
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

	file.close(); //closes file after writing
	cout << "\n\t[game saved as " << fileName << "]" << endl; //tells player what the name of the file is
	return;
}

//function to quick save game without asking for file name, used for file already created
void QuickSaveGame(Setup& s, string fileName) {

	ofstream file(fileName); //opens file for writing

	if (!file) { //if file can't be opened, print error and return
		cout << "\n\t[error saving game]" << endl;
		return;
	}

	//gets all relevant player info and writes it to file
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

	file.close(); //closes file after writing
	cout << "\n\t[game saved as " << fileName << "]" << endl; //tells player what the name of the file is
	return;
}

//function to load game from previously saved file
void loadGame(Setup& s, string fileName) {
	ifstream file(fileName); //opens file for reading

	if (!file) { //if file can't be opened, print error and return (no save file)
		cout << "\n\t[no file found]" << endl;
		return;
	}

	//reads all relevant player info from file and sets it to the player object
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

	file.close(); //closes file after reading

	s.mainPlayer.syncWeapons(s.mainPlayer, s);

	cout << "\n\t[game loaded from " << fileName << "]" << endl; //tells player that game has been loaded and what file it was loaded from
	
	//cout << "debug: " << s.mainPlayer.getName() << ", " << s.mainPlayer.getClassType() << ", " << s.mainPlayer.getHealth() << ", " << s.mainPlayer.getDefense() << ", " << s.mainPlayer.getStrength() << ", " << s.mainPlayer.getOwnedGold() << s.mainPlayer.inventory.size() << endl;
	return;
}

//function to get file name from user input (adds .sf extension to end of file name, this game specific)
string getFileName(string prompt) {
	string fileName;
	cout << prompt; //asks user for file name
	getline(cin >> ws, fileName); //gets user input for file name, using getline to allow for spaces in file name
	fileName += ".sf"; //adds .sf extension to end of file name, this game specific
	return fileName; 
}

//function to list all save files in current directory (looks for files with .sf extension, this game specific)
vector<string> listSaveFiles() {
	vector<string> saveFiles; //vector to store save file names

	for (const auto& entry : fs::directory_iterator(".")) { //iterates through all files in current directory
		string name = entry.path().filename().string();

		if (entry.path().extension() == ".sf") { //if file has .sf extension, add it to saveFiles vector
			saveFiles.push_back(name);
		}
	}
	return saveFiles;
}

//function to allow user to choose a save file to load
string chooseSaveFile(Setup& s) {
	vector<string> saveFiles = listSaveFiles(); //gets list of save files in current directory

	if (saveFiles.empty()) { //if no save files are found, print message and start new game instead
		cout << "\n\t[no save files found]" << endl;
		startNewGame(s);
		return "";
	}

	cout << "\n\tSelect a save file to load:" << endl; 

	for (int i = 0; i < saveFiles.size(); i++) { //prints list of save files with corresponding numbers for user to select
		cout << "\t" << (i + 1) << ". " << saveFiles[i] << endl;
	}

	cout << "\n\tEnter the number of the file you want: ";

	int userFile;
	cin >> userFile; //gets user's file they want to play

	if (userFile < 1 || userFile > saveFiles.size()) { //if user input is invalid (not a number corresponding to a file), print message and start new game instead
		cout << "\n\t[invalid choice]" << endl;
		startNewGame(s);
		return "";
	}

	return saveFiles[userFile - 1]; //returns the name of the file the user selected (subtracting 1 from user input to account for 0 indexing)
}

//function to start new game
void startNewGame(Setup& s) {
	cout << "\n\t Starting New Game..." << endl;

	string playerName;
	cout << "\n\t Enter your name! : ";
	getline(cin >> ws, playerName); //gets user input for player name, using getline to allow for spaces in name

	cout << "Choose your class: "; //class menu
	cout << "\n1.Warrior (high defense)";
	cout << "\n2.Rogue (high health)";
	cout << "\n3.Hunter (high strength)";
	cout << "\n4.Sorcerer (high strength)" << endl;

	int classChoice;
	cin >> classChoice; //gets player choice for class type

	string classType;
	switch (classChoice) { //sets class type as player's choice
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
	default: //if number outside options is chosen, default player class type is 'Warrior'
		cout << "\n\t Invalid Class Choice" << endl;
		cout << "\n\t Defaulting to Warrior class..." << endl;
		classType = "Warrior";
		break;
	}
	player customPlayer(playerName, classType); //sets player's name and class
	s.mainPlayer = customPlayer;
}
