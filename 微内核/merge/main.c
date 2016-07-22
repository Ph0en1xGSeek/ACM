#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}node;//带附加头节点

void reverse(node *c)
{
    node *p = c->next;
    node *q;
    c->next = NULL;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        q->next = c->next;
        c->next = q;
    }

}

void merge(node *a, node *b)
{
    node *p = a->next;
    node *q = b->next;
    node *pre = a;
    while(p != NULL && q != NULL)
    {
        if(p->data <= q->data)
        {
            b->next = q->next;
            q->next = p->next;
            p->next = q;

            pre = q;
            p = pre->next;
            q = b->next;
        }
        else
        {
            b->next = q->next;
            q->next = p;
            pre->next = q;

            pre = q;
            q = b->next;
        }
    }
    if(p == NULL && q != NULL)
        pre->next = q;
    free(b);
    reverse(a);
}



int main()
{
    printf("Hello world!\n");
    return 0;
}
