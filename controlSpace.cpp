/*********************************************************************
 ** Program Filename: controlspace.cpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: controlSpace definitions
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "controlSpace.hpp"

/*********************************************************************
 ** Function: ControlSpace
 ** Description: constructor
 ** Parameters: two strings and a space pointer
 ** Pre-Conditions: class created
 ** Post-Conditions: none
 *********************************************************************/
ControlSpace::ControlSpace(string label, string descrip, Space* nwRm):Space(){
    this->switchThrown = false;
    this->name = label;
    this->desc = descrip;
    this->roomControlled = nwRm;
    this->type = "control";
}

/*********************************************************************
 ** Function: ~ControlSpace
 ** Description: destructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: object destroyed
 *********************************************************************/
ControlSpace::~ControlSpace(){
    
}

/*********************************************************************
 ** Function: special
 ** Description: opens door in another space
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: opened door in other space
 *********************************************************************/
void ControlSpace::special(){
    
    this->switchThrown = true;
    this->roomControlled->special();
    
}

/*********************************************************************
 ** Function: getStatus()
 ** Description: returns bool status
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
bool ControlSpace::getStatus(){
    return this->switchThrown;
}

/*********************************************************************
 ** Function: describeSpace
 ** Description: shows description text
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void ControlSpace::describeSpace(){
    std::cout << this->desc << std::endl;
    if(switchThrown){
        std::cout << "The switch was already thrown." << std::endl;
    }
}