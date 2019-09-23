/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: Brian Martin (A56350138)
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
        cout<<"Circle -- Default Constructor"<<endl;
    };
    
    Circle(const double& x, const double& y, const string& c, const double& r):Shape(x,y,c){
        radius = r;
        cout<<"Circle -- Constructor"<<endl;
    };
    
    Circle(const Circle& c):Shape(c){
        if (this != &c){
            radius = c.getRadius();
            cout<<"Circle -- Copy Constructor"<<endl;
        }
        else cout<<"Circle -- Copy Constructor (Self-Copy)"<<endl;
    };
    
    virtual ~Circle(){
        cout<<"Circle -- Destructor"<<endl;
    }
    
    Circle& operator=(const Circle& c){
        if (this != &c){
            x = c.getX();
            y = c.getY();
            color = c.getColor();
            radius = c.getRadius();
            cout<<"Circle -- Assignment Operator"<<endl;
        }
        return *this;
    }
    
    double getRadius() const{
        return radius;
    }
    
    virtual double computeArea() const{
        return PI * radius * radius;
    }
    
protected:
    double radius;
};

#endif /* CIRCLE_H */

