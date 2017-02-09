/*********************************************************************
 ** Program Filename: goblin.hpp
 ** Author: Joshua Sears
 ** Date: 1 Nov 15
 ** Description: Goblin subclass declarations
 ** Input: None
 ** Output: None
 *********************************************************************/
#ifndef __Assignment_3__goblin__
#define __Assignment_3__goblin__

#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "creature.hpp"

class Goblin: public Creature{
private:
    bool achilles;
    
public:
    Goblin();
    int attack(Creature*);
    string getName();
    void getDesc();
};

#endif 
