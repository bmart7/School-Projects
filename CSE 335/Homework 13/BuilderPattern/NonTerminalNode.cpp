/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonTerminalNode.cpp
 * Author: bmart
 * 
 * Created on March 22, 2019, 9:01 PM
 */

#include "NonTerminalNode.h"
#include <iostream>

void NonTerminalNode::print() const{
    cout<<"(";
    left->print();
    cout<<value;
    right->print();
    cout<<")";
}

void NonTerminalNode::setLeft(Node* node){
    left = node;
}

void NonTerminalNode::setRight(Node* node){
    right = node;
}

Node* NonTerminalNode::getLeft() const{
    return left;
}

Node* NonTerminalNode::getRight() const{
    return right;
}

void NonTerminalNode::Accept(Visitor* v){
    v->visitNonTerminalNode(this);
}

