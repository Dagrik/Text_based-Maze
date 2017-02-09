/*********************************************************************
 ** Program Filename: advent.hpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: Adventure class declaraion
 ** Input: None
 ** Output: None
 *********************************************************************/


#ifndef advent_hpp
#define advent_hpp

#include <iostream>
#include <vector>

#include "space.hpp"
#include "creature.hpp"
#include "hero.hpp"
#include "treasure.hpp"


class Adventurer{

protected:
    std::vector<Treasure*> backpack;
    Space* loc;
    Creature* wizard;
    bool winner;
    
public:
    Adventurer(Space*);
    ~Adventurer();
    void move(char);
    Creature* getWiz();
    void seeSpace();
    void list();
    void viewInventory();
    void hint();
    int bagSize();
    bool didIWin();
};

#endif /* advent_hpp */
