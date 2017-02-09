/*********************************************************************
 ** Program Filename: restspace.cpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: restSpace definiton
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "restSpace.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*********************************************************************
 ** Function: restSpace
 ** Description: constructor
 ** Parameters: two strings
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
RestSpace::RestSpace(string label, string descrip):Space(){

    this->name = label;
    this->desc = descrip;
    this->type = "rest";

}
/*********************************************************************
 ** Function: ~restSpace
 ** Description: destructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: object destroyed
 *********************************************************************/
RestSpace::~RestSpace(){}

/*********************************************************************
 ** Function: special
 ** Description: displays text
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void RestSpace::special(){
    cout << "You find a place to rest for a little, eat some food, and patch yourself up." << endl;
}

/*********************************************************************
 ** Function: describeSpace
 ** Description: prints description
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void RestSpace::describeSpace(){
    cout << this->desc << std::endl;
}