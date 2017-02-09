/*********************************************************************
 ** Program Filename: goblin.cpp
 ** Author: Joshua Sears
 ** Date: 30 Nov 15
 ** Description: subclass Goblin definitions
 ** Input: None
 ** Output: None
 *********************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "goblin.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


/*********************************************************************
 ** Function: Goblin()
 ** Description: calls base class constructor, then also sets additional value
 ** Parameters: none
 ** Pre-Conditions: subclass object created
 ** Post-Conditions: subclass member variables set
 *********************************************************************/
Goblin::Goblin(): Creature(2, 6, 1, 6, 3, 8, "Goblin"){
    this->achilles = 0;
}


/*********************************************************************
 ** Function: attack
 ** Description: Virtual function, generates random attack value.  Additionally
 **              checks for "Achilles" special attack
 ** Parameters: string value of enemy's name
 ** Pre-Conditions: subclass object created
 ** Post-Conditions: returns int value
 *********************************************************************/
int Goblin::attack(Creature* enemy){
    int totalAtk = 0;
    
    //Loops num of dice times, rand for size of dice
    for(int count = 0; count < this->atkDieNum; count++){
        totalAtk += rand() % this->atkDieType + 1;
    }
    
    //Checks if attacking another goblin, then if attack was 12
    //If true, sets Achilles value to 1 (true)
    if (!(enemy->getName() == "Goblin 1" || enemy->getName() == "Goblin 2")){
        if(totalAtk == 12 ){
            cout << this->name << " goes for the achilles!" << endl;
            enemy->setAchilles();
        }
    }
    return totalAtk;
    
}


/*********************************************************************
 ** Function: getName()
 ** Description: returns name of goblin object
 ** Parameters: none
 ** Pre-Conditions: subclass object created
 ** Post-Conditions: string name returned
 *********************************************************************/
string Goblin::getName(){
    return this->name;
}

/*********************************************************************
 ** Function: getDesc()
 ** Description: returns description
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Goblin::getDesc(){
    if(this->isDead(0)){
        cout << "A dead goblin lays on the floor." << endl;
    } else{
        cout << "A raging goblin stares at you ready to strike!" << endl;
    }
    return;
}