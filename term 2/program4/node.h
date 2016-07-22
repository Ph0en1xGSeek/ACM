// File Name:    node.h
// Author:       Pan Guosheng
// Student Number: 3014218157

// Assignment:   #4
// Class Description:  An node class that will be used to composite a double linked list. So it has
//				       a prev pointer and a next pointer.


#ifndef NODE_H
#define NODE_H
#include "pgsstring.h"


class Node
{
    public:
        Node();
        Node(PGSString str);
        PGSString data;
        Node* prev;
        Node* next;
};

#endif // NODE_H
