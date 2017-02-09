/*********************************************************************
 ** Program Filename: hero.cpp
 ** Author: Joshua Sears
 ** Date: 2 dec 15
 ** Description: hero class definitions
 ** Input: None
 ** Output: None
 *********************************************************************/

#include <iostream>
#include "creature.hpp"
#include "hero.hpp"

using std::cout;
using std::endl;
using std::cin;


/*********************************************************************
 ** Function: Hero
 ** Description: constructor
 ** Parameters:none
 ** Pre-Conditions: class created
 ** Post-Conditions: none
 *********************************************************************/
Hero::Hero(): Creature(2, 10, 1, 6, 5, 12, "You"){
}

/*********************************************************************
 ** Function: defense
 ** Description: determines damage
 ** Parameters: int
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Hero::defense(int incoming){
    int damage = 0;
    int totalDef = 0;
    int dodge = 0;
    
    //Calculates random value for dodge btw 0 and 100
    dodge = rand() % 101;
    
    //If dodge >50, takes 0 damage
    if(dodge > 50){
        cout << "You danced around the attack!" << endl;
        return;
    }
    
    //Calculates defense roll
    for(int count = 0; count < this->defDieNum; count++){
        totalDef += rand() % this->defDieType + 1;
    }
    
    //Dam = incoming - defense and armor
    damage = incoming - totalDef - this->armor;
    
    //If damage 0 or less, dodges attack
    if(damage <= 0){
        cout << "The attack missed you!" << endl;
        return;
    }
    
    //Takes damage
    cout << this->name << " took " << damage << " damage!" << endl;
    this->strength -= damage;
    return;
    
}

/*********************************************************************
 ** Function: getName
 ** Description: returns name
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
string Hero::getName(){
    return this->name;
}

/*********************************************************************
 ** Function: getDesc
 ** Description: returns desc
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Hero::getDesc(){
    return;
}

/*********************************************************************
 ** Function: healme
 ** Description: heals creature
 ** Parameters: int
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Hero::healme(int val){
    if((strength + val) > 12){
        this->strength = 12;
        cout << "You are at max health!" << endl;
        return;
    }
    this->strength += val;
    return;
}