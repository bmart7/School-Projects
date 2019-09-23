/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonTerminalNode.h
 * Author: bmart
 *
 * Created on March 22, 2019, 9:01 PM
 */

#ifndef NONTERMINALNODE_H
#define NONTERMINALNODE_H

#include "Node.h"

class NonTerminalNode : public Node {
public:
    NonTerminalNode(string val):Node(val){};
    virtual void print() const;
    void setLeft(Node* node);
    void setRight(Node* node);
    Node* getLeft() const;
    Node* getRight() const;
    virtual void Accept(Visitor* v);
private:
    Node* left;
    Node* right;
};

#endif /* NONTERMINALNODE_H */

