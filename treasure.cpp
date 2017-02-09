/*********************************************************************
 ** Program Filename: treasure.cpp
 ** Author: Joshua Sears
 ** Date: 29 Nov 15
 ** Description: treasure struct constructor
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "treasure.hpp"

Treasure::Treasure(string item, string words){
    this->name = item;
    this->desc = words;
}