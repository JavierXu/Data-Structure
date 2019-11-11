//
//  SLinkedList.h
//  2.1
//
//  Created by javier xu on 30/03/2018.
//  Copyright © 2018 javier xu. All rights reserved.
//

#ifndef SLinkedList_h
#define SLinkedList_h


#endif /* SLinkedList_h */
#include <iostream>
using namespace std;

//build node of integers for the singly linked list
class IntNode{
    friend class SlinkedList;
    friend class LinkedStack;
private:
    int elem;//element inside the node
    IntNode* next;//the node next to it
public:
    IntNode(const int& num){
        elem = num;
        next = NULL;
    }//constructor
    ~IntNode(){};//destructor
};

//build the singly linked list
class SlinkedList{
private:
    IntNode* head;
    friend class LinkedStack;
public:
    SlinkedList();
    ~SlinkedList();
    bool empty() const;
    int& front() const; //return the element of the first node
    void addFront(const int& n);//add a new node from the front of the list
    void removeFront();//remove a node from the front of the list
};
