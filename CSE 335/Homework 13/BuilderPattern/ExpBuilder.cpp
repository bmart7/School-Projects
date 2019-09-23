/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExpBuilder.cpp
 * Author: bmart
 * 
 * Created on March 22, 2019, 10:23 PM
 */

#include "ExpBuilder.h"
#include <iostream>


ExpBuilder::ExpBuilder() {
}

void ExpBuilder::BuildNonTerminalNode(string val){
    NonTerminalNode* temp = new NonTerminalNode(val);
    temp->setRight(expStack.top());
    expStack.pop();
    temp->setLeft(expStack.top());
    expStack.pop();
    expStack.push(temp);
}

void ExpBuilder::BuildTerminalNode(string val){
    expStack.push(new TerminalNode(val));
}

Node* ExpBuilder::getExpression(){
    Node* root = expStack.top();
    expStack.pop();
    return root;
}
