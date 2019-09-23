/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegerVectorSortableSearchable.cpp
 * Author: Brian Martin (A56350138)
 * 
 * Created on February 17, 2019, 7:15 PM
 */

#include "IntegerVectorSortableSearchable.h"

int IntegerVectorSortableSearchable::getSize() const{
    return IntegerVectorSortable::getSize();
}

int IntegerVectorSortableSearchable::compareAt(int i) const{
    if (data[i] == query){
            return 0;
        }
        else if (data[i] > query){
            return 1;
        }
        else{
            return -1;
        }
}

void IntegerVectorSortableSearchable::print() const{
    IntegerVectorSortable::print();
}

void IntegerVectorSortableSearchable::setQuery(int i){
    query = i;
}