//
//  DLCirList.hpp
//  2.2
//
//  Created by javier xu on 30/03/2018.
//  Copyright © 2018 javier xu. All rights reserved.
//

#ifndef DLCirList_hpp
#define DLCirList_hpp

#include <stdio.h>

#endif /* DLCirList_hpp */
#include <iostream>
using namespace std;

class DLL {
private:
    class DNode {//define node class
    private:
        int elem;
        DNode* prev;
        DNode* next;
        friend class DLL;
    public:
        DNode(const int& n);//create node with integer value in it
        ~DNode() {};
    };
public:
    class Iterator {//create iterator class
    private:
        DNode * v;//refer iterator as a node
        Iterator(DNode* u) {
            v = u;
        };
    public:
        int& operator*();//return the value of the node that the iterator point to
        bool operator==(const Iterator& p) const;//compare position
        bool operator!=(const Iterator& p) const;
        Iterator& operator++();//advance iterator
        Iterator& operator--();//move back iterator
        friend class DLL;
    };
private:
    int n;
    DNode* header;
    DNode* trailer;
public:
    DLL();
    int size() const;
    bool empty() const;
    Iterator begin() const;//the first node of the list
    Iterator end() const;//the last value of the list
    void insertpos(const Iterator& p, const int& i);//insert value at a specific position
    void insertback(const int& i);//insert value after the last node
    void erase(const Iterator& p);//erase the node that the iterator points to
};
