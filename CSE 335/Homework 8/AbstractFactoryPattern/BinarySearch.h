/*
 * 
 */

/* 
 * File:   BinarySearch.h
 * Author: Brian Martin (A56350138)
 *
 * Created on February 10, 2019, 8:51 PM
 */

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "AbstractVectorSearchable.h"

class BinarySearch{
    
public:
    BinarySearch(){
    }
    
    int search(AbstractVectorSearchable* avs){
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
    
};

#endif /* BINARYSEARCH_H */

