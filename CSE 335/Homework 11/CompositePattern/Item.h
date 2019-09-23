/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.h
 * Author: bmart
 *
 * Created on March 13, 2019, 7:13 PM
 */

#ifndef ITEM_H
#define ITEM_H

#include<string>

using namespace std;

class Item {
public:
    Item(string n_name):name(n_name){};
    virtual ~Item();
    virtual string getName() const;
    virtual int getPrice() const = 0;
    virtual void print() const = 0;
protected:
    string name;
};

#endif /* SHOPITEM_H */

