/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Laptop.cpp
 * Author: bmart
 * 
 * Created on March 13, 2019, 7:13 PM
 */

#include "Laptop.h"
#include <iostream>

Laptop::~Laptop() {
}

int Laptop::getPrice() const{
    return price;
}

void Laptop::print() const{
    cout<<"(Laptop name="<<name<<", Laptop price="<<price<<");";
}