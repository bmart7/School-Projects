/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegerVectorSortableSearchable.h
 * Author: Brian Martin (A56350138)
 *
 * Created on February 17, 2019, 7:15 PM
 */

#ifndef INTEGERVECTORSORTABLESEARCHABLE_H
#define INTEGERVECTORSORTABLESEARCHABLE_H

#include "IntegerVectorSortable.h"
#include "AbstractVectorSearchable.h"

class IntegerVectorSortableSearchable : public AbstractVectorSearchable, 
        public IntegerVectorSortable{
    
private:
    int query;
        
public:
    IntegerVectorSortableSearchable(): AbstractVectorSearchable(), 
        IntegerVectorSortable(){
        query = 0;
    };
    virtual int getSize() const;
    virtual int compareAt(int i) const;
    virtual void print() const;
    virtual void setQuery(int i);

};

#endif /* INTEGERVECTORSORTABLESEARCHABLE_H */

