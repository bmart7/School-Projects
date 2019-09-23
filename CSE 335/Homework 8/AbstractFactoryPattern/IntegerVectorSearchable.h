/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegerVectorSearchable.h
 * Author: bmart
 *
 * Created on February 10, 2019, 9:12 PM
 */

#ifndef INTEGERVECTORSEARCHABLE_H
#define INTEGERVECTORSEARCHABLE_H

#include <vector>
#include <iostream>
#include "AbstractVectorSearchable.h"

using namespace std;

class IntegerVectorSearchable : public AbstractVectorSearchable{

protected:
    vector<int> data;
    int query;
public:
    IntegerVectorSearchable():AbstractVectorSearchable(){
        query = 0;
    }
    
    virtual int getSize() const{
        return data.size();
    }
    
    virtual int compareAt(int i) const{
        if (data[i] == query){
            return 0;
        }
        else if (data[i] > query){
            return 1;
        }
        else{
            return -1;
        }
    }
    
    virtual void print() const{
        int i;
        for (i = 0; i < data.size() - 1; i++){
            cout<<data[i]<<", ";
        }
        cout<<data[i]<<endl;
    }
    
    void insertInteger(int i){
        data.push_back(i);
    }
    
    virtual void setQuery(int i){
        query = i;
    }
    
};

#endif /* INTEGERVECTORSEARCHABLE_H */

