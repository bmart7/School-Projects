/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackBasedCalVisitor.cpp
 * Author: bmart
 * 
 * Created on March 23, 2019, 12:01 AM
 */

#include "StackBasedCalVisitor.h"
#include "NonTerminalNode.h"
#include "TerminalNode.h"

StackBasedCalVisitor::StackBasedCalVisitor() {
}

void StackBasedCalVisitor::visitNonTerminalNode(NonTerminalNode* node) {
    node->getLeft()->Accept(this);
    node->getRight()->Accept(this);
    double right = resStack.top();
    resStack.pop();
    double left = resStack.top();
    resStack.pop();
    if (node->getValue() == "+"){
        resStack.push(left + right);
    }else if (node->getValue() == "-"){
        resStack.push(left - right);
    }else if (node->getValue() == "*"){
        resStack.push(left * right);
    }else if (node->getValue() == "/"){
        resStack.push(left / right);
    }
}

void StackBasedCalVisitor::visitTerminalNode(TerminalNode* node) {
    resStack.push(stoi(node->getValue()));
}

double StackBasedCalVisitor::getResult(){
    double result = resStack.top();
    resStack.pop();
    return result;
}

