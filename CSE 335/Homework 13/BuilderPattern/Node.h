/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: bmart
 *
 * Created on March 22, 2019, 8:53 PM
 */

#ifndef NODE_H
#define NODE_H

#include <string>
#include "Visitor.h"

using namespace std;

class Node {
public:
    Node(string val):value(val){};
    string getValue() const;
    virtual void print() const = 0;
    virtual void Accept(Visitor* v) = 0;
protected:
    string value;
};

#endif /* NODE_H */

