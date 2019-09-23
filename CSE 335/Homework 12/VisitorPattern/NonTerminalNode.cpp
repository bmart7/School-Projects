/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonTerminalNode.cpp
 * Author: bmart
 * 
 * Created on March 18, 2019, 7:03 PM
 */

#include "NonTerminalNode.h"
#include <algorithm>

NonTerminalNode::~NonTerminalNode() {
    for (int i=0;i<nodes.size();i++){
        delete nodes[i];
    }
}

void NonTerminalNode::Accept(Visitor* v){
    v->visitNonTerminalNode(this);
}

int NonTerminalNode::getSize() const{
    return nodes.size();
}

Node* NonTerminalNode::getChild(int i) const{
    return nodes[i];
}

void NonTerminalNode::addChild(Node* n){
    nodes.push_back(n);
}

void NonTerminalNode::removeChild(Node* n){
    remove(nodes.begin(),nodes.end(), n);
}