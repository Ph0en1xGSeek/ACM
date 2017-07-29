// File Name:    prog6.cpp
// Author:       Pan Guosheng
// Student Number: 3014218157
// Assignment:   #6
// Description:  This program is a test of the STL algorithm merge written by
//				 ourselves. Merge function will move a link list into another
//               list. after moved, the former one will be empty and can be used
//               again. There will be 7 test cases.


#include <iostream>
#include <iomanip>
#include "LkList.h"

using namespace std;

int main(){

    LkList list, list2;

    //------------------------

    list.merge(list2);

    cout << "Merge #1 (empty merge): \n" << list << endl;
    cout << "List size after merge: " << list.size() << endl;
    cout << endl << endl;


    //------------------------


    for(int i = 0; i <= 40; i+=10){
        list2.insert(i);
    }

    list.merge(list2);

    cout << "Merge #2 (into an empty list): \n" << list << endl;
    cout << "List size after merge: " << list.size() << endl;
    cout << endl << endl;

    list.clear();
    list2.clear();


    //------------------------


    for(int i = 0; i <= 40; i+=5){
        list.insert(i);
    }

    list.merge(list2);

    cout << "Merge #3 (from an empty list): \n" << list << endl;
    cout << "List size after merge: " << list.size() << endl;
    cout << endl << endl;

    list.clear();
    list2.clear();

//    //------------------------
//
//

    list.insert(1);
    list.insert(3);

    for(int i = 40; i < 70; i+=7){
        list.insert(i);
    }


    for(int i = 0; i < 20; i+=3){
        list2.insert(i);
    }

    list.merge(list2);

    cout << "Merge #4(source before destination): \n" << list << endl;
    cout << "List size after merge: " << list.size() << endl;
    cout << endl << endl;

    list.clear();
    list2.clear();


    //------------------------

    for(int i = 10; i <= 30; i+=7){
        list.insert(i);
    }


    for(int i = 50; i <= 65; i+=3){
        list2.insert(i);
    }

    list.merge(list2);

    cout << "Merge #5(source after destination): \n" << list << endl;
    cout << "List size after merge: " << list.size() << endl;
    cout << endl << endl;

    list.clear();
    list2.clear();

    //------------------------

    for(int i = 0; i <= 25; i+=5){
        list.insert(i);
    }

    for(int i = -6; i <= 35; i+=2){
        list2.insert(i);
    }

    list.merge( list2 );

    cout << "Merge #6(source overlaps destination):\n" << list << endl;
    cout << "List size after merge: " << list.size() << endl;
    cout << endl << endl;

    list.clear();
    list2.clear();


    //------------------------

    for(int i = -6; i <= 35; i+=4){
        list.insert(i);
    }

    for(int i = 10; i <= 20; i+=3){
        list2.insert(i);
    }

    list.merge( list2 );

    cout << "Merge #7(source within destination):\n" << list << endl;
    cout << "List size after merge: " << list.size() << endl;
    cout << endl << endl;

    list.clear();
    list2.clear();


    //------------------------



    return 0;
}
