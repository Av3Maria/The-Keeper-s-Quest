#include <iostream>
#include <string>
#include "Setup.h"
#include "BattleSequence.h"
#include "talkingNPC.h"
#include "Inventory.h"
#include "Shop.h"
#include "SaveGame.h"
using namespace std;

bool gameRunning = true; //for the menu loop, set to false when user wants to quit the game
string currentSaveFile = ""; //to keep track of current save file

//function prototypes
int printMenu();
int returnToOverworld();
int quitGame(Setup& s);
void refresh();


int main() {

    Setup s;
	s.initializeItems();

    int isSaveGame;
	cout << "Welcome to our game!" << endl;
	cout << "\n1. New Game\n2. Load Game" << endl;
	cin >> isSaveGame;

    if (isSaveGame == 2) {
		string fileName = chooseSaveFile();

        if (fileName != "") {
            loadGame(s, fileName);
        }

        currentSaveFile = fileName;
    }
    else {
		cout << "\n\t Starting New Game..." << endl;
    }

    while (gameRunning) { //while loop to handle user input and menu selection
        printMenu();

        int userInput;
        cout << "\n What would you like to do? (type the number): ";
        cin >> userInput;

        switch (userInput) { //switch to call the function corresponding to the number
        case 1:
            returnToOverworld();
            refresh(); //delete later
            break;
        case 2:
            enterBattle(s, nullptr);
            refresh();
            break;
        case 3:
            manageInventory(s);
            break;
        case 4:
            enterShop(s);
            refresh(); //delete later
            break;
        case 5:
            chat(s);
			refresh(); //delete later
            break;
        case 6: { //save current game
            if (currentSaveFile == "") {
                cout << "\n\t [no save file found, please create a new save file]" << endl;
                break;
            }
            else {
                saveGame(s, currentSaveFile);
            }
            refresh();
            break;
        }
        case 7: { //save new game file
            string fileName = getFileName(" Enter a name for your save file: ");
            currentSaveFile = fileName;
            saveGame(s, currentSaveFile);
            refresh();
            break;
        }
        case 8:
            quitGame(s);
            gameRunning = false;
            break;
        default:
            cout << "\n\t Invalid Number" << endl;
            break;
        }
    }

}

//function code
int printMenu() { //function to print the menu
    cout << "\n 1. Return to Game" << endl;
    cout << " 2. Enter Battle" << endl;
    cout << " 3. Manage Inventory" << endl;
    cout << " 4. Enter Shop" << endl;
    cout << " 5. Talk to Someone" << endl;
	cout << "\n 6. Save Game" << endl;
	cout << " 7. Save Game As" << endl;
    cout << " 8. Quit Game" << endl;
    return 0;
}
int returnToOverworld() { //??
    cout << "\n\t you return to the overworld" << endl;
    return 0;
};
int quitGame(Setup& s) { //function to quit the game
    char saveChoice;
    cout << "save game before you leave? (y/n): ";
    cin >> saveChoice;

    if (saveChoice == 'y' || saveChoice == 'Y') {
        if (currentSaveFile == "") {
            string fileName = getFileName(" Enter a name for your save file: ");
            currentSaveFile = fileName;
        }

		saveGame(s, currentSaveFile);
		cout << "\n\t [game saved to " << currentSaveFile << "]" << endl;
    }
    else {
        cout << "\n\t [game not saved]" << endl;
    }
    cout << "\n\t you exit the game" << endl;
    return 0;
};
void refresh() { //function to refresh the screen
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this codeline makes sure the refresh function waits for the user's enter before refreshing
    cout << "\n Press Enter to refresh: ";
    cin.get(); //reads the user's enter and then refreshes
    system("cls");
}
