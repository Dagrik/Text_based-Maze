/*********************************************************************
 ** Program Filename: enemyspace.hpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: enemySpace declarations
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef enemySpace_hpp
#define enemySpace_hpp

#include <iostream>
#include "space.hpp"
#include "creature.hpp"
#include "goblin.hpp"

class EnemySpace:public Space{
protected:
    Creature* enemy;
    Creature* hero;
    
public:
    EnemySpace(string, string);
    ~EnemySpace();
    void special();
    void describeSpace();
    void setHero(Creature*);
    bool deadEnemy();
};

#endif /* enemySpace_hpp */
