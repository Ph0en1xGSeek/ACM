#include <iostream>
#include <stdio.h>

using namespace std;

struct node
{
    int data;
    node *llink;
    node *rlink;
};
node *pre = NULL;
node *root = NULL;
void isBST(node *t, int &flag)
{
    if(t != NULL && flag != 0)
    {
        isBST(t->llink, flag);
        if(pre == NULL) pre = t;
        else if(pre->data < t->data) pre = t;
        else flag = 0;
        isBST(t->rlink, flag);
    }
}

node* CBST(node *root, int K[], int n)
{
    int i;
    node *p, *f;
    for(i = 1; i <= n; i++)
    {
        p = root, f = NULL;
        while(p)
        {
            if(p->data < K[i])
            {
                f = p;
                p = p->rlink;
            }
            else if(p->data > K[i])
            {
                f = p;
                p = p->llink;
            }
        }
        node *newNode = new node;
        newNode->data = K[i];
        newNode->llink = NULL;
        newNode->rlink = NULL;
        if(f == NULL) {root = newNode;}
        else if(f->data < K[i]) f->rlink = newNode;
        else f->llink = newNode;
    }
    return root;
}

void printBST(node *t)
{
    if(t != NULL)
    {
        printf("%d", t->data);
        if(t->llink || t->rlink)
        {
            printf("(");
            printBST(t->llink);
            if(t->rlink) printf(",");
            printBST(t->rlink);
            printf(")");
        }
    }
}


struct trieNode
{
    int num;//����ǰ׺��
    trieNode* next[26];
};

trieNode* searchTrie(trieNode *root, char key[])
{
    trieNode *p = root;
    if(root == NULL) return NULL;
    int i;
    for(i = 0; key[i] != '\0'; i++)
    {
        if(p->next[key[i]-65]->num == 0) return NULL;
        else p = p->next[key[i]-65];
    }
    return p;
}

struct AVLnode
{
    int data;
    int bf;
    node *llink;
    node *rlink;
};

int height(AVLnode *t)
{
    if(t == NULL) return 0;
    if(t->bf == 1 || t->bf == 0) return 1 + height(t->llink);
    if(t->bf == -1) return 1 = height(t->rlink);
}

int main()
{
    int K[6] = {0,2,1,4,3,5};
    root = CBST(root, K, 5);
    int flag = 1;
    isBST(root, flag);
    printf("%d\n", flag);
    printBST(root);
    printf("\n");
    return 0;
}
