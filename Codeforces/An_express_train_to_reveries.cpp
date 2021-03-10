#include <iostream>
#include <stdio.h>>
#include <algorithm>>
#include <string.h>
#define M 1005

using namespace std;

int arr[M], brr[M];
int existA[M];
int pos[5];
int cnt;

int main()
{
    int num;
    while(~scanf("%d", &num))
    {
        cnt = 0;
        memset(existA, 0, sizeof(existA));
        for(int i = 0; i < num; i++)
            scanf("%d", &arr[i]);
        for(int i = 0; i < num; i++)
            scanf("%d", &brr[i]);
        for(int i = 0; i < num; i++)
        {
            existA[arr[i]]++;
            if(arr[i] != brr[i])
                pos[cnt++] = i;
        }
        if(cnt == 1)
        {
            for(int i = 1; i <= num; i++)
            {
                if(existA[i] == 0)
                {
                    arr[pos[0]] = i;
                    break;
                }
            }
        }
        else if(cnt == 2)
        {
            if(existA[arr[pos[0]]] > 1 && existA[brr[pos[0]]] == 0)
                arr[pos[0]] = brr[pos[0]];
            else
                arr[pos[1]] = brr[pos[1]];
        }
        for(int i = 0; i < num; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
