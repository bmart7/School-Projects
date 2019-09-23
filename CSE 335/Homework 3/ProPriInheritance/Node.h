/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: bmart
 *
 * Created on January 19, 2019, 10:37 PM
 */

#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node {
public:
    Node(string d){data = d;};
    string data;
    Node* prev = nullptr;
    Node* next = nullptr;

};

#endif /* NODE_H */

