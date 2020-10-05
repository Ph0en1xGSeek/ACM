#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct node
{
    int dis[3];
    int pos;
    bool operator<(const node& b) const
    {
        return dis[0] > b.dis[0];
    }
}arr[5];

int ans[5];

int main() {

    int ca;
    int num;
    scanf("%d", &ca);
    while (ca--)
    {
        scanf("%d", &num);
        for(int i = 1; i <= num; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                scanf("%d", &arr[i].dis[j]);
            }
            arr[i].pos = i;
            if(arr[i].dis[1] < arr[i].dis[2])
                swap(arr[i].dis[1], arr[i].dis[2]);
            if(arr[i].dis[0] < arr[i].dis[1])
                swap(arr[i].dis[0], arr[i].dis[1]);
        }
        sort(arr+1, arr+num+1);

        for(int i = 1; i <= num; i++)
        {
            ans[arr[i].pos] = i;
        }

        printf("%d", ans[1]);
        for(int i = 2; i <= num; i++)
        {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}