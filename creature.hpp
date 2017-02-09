/*********************************************************************
 ** Program Filename: creature.cpp
 ** Author: Joshua Sears
 ** Date: 1 Nov 15
 ** Description: base class Creature declarations
 ** Input: None
 ** Output: None
 *********************************************************************/


#ifndef __Assignment_3__creature__
#define __Assignment_3__creature__

#include <string>

using std::string;

class Creature{
    
private:
    
protected:
    int atkDieNum;
    int atkDieType;
    int defDieNum;
    int defDieType;
    int armor;
    int strength;
    string name;
    bool achilles;
    
public:
    Creature(int, int, int, int, int, int, string);
    virtual ~Creature();
    virtual int attack(Creature*);
    virtual void defense(int);
    virtual string getName() = 0;  //True virtual function
    virtual bool isDead(int);
    virtual void adjName(string);
    virtual void setAchilles();
    virtual void getDesc() = 0;
    friend bool operator==(Creature&, Creature&);
    virtual void healme(int);
    virtual int getStr();
};

#endif 
