/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TerminalNode.cpp
 * Author: bmart
 * 
 * Created on March 22, 2019, 9:00 PM
 */

#include "TerminalNode.h"
#include <iostream>

using namespace std;

void TerminalNode::print() const{
    cout<<value;
}

void TerminalNode::Accept(Visitor* v){
    v->visitTerminalNode(this);
}

