/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExpParser.h
 * Author: bmart
 *
 * Created on March 22, 2019, 9:25 PM
 */

#ifndef EXPPARSER_H
#define EXPPARSER_H

#include <string>
#include "Builder.h"

using namespace std;

class ExpParser {
public:
    ExpParser();
    void parse(string exp);
    void setBuilder(Builder* b);
private:
    Builder* builder;
};

#endif /* EXPPARSER_H */

