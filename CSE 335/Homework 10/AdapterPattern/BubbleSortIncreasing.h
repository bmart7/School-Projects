/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSortIncreasing.h
 * Author: Brian Martin (A56350138)
 *
 * Created on February 13, 2019, 3:42 PM
 */

#ifndef BUBBLESORTINCREASING_H
#define BUBBLESORTINCREASING_H

#include "BubbleSort.h"

class BubbleSortIncreasing : public BubbleSort {
public:
    BubbleSortIncreasing():BubbleSort(){
    };
    virtual bool needSwap(AbstractVectorSortable * avs, int i, int j) const;

};

#endif /* BUBBLESORTINCREASING_H */

