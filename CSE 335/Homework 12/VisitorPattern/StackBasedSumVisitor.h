/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackBasedSumVisitor.h
 * Author: bmart
 *
 * Created on March 18, 2019, 7:17 PM
 */

#ifndef STACKBASEDSUMVISITOR_H
#define STACKBASEDSUMVISITOR_H

#include "Visitor.h"
#include <stack>

using namespace std;

class StackBasedSumVisitor : public Visitor{
public:
    StackBasedSumVisitor():Visitor(){};
    virtual ~StackBasedSumVisitor();
    virtual void visitTerminalNode(TerminalNode* trn);
    virtual void visitNonTerminalNode(NonTerminalNode* ntrn);
    int getResult();
private:
    stack<int> sum;
};

#endif /* STACKBASEDSUMVISITOR_H */

