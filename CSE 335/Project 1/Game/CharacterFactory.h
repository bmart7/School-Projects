/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CharacterFactory.h
 * Author: bmart
 *
 * Created on February 25, 2019, 5:26 AM
 */

#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H

#include "Character.h"
#include <vector>
#include <string>

class CharacterFactory {
public:
    CharacterFactory();
    virtual Character* createCharacter(vector<string> tokens) = 0;

};

#endif /* CHARACTERFACTORY_H */

