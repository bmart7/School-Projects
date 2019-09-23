/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegerVectorSortable.h
 * Author: Brian Martin (A56350138)
 *
 * Created on February 13, 2019, 3:10 PM
 */

#ifndef INTEGERVECTORSORTABLE_H
#define INTEGERVECTORSORTABLE_H

#include <vector>
#include "AbstractVectorSortable.h"

using namespace std;

class IntegerVectorSortable : public AbstractVectorSortable{

protected:
    vector<int> data;
public:
    IntegerVectorSortable():AbstractVectorSortable(){
    };
    virtual int getSize() const {return data.size();};
    virtual void swap(int i, int j);
    virtual bool smaller(int i, int j) const;
    virtual void print() const;
    int getInteger(int i) const {return data[i];};
    void insertInteger(int i){data.push_back(i);};

};

#endif /* INTEGERVECTORSORTABLE_H */

