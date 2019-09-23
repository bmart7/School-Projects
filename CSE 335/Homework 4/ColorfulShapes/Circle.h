/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: bmart
 *
 * Created on January 24, 2019, 6:40 PM
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#define PI 3.1415

using namespace std;

class Circle : public Shape{
public:
    Circle():Shape(){
        radius = 0.0;
    };
    
    Circle(const double& x, const double& y, const string& c, const double& r):Shape(x,y,c){
        radius = r;
    };
    
    virtual double computeArea() const{
        return PI * radius * radius;
    }
    
protected:
    double radius;
};

#endif /* CIRCLE_H */

