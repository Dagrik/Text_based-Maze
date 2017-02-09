/*********************************************************************
 ** Program Filename: doorspace.cpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: doorSpace definitions
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "doorSpace.hpp"

/*********************************************************************
 ** Function: DoorSpace
 ** Description: constructor
 ** Parameters: two strings
 ** Pre-Conditions: class created
 ** Post-Conditions: none
 *********************************************************************/
DoorSpace::DoorSpace(string label, string descrip):Space(){
    this->name = label;
    this->desc = descrip;
    this->doorClosed = true;
    this->type = "door";

}

/*********************************************************************
 ** Function: ~doorSpace
 ** Description: destructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: object destroyed
 *********************************************************************/
DoorSpace::~DoorSpace(){
    
}

/*********************************************************************
 ** Function: special
 ** Description: opens door in space, changes pointers
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: opened door
 *********************************************************************/
void DoorSpace::special(){
    
    this->doorClosed = false;
    this->north = this->altN;
    this->south = this->altS;
    this->east = this->altE;
    this->west = this->altW;
}

/*********************************************************************
 ** Function: getStatus()
 ** Description: returns if door closed
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
bool DoorSpace::getStatus(){
    return this->doorClosed;
}

/*********************************************************************
 ** Function: setSpecial
 ** Description: sets alt pointers
 ** Parameters: 4x space*
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void DoorSpace::setSpecial(Space* N, Space* S, Space* E, Space* W){
    this->altN = N;
    this->altS = S;
    this->altE = E;
    this->altW = W;
}

/*********************************************************************
 ** Function: describeSpace
 ** Description: shows description text
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void DoorSpace::describeSpace(){
    std::cout << this->desc << std::endl;
    if(this->doorClosed){
        std::cout << "The door is closed." << std::endl;
    }
    else {
        std::cout << "The door is open." << std::endl;
    }
    return;
}