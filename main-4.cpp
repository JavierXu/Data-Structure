//
//  main.cpp
//  dshw1
//
//  Created by Yaozhong Xu on 02/03/2018.
//  Copyright © 2018 Yaozhong Xu. All rights reserved.
//

#include <iostream>
using namespace std;
class Set{
private:
    int MaxCard, Card; //private attribute of class Set
    int* Elems; //integer array
public:
    Set()//default constructor
    {MaxCard = 10;
        Card = 0;
    Elems = new int[MaxCard];
    };
    Set(const int mc)//constructor
    {MaxCard = mc;
        Card = 0;
        Elems = new int[mc];
    }
    int getMaxCard()//display MaxCard
    {
        return MaxCard;
    }
    int getCard()//display Card
    {
        return Card;
    }
    Set(const Set& CS)//copy constructor
    {
        MaxCard = CS.MaxCard;
        Card = CS.Card;
        Elems = new int[MaxCard];
    }
    ~Set(){};//destructor
    bool Member(const int VE)//verify if an integer is in the element array
    { for (int n =0; n<Card; n++){
        if (Elems[n] == VE){
            return true;
            }
        }
        return false;
    }
    void AddElem(const int NE)//add an element
    {
        if (Card < MaxCard && Member(NE) == false)
        {
            Elems[Card] = NE;
            Card++;
        }
    }
    int getPosition(const int E)//get the position of an integer in the element array
    {
        if (Member(E)){
            for (int n =0; n<Card; n++){
                if (Elems[n]== E){
                    return n;
                }
            }
        }
        return false;
    }
    void RmvElem(const int RE)//remove an element from the array
    {
        if (Member(RE)==true){
            for (int n =getPosition(RE)+1; n <Card; n++){
                Elems[n-1]=Elems[n];
            }
            Card--;
        }
    }
    void Copy(const Set& NS)//copy a set into another
    {
        MaxCard = NS.MaxCard;
        Card = NS.Card;
        for(int n =0; n <NS.Card; n++){
            NS.Elems[n]=Elems[n];
        }
    }
    bool Equal(const Set& TS)//check if two sets are equal
    {
        int count = 0;
        if (Card == TS.Card){
            for (int n =0; n <Card; n++){
                if (Elems[n]==TS.Elems[n]){
                    count++;
                    }
                }
            }
            if (count == Card){
                return true;
            }
        return false;
    }
    Set Intersect(const Set& IS)//find the intersection of two sets
    {
        Set intersection(Card);
        for (int n =0; n <IS.Card; n++){
            if (Member(IS.Elems[n])){
                intersection.AddElem(IS.Elems[n]);
            }
        }
        return intersection;
    }
    Set Union(Set& US)//find the union of two sets
    {
        Set unionset(Card +US.Card);
        for (int n =0; n <Card; n++){
            unionset.AddElem(Elems[n]);
            }
        for (int n =0; n <US.Card; n++){
            if (!Member(US.Elems[n])){
                unionset.AddElem(US.Elems[n]);
            }
        }
        return unionset;
    }
    void Print()//display the set
    {
        for (int n =0; n <Card; n++){
            if (n ==0){
                cout<<"{";
            }
            else{
                cout<<",";
            }
            cout<<Elems[n];
        }
        cout<<"}"<<endl;
    }
    Set& operator = (const Set &S)//assignment operator
    {
        if (this!= &S){
            delete [] Elems;
            MaxCard=S.MaxCard;
            Card = S.Card;
            Elems=new int[MaxCard];
            for(int n =0; n <S.Card; n++){
                Elems[n]=S.Elems[n];
            }
        }
        return *this;
    }
    bool operator& (const int VI)//overloading operator & to verify whether element VI is in the set
    {
        return Member(VI);
    }
    bool operator== (const Set& TS)//overloading operator == to check the equality of two sets
    {
        return Equal(TS);
    }
    bool operator!= (const Set& TS)//overloading operator != to check the inequality of two sets
    {
        return (!Equal(TS));
    }
    Set operator* (const Set& IS)//overloading operator * to compute the intersection of two sets
    {
        return Intersect(IS);
    }
    Set operator+ (Set& US)//overloading operator + to compute the union of two sets
    {
        return Union(US);
    }
    Set Difference(Set& DS)//find the difference of two sets
    {
        Set difference(Card);
        for (int n =0; n <Card; n++){
            if (!DS.Member(Elems[n])){
                difference.AddElem(Elems[n]);
            }
        }
        return difference;
    }
    Set operator- (Set& DS)//overloading operator - to compute the difference of two sets
    {
        return Difference(DS);
    }
    bool Inclusion(const Set& In)//verify whether one set is inclusive of another
    {
        for (int n =0; n <In.Card; n++){
            if (!Member(In.Elems[n])){
                return false;
            }
        }
        return true;
    }
    bool operator<= (const Set& In)//overloading operator <= to check whether one set is inclusive of another
    {
        return Inclusion(In);
    }
    friend ostream& operator<<(ostream& os, const Set& set)//overloading operator << to display the content of the set
    {
        for (int n =0; n <set.Card; n++){
            if (n ==0){
                os<<"{";
            }
            else{
                os<<",";
            }
            os<<set.Elems[n];
        }
        os<<"}";
        return os;
    }
    friend istream& operator>>(istream& is, Set& set)//overloading operator >> to input the content of the set
    {
        int n;
        cin>>n;
        set.AddElem(n);
        return is;
    }
};

//test the class and its functions
int main(){
    //construct 2 sets
    Set A(5);
    Set B(5);
    //add elements to the 2 sets
    A.AddElem(2);
    A.AddElem(4);
    A.AddElem(6);
    A.AddElem(7);
    A.AddElem(8);
    B.AddElem(7);
    B.AddElem(8);
    B.AddElem(1);
    B.AddElem(3);
    B.AddElem(5);
    cout<<A.getMaxCard()<<endl;
    //remove elements from sets
    A.RmvElem(4);
    B.RmvElem(1);
    cout<<B.getCard()<<endl;
    //print sets
    A.Print();
    B.Print();
    //check whether one element is in the set
    if (A.Member(2)){
        cout<<"Bingo! In set!"<<endl;
    }
    else{
        cout<<"Sorry! Out of set"<<endl;
    }
    //check whether two sets are equal
    if (A.Equal(B)){
        cout<<"Bingo! Equal sets!"<<endl;
    }
    else{
        cout<<"Warning! Not the same!"<<endl;
    }
    //compute intersection and union
    Set IS =A.Intersect(B);
    IS.Print();
    Set US(A.Union(B));
    US.Print();
    //use operators
    //check whether given element is in set
    if (A&1){
        cout<<"Bingo! In set!"<<endl;
    }
    else{
        cout<<"Sorry! Out of set"<<endl;
    }
    //check equality and inequality of two sets
    if (A==B){
        cout<<"Bingo! Equal sets!"<<endl;
    }
    else{
        cout<<"Warning! Not the same!"<<endl;
    }
    if (A!=B){
        cout<<"Warning! Not the same!"<<endl;
    }
    else{
        cout<<"Bingo! Equal sets!"<<endl;
    }
    //compute intersecton, union, and difference
    Set intersec = A*B;
    cout<<intersec<<endl;
    Set unionset = A+B;
    cout<<unionset<<endl;
    Set difference1 = A-B;
    difference1.Print();
    Set difference2 = B-A;
    difference2.Print();
    //check inclusion of a set
    if (A <=intersec){
        cout<<"Included!"<<endl;
    }
    else{
        cout<<"Oh no! Not included!"<<endl;
    }
}
