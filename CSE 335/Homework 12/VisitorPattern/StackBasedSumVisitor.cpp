/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackBasedSumVisitor.cpp
 * Author: bmart
 * 
 * Created on March 18, 2019, 7:17 PM
 */

#include "StackBasedSumVisitor.h"
#include "NonTerminalNode.h"
#include "TerminalNode.h"

StackBasedSumVisitor::~StackBasedSumVisitor() {
}

void StackBasedSumVisitor::visitTerminalNode(TerminalNode* trn){
    sum.push(trn->getValue());
}

void StackBasedSumVisitor::visitNonTerminalNode(NonTerminalNode* ntrn){
    for (int i=0; i<ntrn->getSize(); i++){
        ntrn->getChild(i)->Accept(this);
    }
    
    int result = ntrn->getValue();
    for (int i=0; i<ntrn->getSize(); i++){
        result += sum.top();
        sum.pop();
    }
    sum.push(result);
}

int StackBasedSumVisitor::getResult(){
    int result = sum.top();
    sum.pop();
    return result;
}