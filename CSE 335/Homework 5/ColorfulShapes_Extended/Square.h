/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Square.h
 * Author: Brian Martin (A56350138)
 *
 * Created on January 24, 2019, 6:30 PM
 */

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

using namespace std;

class Square: public Shape {
public:
    Square():Shape(){
        edge = 0.0;
        cout<<"Square -- Default Constructor"<<endl;
    };
    
    Square(const double& x, const double& y, const string& c, const double& e):Shape(x,y,c){
        edge = e;
        cout<<"Square -- Constructor"<<endl;
    };
    
    Square(const Square& s):Shape(s){
        if (this != &s){
            edge = s.getEdge();
            cout<<"Square -- Copy Constructor"<<endl;
        }
        else cout<<"Square -- Copy Constructor (Self-Copy)"<<endl;
    };
    
    virtual ~Square(){
        cout<<"Square -- Destructor"<<endl;
    }
    
    Square& operator=(const Square& s){
        if (this != &s){
            x = s.getX();
            y = s.getY();
            color = s.getColor();
            edge = s.getEdge();
            cout<<"Square -- Assignment Operator"<<endl;
        }
        return *this;
    }
    
    double getEdge() const{
        return edge;
    }
    
    virtual double computeArea() const{
        return edge * edge;
    }
    
protected:
    double edge;

};
#endif /* SQUARE_H */

