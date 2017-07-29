#include "node.h"
#include "pgsstring.h"

Node::Node()
{
    prev = NULL;
    next = NULL;
    data = PGSString();
}

Node::Node(PGSString str)
{
    prev = NULL;
    next = NULL;
    data = str;
}
