//
//  DLCirList.cpp
//  2.2
//
//  Created by javier xu on 30/03/2018.
//  Copyright © 2018 javier xu. All rights reserved.
//

#include "DLCirList.hpp"
#include <iostream>
using namespace std;

DLL::DNode::DNode(const int& n) {//create a node with only a value and nothing else
    elem = n;
    prev = NULL;
    next = NULL;
    }

int&  DLL::Iterator::operator*() {
    return v->elem;
    };

bool DLL::Iterator::operator==(const Iterator& p) const {
    return v == p.v;
    };

bool DLL::Iterator::operator!=(const Iterator& p) const {
    return v != p.v;
    };

DLL::Iterator& DLL::Iterator::operator++() {
    v = v->next;
    return *this;
    };

DLL::Iterator& DLL::Iterator::operator--() {
    v = v->prev;
    return *this;
    };


DLL::DLL() {//initiate an empty list
    n = 0;
    header = NULL;
    trailer = NULL;
    }
int DLL::size() const {
    return n;
    }
bool DLL::empty() const {
    return n == 0;
    }
DLL::Iterator DLL::begin() const {
    return Iterator(header);
    }
DLL::Iterator DLL::end() const {
    return Iterator(trailer);
    }
void DLL::insertpos(const Iterator& p, const int& i) {
    DNode* N = p.v;//show the node that the iterator points to
    DNode* NP = N->prev;
    DNode* nnode = new DNode(i);// new node to insert at the position of the iterator
    nnode->next = N;
    N->prev = nnode;
    nnode->prev = NP;
    NP->next = nnode;
    n++;
    }
void DLL::insertback(const int& i) {
    DNode* nnode = new DNode(i);
    if (header == trailer && header == NULL) {//when it's the first node of an empty list
            header = trailer = nnode;
            nnode->next = nnode->prev = nnode;
            n++;
        }
        else{
            insertpos(end(), i);
        }
    }
void DLL::erase(const Iterator& p) {
        DNode* RM = p.v;//the node to erase
        DNode* SC = RM->next;
        DNode* PR = RM->prev;
        PR->next = SC;
        SC->prev = PR;
        delete RM;
        n--;
    }
