/*********************************************************************
 ** Program Filename: controlspace.cpp
 ** Author: Joshua Sears
 ** Date: 28 Nov 15
 ** Description: space definitions
 ** Input: None
 ** Output: None
 *********************************************************************/

#include <iostream>

#include "space.hpp"
#include "creature.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
 ** Function: Space()
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: class object created
 ** Post-Conditions: none
 *********************************************************************/

    
Space::Space(){
    this->name = "";
    this->desc = "";
    this->north = NULL;
    this->south = NULL;
    this->east = NULL;
    this->west = NULL;
    
    for(int count = 0; count < 4; count++){
        for(int next = 0; next < 6; next++){
            map[count][next] = ' ';
        }
    }

    for(int col = 0; col < 5; col++){
        for(int row = 0; row < 6; row++){
            map[col][row] = 'O';
        }
    }

}

/*********************************************************************
 ** Function: ~Space()
 ** Description: destructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: object destroyed
 *********************************************************************/
Space::~Space(){
}


/*********************************************************************
 ** Function: setPath
 ** Description: set pointers to next spaces
 ** Parameters: 4x Spaces*
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Space::setPath(Space* n, Space* s, Space* e, Space* w){
    this->north = n;
    this->south = s;
    this->east = e;
    this->west = w;
}

/*********************************************************************
 ** Function: nextStep
 ** Description: returns pointer to next
 ** Parameters: character
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
Space* Space::nextStep(char next){
    if(next == 'n'){
        return this->north;
    }
    if(next == 's'){
        return this->south;
    }
    if(next == 'e'){
        return this->east;
    }
    else
        return this->west;
    
}

/*********************************************************************
 ** Function: describeSpace
 ** Description: outputs description
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Space::describeSpace(){
    cout << endl<< this->desc << endl;
    return;
}

/*********************************************************************
 ** Function: setMap
 ** Description: sets location in map
 ** Parameters: two ints
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Space::setMap(int col, int row){
    map[col][row] = 'X';
    return;
}

/*********************************************************************
 ** Function: display map
 ** Description: outputs map to screen
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Space::displayMap(){
    for(int col = 0; col < 5; col++){
        cout << endl;
        for(int row = 0; row < 6; row++){
            cout << map[col][row];
        }
    } cout << endl;
}

/*********************************************************************
 ** Function: setSpecial
 ** Description: none
 ** Parameters: 4x spaces (ignored)
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Space::setSpecial(Space* ignore1, Space* ignore2, Space* ignore3, Space* ignore4){
    return;
}

/*********************************************************************
 ** Function: getType
 ** Description: returns type
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
string Space::getType(){
    return this->type;
}



