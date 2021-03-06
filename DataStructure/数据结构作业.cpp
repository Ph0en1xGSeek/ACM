1.
#include <stdio.h>

struct BiTree
{
    BiTree* lchild;
    BiTree* rchild;
    char elem;
};

int precede(char op1, char op2)
{
    if(op1 == '+' || op1 == '-')
    {
        if(op2 == '+' || op2 == '-')
            return 0;
        else
            return -1;
    }
    else if(op1 == '*' || op1 == '/')
    {
        if(op2 == '*' || op2 == '/')
            return 0;
        else
            return 1;
    }
    else
        return -2;
}

void Inorder(BiTree* T)
{
    int bracket;
    if(T)
    {
        if(T->lchild != NULL)
            bracket = precede(T->elem, T->lchild->elem);
        if(bracket == 1)
            printf("(");
        Inorder(T->lchild);
        if(bracket == 1)
            printf(")");
        printf("%c", T->elem);
        if(T->rchild != NULL)
            bracket = precede(T->elem, T->rchild->elem);
        if(bracket == 1)
            printf("(");
        Inorder(T->rchild);
        if(bracket == 1)
            printf(")");
        printf("%c", T->elem);
    }
}

int main()
{
    return 0;
}


2.
#include <stdio.h>

typedef struct BiTree
{
    int elem;
    struct BiTree* son;
    struct BiTree* bro;
};

int count_leave(BiTree* T)
{
    if(T != NULL)
    {
        if(T->son == NULL)
            return 1 + count_leave(T->bro);
        else
            return count_leave(T->son) + count_leave(T->bro);
    }
}

int main()
{
    return 0;
}


3.
#include <stdio.h>
#include <stdlib.h>
#include <queue>

struct BiTree
{
    int elem;
    BiTree* lchild;
    BiTree* rchild;
};

void buildTree(BiTree* T)
{
    int x;
    scanf("%d", &x);
    if(x == 0)  T = NULL;
    else if(x > 0)
    {
        T = (BiTree *)malloc(sizeof(BiTree));
        T->elem = x;
        buildTree(T->lchild);
        buildTree(T->rchild);
    }
    else
    {
        printf("Wrong\n");
        return;
    }
}

bool isComplete(BiTree* root)
{
    BiTree* T;
    int flag = 0;
    std::queue<BiTree*> q;
    while(!q.empty()) q.pop();
    q.push(root);
    while(!q.empty())
    {
        T = q.front();
        q.pop();
        if(T->lchild != NULL && !flag)  q.push(T->lchild);
        else if(T->lchild != NULL)  return false;
        else flag = 1;
        if(T->rchild != NULL && !flag)  q.push(T->rchild);
        else if(T->rchild != NULL)  return false;
        else flag = 1;
    }
    return true;
}

int main()
{
    return 0;
}


4.
#include <stdio.h>
#define M 100
#include <string.h>
#include <iostream>

struct node
{
    int elem;
    int parent;
}tree[M];

int dep[M];

int deep(int x)
{
    if(tree[x].parent == -1)
    {
        dep[x] = 0;
        return 0;
    }
    else if(dep[x] >= 0)
        return dep[x];
    else
        return dep[x] = 1 + deep(tree[x].parent);
}

int main()
{
    int m = 0;
    memset(tree, -1, sizeof(tree));
    memset(dep, -1, sizeof(dep));
    for(int i = 0; i < M; i++)
    {
        if(dep[i] < 0)
            deep(i);
        m = std::max(m, dep[i]);
    }
    printf("%d\n", m);
    return 0;
}


5.
#include <stdio.h>
#include <iostream>
#define M 100

struct BiTree
{
    int elem;
    BiTree* lchild;
    BiTree* rchild;
};

int height(BiTree* T)
{
    if(T == NULL)
        return 0;
    return 1 + std::max(height(T->lchild), height(T->rchild));
}

int width(BiTree* T)
{
    if(T == NULL)
        return 0;
    BiTree* q[M], *p;
    int front = 1, rear = 1, last = 1;
    int tmp = 0, m = 0;
    q[rear] = T;
    while(front <= rear)
    {
        p = q[front++];
        tmp++;
        if(p->lchild != NULL)   q[rear++] = p->lchild;
        if(p->rchild != NULL)   q[rear++] = p->rchild;
        if(front > last)
        {
            last = rear;
            m = std::max(tmp, m);
            tmp = 0;
        }
    }
    return m;
}

int main()
{
    return 0;
}


6.
#include <stdio.h>

struct BiTree
{
    BiTree* lchild, *rchild;
    int elem;
};

bool search_x(BiTree* T, int x)
{
    if(T->elem == x)    return true;
    if(T == NULL)   return false;
    if(search_x(T->lchild, x) || (search_x(T->rchild, x)))
    {
        printf("%d", T->elem);
        return true;
    }
    else
        return false;
}

int main()
{
    return 0;
}


7.
#include <stdio.h>

struct BiTree
{
    BiTree *lchild, *rchild;
    int elem;
};

BiTree* findLast(BiTree *root)
{
    BiTree* p = root;
    if(root == NULL)
        return NULL;
    while(1)
    {
        if(p->rchild != NULL)   p = p->rchild;
        else if(p->rchild != NULL)  p = p->lchild;
        else    return p;
    }
}

int main()
{
    return 0;
}


8.
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

struct BiTree
{
    BiTree *lchild, *rchild;
    int elem;
};

void traverse(BiTree *T)
{
    BiTree* p;
    if(T == NULL)   return;
    queue<BiTree*> q;
    stack<BiTree*> s;
    q.push(T);
    s.push(T);
    while(!q.empty())
    {
        p = q.front();
        if(p->lchild != NULL)
        {
            q.push(p->lchild);
            s.push(p->lchild);
        }
        else if(p->rchild != NULL)
        {
            q.push(p->rchild);
            s.push(p->rchild);
        }
        while(!s.empty())
        {
            p = s.top();
            printf("%d", p->elem);
            s.pop();
        }
    }
}

int main()
{
    return 0;
}


9.
#include <stdio.h>

struct BiTree
{
    BiTree *left, *right;
    int elem;
};

BiTree* postfirst(BiTree* T)
{
    BiTree* p = T;
    if(T == NULL)   return NULL;
    while(1)
    {
        if(T->left != NULL) p = p->left;
        else if(T->right != NULL) p = p->right;
        else return p;
    }
}

int main()
{
    return 0;
}


10.
#include <stdio.h>

struct BiTree
{
    BiTree *lchild, *rchild;
    int elem;
} *pre = NULL, *head = NULL;

BiTree* Inorder(BiTree *T)
{
    if(T == NULL)
        return NULL;
    if(T->lchild == NULL && T->rchild == NULL)
    {
        if(pre == NULL)
        {
            pre = head = T;
            pre->rchild = NULL;
        }
        else
        {
            pre->rchild = T;
            pre = T;
            pre->rchild = NULL;
        }
    }
    Inorder(T->lchild);
    Inorder(T->rchild);
    return head;
}

int main()
{
    return 0;
}
