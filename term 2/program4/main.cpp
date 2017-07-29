// File Name:    main.cpp
// Author:       Pan Guosheng
// Student Number: 3014218157
// Assignment:   #4
// Description:  This program will create 4 double linked lists and read from a file
//				 copy to another two linked lists, and remove the words the other one
//               has and add "1" to "10" to them. Print each step


#include <iostream>
#include "pgsstring.h"
#include "node.h"
#include "doublelinkedlist.h"
#include <fstream>
#include <cstdlib>

using namespace std;

inline void print(DoubleLinkedList &dll1, DoubleLinkedList &dll2,
                  DoubleLinkedList &dll3, DoubleLinkedList &dll4)
{
    cout << "Size of the list1: " << dll1.getNumberElements() << endl;
    cout << "Size of the list2: " << dll2.getNumberElements() << endl;
    cout << "Size of the modList1: " << dll3.getNumberElements() << endl;
    cout << "Size of the modList2: " << dll4.getNumberElements() << endl << endl;
}

void changer(DoubleLinkedList list1)
{
    list1.insert("1");
    list1.insert("2");
    list1.insert("3");
    list1.insert("4");
    list1.insert("5");
    list1.insert("6");
    list1.insert("7");
    list1.insert("8");
    list1.insert("9");
    list1.insert("10");
    cout << "Inside changer function size of list is: " << list1.getNumberElements() << endl << endl;
}

int main()
{
    PGSString str;
    DoubleLinkedList list1, list2, modList1, modList2;
    ifstream fin;
    fin.open("file1.txt");
    while(fin >> str)
        list1.insert(str);
    fin.close();
    fin.clear();
    fin.open("file2.txt");
    while(fin >> str)
        list2.insert(str);
    fin.close();
    print(list1, list2, modList1, modList2);
    modList1 = list1;
    modList2 = list2;
    print(list1, list2, modList1, modList2);
    list1.resetIteration();
    list2.resetIteration();
    while(list2.hasNext())
        modList1.remove(list2.next());
    while(list1.hasNext())
        modList2.remove(list1.next());
    print(list1, list2, modList1, modList2);
    changer(modList1);
    changer(modList2);
    print(list1, list2, modList1, modList2);
    ofstream fout;
    fout.open("outfile1.txt");
    fout << modList1;
    fout.close();
    fout.clear();
    fout.open("outfile2.txt");
    fout << modList2;
    fout.close();
    return 0;
}
