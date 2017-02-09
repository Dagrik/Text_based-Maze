/*********************************************************************
 ** Program Filename: hero.hpp
 ** Author: Joshua Sears
 ** Date: 2 dec 15
 ** Description: hero class declaration
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef hero_hpp
#define hero_hpp

#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "creature.hpp"

class Hero: public Creature{
private:
    
    
public:
    Hero();
    void defense(int);
    string getName();
    void getDesc();
    void healme(int);
};

#endif /* hero_hpp */
