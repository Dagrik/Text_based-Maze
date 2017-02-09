/*********************************************************************
 ** Program Filename: treasurespace.hpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: treasurespace declaration
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef treasureSpace_hpp
#define treasureSpace_hpp

#include <iostream>
#include <vector>
#include "space.hpp"
#include "treasure.hpp"
#include "creature.hpp"

using std::string;

class TreasureSpace:public Space{
protected:
    std::vector<Treasure>* bag;
    Treasure* prize;
    bool isTaken;
public:
    TreasureSpace(string, string);
    ~TreasureSpace();
    void special();
    void describeSpace();
    void setTreasure(Treasure*);
    Treasure* grabTreasure();
    bool isAvail();
};

#endif /* treasureSpace_hpp */
