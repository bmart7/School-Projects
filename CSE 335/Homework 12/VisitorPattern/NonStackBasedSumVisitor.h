/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonStackBasedSumVisitor.h
 * Author: bmart
 *
 * Created on March 18, 2019, 7:18 PM
 */

#ifndef NONSTACKBASEDSUMVISITOR_H
#define NONSTACKBASEDSUMVISITOR_H

#include "Visitor.h"

class NonStackBasedSumVisitor : public Visitor{
public:
    NonStackBasedSumVisitor():Visitor(),sum(0){};
    virtual ~NonStackBasedSumVisitor();
    virtual void visitTerminalNode(TerminalNode* trn);
    virtual void visitNonTerminalNode(NonTerminalNode* ntrn);
    int getResult();
private:
    int sum;
};

#endif /* NONSTACKBASEDSUMVISITOR_H */

