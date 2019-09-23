/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MedCharacterFactory.cpp
 * Author: bmart
 * 
 * Created on February 25, 2019, 5:38 AM
 */

#include "MedCharacterFactory.h"
#include "MedCharacter.h"

Character* MedCharacterFactory::createCharacter(vector<string> tokens) {
    return new MedCharacter(tokens[0],tokens[1],
                        stod(tokens[2]),stoi(tokens[3]),
                        stod(tokens[4]),tokens[5],tokens[6]);
}


