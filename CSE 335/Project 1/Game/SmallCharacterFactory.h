/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SmallCharacterFactory.h
 * Author: bmart
 *
 * Created on February 25, 2019, 5:36 AM
 */

#ifndef SMALLCHARACTERFACTORY_H
#define SMALLCHARACTERFACTORY_H

#include "CharacterFactory.h"
#include <string>

using namespace std;

class SmallCharacterFactory : public CharacterFactory{
public:
    SmallCharacterFactory():CharacterFactory(){};
    virtual Character* createCharacter(vector<string> tokens);

};

#endif /* SMALLCHARACTERFACTORY_H */

