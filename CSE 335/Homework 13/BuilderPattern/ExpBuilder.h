/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExpBuilder.h
 * Author: bmart
 *
 * Created on March 22, 2019, 10:23 PM
 */

#ifndef EXPBUILDER_H
#define EXPBUILDER_H

#include "Builder.h"
#include "TerminalNode.h"
#include "NonTerminalNode.h"
#include <stack>

class ExpBuilder : public Builder {
public:
    ExpBuilder();
    virtual void BuildNonTerminalNode(string val);
    virtual void BuildTerminalNode(string val);
    Node* getExpression();
private:
    Node* quickLeft;
    Node* quickRight;
    stack<Node*> expStack;
};

#endif /* EXPBUILDER_H */

