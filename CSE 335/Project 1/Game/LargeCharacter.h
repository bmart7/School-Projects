/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LargeCharacter.h
 * Author: bmart
 *
 * Created on February 25, 2019, 5:34 AM
 */

#ifndef LARGECHARACTER_H
#define LARGECHARACTER_H

#include "Character.h"
#include <string>

using namespace std;

class LargeCharacter : public Character{
public:
    LargeCharacter(string a, string b, double c, int d, double e, string f, string mSkill):Character(a,b,c,d,e,f){
        skill = mSkill;
    };
    virtual void print() const;
private:
    string skill;
};

#endif /* LARGECHARACTER_H */

