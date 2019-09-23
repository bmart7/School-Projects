/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LargeCharacterFactory.h
 * Author: bmart
 *
 * Created on February 25, 2019, 5:40 AM
 */

#ifndef LARGECHARACTERFACTORY_H
#define LARGECHARACTERFACTORY_H

#include "CharacterFactory.h"
#include <string>

using namespace std;

class LargeCharacterFactory : public CharacterFactory{
public:
    LargeCharacterFactory():CharacterFactory(){};
    virtual Character* createCharacter(vector<string> tokens);

};

#endif /* LARGECHARACTERFACTORY_H */

