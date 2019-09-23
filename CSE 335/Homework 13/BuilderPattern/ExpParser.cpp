/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExpParser.cpp
 * Author: bmart
 * 
 * Created on March 22, 2019, 9:25 PM
 */

#include "ExpParser.h"
#include <stack>
#include <cctype>

ExpParser::ExpParser() {
}

void ExpParser::setBuilder(Builder* b){
    builder = b;
}

void ExpParser::parse(string exp){
    stack<string> valStack;
    stack<string> expStack;
    for (int i=0; i<exp.length(); i++){
        if (exp[i] == '('){
            string temp = "";
            temp += exp[i];
            valStack.push(temp);
        }else if (isdigit(exp[i])){
            string temp = "";
            temp += exp[i];
            while (isdigit(exp[i+1])){
                i++;
                temp += exp[i];
            }
            valStack.push(temp);
        }else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            string temp = "";
            temp += exp[i];
            expStack.push(temp);
        }else if (exp[i] == ')'){
            string right = "";
            if (valStack.top().compare("(") != 0){
                right = valStack.top();
                valStack.pop();
            }
            if (!valStack.empty() && valStack.top().compare("(") != 0){
                string left = valStack.top();
                valStack.pop();
                builder->BuildTerminalNode(left);
            }
            if (right.compare("") != 0){
                builder->BuildTerminalNode(right);
            }
            builder->BuildNonTerminalNode(expStack.top());
            expStack.pop();
            valStack.pop();
        }
    }
}

