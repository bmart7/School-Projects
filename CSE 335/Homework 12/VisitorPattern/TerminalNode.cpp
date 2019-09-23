/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TerminalNode.cpp
 * Author: bmart
 * 
 * Created on March 18, 2019, 6:55 PM
 */

#include "TerminalNode.h"

TerminalNode::~TerminalNode() {
}

void TerminalNode::Accept(Visitor* v){
    v->visitTerminalNode(this);
}