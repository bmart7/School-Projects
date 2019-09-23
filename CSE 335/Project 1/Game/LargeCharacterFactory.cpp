/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LargeCharacterFactory.cpp
 * Author: bmart
 * 
 * Created on February 25, 2019, 5:40 AM
 */

#include "LargeCharacterFactory.h"
#include "LargeCharacter.h"

Character* LargeCharacterFactory::createCharacter(vector<string> tokens) {
    return new LargeCharacter(tokens[0],tokens[1],
                        stod(tokens[2]),stoi(tokens[3]),
                        stod(tokens[4]),tokens[5],tokens[6]);
}

