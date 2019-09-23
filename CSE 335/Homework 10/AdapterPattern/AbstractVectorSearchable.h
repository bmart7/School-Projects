/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbstractVectorSearchable.h
 * Author: Brian Martin (A56350138)
 *
 * Created on February 17, 2019, 7:08 PM
 */

#ifndef ABSTRACTVECTORSEARCHABLE_H
#define ABSTRACTVECTORSEARCHABLE_H

using namespace std;

class AbstractVectorSearchable{
    
public:
    AbstractVectorSearchable();
    virtual int getSize() const = 0;
    virtual int compareAt(int i) const = 0;
    virtual void print() const = 0;
};

#endif /* ABSTRACTVECTORSEARCHABLE_H */

