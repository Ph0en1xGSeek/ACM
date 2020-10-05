#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct node
{
    char color[20];
    int n;
    bool operator<(const node& b) const
    {
        return n > b.n;
    }
}arr[50];

int main()
{
    int ca;
    int num;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &num);
        for(int i = 0; i < num; i++)
        {
            getchar();
            scanf("%s", arr[i].color);
            scanf("%d", &arr[i].n);
        }
        sort(arr, arr+num);
        printf("%s", arr[0].color);
        for(int i = 1; i < num; i++)
        {
            printf(" %s", arr[i].color);
        }
        printf("\n");
    }
    return 0;
}
