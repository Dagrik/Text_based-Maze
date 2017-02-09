/*********************************************************************
 ** Program Filename: space.hpp
 ** Author: Joshua Sears
 ** Date: 28 Nov 15
 ** Description: space declarations
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef space_hpp
#define space_hpp

#include "creature.hpp"
using std::string;

class Space{
    
protected:
    Space* north;
    Space* south;
    Space* east;
    Space* west;
    string desc;
    string name;
    string type;
    char map[5][6];
    
public:
    Space();
    ~Space();
    virtual void special() = 0;
    virtual void setPath(Space*, Space*, Space*, Space*);
    Space* nextStep(char);
    virtual void describeSpace() = 0;
    void setMap(int, int);
    void displayMap();
    virtual void setSpecial(Space*, Space*, Space*, Space*);
    string getType();
    
};

#endif /* space_hpp */
