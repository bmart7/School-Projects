/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackBasedCalVisitor.h
 * Author: bmart
 *
 * Created on March 23, 2019, 12:01 AM
 */

#ifndef STACKBASEDCALVISITOR_H
#define STACKBASEDCALVISITOR_H

#include "Visitor.h"
#include <stack>

using namespace std;

class StackBasedCalVisitor : public Visitor{
public:
    StackBasedCalVisitor();
    virtual void visitNonTerminalNode(NonTerminalNode* node);
    virtual void visitTerminalNode(TerminalNode* node);
    double getResult();
private:
    stack<double> resStack;
};

#endif /* STACKBASEDCALVISITOR_H */

