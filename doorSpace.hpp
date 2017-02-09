/*********************************************************************
 ** Program Filename: doorspace.hpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: controlSpace declarations
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef doorSpace_hpp
#define doorSpace_hpp

#include <iostream>
#include "space.hpp"

using std::string;

class DoorSpace:public Space{
protected:
    bool doorClosed;
    Space* altN;
    Space* altS;
    Space* altE;
    Space* altW;

public:
    DoorSpace(string, string);
    ~DoorSpace();
    void special();
    void setSpecial(Space* N, Space* S, Space* E, Space* W);
    bool getStatus();
    void describeSpace();
    
};

#endif /* doorSpace_hpp */
