/*********************************************************************
 ** Program Filename: finalspace.cpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: controlSpace definitions
 ** Input: None
 ** Output: None
 *********************************************************************/
#include <iostream>
#include "finalSpace.hpp"
#include "space.hpp"


/*********************************************************************
 ** Function: finalSpace
 ** Description: constructor
 ** Parameters: two strings
 ** Pre-Conditions: class created
 ** Post-Conditions: none
 *********************************************************************/
FinalSpace::FinalSpace(string label, string descrip):Space(){
    this->name = label;
    this->desc = descrip;
    this->doorClosed = true;
    this->type = "final";
    
}


/*********************************************************************
 ** Function: ~FinalSpace
 ** Description: destructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: object destroyed
 *********************************************************************/
FinalSpace::~FinalSpace(){
    
}

/*********************************************************************
 ** Function: special
 ** Description: opens door in another space, sets finished bool variable
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: opened final door
 *********************************************************************/
void FinalSpace::special(){
    this->finished = 1;
    this->doorClosed = false;
    this->north = this->altN;
    this->south = this->altS;
    this->east = this->altE;
    this->west = this->altW;
}

/*********************************************************************
 ** Function: getStatus()
 ** Description: returns bool status
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
bool FinalSpace::getStatus(){
    return this->doorClosed;
}

/*********************************************************************
 ** Function: setSpecial
 ** Description: sets alternate pointers
 ** Parameters: 4x Space*
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void FinalSpace::setSpecial(Space* N, Space* S, Space* E, Space* W){
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
void FinalSpace::describeSpace(){
    std::cout << this->desc << std::endl;
    
    return;
}

/*********************************************************************
 ** Function: isFinished
 ** Description: returns bool variable
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
bool FinalSpace::isFinished(){
    return finished;
}

