#include <iostream>
#include <string>
#include "BinaryTrees.h"
#include "BinarySearchTrees.h"
#include "OrderedMap.h"
#include "Header.h"

#define PART 3

using namespace std;


int main()
{
#if PART==1
    // LinkedBinaryTree of int type elems
    LinkedBinaryTree<int>  tr ;
    cout<<"Size tr1= "<<tr.getSize()<<endl ;
    tr.addRoot() ;
    tr.expandExternal(tr.root()) ;
    cout<<"Size tr1= "<<tr.getSize()<<endl ;
    
    // LinkedBinaryTree of Entry type elems
    LinkedBinaryTree<Entry<int, string>>  tr2 ;
    cout<<"\nSize tr2= "<<tr2.getSize()<<endl ;
    tr2.addRoot() ;
    tr2.expandExternal(tr2.root()) ;
    cout<<"Size tr2= "<<tr2.getSize()<<endl ;
    
    
#elif PART==2
    // Create a Search tree, fill it, then disply it
    SearchTree<Entry<int,int>> search ;
    cout<<"nSize= "<<search.getSize()<<endl ;

    search.insert(25,125) ;
    search.insert(35,135) ;
    search.insert(55,145) ;
    search.insert(55,155) ;
    cout<<"Size= "<<search.getSize()<<endl ;
    
    SearchTree<Entry<int,int>>::Iterator iter=search.begin() ;
    while( !(iter == search.end())) {
        cout<<(*iter).key()<<", "<<(*iter).value()<<endl ;
        ++iter;
    }

#elif PART==3
    // Create an OrderedMap, fill it, then disply it
    OrderedMap<int, int> oMap ;
    cout<<"nSize= "<<oMap.getSize()<<endl ;
    oMap.put(25,125) ;
    oMap.put(35,135) ;
    oMap.put(55,145) ;
    oMap.put(55,155) ;


  
    SearchTree<Entry<int,int>>::Iterator iter=oMap.begin() ;
    while( !(iter == oMap.end())) {
        cout<<(*iter).key()<<", "<<(*iter).value()<<endl ;
        ++iter;
    }
	int a;

	OrderedMap<Flight, string> fMap;
	cout << "nSize= " << fMap.getSize() << endl;
	string tt1 = "ORD";
	string tt2 = "PVD";
	string tt3 = "05MAY";
	int time1 = 953;
	int time2 = 1329;
	int time3 = 1739;
	int time4 = 1950;

	Flight flight1 = Flight(tt1,tt2,tt3,time1);
	fMap.put(flight1, "(AA 1840, F5, Y15, 02:05, $251)");
	Flight flight2 = Flight(tt1, tt2, tt3, time2);
	fMap.put(flight2, "(AA 600, F2, Y0, 02:16, $713)");
	Flight flight3 = Flight(tt1, tt2, tt3, time3);
	fMap.put(flight3, "(AA 416, F3, Y9, 02:09, $365)");
	Flight flight4 = Flight(tt1, tt2, tt3, time4);
	fMap.put(flight4, "(AA 1828, F9, Y25, 02:13, $186)");


	SearchTree<Entry<Flight, string>>::Iterator fiter = fMap.begin();
	while (!(fiter == fMap.end())) {

		cout << (*fiter).key()<< ", " << (*fiter).value() << endl;
		++fiter;
	}




	cout <<"\n\n\nThe target we found is\n"<< fMap.higherEntry(1329).v.v->elt.key()<< (*fiter).value() << endl;
	cin >> a;
#endif
    return 0;
}


