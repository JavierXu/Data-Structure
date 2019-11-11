//
//  SLinkedList.cpp
//  2.1
//
//  Created by javier xu on 30/03/2018.
//  Copyright © 2018 javier xu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "SLinkedList.h"
using namespace std;

    SlinkedList::SlinkedList(){
        head = NULL;//an empty list with no head
    };
    SlinkedList::~SlinkedList(){
        while(!empty()) removeFront();
    };
    bool SlinkedList::empty() const{
        return head == NULL;
    }
    const int& SlinkedList::front() const{
        return head -> elem;
    }
    void SlinkedList::addFront(const int& n){
        if (head == NULL){ //if the list is empty, add the node as a head
            IntNode* v = new IntNode(n);
            head = v;
        }
        else {
            IntNode* r = new IntNode(n);
            r->next = head;
            head = r;
        }
    }
    void SlinkedList::removeFront(){
        if (head==NULL){ // if the list is empty, nothing to remove
            return;
        }
        else{
            IntNode* old = head;
            head = old->next;
            delete old;
        }
    }

