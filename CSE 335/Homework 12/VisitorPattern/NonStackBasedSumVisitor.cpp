/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonStackBasedSumVisitor.cpp
 * Author: bmart
 * 
 * Created on March 18, 2019, 7:18 PM
 */

#include "NonStackBasedSumVisitor.h"
#include "NonTerminalNode.h"
#include "TerminalNode.h"

NonStackBasedSumVisitor::~NonStackBasedSumVisitor() {
}

void NonStackBasedSumVisitor::visitNonTerminalNode(NonTerminalNode* ntrn){
    sum += ntrn->getValue();
    for (int i=0; i<ntrn->getSize(); i++){
        ntrn->getChild(i)->Accept(this);
    }
}

void NonStackBasedSumVisitor::visitTerminalNode(TerminalNode* trn){
    sum += trn->getValue();
}

int NonStackBasedSumVisitor::getResult(){
    int result = sum;
    sum = 0;
    return result;
}