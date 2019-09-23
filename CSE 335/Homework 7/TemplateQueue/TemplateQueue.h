/*
 * Vector implemented Queue that is templated to hold data of any type
 */

/* 
 * File:   TemplateQueue.h
 * Author: Brian Martin
 *
 * Created on February 5, 2019, 8:44 PM
 */

#ifndef TEMPLATEQUEUE_H
#define TEMPLATEQUEUE_H

#include <vector>
using namespace std;

template <class X> class TemplateQueue{
    
protected:
    vector<X> data;
    
public:
    TemplateQueue(){
    };
    
    void push(X obj){
        data.push_back(obj);
    }
    
    X pop(){
        if (!data.empty()){
            X temp = data[0];
            data.erase(data.begin());
            return temp;
        }
        else{
            throw "Queue Empty";
        }
    }
    
    bool empty(){
        return data.empty();
    }
    
    X top(){
        if (!data.empty()){
            return data[0];
        }
        else{
            throw "Queue Empty";
        }
    }
    
};

#endif /* TEMPLATEQUEUE_H */

