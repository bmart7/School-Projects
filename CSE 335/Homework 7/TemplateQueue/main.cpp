/*
 * Homework #7
 */

/* 
 * File:   main.cpp
 * Author: Brian Martin (A56350138)
 *
 * Created on February 4, 2019, 8:43 PM
 */

#include <cstdlib>
#include <iostream>
#include "TemplateQueue.h"

using namespace std;

int main(int argc, char** argv) {

    TemplateQueue<int> intQueue = TemplateQueue<int>();
    for (int i = 1; i < 7; i++){
        intQueue.push(i);
    }
    for (int i = 0; i < 5; i++){
        cout<<intQueue.pop()<<", ";
    }
    cout<<intQueue.pop()<<endl;
    
    TemplateQueue<double> doubleQueue = TemplateQueue<double>();
    for (double i = 0.1; i < 0.7; i+=.1){
        doubleQueue.push(i);
    }
    for (int i = 0; i < 5; i++){
        cout<<doubleQueue.pop()<<", ";
    }
    cout<<doubleQueue.pop()<<endl;
    
    return 0;
}

