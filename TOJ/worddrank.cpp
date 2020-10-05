#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct node
{
    char c[13];
}arr[100005];

bool cmp(node a, node b)
{
    for(int i = 0; i < 10; i++)
    {
        if(a.c[i] > b.c[i])
            return 1;
        else if(a.c[i] < b.c[i])
            return 0;
    }
    return 1;
}

int main()
{
    int num;
    int n, q;
    int index;
    scanf("%d", &num);
    while(num--)
    {
        memset(arr, 0, sizeof(arr));
        scanf("%d%d", &n, &q);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", arr[i].c);
        }
        sort(arr, arr + n, cmp);

        for(int i = 0; i < q; i++)
        {
            scanf("%d", &index);
            printf("%s\n" ,arr[index-1].c);
        }
    }
    return 0;
}
