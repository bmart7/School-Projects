/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Builder.h
 * Author: bmart
 *
 * Created on March 22, 2019, 10:22 PM
 */

#ifndef BUILDER_H
#define BUILDER_H

#include "TerminalNode.h"
#include "NonTerminalNode.h"

using namespace std;

class Builder {
public:
    Builder();
    virtual void BuildNonTerminalNode(string val) = 0;
    virtual void BuildTerminalNode(string val) = 0;
};

#endif /* BUILDER_H */

