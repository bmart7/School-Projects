/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearch.h
 * Author: Brian Martin (A56350138)
 *
 * Created on February 17, 2019, 7:11 PM
 */

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "AbstractVectorSearchable.h"

class BinarySearch {
public:
    BinarySearch(){
    };
    virtual int search(AbstractVectorSearchable* avs) const;
};

#endif /* BINARYSEARCH_H */

