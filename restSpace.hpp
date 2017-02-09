/*********************************************************************
 ** Program Filename: restSpace.hpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: restSpace declaration
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef restSpace_hpp
#define restSpace_hpp

#include <iostream>
#include "space.hpp"

using std::string;

class RestSpace:public Space{
private:
    
public:
    RestSpace(string, string);
    ~RestSpace();
    void special();
    void describeSpace();
    
};

#endif /* restSpace_hpp */
