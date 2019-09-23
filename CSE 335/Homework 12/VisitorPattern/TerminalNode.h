/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TerminalNode.h
 * Author: bmart
 *
 * Created on March 18, 2019, 6:55 PM
 */

#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include "Node.h"

class TerminalNode : public Node{
public:
    TerminalNode(int val):Node(val){};
    virtual ~TerminalNode();
    virtual void Accept(Visitor* v);
};

#endif /* TERMINALNODE_H */

