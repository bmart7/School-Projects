/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Phone.h
 * Author: bmart
 *
 * Created on March 13, 2019, 7:12 PM
 */

#ifndef PHONE_H
#define PHONE_H

#include "Item.h"

class Phone : public Item{
public:
    Phone(string n_name,int n_price,int n_year):
                Item(n_name),price(n_price),year(n_year){};
    virtual ~Phone();
    virtual int getPrice() const;
    virtual void print() const;
private:
    int price;
    int year;
};

#endif /* PHONE_H */

