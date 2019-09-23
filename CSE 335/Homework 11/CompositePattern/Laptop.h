/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Laptop.h
 * Author: bmart
 *
 * Created on March 13, 2019, 7:13 PM
 */

#ifndef LAPTOP_H
#define LAPTOP_H

#include "Item.h"

class Laptop : public Item{
public:
    Laptop(string n_name, int n_price, string n_clockSpeed):
                Item(n_name),price(n_price),clockSpeed(n_clockSpeed){};
    virtual ~Laptop();
    virtual int getPrice() const;
    virtual void print() const;
private:
    int price;
    string clockSpeed;
};

#endif /* LAPTOP_H */

