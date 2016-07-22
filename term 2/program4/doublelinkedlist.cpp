#include "doublelinkedlist.h"
#include "node.h"
#include "pgsstring.h"

DoubleLinkedList::DoubleLinkedList()
{
    head = NULL;
    tail = NULL;
    nodePtr = NULL;
    numElements = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
    if(numElements > 1)//many nodes
    {
        Node* ptr = head;
        for(int i = 1; i < numElements; i++)
        {
            ptr = ptr->next;
            delete ptr->prev;
        }
        delete ptr;
    }
    else if(numElements == 1)//one node
    {
        delete head;
    }
   //no node
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& dll)//copy constructor
{
    numElements = dll.numElements;
    if(numElements != 0)//one or more nodes
    {
        Node* temp;
        Node* ptr = dll.head;
        head = tail = new Node;
        head->data = ptr->data;
        for(int i = 1; i < numElements; i++)
        {
            temp = tail;
            tail->next = new Node;
            tail = tail->next;
            ptr = ptr->next;
            tail->data = ptr->data;
            tail->prev = temp;
        }
        resetIteration();
    }
    else//no node
    {
        head = NULL;
        tail = NULL;
        nodePtr = NULL;
    }
}

DoubleLinkedList& DoubleLinkedList:: operator=(const DoubleLinkedList& dll)
{
    if(this != &dll)
    {
        Node* nptr = head;
        for(int i = 1; i < numElements; i++)
        {
            nptr = nptr->next;
            delete nptr->prev;
        }
        delete nptr;
        numElements = dll.numElements;
        if(numElements != 0)
        {
            Node* temp;
            Node* ptr = dll.head;
            head = tail = new Node;
            head->data = ptr->data;
            for(int i = 1; i < numElements; i++)
            {
                temp = tail;
                tail->next = new Node;
                tail = tail->next;
                ptr = ptr->next;
                tail->data = ptr->data;
                tail->prev = temp;
            }
            resetIteration();
        }
        else
        {
            head = NULL;
            tail = NULL;
            nodePtr = NULL;
        }
    }
    return *this;
}

ostream& operator<<(ostream& ostr, DoubleLinkedList& dll)
{
    dll.resetIteration();
    if(dll.hasNext())
        ostr << dll.next();
    while(dll.hasNext())
        ostr << ' ' << dll.next();
    return ostr;
}

bool DoubleLinkedList::insert(const PGSString& str)
{
    if(numElements != 0)//One or more nodes
    {
        Node* ptr = head;
        while(ptr != NULL)//one node situation will skip this loop
        {
            if(ptr->data == str)
                return false;
            else if(ptr->data < str)
                ptr = ptr->next;
            else
            {
                if(ptr != head)
                {
                    Node* follow = ptr->prev;
                    Node* newNode = new Node;
                    newNode->data = str;
                    newNode->prev = follow;
                    newNode->next = ptr;
                    follow->next = newNode;
                    ptr->prev = newNode;
                    numElements++;
                    return true;
                }
                else//addFirst
                {
                    head->prev = new Node;
                    head = head->prev;
                    head->next = ptr;
                    head->data = str;
                    numElements++;
                    return true;
                }

            }
        }
        if(tail->data != str)//addLast
        {
            Node* follow = tail;
            tail->next = new Node;
            tail = tail->next;
            tail->prev = follow;
            tail->data = str;
            numElements++;
            return true;
        }
        else
            return false;

    }
    else//No Node
    {
        head = tail = new Node;
        head->data = str;
        numElements++;
        resetIteration();
        return true;
    }
}

bool DoubleLinkedList::remove(const PGSString& str)
{
    if(numElements == 0)//No node
        return false;
    else//one or more nodes
    {
        Node* ptr = head;
        for(int i = 1; i <= numElements; i++)
        {
            if(ptr->data == str)
            {
                Node* prePtr = ptr->prev;
                Node* nextPtr = ptr->next;
                delete ptr;
                numElements--;
                if(prePtr == NULL)//removeFirst
                {
                    head = nextPtr;
                    head->prev = NULL;
                    return true;
                }
                if(nextPtr == NULL)//removeLast
                {
                    tail = prePtr;
                    tail->next = NULL;
                    return true;
                }
                prePtr->next = nextPtr;
                nextPtr->prev = prePtr;
                return true;
            }
            else
                ptr = ptr->next;
        }
        return false;
    }
}

int DoubleLinkedList::getNumberElements( )
{
    return numElements;
}

void DoubleLinkedList::resetIteration()
{
    if(numElements != 0)
        nodePtr = head;
    else//no node
        nodePtr = NULL;
}

PGSString& DoubleLinkedList::next()
{
    if(numElements != 0)
    {
        Node* ptr = nodePtr;
        nodePtr = nodePtr->next;
        return ptr->data;
    }

    else//no node
    {
        PGSString emptyStr;
        return emptyStr; //If it is not converted by reference, it can use PGSString() here
    }

}

bool DoubleLinkedList::hasNext()
{
    if(nodePtr == NULL)
        return false;
    else
        return true;
}
