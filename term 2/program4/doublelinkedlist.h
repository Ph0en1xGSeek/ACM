// File Name:    doublelinkedlist.h
// Author:       Pan Guosheng
// Student Number: 3014218157

// Assignment:   #4
// Class Description:  This is a double linked list class with which you can insert nodes to it or
//				       remove nodes from it. It can also be printed by iteration.


#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "node.h"


class DoubleLinkedList
{
    public:
        DoubleLinkedList();
        virtual ~DoubleLinkedList();
        DoubleLinkedList(const DoubleLinkedList&);
        DoubleLinkedList& operator=(const DoubleLinkedList& dll);
        friend ostream& operator<<(ostream& ostr, DoubleLinkedList& dll);
        bool insert(const PGSString& str);
        bool remove( const PGSString& str);
        int getNumberElements( );
        void resetIteration();
        PGSString& next();
        bool hasNext();


    private:
        Node* head;
        Node* tail;
        Node* nodePtr;
        int numElements;
};

#endif // DOUBLELINKEDLIST_H
