/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bundle.cpp
 * Author: bmart
 * 
 * Created on March 13, 2019, 7:13 PM
 */

#include "Bundle.h"
#include <iostream>
#include <algorithm>

Bundle::~Bundle() {
    for (int i=0;i<items.size();i++){
        delete items[i];
    }
}

int Bundle::getPrice() const{
    int sum = 0;
    for (int i = 0; i < items.size(); i++){
        sum += items[i]->getPrice();
    }
    return sum * discount;
}

void Bundle::print() const{
    cout<<"Bundle "<<name<<" contains: (";
    for (int i=0;i<items.size();i++){
        items[i]->print();
    }
    cout<<";Bundle Price="<<getPrice()<<");";
}

void Bundle::addItem(Item* item){
    items.push_back(item);
}

void Bundle::removeItem(Item* item){
    remove(items.begin(),items.end(),item);
}

Item* Bundle::getItem(int i) const{
    return items[i];
}