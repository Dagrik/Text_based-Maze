/*********************************************************************
 ** Program Filename: enemyspace.cpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: enemySpace definitions
 ** Input: None
 ** Output: None
 *********************************************************************/
#include <iostream>
#include "enemySpace.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*********************************************************************
 ** Function: battle
 ** Description: Function which has creatures battle one another.
 **              Determines which one has 0 str first.  Loop runs infinitely
 **              until the isDead() returns true.
 ** Parameters: Two creature pointers
 ** Pre-Conditions: creature objects created
 ** Post-Conditions: displays "death", void return
 *********************************************************************/
void battle(Creature *c1, Creature* c2){
    int atkValue;
    int ignore = 0;
    
    while (ignore < 1){
        cout << endl << "A bolt of energy launches from your hand!" << endl;
        atkValue = c1->attack(c2);
        cout << "Atk: " << atkValue << endl;
        c2->defense(atkValue);
        
        if(c2->isDead(1)){
            cout << endl << c2->getName() << " has died!" << endl;
            cout << "You win!" << endl;
            return;
        }
        
        cout << endl << c2->getName() << " attacks!" << endl;
        atkValue = c2->attack(c1);
        cout << "Atk: " << atkValue << endl;
        c1->defense(atkValue);
        
        if(c1->isDead(1)){
            cout << endl << "You have died!" << endl;
            cout << c2->getName() << " wins!" << endl;
            return;
        }
    }
}

/*********************************************************************
 ** Function: EnemySpace
 ** Description: constructor
 ** Parameters: two strings
 ** Pre-Conditions: class created
 ** Post-Conditions: none
 *********************************************************************/
EnemySpace::EnemySpace(string label, string descrip):Space(){
    this->enemy = new Goblin;
    this->name = label;
    this->desc = descrip;
    this->type = "enemy";
}

/*********************************************************************
 ** Function: ~EnemySpace
 ** Description: destructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: object destroyed
 *********************************************************************/
EnemySpace::~EnemySpace(){
    
}

/*********************************************************************
 ** Function: special
 ** Description: battles charater and enemy
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: battled
 *********************************************************************/
void EnemySpace::special(){
    if(this->enemy->isDead(0)){
        cout << "Goblin is already dead!" << endl;
    } else{
        battle(this->hero, this->enemy);
    }
}

/*********************************************************************
 ** Function: describeSpace
 ** Description: shows description text
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void EnemySpace::describeSpace(){
    cout << this->desc << endl;
    this->enemy->getDesc();
}

/*********************************************************************
 ** Function: setHero()
 ** Description: sets pointer to hero
 ** Parameters: Creature*
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void EnemySpace::setHero(Creature* newHero){
    this->hero = newHero;
}

/*********************************************************************
 ** Function: deadEnemy
 ** Description: returns if enemy is dead
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
bool EnemySpace::deadEnemy(){
    return this->enemy->isDead(0);
}