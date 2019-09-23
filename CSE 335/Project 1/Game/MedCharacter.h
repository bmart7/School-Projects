/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MedCharacter.h
 * Author: bmart
 *
 * Created on February 25, 2019, 5:33 AM
 */

#ifndef MEDCHARACTER_H
#define MEDCHARACTER_H

#include "Character.h"
#include <string>

using namespace std;

class MedCharacter : public Character {
public:
    MedCharacter(string a, string b, double c, int d, double e, string f, string mWeapon):Character(a,b,c,d,e,f){
        weapon = mWeapon;
    };
    virtual void print() const;
private:
    string weapon;
};

#endif /* MEDCHARACTER_H */

