/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bundle.h
 * Author: bmart
 *
 * Created on March 13, 2019, 7:13 PM
 */

#ifndef BUNDLE_H
#define BUNDLE_H

#include "Item.h"
#include <vector>

class Bundle : public Item{
public:
    Bundle(string n_name, double n_discount):Item(n_name),discount(n_discount){};
    virtual ~Bundle();
    virtual int getPrice() const;
    virtual void print() const;
    void addItem(Item* item);
    void removeItem(Item* item);
    Item* getItem(int i) const;
private:
    double discount;
    vector<Item*> items;
};

#endif /* BUNDLE_H */

