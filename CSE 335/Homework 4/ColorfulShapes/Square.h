/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Square.h
 * Author: bmart
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
    };
    
    Square(const double& x, const double& y, const string& c, const double& e):Shape(x,y,c){
        edge = e;
    };
    
    virtual double computeArea() const{
        return edge * edge;
    }
    
protected:
    double edge;

};
#endif /* SQUARE_H */

