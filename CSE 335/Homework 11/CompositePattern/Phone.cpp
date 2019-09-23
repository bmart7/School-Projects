/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Phone.cpp
 * Author: bmart
 * 
 * Created on March 13, 2019, 7:12 PM
 */

#include "Phone.h"
#include <iostream>

Phone::~Phone() {
}

int Phone::getPrice() const{
    return price;
}

void Phone::print() const{
    cout<<"(Phone name="<<name<<", Phone price="<<price<<");";
}