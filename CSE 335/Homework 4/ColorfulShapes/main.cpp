/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: bmart
 *
 * Created on January 24, 2019, 6:15 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Square.h"
#include "Circle.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Square square1 = Square(1,1,"white",1);
    Square square2 = Square(2,2,"white",2);
    Square square3 = Square(3,3,"black",3);
    Square square4 = Square(4,4,"black",4);
    
    Circle circle1 = Circle(1,1,"red",1);
    Circle circle2 = Circle(2,2,"red",2);
    
    vector<Shape*> shapes;
    shapes.push_back(&square1);
    shapes.push_back(&square2);
    shapes.push_back(&square3);
    shapes.push_back(&square4);
    shapes.push_back(&circle1);
    shapes.push_back(&circle2);
    
    for (int i = 0; i<shapes.size(); i++){
        shapes[i]->printColor();
        cout<<shapes[i]->computeArea()<<endl;
    }

    return 0;
}

