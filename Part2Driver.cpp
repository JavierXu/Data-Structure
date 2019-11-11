//
//  main.cpp
//  2.2
//
//  Created by javier xu on 29/03/2018.
//  Copyright © 2018 javier xu. All rights reserved.
//
#include <iostream>
#include "DLCirList.hpp"
using namespace std;
class solveMCP {
private:
    DLL * circle; //the initial circle of the missionaries
    DLL* surcle;//the circle of the survivers
    DLL* death;//the order of the dead
    int nummis;// number of missionaries
    friend class DLL;
public:
    solveMCP(const int num) {
        circle = new DLL;
        surcle = new DLL;
        death = new DLL;
        nummis = num;
        for (int i = 0; i<nummis; i++) {//add node to the initial circle
            circle->insertback(i + 1);
        }
    }
    int N() {//ask the user to pick a number for the test
        int a;
        cout << "Please enter the number for the test" << endl;
        cin >> a;
        return a;
    }
    void printcircle(){//display the initial circle
        if(!circle->empty()){
            DLL::Iterator c = circle->begin();
            cout<<"The circle is"<<endl;
            for (int y = 0; y<circle->size(); y++) {
                cout << c.operator*()<<";";
                c.operator++();
            }
            cout<<"\n";
        }
        else{
            return;
        }
    }
    void printdeath() {//display the sequence of the dead
        if(!death->empty()){
            DLL::Iterator i = death->begin();
            cout<<"The order of death is"<<endl;
            for (int x = 0; x<death->size(); x++) {
                cout << i.operator*() << endl;
                i.operator++();
            }
        }
        else{
            return;
        }
    }
    void printsurcle(){//display the order of survivers
        if(!surcle->empty()){
            DLL::Iterator s = surcle->begin();
            cout<<"The order of survivers is"<<endl;
            for (int n=0; n<surcle->size();n++){
                cout<<s.operator*()<<";";
                s.operator++();
            }
            cout<<"\n";
        }
        else{
            return;
        }
    }
    void eatone() {//to decide which missionary to be eaten each time
        int const t = N();
        int const sz = circle->size();
        if (sz % 2 == 0) {//clockwise
            DLL::Iterator cur = circle->end();
            while (circle->size()>1) {
                int adv = t % sz;//decide how much to advance the cursor
                for (int i = 0; i<adv - 1; i++) {
                    cur.operator++();
                }
                surcle->insertback(cur.operator*());//insert surviver to the circle of survivers
                cout<<"The surviver:"<<cur.operator*()<<endl;
                DLL::Iterator old = cur;
                cur.operator++();
                circle->erase(old);//delete the surviver from the initial circle
            }
            death->insertback(cur.operator*());//insert the dead to dead list
        }
        else if (sz % 2 != 0) {//counter clockwise
            DLL::Iterator ccur = circle->begin();//.operator++();
            
            while (circle->size()>1) {
                int adv = t % sz;
                for (int i = 0; i<adv - 1; i++) {
                    ccur.operator--();
                }
                surcle->insertback(ccur.operator*());
                cout<<"The surviver:"<<ccur.operator*()<<endl;
                DLL::Iterator old = ccur;
                ccur.operator--();
                circle->erase(old);
                
            }
            death->insertback(ccur.operator*());
        }
        printsurcle();
        DLL* oldc = circle;
        circle=surcle;
        surcle=new DLL();
        delete oldc;
    }
    void eatthemall(){//repeat the process of deciding which one to eat until there is no one left
        for (int i=0; i<nummis; i++){
            eatone();
        }
    }
};

int main() {
    solveMCP* sol = new solveMCP(10); //create a list of 10 missionaries
    sol->printcircle();//print the initial list
    sol->eatthemall();//carry out the solving process
    sol->printdeath();//print the order of death
}

