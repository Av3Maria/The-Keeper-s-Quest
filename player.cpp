#include <iostream>
#include <string>
#include <iomanip>
#include "character.h"
#include "player.h"

using namespace std;


void player::die(){
cout << "OH NO. It appears that you have died. " << endl << endl << "I suppose that was slightly disappointing.";
  ~player();
}

void player::displayPlayerStats(){
    cout << endl << setw(15) << "YOUR STATISTICS" << endl ;
    cout << setw(10) << "HEALTH" << setw(5) << health << endl;
    cout << setw(10) << "DEFENSE" << setw(5) << defense << endl;
    cout << setw(10) << "STRENGTH" << setw(5) << strength << endl;
  cout << setw(10) << "HEALS" << setw(5) << heals << endl;

}

player::~player(){

}


