// File Name:    LkList.cpp
// Author:       Pan Guosheng
// Student Number: 3014218157
// Assignment:   #6
// Description:  This program is a test of the STL algorithm merge written by
//				 ourselves. Merge function will move a link list into another
//               list. after moved, the former one will be empty and can be used
//               again. There will be 7 test cases.


#include "LkList.h"
#include <iostream>

using namespace std;

LkList::LkList(){
    head = NULL;
    tail = NULL;
    it = NULL;
    count = 0;
}

//LkList::~LkList(){}
//LkList::LkList(const LkList& other){}
//LkList& LkList::operator=(const LkList& rhs){}

int LkList::size(){
    return count;
}

bool LkList::insert(int num ){
    if ( count == 0 ){                      // empty list
        head = tail = new Node( num );
    }
    else{                                   // >1 count, then add back
        Node* temp = new Node( num );
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    count++;
    return true;
}


void LkList::merge( LkList & src ) {
    count += src.count;
    src.count = 0;
    bool isMove;
    bool isTail = false;
    if(src.head == NULL)//list2 is empty
    {
        //do nothing
    }
    else if(head == NULL)//list1 is empty
    {
        head = src.head;
        tail = src.tail;
        src.head = NULL;
        src.tail = NULL;
    }
    else
    {
        if(head->data > src.tail->data)
        {
            src.tail->next = head;
            head->prev = src.tail;
            head = src.head;
            src.head = NULL;
            src.tail = NULL;
        }
        else if(tail->data < src.head->data)
        {
            src.head->prev = tail;
            tail->next = src.head;
            tail = src.tail;
            src.head = NULL;
            src.tail = NULL;
        }
        else
        {
            Node* prevP, *point, *from, *to;
            for(point = head; point != NULL; point = point->next)
            {
                isMove = false;
                //nothing should be moved to this point if it is false;
                prevP = point->prev;
                from = to = src.head;
                while(to->data < point->data && to != src.tail)
                {
                    isMove = true;
                    to = to->next;
                    if(to == src.tail)
                    {
                        if(to->data > point->data)
                        {
                            to = to->prev;
                            isTail = true;
                            break;
                        }
                        else
                            break;
                    }
                }
                if(to != src.tail && isMove)
                {
                    if(isTail)//tail is larger than the point
                        src.head = src.tail;
                    else
                    {
                        src.head = to;
                        to = to->prev;
                    }
                    if(point == head)
                    {
                        to->next = head;
                        head->prev = to;
                        head = from;
                    }
                    else
                    {
                        prevP->next = from;
                        from->prev = prevP;
                        to->next = point;
                        point->prev = to;
                    }
                    src.head->prev = NULL;

                }
                else if(to == src.tail)
                {
                    prevP->next = from;
                    from->prev = prevP;
                    to->next = point;
                    point->prev = to;
                    src.head = src.tail = NULL;
                    break;
                }
            }
            //the elements remain in src is larger than tail
            if(src.head != src.tail)
            {
                src.head->prev = tail;
                tail->next = src.head;
                tail = src.tail;
            }
        }
    }
    src.head = src.tail = NULL;
}  // end of merge function


void LkList::clear(){
    if (count == 0 )
        return;

    while(tail != head){
        tail = tail->prev;
        delete tail->next;
    }
    delete head;
    head = tail = NULL;
    count = 0;
}

void LkList::resetIterator(){
    it = head;
}

bool LkList::hasMore(){
    return (it != NULL );
}

int LkList::next(){
    int num = it->data;
    it = it->next;
    return num;
}

ostream& operator << (ostream & outStr, LkList & lst ){
    lst.resetIterator();
    while( lst.hasMore() )
        outStr << lst.next() << "  ";
    return outStr;
}

