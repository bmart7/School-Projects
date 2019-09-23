/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TerminalNode.h
 * Author: bmart
 *
 * Created on March 22, 2019, 9:00 PM
 */

#ifndef TERMINALNODE_H
#define TERMINALNODE_H

#include "Node.h"

class TerminalNode : public Node{
public:
    TerminalNode(string val):Node(val){};
    virtual void print() const;
    virtual void Accept(Visitor* v);
};

#endif /* TERMINALNODE_H */

