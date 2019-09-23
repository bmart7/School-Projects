/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LargeCharacter.cpp
 * Author: bmart
 * 
 * Created on February 25, 2019, 5:34 AM
 */

#include "LargeCharacter.h"
#include <iostream>

using namespace std;

void LargeCharacter::print() const{
    printAttribute(name, 18, "Name: ");
    printAttribute(size, 13, "Size: ");
    printAttribute(weight, 16, "Weight: ");
    printAttribute(speed, 10, "Speed: ");
    printAttribute(hairLength, 15, "HairLen: ");
    printAttribute(race, 17, "Race: ");
    printAttribute(skill, 22, "Skill: ");
    cout<<endl;
}

