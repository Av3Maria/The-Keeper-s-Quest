#include <iostream>
#include <iomanip>
#include "BattleSequence.h"
using namespace std;

bool on = true;

//function prototypes
int printMenu();
int returnToOverworld();
int manageInventory();
int enterShop();
int chat();
int quitGame();
void refresh();

int main() {

    while (on) { //while loop to handle user input and menu selection
        printMenu();

        int userInput;
        cout << "\n What would you like to do? (type the number): ";
        cin >> userInput;

        switch (userInput) { //switch to call the function corresponding to the number
        case 1:
            returnToOverworld();
            break;
        case 2:
            enterBattle();
            break;
        case 3:
            manageInventory();
            break;
        case 4:
            enterShop();
            break;
        case 5:
            chat();
            break;
        case 6:
            quitGame();
            break;
        default:
            cout << "\n\t Invalid Number" << endl;
            break;
        }

        if (on) { //clears the screen when you hit enter
            refresh();
            system("cls");
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
    cout << " 6. Quit Game" << endl;
    return 0;
}
int returnToOverworld() {
    cout << "\n\t you return to the overworld" << endl;
    return 0;
};
int manageInventory() { //function to open inventory
    cout << "\n\t you open your inventory" << endl;
    return 0;
};
int enterShop() { //function to enter the shop
    cout << "\n\t you walk into the shop" << endl;
    return 0;
};
int chat() { //function to talk to an npc
    cout << "\n\t you say hello" << endl;
    return 0;
};
int quitGame() { //function to quit the game
    cout << "\n\t you exit the game" << endl;
    on = false;
    return 0;
};
void refresh() { //function to refresh the screen
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this codeline makes sure the refresh function waits for the user's enter before refreshing
    cout << "\n Press Enter to refresh: ";
    cin.get(); //reads the user's enter and then refreshes
}
