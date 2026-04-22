#include <iostream>
#include <istream>
#include <string>
#include "Setup.h"
//#include "player.h"
#include "BattleSequence.h"
#include "talkingNPC.h"
#include "Inventory.h"
#include "Shop.h"
#include "SaveGame.h"
#include <thread>
#include <chrono>
#include <cstdlib>

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
	cout << "\n\tWelcome to our game!" << endl;
	cout << "\n 1. New Game\n 2. Load Game" << endl;
	cin >> isSaveGame;

    if (isSaveGame == 2) {
		string fileName = chooseSaveFile(s);

        if (fileName != "") {
            loadGame(s, fileName);
        }

        currentSaveFile = fileName;

    }
    else {
        startNewGame(s);
    }

    while (gameRunning) { //while loop to handle user input and menu selection
        refresh();
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
            refresh();
            cout << "\nYou step into the shop where you recieve a friendly greeting." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            enterShop(s);
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
                QuickSaveGame(s, currentSaveFile);
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
            break;
        default:
            cout << "\n\t Invalid Number" << endl;
            break;
        }
    }

}

//function code
int printMenu() { //function to print the menu
    cout << "\n 1. Return to Overworld" << endl;
    cout << " 2. Enter A Battle" << endl;
    cout << " 3. Manage Your Inventory" << endl;
    cout << " 4. Enter Shop" << endl; //name shop?
    cout << " 5. Talk to Someone" << endl; //chamge this wordng?

	cout << "\n 6. Quick Save Game" << endl; //save current game
	cout << " 7. Save Game As" << endl; //save new game
    cout << " 8. Quit Game" << endl; //end game session
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
		//cout << "\n\t [game saved to " << currentSaveFile << "]" << endl;
    }
    else {
        cout << "\n\t [game not saved]" << endl;
    }
    cout << "\n\t you exit the game" << endl;

    gameRunning = false;
    return 0;
};
void refresh() { //function to refresh the screen
	this_thread::sleep_for(chrono::milliseconds(500));
	system("cls");
}
