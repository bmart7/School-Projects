/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbstractVectorSortable.h
 * Author: Brian Martin (A56350138)
 *
 * Created on February 13, 2019, 3:06 PM
 */

#ifndef ABSTRACTVECTORSORTABLE_H
#define ABSTRACTVECTORSORTABLE_H

class AbstractVectorSortable {
public:
    AbstractVectorSortable();
    virtual int getSize() const = 0;
    virtual void swap(int i, int j) = 0;
    virtual bool smaller(int i, int j) const = 0;
    virtual void print() const = 0;

};

#endif /* ABSTRACTVECTORSORTABLE_H */

