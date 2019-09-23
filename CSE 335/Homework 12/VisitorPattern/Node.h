/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: bmart
 *
 * Created on March 18, 2019, 6:51 PM
 */

#ifndef NODE_H
#define NODE_H

#include "Visitor.h"

class Node {
public:
    Node(int val):value(val){};
    virtual ~Node();
    int getValue() const;
    virtual void Accept(Visitor* v) = 0;
protected:
    int value;
};

#endif /* NODE_H */

