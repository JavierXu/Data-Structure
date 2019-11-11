//
//  StackQueue.cpp
//  2.1
//
//  Created by javier xu on 30/03/2018.
//  Copyright © 2018 javier xu. All rights reserved.
//

#include "StackQueue.hpp"
    LinkedStack::LinkedStack(){
        L = new SlinkedList();
        n=0;// initiate an empty list
    };
    LinkedStack::~LinkedStack(){
        delete L;
    }
    void LinkedStack::push(const int& e){
        ++n;
        L->addFront(e);//add a node to the front of the singly linked list
    };
    int LinkedStack::pop() throw(StackEmpty){
        if (empty()) throw StackEmpty("Empty");// throw exception if it's an empty stack
            else{
                const int t = L->front();
                --n;
                L->removeFront();
                return t; //return the popped value
            }
    };
    int LinkedStack::size() const{
        return n;
    };
    bool LinkedStack::empty() const{
        return n==0;
    };


    StackQueue::StackQueue(){
        in = new LinkedStack(); //to insert data
        out = new LinkedStack();//to remove data
    };
    int StackQueue::size() const{
        return in->size();
    }
    bool StackQueue::empty() const{
        return in->empty();
    }
    void StackQueue::enqueue(const int& i){
        in->push(i);
    }
    int StackQueue::dequeue()throw (StackEmpty){
        const int is = in->size();
        for(int i=0; i < is;i++){
            out->push(in->pop());
        }//transfer value from input stack to output stack
        const int np=out->pop();//pop out the first value of the output stack
        
        int os = out->size();
        for (int i=0; i < os;i++){
            in->push(out->pop());
        }//transfer value from output back into input
        return np;//return popped out value
    }
    StackQueue::~StackQueue(){
        delete in;
        delete out;
    };
