/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegerVectorSortable.cpp
 * Author: Brian Martin (A56350138)
 * 
 * Created on February 13, 2019, 3:10 PM
 */

#include "IntegerVectorSortable.h"
#include <iostream>

using std::cout;
using std::endl;

void IntegerVectorSortable::swap(int i, int j){
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

bool IntegerVectorSortable::smaller(int i, int j) const{
    return getInteger(i) < getInteger(j);
}

void IntegerVectorSortable::print() const{
    for (int i = 0; i < data.size()-1; i++){
        cout<<data[i]<<";";
    }
    cout<<data[data.size()-1]<<";"<<endl;
}

