/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.h
 * Author: bmart
 *
 * Created on February 25, 2019, 5:28 AM
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>


using namespace std;

class Character {
public:
    Character(string mName, string mSize, double mWeight, int mSpeed, double mHairLength, string mRace);
    virtual void print() const = 0;
    string getRace() const;
    int getSpeed() const;
    double getHair() const;
    template<typename T> void printAttribute(T t, const int& width, string label) const{
        stringstream ss;
        ss << label << t;
        cout << setw(width) << setfill(' ') << left << ss.str();
    }
    
protected:
    string name;
    double weight;
    int speed;
    double hairLength;
    string race;
    string size;
    
};

#endif /* CHARACTER_H */

