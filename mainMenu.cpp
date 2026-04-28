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
void Intro();

int main() {

    Setup s;
	s.initializeItems();

	cout << "\n\tWelcome to our game!" << endl;
	cout << "\n 1. New Game\n 2. Load Game" << endl;

    int isSavedGame;
	cin >> isSavedGame;

    if (isSavedGame == 2) { //if the user chooses to load a file previously saved
		string fileName = chooseSaveFile(s);

        if (fileName != "") {
            loadGame(s, fileName);
        }

        currentSaveFile = fileName; //sets the file running to the saved file
    }
    else { //if there isn't a saved file the user wants to play
        startNewGame(s);
    }

    while (gameRunning) { //while loop to handle user input and menu selection
        refresh();
        Intro();
        printMenu();

        cout << "\n What would you like to do? (type the number): ";

        int userInput;
        cin >> userInput; //gets user input for menu choice

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
void Intro() {

    system("cls");

    cout << "-------------------------------------------------------------------------------------------\n";
    cout << "                                 A NEW JOURNEY BEGINS      \n";
    cout << "-------------------------------------------------------------------------------------------\n";

    cout << "You wake up in an open field... with no memory of how you got here." << endl;
    cout << "The wind blows softly through the grass as you sit up. The air is cold as the morning sun rises." << endl;
    cout << "You look around in confusion and notice a small town nearby, smoke rising from chimneys and the quiet sounds of townsfolk going about their day." << endl;
    cout << "With no other apparent options, you decide to head over to the village, curious about what it may offer.\n" << endl;

    cout << "After a short journey across the tall weeds and flowers, you arrive at what seems to be the gate at the entrance." << endl;
    cout << "Looking around, you notice that you are starting to gather the attention of some nearby townsfolk." << endl;
    cout << "Worried, you start to rethink your choice of coming here, but what else can you do? You have no clue where you are, so the best option is to ask for help where it is presented." << endl;

    cout << "\nA few of them approach you and ask if you would like to be shown around, and you agree." << endl;
    cout << "They lead you around, showing you the scenery they have to offer. Houses of all shapes and sizes line the roads, their wooden frames weathered but well cared for." << endl;
    cout << "Vendors call out to those passing by, selling fresh goods, tools, and handmade trinkets. Children run through the streets laughing, weaving between villagers as the town hums with quiet life and warmth." << endl;

    cout << "As you walk through, the townsfolk guiding you stop in front of a small cottage at what seems to be the edge of the town." << endl;
    cout << "Hesitant, you follow them inside. An old man sits in the corner near a fireplace, rocking back and forth on a wooden rocking chair." << endl;

    cout << "\nThe elder studies you carefully before speaking." << endl;
    cout << "\"Well, who do we have here? We get adventurers from time to time, but you seem different. Let me tell you a story...\"" << endl;

    cout << "\"Long ago, our home was protected by a sacred Amulet, a relic that kept peace and safety over these lands.\"" << endl;
    cout << "\"I may not look like it, but I was one of the keepers of it. I watched over that thing for years... until something terrible happened.\"" << endl;

    cout << "\"A wizard, old but very dangerous, came here in search of our only power. We did not give it up easily, oh no, we fought hard and long to chase him out.\"" << endl;
    cout << "\"It did not matter what we did though, the amulet shattered. Five pieces were strewn across these lands, and it is said that monsters were able to get their hands on them.\"\n" << endl;

    cout << "\"Without the amulet, our people are defenseless. Many have tried to retrieve the pieces, but have come back empty-handed.\"" << endl;

    cout << "He steps closer to you. With fierce determination in his eyes, he says:" << endl;
    cout << "\"You, on the other hand, seem to hold great power within you. I believe you have what it takes to retrieve the shards of the amulet and save our town.\"" << endl;

    cout << "\"Defeating the wizard will not be easy, but we are all cheering for you. Defeat him and bring back our protector.\"" << endl;

    cout << "He hands you an old map before walking back to his chair." << endl;
    cout << "\n\"Find the five pieces throughout the land, restore the amulet, save the town, and be a hero.\"" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nPress Enter...";
    cin.get();
    system("cls");

}
int quitGame(Setup& s) { //function to quit the game
    cout << "save game before you leave? (y/n): "; //to make sure player doesn't accidentally quit before saving

    char saveChoice;
    cin >> saveChoice; //gets user choice for saving game before quitting

    if (saveChoice == 'y' || saveChoice == 'Y') { //if player does want to save

        if (currentSaveFile == "") { //if there isn't a save file already
            string fileName = getFileName(" Enter a name for your save file: ");
            currentSaveFile = fileName;
        }

		saveGame(s, currentSaveFile);
    }
    else { //if player chooses not to save
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
