#include "SaveGame.h"

void saveGame(Setup& s, string fileName) {
	ofstream file(fileName);

	if (!file) {
		cout << "\n\t[error saving game]" << endl;
		return;
	}

	file << s.mainPlayer.getHealth() << endl;
	file << s.mainPlayer.getDefense() << endl;
	file << s.mainPlayer.getStrength() << endl;

	file << s.mainPlayer.getOwnedGold() << endl;

	file << s.mainPlayer.inventory.size() << endl;
	for (const auto& pair : s.mainPlayer.inventory) {
		file << pair.first << " " << pair.second << endl;
	}

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

	file >> s.mainPlayer.health;
	file >> s.mainPlayer.defense;
	file >> s.mainPlayer.strength;
	file >> s.mainPlayer.getOwnedGold();

	size_t inventorySize;
	file >> inventorySize;
	for (size_t i = 0; i < inventorySize; ++i) {
		string itemName;
		int itemQuantity;
		file >> itemName >> itemQuantity;
		s.mainPlayer.inventory[itemName] = itemQuantity;
	}

	file.close();
	cout << "\n\t[game loaded from " << fileName << "]" << endl;
	return;
}

string getFileName(string prompt) {
	string fileName;
	cout << prompt;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, fileName);
	fileName += ".sav";
	return fileName;
}

vector<string> listSaveFiles() {
	vector<string> saveFiles;

	for (const auto& entry : fs::directory_iterator(".")) {
		string name = entry.path().filename().string();

		if (name.find(".sav") != string::npos) {
			saveFiles.push_back(name);
		}
	}
	return saveFiles;
}

string chooseSaveFile() {
	vector<string> saveFiles = listSaveFiles();

	if (saveFiles.empty()) {
		cout << "\n\t[no save files found]" << endl;
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
