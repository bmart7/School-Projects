/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MedCharacterFactory.h
 * Author: bmart
 *
 * Created on February 25, 2019, 5:38 AM
 */

#ifndef MEDCHARACTERFACTORY_H
#define MEDCHARACTERFACTORY_H

#include "CharacterFactory.h"
#include <string>

using namespace std;

class MedCharacterFactory : public CharacterFactory{
public:
    MedCharacterFactory():CharacterFactory(){};
    virtual Character* createCharacter(vector<string> tokens);

};

#endif /* MEDCHARACTERFACTORY_H */

