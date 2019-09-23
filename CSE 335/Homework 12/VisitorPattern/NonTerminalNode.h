/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonTerminalNode.h
 * Author: bmart
 *
 * Created on March 18, 2019, 7:03 PM
 */

#ifndef NONTERMINALNODE_H
#define NONTERMINALNODE_H

#include "Node.h"
#include <vector>

using namespace std;

class NonTerminalNode : public Node{
public:
    NonTerminalNode(int val):Node(val){};
    virtual ~NonTerminalNode();
    virtual void Accept(Visitor* v);
    int getSize() const;
    Node* getChild(int i) const;
    void addChild(Node* n);
    void removeChild(Node* n);
private:
    vector<Node*> nodes;
};

#endif /* NONTERMINALNODE_H */

