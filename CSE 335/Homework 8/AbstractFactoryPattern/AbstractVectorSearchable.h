/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbstractVectorSearchable.h
 * Author: bmart
 *
 * Created on February 10, 2019, 8:55 PM
 */

#ifndef ABSTRACTVECTORSEARCHABLE_H
#define ABSTRACTVECTORSEARCHABLE_H

using namespace std;

class AbstractVectorSearchable{
    
public:
    virtual int getSize() const = 0;
    virtual int compareAt(int i) const = 0;
    virtual void print() const = 0;
    virtual void setQuery(int i) = 0;
};

#endif /* ABSTRACTVECTORSEARCHABLE_H */

