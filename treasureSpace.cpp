/*********************************************************************
 ** Program Filename: treasurespace.cpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: controlSpace definitions
 ** Input: None
 ** Output: None
 *********************************************************************/
#include <iostream>
#include "treasureSpace.hpp"
#include "space.hpp"

using std::cout;
using std::endl;

/*********************************************************************
 ** Function: TreasureSpace
 ** Description: constructor
 ** Parameters: two strings
 ** Pre-Conditions: class created
 ** Post-Conditions: none
 *********************************************************************/
TreasureSpace::TreasureSpace(string label, string descrip):Space(){
    
    this->name = label;
    this->desc = descrip;
    this->type = "treasure";
    this->isTaken = 0;
    
}


/*********************************************************************
 ** Function: ~TreasureSpace
 ** Description: destructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: object destroyed
 *********************************************************************/
TreasureSpace::~TreasureSpace(){
    
}

/*********************************************************************
 ** Function: special
 ** Description: changes bool marker
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions:none
 *********************************************************************/
void TreasureSpace::special(){
    this->isTaken = 1;
}

/*********************************************************************
 ** Function: grabTreasure
 ** Description: output desc and returns prize pointer
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
Treasure* TreasureSpace::grabTreasure(){
    cout << this->prize->desc << endl;
    return this->prize;
}

/*********************************************************************
 ** Function: describeSpace()
 ** Description: shows description
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void TreasureSpace::describeSpace(){
    std::cout << this->desc << std::endl;
    if(!isTaken){
        std::cout << "A " << this->prize->name << " lies here." << std::endl;
    }else{
        std::cout << "The chest is empty." << endl;
    }
    return;
}

/*********************************************************************
 ** Function: setTreasure
 ** Description: sets pointer
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void TreasureSpace::setTreasure(Treasure* newT){
    this->prize = newT;
}

/*********************************************************************
 ** Function: isAvail
 ** Description: returns bool taken
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
bool TreasureSpace::isAvail(){
    return !(isTaken);
}