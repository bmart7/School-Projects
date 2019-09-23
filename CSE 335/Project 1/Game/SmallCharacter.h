/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SmallCharacter.h
 * Author: bmart
 *
 * Created on February 25, 2019, 5:31 AM
 */

#ifndef SMALLCHARACTER_H
#define SMALLCHARACTER_H

#include "Character.h"
#include <string>

using namespace std;

class SmallCharacter : public Character{
public:
    SmallCharacter(string a, string b, double c, int d, double e, string f, bool mHasGun):Character(a,b,c,d,e,f){
        hasGun = mHasGun;
    };
    virtual void print() const;
private:
    bool hasGun;
};

#endif /* SMALLCHARACTER_H */

