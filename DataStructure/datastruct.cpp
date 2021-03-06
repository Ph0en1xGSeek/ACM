#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArcNode
{
    int adjvext;
    struct ArcNode *next;
    int num;
}ArcNode;

void add(ArcNode **head, int u, int v, int num)/*#1*/
{
    ArcNode *p = (ArcNode *) malloc(sizeof(ArcNode));
    p->adjvext = v;
    p->num = num;
    p->next = head[u];
    head[u] = p;
}

void toMatrix(ArcNode **head, int n, int arr[][100])/*#2*/
{
    int i;
    ArcNode *p;
    for(i = 0; i < n; i++)
    {
        p = head[i];
        while(p)
        {
            int j = p->adjvext;
            arr[i][j] = (p->num);
            p = p->next;
        }
    }
}

void del(ArcNode **head, int u, int v)/*#3*/
{
    ArcNode *p = head[u];
    ArcNode *pre = head[u];
    while(p)
    {
        if(p->adjvext == v)
            if(p == pre)
            {
                head[u] = p->next;
                free(pre);
                break;
            }
            else
            {
                pre->next = p->next;
                free(p);
                break;
            }
        pre = p;
        p = p->next;
    }
    p = head[v];
    pre = head[v];
    while(p)
    {
        if(p->adjvext == u)
            if(p == pre)
            {
                head[v] = p->next;
                free(pre);
                break;
            }
            else
            {
                pre->next = p->next;
                free(p);
                break;
            }
        pre = p;
        p = p->next;
    }
}

int vis[100];
void component(int n, ArcNode **head)/*#4*/
{
    memset(vis, 0, sizeof(vis));
    int i;
    for(i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i, head);
            printf("\n");
        }
    }
}

void dfs(int u, ArcNode **head)
{
    vis[u] = 1;
    printf("%d ", u);
    ArcNode *p = head[u];
    while(p)
    {
        if(!vis[p->adjvext])
            dfs(p->adjvext, head);
        p = p->next;
    }
}

int main()
{
    int n, m, i;
    int u, v, num;
    scanf("%d%d", &n, &m);
    ArcNode **head = (ArcNode**) malloc(n * sizeof(ArcNode*));
    for(i = 0; i < n; i++)
        head[i] = NULL;
    for(i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &num);
        add(head, u, v, num);
        add(head, v, u, num);
    }

    int arr[100][100];
    int j;
    memset(arr, 0, sizeof(arr));
    toMatrix(head, n, arr);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    del(head, 1, 4);
    ArcNode *p;
    for(i = 0; i < n; i++)
    {
        printf("%d ", i);
        p = head[i];
        while(p)
        {
            printf("%d ", p->adjvext);
            p = p->next;
        }
        printf("\n");
    }

    component(n, head);
    return 0;
}
