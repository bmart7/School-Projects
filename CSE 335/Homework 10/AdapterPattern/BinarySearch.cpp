/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearch.cpp
 * Author: Brian Martin (A56350138)
 * 
 * Created on February 17, 2019, 7:11 PM
 */

#include "BinarySearch.h"
#include "AbstractVectorSearchable.h"

int BinarySearch::search(AbstractVectorSearchable* avs) const{
    int left = 0;
        int right = avs->getSize();
        while (left <= right){
            int middle = (left + right) / 2;
            if (avs->compareAt(middle) == 0){
                return middle;
            }
            else if (avs->compareAt(middle) == 1){
                right = middle - 1;
            }
            else{
                left = middle + 1;
            }
        }
        return -1;
}

