/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSortIncreasing.cpp
 * Author: Brian Martin (A56350138)
 * 
 * Created on February 13, 2019, 3:42 PM
 */

#include "BubbleSortIncreasing.h"

bool BubbleSortIncreasing::needSwap(AbstractVectorSortable * avs, int i, int j)const{
    return !avs->smaller(i, j);
}

