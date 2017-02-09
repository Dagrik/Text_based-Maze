/*********************************************************************
 ** Program Filename: advent.cpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: Adventure class definitions
 ** Input: None
 ** Output: None
 *********************************************************************/
//
#include <iostream>
#include <cstdlib>
#include "advent.hpp"
#include "treasureSpace.hpp"
#include "enemySpace.hpp"

using std::cin;
using std::cout;
using std::endl;


/*********************************************************************
 ** Function: Adventurer()
 ** Description: constructor
 ** Parameters: pointer to starting space
 ** Pre-Conditions: class created
 ** Post-Conditions: none
 *********************************************************************/
Adventurer::Adventurer(Space* start){
    this->loc = start;
    this->winner = 0;
    wizard = new Hero;
}

/*********************************************************************
 ** Function: Destructor
 ** Description: destroys adventurer class
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: object destroyed
 *********************************************************************/
Adventurer::~Adventurer(){
    
}


/*********************************************************************
 ** Function: move()
 ** Description: moves Adventurer around map
 ** Parameters: character value
 ** Pre-Conditions: none
 ** Post-Conditions: char moved
 *********************************************************************/
void Adventurer::move(char next){
    //If direction pointer points to current space
    while(this->loc == loc->nextStep(next)){
        cout << "Cannot go that direction." << endl;
        cout << "Please choose a different direction from the listed options. " << endl;
        cin >> next;
    }
    this->loc = loc->nextStep(next);
    return;
}

/*********************************************************************
 ** Function: getWiz
 ** Description: returns pointer to Adventurer creature
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
Creature* Adventurer::getWiz(){
    return wizard;
}

/*********************************************************************
 ** Function: viewInventory
 ** Description: shows list of items in inventory
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Adventurer::viewInventory(){
    cout << endl << "Backpack:" << endl;
    if(backpack.size() == 0){
        cout << "You have nothing!" << endl;
        return;
    }
    for(int count = 0; count < backpack.size(); count++){
        cout << backpack.at(count)->name << endl;
    }
    return;
}

/*********************************************************************
 ** Function: seeSpace()
 ** Description: shows list of options to player
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Adventurer::seeSpace(){
    
    cout << endl;
    this->loc->describeSpace();
    cout << endl << endl << "Options: " << endl;
    
    if(!backpack.empty()){
        cout << "(V)iew your inventory." << endl;
    }
    if(this->loc != loc->nextStep('n')){
        cout << "Doorway to the (N)orth." << endl;
    }
    if(this->loc != loc->nextStep('s')){
        cout << "Doorway to the (S)outh." << endl;
    }
    if(this->loc != loc->nextStep('e')){
        cout << "Doorway to the (E)ast." << endl;
    }
    if(this->loc != loc->nextStep('w')){
        cout << "Doorway to the (W)est." << endl;
    }
    if(this->loc->getType() == "enemy"){
        cout << "(B)attle!" << endl;
    }
    if(this->loc->getType() == "control"){
        cout << "(U)se the lever." << endl;
    }
    if(this->loc->getType() == "treasure"){
        cout << "(P)ick up the treasure." << endl;
    }
    if(this->loc->getType() == "rest"){
        cout << "(R)est and recover." << endl;
    }
    cout << "Need a (H)int?" << endl;
    
    cout << endl << "Map:";
    this->loc->displayMap();
    return;
}

/*********************************************************************
 ** Function: list()
 ** Description: switch to choose next actions
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: action taken
 *********************************************************************/
void Adventurer::list(){
    char choice;
    
    cout << endl << "What would you like to do?" << endl;

    cin >> choice;
    
    switch (choice){
            case 'v':
            case 'V':
            viewInventory();
            break;
            //Cardinal directions
            case 'n':
            case 'N':
                this->move('n');
                system("clear");
                break;
           
            case 's':
            case 'S':
                this->move('s');
                system("clear");
                break;
            
            case 'e':
            case 'E':
                this->move('e');
                system("clear");
                break;
            
            case 'w':
            case 'W':
                this->move('w');
                system("clear");
                break;
            //Use switch/lever
            case 'U':
            case 'u':
                this->loc->special();
                system("clear");
                break;
            //Pick up item
            case 'P':
            case 'p':
                if(dynamic_cast<TreasureSpace*>(loc)->isAvail()){
                    backpack.push_back(dynamic_cast<TreasureSpace*>(loc)->grabTreasure());
                }
                else{
                    cout << "No items to take!" << endl;
                }
                this->loc->special();
                break;
            //Battle
            case 'B':
            case 'b':
                loc->special();
                break;
            //Hint
            case 'h':
            case 'H':
                this->hint();
                break;
            //Rest
            case 'r':
            case 'R':
                loc->special();
                wizard->healme(2);
                cout << "Your health is now at " << wizard->getStr() << endl;
                break;
           
            default:
                cout << "Invalid option" << endl;
    }

}

/*********************************************************************
 ** Function: hint()
 ** Description: shows map of dungeon and the objective
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Adventurer::hint(){
    cout << endl << "Hint:" << endl;
    cout << "Your goal is to obtain the four pieces of treasure within the time limit, and make it to the exit."
         << endl;
    cout << endl << "Map:" << endl << "OEOOMO" << endl << "MMTODT" << endl << "MSDMTO" << endl << "TMOODM" << endl
         << "OCOCOC" << endl;
    cout << endl << "Key:" << endl << "M = monster T = treasure" << endl << "D = door    S = start" << endl
         << "E = exit    C = control switch" << endl;
}

/*********************************************************************
 ** Function: bagSize()
 ** Description: returns size of inventory vector
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int Adventurer::bagSize(){
    return backpack.size();
}

/*********************************************************************
 ** Function: didIWin
 ** Description: checks if in "final" space
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
bool Adventurer::didIWin(){
    if(loc->getType() == "final"){
        return true;
    }
    return false;
}