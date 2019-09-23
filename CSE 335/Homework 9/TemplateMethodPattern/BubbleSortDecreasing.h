/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSortDecreasing.h
 * Author: Brian Martin (A56350138)
 *
 * Created on February 13, 2019, 3:47 PM
 */

#ifndef BUBBLESORTDECREASING_H
#define BUBBLESORTDECREASING_H

#include "BubbleSort.h"

class BubbleSortDecreasing : public BubbleSort{
public:
    BubbleSortDecreasing() : BubbleSort(){
    }
    virtual bool needSwap(AbstractVectorSortable * avs, int i, int j) const;

};
#endif /* BUBBLESORTDECREASING_H */

