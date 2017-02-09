/*********************************************************************
 ** Program Filename: creature.cpp
 ** Author: Joshua Sears
 ** Date: 1 Nov 15
 ** Description: base class Creature definitions
 ** Input: None
 ** Output: None
 *********************************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include "creature.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*********************************************************************
 ** Function: Creature()
 ** Description: constructor for base and all subclasses
 ** Parameters: ints for all values and a string for the name
 ** Pre-Conditions: subclass object created
 ** Post-Conditions: subclass member variables set
 *********************************************************************/

Creature::Creature(int atkNum, int atkType, int defNum, int defType, int arm, int str, string word){
    this->atkDieNum = atkNum;
    this->atkDieType = atkType;
    this->defDieNum = defNum;
    this->defDieType = defType;
    this->armor = arm;
    this->strength = str;
    this->name = word;
    this->achilles = 0;
}

/*********************************************************************
 ** Function: ~Creature
 ** Description: virtual Destructor
 ** Parameters: N/A
 ** Pre-Conditions: None
 ** Post-Conditions: Object destroyed
 *********************************************************************/
Creature::~Creature(){
    
}


/*********************************************************************
 ** Function: attack
 ** Description: Virtual function, generates random attack value.  
 **              If achilles true, damage is halved.
 ** Parameters: string value of enemy's name
 ** Pre-Conditions: subclass object created
 ** Post-Conditions: returns int value
 *********************************************************************/
int Creature::attack(Creature* enemy){
    int totalAtk = 0;
    
    //Loop times = number of dice, rand value for dice size
    for(int count = 0; count < this->atkDieNum; count++){
        totalAtk += rand() % this->atkDieType + 1;
    }
    
    
    //If achilles is hit, all damage cut in half
    if(this->achilles){
        totalAtk /= 2;
        cout << this->name << " damage has been reduced by the achilles hit!" << endl;
    }
    
    return totalAtk;
    
}

/*********************************************************************
 ** Function: defense
 ** Description: Virtual function, generates defense roll, calculates
 **              damage by subtracting armor and defense from attack
 **              Applies to strength
 ** Parameters: int value (opposing creatures attack roll)
 ** Pre-Conditions: opponent made attack
 ** Post-Conditions: creature obtains damage or dodges
 *********************************************************************/
void Creature::defense(int incoming){
    int damage = 0;
    int totalDef = 0;
    
    //Loops num defense dice times, rand value for size of def dice
    for(int count = 0; count < this->defDieNum; count++){
        totalDef += rand() % this->defDieType + 1;
    }
    
    //Atk roll - defense - armor value
    damage = incoming - totalDef - this->armor;
    
    //If damage is 0 or less, creature "dodged"
    if(damage <= 0){
        cout << this->name << " dodged the attack!"<< endl;
        return;
    }
    
    //If not dodged, apply damage to creature
    cout << this->name << " took " << damage << " damage!" << endl;
    this->strength -= damage;
    return;
    
}

/*********************************************************************
 ** Function: isDead()
 ** Description: Virtual function, determines if creatures has 0 or less str
 ** Parameters: none
 ** Pre-Conditions: None
 ** Post-Conditions: returns bool value of true if dead
 *********************************************************************/
bool Creature::isDead(int check = 1){
    
    //Checks if creature is dead.  Shows total strength left
    if(check != 0){
        cout << this->name << " : " << this->strength << " life." << endl;
    }
    if(this->strength <= 0){
        return true;
    } else{
        return false;
    }
}

/*********************************************************************
 ** Function: adjName
 ** Description: Virtual function, adds to name, used when two same creatures
 **              fight
 ** Parameters: string value to add to name
 ** Pre-Conditions: None
 ** Post-Conditions: creature name altered
 *********************************************************************/
void Creature::adjName(string add){
    this->name += add;
}

/*********************************************************************
 ** Function: adjName
 ** Description: Virtual function, sets Achilles status effect to on
 ** Parameters: string value to add to name
 ** Pre-Conditions: None
 ** Post-Conditions: creature name altered
 *********************************************************************/
void Creature::setAchilles(){
    this->achilles = 1;
}

/*********************************************************************
 ** Function: Overloaded == function
 ** Description: compares two creature types
 ** Parameters: two creature addresses
 ** Pre-Conditions: two creature objects created
 ** Post-Conditions: returns true or false
 *********************************************************************/
bool operator==(Creature& left, Creature& right){
    
    return (left.name == right.name);
}

/*********************************************************************
 ** Function: healme
 ** Description: adds to strength
 ** Parameters: integer val
 ** Pre-Conditions: none
 ** Post-Conditions: strength increased
 *********************************************************************/
void Creature::healme(int val){
    this->strength += val;
}

/*********************************************************************
 ** Function: getStr
 ** Description: returns value of str
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int Creature::getStr(){
    return strength;
}
