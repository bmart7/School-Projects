/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Visitor.h
 * Author: bmart
 *
 * Created on March 22, 2019, 11:58 PM
 */

#ifndef VISITOR_H
#define VISITOR_H

class TerminalNode;
class NonTerminalNode;

class Visitor {
public:
    Visitor();
    virtual void visitTerminalNode(TerminalNode* node) = 0;
    virtual void visitNonTerminalNode(NonTerminalNode* node) = 0;
};

#endif /* VISITOR_H */

