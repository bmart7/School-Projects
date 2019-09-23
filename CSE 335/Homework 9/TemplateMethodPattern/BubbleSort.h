/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSort.h
 * Author: Brian Martin (A56350138)
 *
 * Created on February 13, 2019, 3:31 PM
 */

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "AbstractVectorSortable.h"

class BubbleSort {
public:
    BubbleSort(){
    };
    virtual void sort(AbstractVectorSortable * avs);
    virtual bool needSwap(AbstractVectorSortable * avs, int i, int j) const = 0;

};

#endif /* BUBBLESORT_H */

