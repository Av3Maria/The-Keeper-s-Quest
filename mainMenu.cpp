#include <iostream>
#include <string>
#include <limits>
#include <thread>
#include <chrono>
#include "Setup.h"
#include "BattleSequence.h"
#include "talkingNPC.h"
#include "Inventory.h"
#include "Shop.h"
#include "SaveGame.h"
#include "Map.h"

/*notes to do:
* 
* change boss names (if isBoss = "", else " (regular name) ")
* end of game code
* play through game and stress test everything
* make sure menu prompts make sense and are correctly named
* finalize game name
* look through dialogue and edit spelling
* make sure everything is formatted correctly and looks good
* make sure refreshing works correctly and doesn't cause any issues
*/


using namespace std;

//bool gameRunning = true; //for the menu loop, set to false when user wants to quit the game
//string currentSaveFile = ""; //to keep track of current save file

//function prototypes
int printMenu();
void refresh();
void Intro();

int main() {

    Map map;
    Setup s;
    s.initializeItems();
    map.assignCharacters();

    bool inGame = false;
    bool inWorld = false;

    cout << "-------------------------------------------------------------------------------------------\n";
    cout << "                                 THE KEEPER'S QUEST      \n";
    cout << "-------------------------------------------------------------------------------------------\n";


    while (gameRunning) {

        if (!inGame) {

            cout << "\n 1. New Game\n 2. Load Game\n";

            int input;
            cin >> input;

            switch (input) {

            case 1:

                startNewGame(s);
                Intro();

                map.currentTile = map.startTile;
                inGame = true;
                break;

            case 2: {
                string fileName = chooseSaveFile(s);

                if (!fileName.empty()) {
                    loadGame(s, map, fileName);
                    currentSaveFile = fileName;
                    inGame = true;
                }
                break;
            }

            default:
                cout << "\nInvalid option.\n";
                break;
            }
        }

        else if (!inWorld) {

            printMenu();

            int input;
            cin >> input;

            switch (input) {

            case 1:
                inWorld = true;
                break;

            case 2:
                currentSaveFile = getFileName("Enter save file name: ");
                saveGame(s, map, currentSaveFile);
                refresh();
                break;

            case 3:
                quitGame(s, map);
                break;

            case 4:
                if (!currentSaveFile.empty())
                    QuickSaveGame(s, map, currentSaveFile);
                else
                    cout << "\nNo save file selected.\n";
                refresh();
                break;

            default:
                cout << "\nInvalid option.\n";
                break;
            }
        }

        else {
            inWorld = map.returnToOverworld(s);
        }
    }

    return 0;
}

//function code

int printMenu() { //function to print the menu
    system("cls");

    cout << "\nWhat would you like to do...\n";
    cout << "\n 1. Enter Game\n" << endl;
    cout << " 2. Save Game" << endl;
    cout << " 3. Quit Game" << endl;
    cout << " 4. Quick Save Game" << endl;
    return 0;
}
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
void refresh() { //function to refresh the screen
	this_thread::sleep_for(chrono::milliseconds(500));
	system("cls");
}
