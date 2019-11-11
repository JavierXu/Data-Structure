//
//  StackQueue.hpp
//  2.1
//
//  Created by javier xu on 30/03/2018.
//  Copyright © 2018 javier xu. All rights reserved.
//

#ifndef StackQueue_hpp
#define StackQueue_hpp

#include <stdio.h>

#endif /* StackQueue_hpp */
#include "SLinkedList.h"

//define the exception for empty stack
class RuntimeException{
private:
    string errorMsg;
public:
    RuntimeException(const string& err){errorMsg = err;}
    string getMsg() const{return errorMsg;}
};
class StackEmpty:public RuntimeException{
public:
    StackEmpty(const string&err): RuntimeException(err){}
};

//implement the singly linked list to the use of a stack
class LinkedStack{
private:
    SlinkedList* L; //starts with a singly linked list
    int n;
public:
    LinkedStack();
    ~LinkedStack();
    void push(const int& e); //add a integer
    int pop() throw(StackEmpty);//return the removed integer
    int size() const;
    bool empty() const;
};

//implement the linked stack to the use of a queue
class StackQueue{
private:
    LinkedStack* in; //stack for input
    LinkedStack* out;//stack for output
public:
    StackQueue();
    int size() const;
    bool empty() const;
    void enqueue(const int& i);
    int dequeue()throw (StackEmpty);
    ~StackQueue();
};
