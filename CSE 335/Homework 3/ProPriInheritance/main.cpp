/*
 * Homework #3 - Protected and Private Inheritance
 * DoubleQueue's and subsequent child classes
 */

/* 
 * File:   main.cpp
 * Author: Brian Martin (A56350138)
 *
 * Created on January 19, 2019, 8:43 PM
 */

#include <cstdlib>
#include<iostream>
#include "Node.h"

using namespace std;

class DoubleQueue {
    
protected:
    Node* front = nullptr;
    Node* back = nullptr;
    int size = 0;

public:
    DoubleQueue(){
    };
    
    void pushLeft(string in) {
        Node* data = new Node(in);
        if (front == nullptr){
            front = data;
            back = data;
        }
        else
        {
            data->next = front;
            front->prev = data;
            front = data;
        }
        size++;
    }
    
    void pushRight(string in) {
        Node* data = new Node(in);
        if (back == nullptr){
            front = data;
            back = data;
        }
        else{
            data->prev = back;
            back->next = data;
            back = data;
        }
        size++;
    }
    
    string popLeft() {
        string data = "";
        if (size != 0 && front != nullptr){
            Node* current = front;
            if (front != back){
                data = current->data;
                front = current->next;
                front->prev = nullptr;
                current->next = nullptr;
            }
            else{
                front = back = nullptr;
                data = current->data;
            }
            delete current;
        }
        size--;
        return data;
    }
    
    string popRight() {
        string data = "";
        if (size != 0 && back != nullptr){
            Node* current = back;
            if (front != back){
                data = current->data;
                back = current->prev;
                back->next = nullptr;
                current->prev = nullptr;
            }
            else{
                front = back = nullptr;
                data = current->data;
            }
            delete current;
        }
        size--;
        return data;
    }
    
    string peakLeft(){
        if(size != 0 && front != nullptr){
            return front->data;
        }
        return nullptr;
    }
    
    string peakRight(){
        if (size != 0 && back != nullptr){
            return back->data;
        }
        return nullptr;
    }
    
    int getSize(){
        return size;
    }

};

class Stack:private DoubleQueue{
    using DoubleQueue::pushLeft;
    using DoubleQueue::popLeft;
    using DoubleQueue::peakLeft;
    
public:
    Stack():DoubleQueue(){
    };
    
    void push(string in){
        DoubleQueue::pushLeft(in);
    }
    
    string pop(){
        return DoubleQueue::popLeft();
    }
    
    string top(){
        return DoubleQueue::peakLeft();
    }
};

class Queue{
private:
    DoubleQueue queue;
    int capacity = 10;
    
public:
    Queue(){
    };
    
    Queue(int cap){
        capacity = cap;
    }
    
    void push(string in){
        queue.pushLeft(in);
    }
    
    string pop(){
        return queue.popRight();
    }
    
    bool full(){
        return queue.getSize() == capacity;
    }
};

int main(int argc, char** argv) {
    
    cout<<"DoubleQueue:\n"<<endl;
    DoubleQueue dequeue = DoubleQueue();
    dequeue.pushLeft("string1");
    dequeue.pushLeft("string2");
    dequeue.pushLeft("string3");
    dequeue.pushLeft("string4");
    dequeue.pushLeft("string5");
    dequeue.pushRight("string6");
    dequeue.pushRight("string7");
    dequeue.pushRight("string8");
    
    for (int i=0; i < 8; i++){
        cout<<dequeue.popLeft()<<endl;
    }
    
    cout<<"\nStack:\n"<<endl;
    Stack stack = Stack();
    stack.push("string100");
    stack.push("string200");
    stack.push("string300");
    stack.push("string400");
    
    for (int i=0; i<4; i++){
        cout<<stack.pop()<<endl;
    }
    
    cout<<"\nQueue:\n"<<endl;
    Queue queue = Queue(4);
    queue.push("string10");
    queue.push("string20");
    queue.push("string30");
    queue.push("string40");
    
    for (int i=0; i<4; i++){
        cout<<queue.pop()<<endl;
    }
    
    return 0;
}

