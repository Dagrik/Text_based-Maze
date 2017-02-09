/*********************************************************************
 ** Program Filename: finalspace.hpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: finalSpace declarations
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef finalSpace_hpp
#define finalSpace_hpp

#include <iostream>
#include "space.hpp"



class FinalSpace: public Space{
protected:
    bool finished;
    bool doorClosed;
    Space* altN;
    Space* altS;
    Space* altE;
    Space* altW;
    
public:
    FinalSpace(string, string);
    ~FinalSpace();
    void special();
    void setSpecial(Space* N, Space* S, Space* E, Space* W);
    bool getStatus();
    void describeSpace();
    bool isFinished();
};


#endif /* finalSpace_hpp */
