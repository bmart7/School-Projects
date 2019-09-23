/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSort.cpp
 * Author: Brian Martin (A56350138)
 * 
 * Created on February 17, 2019, 7:04 PM
 */

#include "BubbleSort.h"


void BubbleSort::sort(AbstractVectorSortable * avs){
    bool sorted = false;
    int n = avs->getSize();
    while (!sorted){
        sorted = true;
        for (int i = 1; i < n; i++){
            if (needSwap(avs, i-1, i)){
                avs->swap(i-1, i);
                sorted = false;
            }
        }
        n--;
    }
}