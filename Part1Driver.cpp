//
//  Part1Driver.cpp
//  assignment 2
//
//  Created by javier xu on 26/03/2018.
//  Copyright © 2018 javier xu. All rights reserved.
//

#include <iostream>
#include "StackQueue.hpp"
using namespace std;
int main(){
    try{//test the implementation of stackqueue
        StackQueue SQ;
        SQ.enqueue(1);
        SQ.enqueue(0);
        SQ.enqueue(9);
        cout<<SQ.dequeue()<<endl;
        cout<<SQ.dequeue()<<endl;
        SQ.enqueue(8);
        cout<<SQ.dequeue()<<endl;
        cout<<SQ.dequeue()<<endl;//test the transfer of data
        cout<<SQ.dequeue()<<endl;//test whether the exception is thrown when the list is empty
    }
    catch(StackEmpty& EM)
    {
        cout << EM.getMsg()<<endl;
    }
}

