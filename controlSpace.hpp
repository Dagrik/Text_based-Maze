/*********************************************************************
 ** Program Filename: controlspace.hpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: controlSpace declarations
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef controlSpace_hpp
#define controlSpace_hpp

#include <iostream>
#include "space.hpp"

using std::string;

class ControlSpace:public Space{
protected:
    bool switchThrown;
    Space* roomControlled;
    
public:
    ControlSpace(string, string, Space*);
    ~ControlSpace();
    void special();
    bool getStatus();
    void describeSpace();
};

#endif /* controlSpace_hpp */
