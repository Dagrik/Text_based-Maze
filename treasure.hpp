/*********************************************************************
 ** Program Filename: treasure.hpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: treasure struct
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef treasure_hpp
#define treasure_hpp

#include <iostream>
using std::string;


struct Treasure{
    
    string name;
    string desc;
    
    Treasure(string, string);
    
};

#endif /* treasure_hpp */
