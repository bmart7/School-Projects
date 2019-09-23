/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.cpp
 * Author: bmart
 * 
 * Created on February 25, 2019, 5:28 AM
 */

#include "Character.h"

using namespace std;

Character::Character(string mName, string mSize, double mWeight, int mSpeed, double mHairLength, string mRace) {
    name = mName;
    size = mSize;
    weight = mWeight;
    speed = mSpeed;
    hairLength = mHairLength;
    race = mRace;
}

double Character::getHair() const{
    return hairLength;
}

int Character::getSpeed() const{
    return speed;
}

string Character::getRace() const{
    return race;
}