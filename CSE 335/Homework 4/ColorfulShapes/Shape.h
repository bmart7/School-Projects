/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shape.h
 * Author: bmart
 *
 * Created on January 24, 2019, 6:16 PM
 */

#ifndef SHAPE_H
#define SHAPE_H

using namespace std;

class Shape {
public:
    Shape(){
        x = 0.0;
        y = 0.0;
        color = "white";
    };
    Shape(const double& x_pos, const double& y_pos, const string& color_n){
        x = x_pos;
        y = y_pos;
        color = color_n;
    };
    
    void printColor() const{
        cout<<color<<endl;
    }
    
    virtual double computeArea()const=0;
    
protected:
    double x;
    double y;
    string color;
};

#endif /* SHAPE_H */

